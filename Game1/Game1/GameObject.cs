using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.Xna.Framework;

namespace Game1
{
    class GameObject
    {
        private Vector3 pos = new Vector3 (0,0,0);
        public Vector2 pos2D
        {
            get
            {
                return new Vector2(pos.X, pos.Y);
            }
            set
            {
                pos.X = value.X;
                pos.Y = value.Y;
            }
        }
        public Vector3 pos3D
        {
            get
            {
                return pos;
            }
            set
            {
                pos = pos3D;
            }
        }
        public virtual void Update(GameTime gameTime)
        {

        }

        /*
        public virtual void Render()
        {

        }
        */

    }
}
