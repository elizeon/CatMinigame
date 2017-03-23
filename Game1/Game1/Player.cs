using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;


namespace Game1
{
    class Player : GameObject2D
    {
        private float moveSpeed = 300f;

        public Player(string newid, string newtype, float newhp) : base(newid, newtype,newhp)
        {

        }



        public override void Update(GameTime gameTime)
        {
            base.Update(gameTime);

            // Player input

            var state = Input.keyState;

            // Player movement

            if (state.IsKeyDown(Input.Controls.goUp))
            {
                pos2D += new Vector2(0, -moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goLeft))
            {
                pos2D += new Vector2(-moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goRight))
            {
                pos2D += new Vector2(moveSpeed, 0) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            if (state.IsKeyDown(Input.Controls.goDown))
            {
                pos2D += new Vector2(0, moveSpeed) * (float)gameTime.ElapsedGameTime.TotalSeconds;
                // do something here
            }

            // Player combat




        }
    }
}
