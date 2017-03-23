using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    class GameObject2D : GameObject
    {
        /// <summary>
        /// Whether the object should collide with anything.
        /// </summary>
        public bool collisions = true;
        /// <summary>
        /// Whether the object should be drawn.
        /// </summary>
        public bool visible = true;
        /// <summary>
        /// Whether the object should update each frame.
        /// </summary>
        public bool active = true;

        public float maxHP =0;

        private string m_type;
        public string type
        {
            get { return m_type; }
            set { m_type = value; }
        }

        private string m_id;
        public string id
        {
            get { return m_id; }
            set { m_id = value; }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="newid">Unique string ID of object.</param>
        /// <param name="newtype">Type of object, eg. enemy, NPC.</param>
        /// <param name="maxHP">Object's max HP. 0 if invincible object.</param>
        public GameObject2D(string newid, string newtype, float maxHP)
        {
            m_id = newid;
            m_type = newtype;
            hp = maxHP;
        }

        public GameObject2D(string newid, string newtype)
        {
            m_id = newid;
            m_type = newtype;
        }


        private Vector2 m_scale = new Vector2(1,1);
        private float m_rotation = 0;
        public float rotation
        {
            get { return m_rotation; }
            set { m_rotation = value; }
        }
        private Texture2D m_sprite;
        public Texture2D sprite
        {
            get { return m_sprite; }
            set { m_sprite = value; }
        }

        private Queue<GameObject2D> m_collisionEvents = new Queue<GameObject2D>();

        const int COLTRIGGERSIZE = 1000;
        Table<GameObject2D, Action<GameTime, GameObject2D, GameObject2D>> collisionTriggers = new Table<GameObject2D, Action<GameTime, GameObject2D, GameObject2D>>(COLTRIGGERSIZE);
        Table<string, Action<GameTime, GameObject2D, GameObject2D>> collisionTypeTriggers = new Table<string, Action<GameTime, GameObject2D, GameObject2D>>(COLTRIGGERSIZE);
        //Table<Creature, Action<GameTime, Creature, Creature>> creatureCollisionTriggers = new Table<Creature, Action<GameTime, Creature, Creature>>(COLTRIGGERSIZE);



        public void AddCollisionTrigger(GameObject2D obj, Action<GameTime, GameObject2D, GameObject2D> method)
        {
            collisionTriggers.Add(obj, method);
        }

        public void AddCollisionTrigger(string objType, Action<GameTime, GameObject2D, GameObject2D> method)
        {
            collisionTypeTriggers.Add(objType, method);
        }


        public void AddCollisionEvent(GameObject2D obj)
        {
            m_collisionEvents.Enqueue(obj);
        }

        public void ProcessCollisionEvent(GameTime gameTime, GameObject2D otherObj)
        {
            if (collisionTriggers.ContainsKey(otherObj))
            {
                collisionTriggers.Get(otherObj).DynamicInvoke(gameTime,this, otherObj);
            }

            if (collisionTypeTriggers.ContainsKey(otherObj.type))
            {
                collisionTriggers.Get(otherObj).DynamicInvoke(gameTime,this, otherObj);
            }
        }

        /// <summary>
        /// Last position the gameobject was not colliding with anything.
        /// </summary>
        private Vector2 m_lastPosNoCol = new Vector2();

        public Vector2 lastPosNoCol
        {
            get { return m_lastPosNoCol; }
            set { m_lastPosNoCol = value; }
        }
        /// <summary>
        /// Update the 2D game object.
        /// </summary>
        /// <param name="gameTime"></param>
        public override void Update(GameTime gameTime)
        {
            for(int i=0; i< m_collisionEvents.Count;i++)
            {
                ProcessCollisionEvent(gameTime, m_collisionEvents.Dequeue());
            }


        }

        

        

        public void Render(SpriteBatch sprBatch)
        {
            if(sprite!=null)
            {
                Render2D.DrawSpriteAtLocation(sprBatch, this.sprite, this.pos2D, this.rotation, m_scale);
            }
            
        }

        public Rectangle boundingBox

        {
            get
            {

                if(sprite != null)
                {
                    return new Rectangle((int)pos2D.X, (int)pos2D.Y, sprite.Width, sprite.Height);
                }
                else
                {
                    return new Rectangle();
                }
                

            }

        }






        public float hp;
        public float hitLimitSeconds = 1;
        public System.TimeSpan lastTimeHitTaken;


        

        public void RegisterHit(GameTime gameTime, float hpTaken)
        {
            System.TimeSpan totalTime = gameTime.TotalGameTime;
            if (totalTime - lastTimeHitTaken > TimeSpan.FromSeconds(hitLimitSeconds))
            {
                Console.WriteLine(m_id + " takes " + hpTaken + " damage.");
                TakeDamage(hpTaken);
                lastTimeHitTaken = gameTime.TotalGameTime;
            }
        }

        public void TakeDamage(float hpTaken)
        {
            hp -= hpTaken;
            if(hp<=0)
            {
                TriggerDeath();
            }
        }
        

        /// <summary>
        /// TODO actually destroy object.
        /// </summary>
        public void TriggerDeath()
        {
            Console.WriteLine(id + " died.");
            visible = false;
            collisions = false;
            active = false;
        }












    }

}
