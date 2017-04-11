using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Game1
{

    public static class Utility
    {
        public static Vector2 PointToVec2(Point point)
        {
            return new Vector2(point.X, point.Y);
        }
        public static Point Vec2ToPoint(Vector2 vec)
        {
            return new Point((int)vec.X, (int)vec.Y);
        }
    }
    

    public class vec2 
    {

        public static vec2 FromXnaVec(Vector2 xna)
        {
            return new vec2(xna.X, xna.Y);
        }
        private Vector2 myvec;

        public static vec2 operator *(vec2 a, vec2 b)
        {

            return FromXnaVec(a.xnaVec * b.xnaVec);//new vec2(a.x*b.x,a.y*b.y);
        }

        public static vec2 operator *(vec2 a, float b)
        {

            return FromXnaVec(a.xnaVec * b);
        }

        public static vec2 operator +(vec2 a, vec2 b)
        {

            return FromXnaVec(a.xnaVec + b.xnaVec);
        }

        public static vec2 operator -(vec2 a, vec2 b)
        {

            return FromXnaVec(a.xnaVec - b.xnaVec);
        }
        
        public void Normalise()
        {
            Vector2 newvec = new Vector2(x, y);
            newvec.Normalize();
            x = newvec.X;
            y = newvec.Y;
        }

        public float x;
        public float y;
        public vec2(float x1, float y1)
        {
            x = x1;
            y = y1;
        }

        public vec2(vec2 copy)
        {
            x = copy.x;
            y = copy.y;
        }



        public Vector2 xnaVec
        {
            get { return myvec; }
            //get { return new Vector2(x, y); }
        }

        public vec2 Clone()
        {
            return new vec2(x, y);
        }
    }

    public class vec3 
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
            get { return new Vector3(x, y, z); }
        }

        public vec3 Clone()
        {
            return new vec3(x, y, z);
        }

        public vec3(vec3 copy)
        {
            x = copy.x;
            y = copy.y;
            z = copy.z;
        }

    }
}
    
