using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Game1
{
    static class _2DUtil
    {
        /// <summary>
        /// Returns true if the first value is the same as the second
        /// </summary>
        /// <param name="first"></param>
        /// <param name="second"></param>
        /// <returns></returns>
        public static bool IsAt(Vector2 first, Vector2 second)
        {
            if(first.X==second.X && first.Y==second.Y)
            {
                return true;
            }
            return false;
        }


        public static float Distance(Vector2 first, Vector2 second)
        {
            return (float) Math.Sqrt(Math.Pow(second.X - first.X, 2) + Math.Pow(second.Y - first.Y, 2));
        }
        public static float LookAt(Vector2 source, Vector2 dest)
        {
            Vector2 direction = dest - source;
            return (float)Math.Atan2(direction.Y, direction.X);

        }
        public static void MoveTowards(GameObject2D obj, Vector2 dest, float step)
        {
            Vector2 direction = Vector2.Normalize(dest - obj.pos2D);
            obj.SetPos2D( obj.pos2D + direction * step);

            if (Distance(obj.pos2D, dest) <= step)
            {
                //Console.WriteLine(obj.pos2D.X + "," + obj.pos2D.Y);
                //Console.WriteLine(dest.X + "," + dest.Y);
                obj.SetPos2D(new Vector2(dest.X, dest.Y));

                PrintXnaVec(obj.pos2D);
            }
            
        }


        public static void PrintXnaVec(Vector2 vec)
        {
            Console.WriteLine(vec.X + "," + vec.Y);
        }
        /*
        public static bool CheckCollision(GameObject2D obj1, GameObject2D obj2)
        {
            //if(obj1.collisions && obj2.collisions)
            //{
                if (obj1.boundingBox.Intersects(obj2.boundingBox))
                {
                    return (true);

                }
                
            //}
            return false;

        }
        */

        public static bool CheckCollision(OBB obj1, Rectangle obj2)
        {
            if(obj1==default(OBB) || obj2 ==default(Rectangle))
            {
                return false;
            }
            //if(obj1.collisions && obj2.collisions)
            //{
            OBB newOBB = new OBB(new Vector2(obj2.Center.X, obj2.Center.Y), 0, new Vector2(obj2.Width / 2, obj2.Height / 2));
            if (obj1.Intersects(newOBB))
            {
                return (true);

            }

            //}
            return false;

        }

        /*

        public static bool CheckCollision(GameObject2D obj1, Rectangle obj2)
        {
            if(obj1.collisions)
            {
                if (obj1.boundingBox.Intersects(obj2))
                {
                    return (true);

                }
            }
            return false;
        }
        */
        public static bool CheckCollision(Rectangle obj1, Rectangle obj2)
        {

            if (obj1 == default(Rectangle) || obj2 == default(Rectangle))
            {
                return false;
            }

            if (obj1.Intersects(obj2))
            {
                return (true);

            }
            return (false);
        }

        public static void ResolveCollision(GameObject2D obj1, GameObject2D obj2)
        {
            obj1.SetPos2D( new Vector2(obj1.lastPosNoCol.X, obj1.lastPosNoCol.Y));
            obj2.SetPos2D( new Vector2(obj2.lastPosNoCol.X, obj2.lastPosNoCol.Y));
        }

    }
}
