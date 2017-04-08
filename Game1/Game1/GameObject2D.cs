using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;


namespace Game1
{
    public class GameObject2D : GameObject
    {

        //public Dictionary<string,bool> states { get; set; }
        public AnimatedSprite animSprite { get; protected set; }

        /// <summary>
        /// Dictionary of animated (or static) sprites.
        /// </summary>
        public Dictionary<string, AnimatedSprite> animSprites { get; }
        /// <summary>
        /// For searching the dictionary elements recursively.
        /// </summary>
        private List<AnimatedSprite> animSpritesList = new List<AnimatedSprite>();

        public void AddAnimSprite(string key, AnimatedSprite sprite)
        {
            animSprites[key] = sprite;
            animSpritesList.Add(sprite);

            if (defaultAnim == null)
            {
                defaultAnim = key;
            }
            if (animSprite == null)
            {
                animSprite = sprite;
            }

            if (animSprite != null)
            {

                maxX = 0;
                maxY = 0;
                for (int i = 0; i < animSpritesList.Count; i++)
                {
                    if (animSpritesList[i].width > maxX)
                    {
                        maxX = animSpritesList[i].width * scale.X;

                    }
                    if (animSpritesList[i].width > maxY)
                    {
                        maxY = animSpritesList[i].width * scale.Y;

                    }

                    //m_boundingBox = 
                }


            }
        }

        //todo rename these vars to be more explanatory
        public float maxX { get; private set; }
        public float maxY { get; private set; }

        /// <summary>
        /// Default AnimatedSprite to revert to once finished playing a temp animation.
        /// If null, will be set to the first AnimatedSprite you add.
        /// </summary>
        public string defaultAnim { get; set; }
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

        public float maxHP = 0;

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
        /// Constructor with HP. Makes new object with given HP. (0 if invincible)
        /// </summary>
        /// <param name="newid">Unique string ID of object.</param>
        /// <param name="newtype">Type of object, eg. enemy, NPC.</param>
        /// <param name="maxHP">Object's max HP. 0 if invincible object.</param>
        public GameObject2D(string newid, string newtype, float maxHP) : this(newid, newtype)
        {
            hp = maxHP;
        }

        /// <summary>
        /// Basic constructor. Makes new object with 0 (invincible) HP.
        /// </summary>
        /// <param name="newid">Unique string ID of object.</param>
        /// <param name="newtype">Type of object, eg. enemy, NPC.</param>
        public GameObject2D(string newid, string newtype)
        {
            animSprites = new Dictionary<string, AnimatedSprite>();

            animSprites["default"] = new AnimatedSprite(null, 1, 1);
            animSprite = animSprites["default"];
            m_id = newid;
            m_type = newtype;
            hp = 0;
            direction = new Vector2(0, 0);
            //targetDirection = new Vector2(direction.X,direction.Y);
            rotation = 0;
            //targetRotation = 0;
            
            //m_boundingBox = new Rectangle(-10000,-10000,1,1);



        }

        public float rotation { get; protected set; }

        //public float targetRotation { get; protected set; }
       // public Vector2 targetDirection { get; protected set; }
        
        public Vector2 direction { get; protected set; }



        private Vector2 m_scale = new Vector2(1, 1);
        /// <summary>
        /// Scale of the object. Assumes that sprites in animation set for this object are uniform and do not require individual scaling.
        /// </summary>
        public Vector2 scale { get { return m_scale; } set { m_scale = value; } }

        
        private Queue<GameObject2D> m_collisionEvents = new Queue<GameObject2D>();
        public Queue<GameObject2D> collisionEvents { get { return m_collisionEvents; } }

        public const int COLTRIGGERSIZE = 1000;
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
                collisionTriggers.Get(otherObj).DynamicInvoke(gameTime, this, otherObj);
            }

            if (collisionTypeTriggers.ContainsKey(otherObj.type))
            {
                collisionTriggers.Get(otherObj).DynamicInvoke(gameTime, this, otherObj);
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
            if(!usingCustomBBox)
            {
                m_boundingBox = new Rectangle((int)(pos2D.X - maxX / 2), (int)(pos2D.Y - maxY / 2), (int)(maxX), (int)(maxY));

            }

            /*
            if(!animSprite.playing)
            {
                SetAnim(defaultAnim);
                animSprite.playing = true;
            }
            else
            {
            */
            animSprite.Update(gameTime);
                for (int i = 0; i < m_collisionEvents.Count; i++)
                {
                    ProcessCollisionEvent(gameTime, m_collisionEvents.Dequeue());
                }
            //}
            


        }

        private bool usingCustomBBox = false;

        /// <summary>
        /// Set the animation to that with the string key given.
        /// </summary>
        /// <param name="anim">String key of animation to set the object to.</param>
        public void SetAnim(string anim)
        {
            if (animSprites.ContainsKey(anim))
            {
                animSprite = animSprites[anim];
            }

        }

        /*
        /// <summary>
        /// Play animation of this string once, then revert to default.
        /// </summary>
        /// <param name="anim">String key of animation to set the object to.</param>
        public void PlayAnim(string anim)
        {
            if (animSprites.ContainsKey(anim))
            {
                animSprite = animSprites[anim];
                animSprite.PlayOnce();
            }

        }
        */

        /// <summary>
        /// Returns size of the current sprite.
        /// </summary>
        public Vector2 spriteSize
        {
            get
            {
                return new Vector2(animSprite.width * scale.X, animSprite.height * scale.Y);

            }
        }


        public virtual void Render(SpriteBatch sprBatch)
        {
            if(visible)
            {
                if (animSprite != null)
                {
                    animSprite.Draw(sprBatch, new Vector2(pos2D.X-(spriteSize.X)/2,pos2D.Y-(spriteSize.Y)/2), rotation, scale);
                    Render2D.Instance.DrawRectangle(sprBatch, boundingBox, Color.White);

                }
            }
            

        }

        public Rectangle boundingBox

        {
            get
            {

                return m_boundingBox ;


            }
            set
            { m_boundingBox = value; }

        }
        private Rectangle m_boundingBox;







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
            if (hp <= 0)
            {
                TriggerDeath();
            }
        }

        public void SetCustomBoundingBox(Rectangle rect)
        {
            m_boundingBox = rect;
            usingCustomBBox = true;
            Console.WriteLine(this.id + " now using custom bounding box.\n");
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
            SetCustomBoundingBox( default(Rectangle));
        }












    }

}
