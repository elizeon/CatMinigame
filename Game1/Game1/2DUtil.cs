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

        public static float LookAt(Vector2 source, Vector2 dest)
        {
            Vector2 direction = dest - source;
            return (float)Math.Atan2(direction.Y, direction.X);

        }
        

        public static bool CheckCollision(GameObject2D obj1, GameObject2D obj2)
        {
            if(obj1.collisions && obj2.collisions)
            {
                if (obj1.boundingBox.Intersects(obj2.boundingBox))
                {
                    return (true);

                }
                
            }
            return false;

        }

        public static void ResolveCollision(GameObject2D obj1, GameObject2D obj2)
        {
            obj1.pos2D = new Vector2(obj1.lastPosNoCol.X, obj1.lastPosNoCol.Y);
            obj2.pos2D = new Vector2(obj2.lastPosNoCol.X, obj2.lastPosNoCol.Y);
        }

    }
}
