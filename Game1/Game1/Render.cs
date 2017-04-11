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
            m_basicEffect = new BasicEffect(m_graphicsDevice);
            m_basicEffect.World = Matrix.Identity;
            m_basicEffect.View = Game1.viewMatrix;
            m_basicEffect.Projection = Matrix.Identity;
        }

        public void DrawSpriteAtLocation(SpriteBatch spriteBatch, Texture2D sprite, Vector2 loc, float rotation, Vector2 scale)
        {
            foreach (EffectPass pass in m_basicEffect.CurrentTechnique.Passes)
            {
                pass.Apply();

                spriteBatch.Draw(sprite, loc, null, Color.White, rotation, new Vector2(sprite.Width * scale.X / 2, sprite.Height * scale.Y / 2), scale, SpriteEffects.None, 0f);
                // 45 degrees ((float) Math.PI)
            }
        }

        BasicEffect m_basicEffect;

        public void DrawSpriteAtRect(SpriteBatch spriteBatch, Texture2D sprite, Rectangle dest, Rectangle source, float rotation, Vector2 scale, SpriteEffects effect, Vector2 location)
        {

            dest.X += (int)(dest.Width * scale.X /2);
            dest.Y += (int)(dest.Height * scale.Y/2 );

            Vector2 origin = new Vector2(dest.Width/2, dest.Height/2);

            foreach (EffectPass pass in m_basicEffect.CurrentTechnique.Passes)
            {
                pass.Apply();
                
                spriteBatch.Draw(sprite, dest, source, Color.White, rotation, origin, effect, 0);
                
            }
        }

        /// <summary>
        /// Draws sphere radius from centre as a line, for debugging.
        /// </summary>
        /// <param name="spriteBatch"></param>
        /// <param name="pos"></param>
        /// <param name="radius"></param>

        public void DebugSphere(SpriteBatch spriteBatch, Vector2 pos, int radius)
        {
            var t = new Texture2D(m_graphicsDevice, 1, 1);
            t.SetData(new[] { Color.White });
            spriteBatch.Draw(t, new Rectangle(new Point((int)pos.X - radius+1, (int)pos.Y+1), new Point(radius,5)),Color.White);

        }
        

        public void DrawRectangle(SpriteBatch spriteBatch, Rectangle r, Color color)
        {

            //Console.WriteLine("Rectangle drawn at " + r.Location.X, ", " + r.Location.Y);
            var t = new Texture2D(m_graphicsDevice, 1, 1);
            t.SetData(new[] { Color.White });
            //spriteBatch.Draw(t, rect, Color.Black);
            int bw = 2; // Border width


            foreach (EffectPass pass in m_basicEffect.CurrentTechnique.Passes)
            {


                pass.Apply();

                spriteBatch.Draw(t, new Rectangle(r.Left, r.Top, bw, r.Height), color); // Left
                spriteBatch.Draw(t, new Rectangle(r.Right, r.Top, bw, r.Height), color); // Right
                spriteBatch.Draw(t, new Rectangle(r.Left, r.Top, r.Width, bw), color); // Top
                spriteBatch.Draw(t, new Rectangle(r.Left, r.Bottom, r.Width, bw), color); // Bottom
            }
        }

    }
}
