using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    static class Render2D
    {
        public static void DrawSpriteAtLocation(SpriteBatch spriteBatch, Texture2D sprite, Vector2 loc, float rotation, Vector2 scale)
        {
            spriteBatch.Draw(sprite, loc, null, Color.White, rotation, new Vector2(sprite.Width / 2, sprite.Height / 2), scale, SpriteEffects.None, 0f);
            // 45 degrees ((float) Math.PI)

        }
    }
}
