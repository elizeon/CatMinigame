using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;


namespace Game1
{
    public class Player : GameObject2D
    {
        private bool m_hiding = false;
        public bool hiding { get { return m_hiding; }set { m_hiding = value; } }
        private float m_moveSpeed = 300f;

        public Player(string newid, string newtype, float newhp) : base(newid, newtype,newhp)
        {

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

        public override void Update(GameTime gameTime)
        {

            for (int i = 0; i < collisionEvents.Count; i++)
            {
                ProcessCollisionEventPlayer(gameTime, collisionEvents.Dequeue());
            }
            // Player input

            var state = Input.keyState;

            // Player movement

            if (state.IsKeyDown(Input.Controls.goUp))
            {
                pos2D += new Vector2(0, -m_moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                if (animSprite != animSprites["runUp"])
                {
                    animSprite = animSprites["runUp"];
                }
            }

            if (state.IsKeyDown(Input.Controls.goLeft))
            {
                pos2D += new Vector2(-m_moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                if (animSprite != animSprites["runLeft"])
                {
                    animSprite = animSprites["runLeft"];
                }

            }

            if (state.IsKeyDown(Input.Controls.goRight))
            {
                pos2D += new Vector2(m_moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;

                if (animSprite != animSprites["runRight"])
                {
                    animSprite = animSprites["runRight"];
                }
            }

            if (state.IsKeyDown(Input.Controls.goDown))
            {
                pos2D += new Vector2(0, m_moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                if (animSprite != animSprites["runDown"])
                {
                    animSprite = animSprites["runDown"];
                }
            }

            if (!state.IsKeyDown(Input.Controls.goUp) && !state.IsKeyDown(Input.Controls.goDown) && !state.IsKeyDown(Input.Controls.goLeft) && !state.IsKeyDown(Input.Controls.goRight))
            {
                if (animSprite != animSprites["idle"])
                {
                    animSprite = animSprites["idle"];
                }
            }
            // Player combat

            // Hiding
            List<GameObject2D> toReturn = new List<GameObject2D>();
            bool tohide = false;

            for (int i = 0; i < collisionEvents.Count; i++)
            {
                var val = collisionEvents.Dequeue();
                switch (val.type)
                {
                    case "hideloc":
                        {
                            tohide = true;
                            break;
                        }
                        /*
                    case "enemy":
                        {
                            RegisterHit(gameTime,10);
                            val.
                            break;
                        }*/
                        
                }
                
             
                
                toReturn.Add(val);
            }

            if (tohide)
            {
                hiding = true;
            }
            else
            {
                hiding = false;
            }

            for (int i=0;i<toReturn.Count;i++)
            {
                collisionEvents.Enqueue(toReturn[i]);
            }
            

            Console.WriteLine("Hiding: " + hiding);


            base.Update(gameTime);

        }
    }
}
