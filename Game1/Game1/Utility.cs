using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Game1
{
    class vec2 : ICloneable
    {
        public float x;
        public float y;
        public vec2(float x1, float y1)
        {
            x = x1;
            y = y1;
        }

        public Vector2 xnaVec
        {
            get { return new Vector2(x, y); }
        }

        public object Clone()
        {
            return new vec2(x, y);
        }
    }

    class vec3 : ICloneable
    {
        public float x;
        public float y;
        public float z;
        public vec3(float x1, float y1, float z1)
        {
            x = x1;
            y = y1;
            z = z1;
        }

        public Vector3 xnaVec
        {
            get { return new Vector3(x, y,z); }
        }

        public object Clone()
        {
            return new vec3(x, y,z);
        }
    }

    class Utility
    {

    }
}
