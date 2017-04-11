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
            if (visible)
            {
                //viewCone.Draw(Game1.whiteTex, sprBatch);

                base.Render(sprBatch);

                Render2D.Instance.DebugSphere(sprBatch, pos2D, (int)viewDist);
                //Render2D.Instance.DrawRectangle(sprBatch, viewCone[0], Color.White);
                //Render2D.Instance.DrawRectangle(sprBatch, new Rectangle((int)pos2D.X, (int)pos2D.Y, 10, 10), Color.White);
            }
        }

        private List<Vector2> m_patrolPath = new List<Vector2>();
        public List<Vector2> patrolPath { set { m_patrolPath = value; } get { return m_patrolPath; } }

        private int m_patrolIndex = 0;
        private float m_moveSpeed = 0;
        public void SetMoveSpeed(float sp)
        {
            m_moveSpeed = sp;
        }

        public enum EnemyState { patrolling, chasing }
        private EnemyState m_enemyState = EnemyState.chasing;
        //public EnemyState enemyState { get { return m_enemyState; }set { m_enemyState = value; } }
        public void SetEnemyState(EnemyState istate)
        {
            Console.WriteLine("Enemy state changed to "+istate);
            m_enemyState = istate;
            if (istate == EnemyState.patrolling)
            {
                m_moveSpeed = 0.1f;
            }
            if (istate == EnemyState.chasing)
            {
                m_moveSpeed = 2f;
            }
        }


        Table<GameObject2D, Action<GameTime, Enemy, GameObject2D>> collisionTriggersWithThisType = new Table<GameObject2D, Action<GameTime, Enemy, GameObject2D>>(COLTRIGGERSIZE);

        public Enemy(string newid, string newtype, float newhp) : base(newid, newtype, newhp)
        {
            viewDist = 100;
            viewAngle = 20;
            hiddenViewDist = 0;
            closeViewDist = 0;
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

        //private List<Rectangle> m_viewCone = new List<Rectangle>();

        public override void Update(GameTime gameTime)
        {
            base.Update(gameTime);

            /*
           if(rotation != targetRotation)
           {
               rotation = rotation + Game1.deltaTime * rotation / 10;
               if(rotation - targetRotation < Game1.deltaTime*rotation / 10)
               {
                   rotation = targetRotation;
               }
           }


           if (direction != targetDirection)
           {
               float xinc = Game1.deltaTime * direction.X / 10;
               float yinc = Game1.deltaTime * direction.Y / 10;

               direction = new Vector2(direction.X + xinc, direc
               tion.Y +  yinc );


               if (direction.X - targetDirection.X < xinc && direction.Y - targetDirection.Y < yinc)
               {
                   direction = targetDirection;
               }
           }

           */






            if (m_enemyState == EnemyState.patrolling)
            {
                Player player = Game1.player;
                bool chase = false;

                if (_2DUtil.CheckSphereCollision(pos2D, viewDist, player.pos2D, player.boundingBox.Width))
                {
                    float rotToPlayer = _2DUtil.LookAt(pos2D, player.pos2D);
                    
                    if (!player.hiding &&// If the player is not hiding
                        // Is the player within the enemy's view angle?
                        (Utility.Within(rotToPlayer, rotation, MathHelper.ToRadians(viewAngle)) ||
                         // Is the player in the close view distance sphere?
                         _2DUtil.CheckSphereCollision(pos2D, closeViewDist, player.pos2D, player.boundingBox.Width)))
                    {
                        chase = true;
                    }
                    else
                    {
                        // If the player is within the cat's hidden sight
                        if (_2DUtil.CheckSphereCollision(pos2D, closeViewDist, player.pos2D, player.boundingBox.Width))
                        {
                            chase = true;
                        }
                    }


                }

                if(chase)
                {
                    SetEnemyState(EnemyState.chasing);

                }

            }
            
            for (int i = 0; i < collisionEvents.Count; i++)
            {

                ProcessCollisionEventEnemy(gameTime, collisionEvents[i]);
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
                    direction = Game1.player.pos2D - this.pos2D;
                    direction.Normalize();
                    _2DUtil.MoveTowards(this, Game1.player.pos2D, (float)gameTime.ElapsedGameTime.TotalMilliseconds * m_moveSpeed);
                }
            }

        }

        /// <summary>
        /// The view distance in which the enemy will see the player even if they are not in their view angle.
        /// Will have no effect if greater than viewDist.
        /// </summary>
        public float closeViewDist { get; set; }

        /// <summary>
        /// The view distance in which the enemy will see the player even if they are hidden.
        /// Will have no effect if greater than viewDist.
        /// </summary>
        public float hiddenViewDist { get; set; }

        public void StartPatrol(int newPatrolIndex)
        {
            Vector2 source = this.pos2D;
            Vector2 dest = m_patrolPath[newPatrolIndex];

            /*
            if(rotation!=targetRotation)
            {
                rotation = targetRotation;
            }

            if (direction != targetDirection)
            {
                direction = new Vector2(targetDirection.X,targetDirection.Y);
            }
            */


            rotation = _2DUtil.LookAt(source, dest);
            //
            //targetRotation = rotation;//_2DUtil.LookAt(source, dest);
            direction = dest - this.pos2D;
            //targetDirection = direction;//dest - this.pos2D;

            m_patrolIndex = newPatrolIndex;

        }
        
        public float viewDist { get; set; }

        public float viewAngle { get; set; }
        
    }
}
