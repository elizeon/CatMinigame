using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;


namespace Game1
{
    public class Player : GameObject2D
    {
        private bool m_hiding = false;
        public bool hiding { get { return m_hiding; }set { m_hiding = value; } }
        private float m_moveSpeed = 0.3f;

        private Vector2 m_targetLoc;

        public Player(string newid, string newtype, float newhp) : base(newid, newtype,newhp)
        {
            
        }

        /// <summary>
        /// True if initial position of player has not been set.
        /// </summary>
        bool m_initPos = true;
        public override void SetPos2D(Vector2 newpos)
        {
            base.SetPos2D(newpos);
            if(m_initPos)
            {
                m_targetLoc = pos2D;
                m_initPos = false;

            }
        }

        public override void Render(SpriteBatch sprBatch)
        {
            base.Render(sprBatch);
            //Render2D.Instance.DrawRectangle(sprBatch, new Rectangle((int)pos2D.X, (int)pos2D.Y, 10, 10), Color.White);
        }


        Table<string, Action<GameTime, Player, GameObject2D>> collisionTriggersWithThisType = new Table<string, Action<GameTime, Player, GameObject2D>>(COLTRIGGERSIZE);
        

        public void AddCollisionTrigger(string objType, Action<GameTime, Player, GameObject2D> method)
        {
            collisionTriggersWithThisType.Add(objType, method);
        }

        public void ProcessCollisionEventPlayer(GameTime gameTime, GameObject2D otherObj)
        {
            if (collisionTriggersWithThisType.ContainsKey(otherObj.type))
            {
                collisionTriggersWithThisType.Get(otherObj.type).DynamicInvoke(gameTime, this, otherObj);
            }
        }

        bool m_playerMoving = false;

        public override void TriggerLife()
        {
            base.TriggerLife();
            m_initPos = true;
        }

        public override void Update(GameTime gameTime)
        {
            // Hiding
            List<GameObject2D> toReturn = new List<GameObject2D>();
            bool tohide = false;

            for (int i = 0; i < collisionEvents.Count; i++)
            {
                var val = collisionEvents[i];

                ProcessCollisionEventPlayer(gameTime, val);

                switch (val.type)
                {
                    case "hideloc":
                        {
                            tohide = true;
                            break;
                        }
                }
                
            }

            if (tohide)
            {
                hiding = true;
            }
            else
            {
                hiding = false;
            }

            for (int i = 0; i < collisionEvents.Count; i++)
            {
                
            }

            base.Update(gameTime);

            // Player input

            var state = Game1.keyState;
            var mouse = Game1.mouseState;
            

            if(mouse.LeftButton == Microsoft.Xna.Framework.Input.ButtonState.Pressed)
            {
                bool newClick = false;
                if (Game1.oldMouseState.LeftButton == Microsoft.Xna.Framework.Input.ButtonState.Pressed)
                {
                    newClick = false;
                }
                else
                {
                    newClick = true;
                }
                if(newClick)
                {
                    //m_targetLoc =  new Vector2(mouse.Position.X,mouse.Position.Y);
                    m_playerMoving = true;
                    m_targetLoc = Game1.gameGrid.GetPoint(mouse.Position.X / Game1.screenWidth, mouse.Position.Y / Game1.screenHeight);
                    Vector2 source = this.pos2D;
                    Vector2 dest = m_targetLoc;


                    rotation = _2DUtil.LookAt(source, dest);
                    //
                    direction = dest - this.pos2D;
                }
                else
                {

                }
                

            }
            // Player movement

            if (m_playerMoving && !_2DUtil.IsAt(this.pos2D, m_targetLoc))
            {
                _2DUtil.MoveTowards(this, m_targetLoc, (float)gameTime.ElapsedGameTime.TotalMilliseconds * m_moveSpeed);
                //Console.WriteLine(pos2D.X + ", " + pos2D.Y + " / " + patrolPath[m_patrolIndex].X + ", " + patrolPath[m_patrolIndex].Y);
                if (animSprite != animSprites["runUp"])
                {
                    animSprite = animSprites["runUp"];
                }
            }
            else
            {
                m_playerMoving = false;
            }
              
            if (!m_playerMoving)
            {
                if (animSprite != animSprites["idle"])
                {
                    animSprite = animSprites["idle"];
                }
            }
            // Player combat

           
            

            //Console.WriteLine("Hiding: " + hiding);



            //Console.WriteLine("Player location at " + pos2D.X, ", " + pos2D.Y);


        }
    }
}
