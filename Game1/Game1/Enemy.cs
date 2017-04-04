using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    class Enemy : GameObject2D
    {

        public override void Render(SpriteBatch sprBatch)
        {
            base.Render(sprBatch);
            Render2D.Instance.DrawRectangle(sprBatch, viewCone[0], Color.White);
        }

        private List<Vector2> m_patrolPath = new List<Vector2>();
        public List<Vector2> patrolPath { set { m_patrolPath = value; } get { return m_patrolPath; } }

        private int m_patrolIndex = 0;
        private float m_moveSpeed = 0;

        public enum EnemyState { patrolling, chasing }
        private EnemyState m_enemyState = EnemyState.chasing;
        //public EnemyState enemyState { get { return m_enemyState; }set { m_enemyState = value; } }
        public void SetEnemyState(EnemyState istate)
        {
            Console.WriteLine("Enemy state changed.");
            m_enemyState = istate;
            if (istate == EnemyState.patrolling)
            {
                m_moveSpeed = 0.1f;
            }
            if (istate == EnemyState.chasing)
            {
                m_moveSpeed = 0.5f;
            }
        }


        Table<GameObject2D, Action<GameTime, Enemy, GameObject2D>> collisionTriggersWithThisType = new Table<GameObject2D, Action<GameTime, Enemy, GameObject2D>>(COLTRIGGERSIZE);

        public Enemy(string newid, string newtype, float newhp) : base(newid, newtype, newhp)
        {
            SetEnemyState(EnemyState.patrolling);
        }

        public void AddCollisionTrigger(GameObject2D objType, Action<GameTime, Enemy, GameObject2D> method)
        {
            collisionTriggersWithThisType.Add(objType, method);
        }

        public void ProcessCollisionEventEnemy(GameTime gameTime, GameObject2D otherObj)
        {
            if (collisionTriggersWithThisType.ContainsKey(otherObj))
            {
                collisionTriggersWithThisType.Get(otherObj).DynamicInvoke(gameTime, this, otherObj);
            }
        }

        private List<Rectangle> m_viewCone = new List<Rectangle>();

        public override void Update(GameTime gameTime)
        {
            base.Update(gameTime);


                if (m_enemyState == EnemyState.patrolling)
            {
                if (_2DUtil.CheckCollision(Game1.player.boundingBox, viewCone[0]) && !Game1.player.hiding)
                {
                    SetEnemyState(EnemyState.chasing);
                }
            }
            
            for (int i = 0; i < collisionEvents.Count; i++)
            {
                ProcessCollisionEventEnemy(gameTime, collisionEvents.Dequeue());
            }

            //pos2D +=  new Vector2(10,0);

            if (m_enemyState == EnemyState.patrolling)
            {
                if (!_2DUtil.IsAt(this.pos2D, patrolPath[m_patrolIndex]))
                {
                    _2DUtil.MoveTowards(this, patrolPath[m_patrolIndex], (float)gameTime.ElapsedGameTime.TotalMilliseconds * m_moveSpeed);
                    //Console.WriteLine(pos2D.X + ", " + pos2D.Y + " / " + patrolPath[m_patrolIndex].X + ", " + patrolPath[m_patrolIndex].Y);

                    if (_2DUtil.IsAt(pos2D, patrolPath[m_patrolIndex]))
                    {
                        if (m_patrolIndex < m_patrolPath.Count - 1)
                        {
                            m_patrolIndex += 1;
                            StartPatrol(m_patrolIndex);

                        }
                        else
                        {
                            m_patrolIndex = 0;
                            StartPatrol(m_patrolIndex);
                        }

                    }

                }


            }

            else
            {
                if (m_enemyState == EnemyState.chasing)
                {
                    rotation = _2DUtil.LookAt(this.pos2D, Game1.player.pos2D);
                    m_direction = Game1.player.pos2D - this.pos2D;
                    m_direction.Normalize();
                    _2DUtil.MoveTowards(this, Game1.player.pos2D, (float)gameTime.ElapsedGameTime.TotalMilliseconds * m_moveSpeed);
                }
            }

        }

        private Vector2 m_direction = new Vector2();

        public void StartPatrol(int patrolIndex)
        {
            Vector2 source = this.pos2D;
            Vector2 dest = m_patrolPath[patrolIndex];

            rotation = _2DUtil.LookAt(source, dest);
            m_direction = dest - this.pos2D;
            m_direction.Normalize();
        }

        private float m_viewDist = 4f;
        //todo must be rotating rectangle...
        public List<Rectangle> viewCone
        {
            get
            {


                if (animSprite != null)
                {

                    //Vector2 spriteSize = new Vector2((int)(animSprite.width / (1 / scale.X)), (int)(animSprite.height / (1 / scale.Y)));
                    //Vector2 direction = dest - source;

                    Vector2 distdir = new Vector2(m_direction.X * m_viewDist, m_direction.Y * m_viewDist);
                    //Rectangle rect1 = new Rectangle((int)pos2D.X - (int)(spriteSize.X/2), (int)pos2D.Y - (int)(spriteSize.Y / 2), ((int)pos2D.X + (int)(spriteSize.X / 2)) * (int)distdir.X, ((int)pos2D.Y + (int)(spriteSize.Y / 2)) * (int)distdir.Y);

                    //int w = (int)(spriteSize.X * m_viewDist);
                    //int h = (int)(spriteSize.Y * m_viewDist);
                    int w = 100;
                    int h = 100;
                    //Rectangle rect1 = new Rectangle((int)(pos2D.X - (spriteSize.X / 2)), (int)(pos2D.Y - (spriteSize.Y / 2)), w, h);
                    Rectangle rect1 = new Rectangle((int)(pos2D.X ), (int)(pos2D.Y), w, h);

                    if (m_viewCone.Count > 0)
                    {
                        m_viewCone[0] = rect1;
                    }
                    else
                    {
                        m_viewCone.Add(rect1);
                    }

                    return m_viewCone;
                }
                else
                    return null;
                

                    
                

            }
        }

    }
}
