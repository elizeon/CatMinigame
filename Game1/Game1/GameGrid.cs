using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Game1
{

    /// <summary>
    /// The layout of the game world on screen.
    /// </summary>
    class GameGrid
    { 
        vec2[,] centrePoints;
        /// <summary>
        /// Creates a grid
        /// </summary>
        /// <param name="xsize">number of squares along screen x axis</param>
        /// <param name="ysize">number of squares along screen y axis</param>
        /// <param name="squareLength">square length as proportion of screen</param>
        public GameGrid(int xsize, int ysize, float squareLength )
        {
            centrePoints = new vec2[xsize,ysize];

            for (int x=0;x<xsize;x++)
            {
                for(int y=0;y<ysize;y++)
                {
                    centrePoints[x, y] = new vec2(x * squareLength * Game1.screenWidth, y * squareLength * Game1.screenHeight);
                }
            }

        }

        /// <summary>
        /// Returns point in centre of chosen grid square.
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>

        vec2 GetPoint(int x, int y)
        {
            return new vec2(centrePoints[x,y].x, centrePoints[x,y].y);
        }


        /// <summary>
        /// Gets point as proportion of game screen
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public Vector2 GetPoint(float x, float y)
        {
            if (x <= 1 && y <= 1)
            {
                return new Vector2(x * Game1.screenWidth, y * Game1.screenHeight);
            }
            else
            {
                return default(Vector2);
            }
        }


    }
}
