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



        public override void Update(GameTime gameTime)
        {


            // Player input

            var state = Input.keyState;

            // Player movement

            if (state.IsKeyDown(Input.Controls.goUp))
            {
                pos2D += new Vector2(0, -m_moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goLeft))
            {
                pos2D += new Vector2(-m_moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goRight))
            {
                pos2D += new Vector2(m_moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goDown))
            {
                pos2D += new Vector2(0, m_moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
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
                            hiding = true;
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
                
                
                hiding = false;
                toReturn.Add(val);
            }
            for(int i=0;i<toReturn.Count;i++)
            {
                collisionEvents.Enqueue(toReturn[i]);
            }
            

            Console.WriteLine("Hiding: " + hiding);


            base.Update(gameTime);

        }
    }
}
