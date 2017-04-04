using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    public class AnimatedSprite
    {
        public Texture2D texture { get; set; }
        public int rows { get; set; }
        public int columns { get; set; }
        public int startIndex { get; set; }
        public int endIndex { get; set; }
        private bool flipHorizontal;
        private bool flipVertical;

        public float width
        {
            get
            {
                int mwidth = texture.Width / columns;
                return mwidth;
            }
        }

        public float height
        {
            get
            {
                int mheight = texture.Height / rows;
                return mheight;
            }
        }


        int currentFrame;
        int totalFrames;
        public float playSpeed { get; set;}
        float totalTime = 0;
        bool playingTempAnim = false;
        
        public void PlayOnce()
        {
            playingTempAnim = true;
            playing = true;
        }

        public void Play()
        {
            playing = true;
        }

        public AnimatedSprite(AnimatedSprite animToCopy) : this(animToCopy.texture,animToCopy.rows,animToCopy.columns,animToCopy.startIndex,animToCopy.endIndex)
        {
            this.flipHorizontal = animToCopy.flipHorizontal;
            this.flipVertical = animToCopy.flipVertical;
        }

        /// <summary>
        /// If true, all sprites in the animation will render flipped horizontally
        /// </summary>
        public void FlipHorizontal(bool flip)
        {
            flipHorizontal = flip;
        }
        /// <summary>
        /// If true, all sprites in the animation will render flipped vertically
        /// </summary>
        public void FlipVertical(bool flip)
        {
            flipVertical = flip;
        }

        /// <summary>
        /// The animation will use sprites in the image starting from startIndex and ending at endIndex.
        /// Each square formed by the grid of rows and columns is considered a sprite.
        /// Rows and columns must be the total in the entire image passed in, to split the image correctly.
        /// </summary>
        /// <param name="image">Full sprite sheet that contains the animation.</param>
        /// <param name="imagerows">Number of rows in the sprite sheet image</param>
        /// <param name="imagecolumns">Number of columns in the sprite sheet image</param>
        /// <param name="nStartIndex">Index of the first sprite of the animation in the given sprite sheet.</param>
        /// <param name="nEndIndex">Index of the last sprite of the animation in the given sprite sheet.</param>
        public AnimatedSprite(Texture2D image, int imagerows, int imagecolumns, int nStartIndex, int nEndIndex) : this(image,imagerows,imagecolumns)
        {
            startIndex = nStartIndex;
            if(endIndex > totalFrames)
            {
                endIndex = totalFrames;
            }
            else
            {
                endIndex = nEndIndex;
            }
            
            
            
        }

        /// <summary>
        /// Basic constructor, bare minimum for an animated sprite. The animation will use all sprites in the image.
        /// Each square formed by the grid of rows and columns is considered a sprite.
        /// </summary>
        /// <param name="image">Full sprite sheet containing the animation.</param>
        /// <param name="imagerows">Number of rows in the sprite sheet image</param>
        /// <param name="imagecolumns">Number of columns in the sprite sheet image</param>
        public AnimatedSprite(Texture2D image, int imagerows, int imagecolumns)
        {
            playing = true;
            flipHorizontal = false;
            flipVertical = false;

            playSpeed = 1;
            texture = image;
            rows = imagerows;
            columns = imagecolumns;
            startIndex = 0;
            currentFrame = startIndex;//(int)startLoc.X+(int)startLoc.Y*ncolumns;
            
            totalFrames = rows * columns;
            endIndex = totalFrames;


        }

        /// <summary>
        /// Basic constructorfor a static sprite.
        /// </summary>
        /// <param name="image">Image for the sprite.</param>
        public AnimatedSprite(Texture2D image)
        {
            playing = true;
            flipHorizontal = false;
            flipVertical = false;

            playSpeed = 1;
            texture = image;
            rows = 1;
            columns = 1;
            startIndex = 0;
            currentFrame = startIndex;//(int)startLoc.X+(int)startLoc.Y*ncolumns;

            totalFrames = rows * columns;
            endIndex = totalFrames;
        }

        public bool playing { get; set; }

        public void Update(GameTime gameTime)
        {
            totalTime += (float)gameTime.ElapsedGameTime.TotalMilliseconds /100;
            if (totalTime > (1 / playSpeed))// && playing)
            {
                currentFrame++;
                totalTime = 0;
                if (currentFrame == endIndex)
                {
                    /*if(!playingTempAnim)
                    {*/
                    currentFrame = startIndex;
                    /*
                        }
                    else
                        {
                            playing = false;
                            playingTempAnim = false;
                        }
                        */

                    
                }

            }
        }
        public void Draw(SpriteBatch spriteBatch, Vector2 location, float rotation, Vector2 scale)
        {
            if(texture != null)
            {
                int width = texture.Width / columns;
                int height = texture.Height / rows;
                int row = (int)((float)currentFrame / (float)columns);
                int column = currentFrame % columns;

                Rectangle sourceRectangle = new Rectangle(width * column, height * row, width, height);

                Rectangle destinationRectangle = new Rectangle((int)location.X, (int)location.Y, width, height);

                SpriteEffects myEffect = SpriteEffects.None;
                if (flipHorizontal)
                {
                    myEffect = SpriteEffects.FlipHorizontally;
                    if (flipVertical)
                    {
                        myEffect = myEffect | SpriteEffects.FlipVertically;
                    }

                }
                else
                {
                    if (flipVertical)
                    {
                        myEffect = SpriteEffects.FlipVertically;
                    }
                }
                


                Render2D.Instance.DrawSpriteAtRect(spriteBatch, texture, destinationRectangle, sourceRectangle, rotation, scale, myEffect);
                
            }
            
        }
        
    }

    
}
