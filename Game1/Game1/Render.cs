using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{

    public sealed class Render2D
    {
        private static readonly Render2D instance = new Render2D();

        private Render2D()
        { 
        }

        public static Render2D Instance
        {
            get
            {
                return instance;
            }
        }
        private GraphicsDevice m_graphicsDevice = null;

        public void Init(GraphicsDevice gDevice)
        {
            m_graphicsDevice = gDevice;
        }

        public void DrawSpriteAtLocation(SpriteBatch spriteBatch, Texture2D sprite, Vector2 loc, float rotation, Vector2 scale)
        {
            spriteBatch.Draw(sprite, loc, null, Color.White, rotation, new Vector2(sprite.Width / 2, sprite.Height / 2), scale, SpriteEffects.None, 0f);
            // 45 degrees ((float) Math.PI)

        }

        public void DrawSpriteAtRect(SpriteBatch spriteBatch, Texture2D sprite, Rectangle dest, Rectangle source, float rotation, Vector2 scale)
        {
            // todo does not apply rotation or scale
            //dest = new Rectangle(dest.Location,new Point((int)dest.Size.X * (int)scale.X,(int)dest.Size.Y*(int)scale.Y));
            dest = new Rectangle(dest.Location, new Point(dest.Size.X / (int)(1 / scale.X), dest.Size.Y / (int)(1 / scale.Y)));

            spriteBatch.Draw(sprite, dest, source, Color.White);

        }


        public void DrawSpriteAtRect(SpriteBatch spriteBatch, Texture2D sprite, Rectangle dest, Rectangle source, float rotation, Vector2 scale, SpriteEffects effect)
        {
            // todo does not apply rotation or scale
            //dest = new Rectangle(dest.Location,new Point((int)dest.Size.X * (int)scale.X,(int)dest.Size.Y*(int)scale.Y));
            dest = new Rectangle(dest.Location, new Point(dest.Size.X / (int)(1 / scale.X), dest.Size.Y / (int)(1 / scale.Y)));

            spriteBatch.Draw(sprite, dest, source, Color.White, 0, new Vector2(dest.Location.X + (dest.Size.X / 2), dest.Location.Y + (dest.Size.Y / 2)), effect, 0f);


        }

        public void DrawRectangle(SpriteBatch spriteBatch, Rectangle r, Color color)
        {


            var t = new Texture2D(m_graphicsDevice, 1, 1);
            t.SetData(new[] { Color.White });
            //spriteBatch.Draw(t, rect, Color.Black);
            
            int bw = 2; // Border width

            
            spriteBatch.Draw(t, new Rectangle(r.Left, r.Top, bw, r.Height), color); // Left
            spriteBatch.Draw(t, new Rectangle(r.Right, r.Top, bw, r.Height), color); // Right
            spriteBatch.Draw(t, new Rectangle(r.Left, r.Top, r.Width, bw), color); // Top
            spriteBatch.Draw(t, new Rectangle(r.Left, r.Bottom, r.Width, bw), color); // Bottom

        }

    }
}
