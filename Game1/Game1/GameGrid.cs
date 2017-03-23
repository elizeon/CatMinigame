using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game1
{

    
    class GameGrid
    { 
        vec2[][] centrePoints;
        /// <summary>
        /// Creates a grid
        /// </summary>
        /// <param name="xsize"></param>
        /// <param name="ysize"></param>
        /// <param name="squareLength"></param>
        GameGrid(int xsize, int ysize, float squareLength )
        {
            centrePoints = new vec2[][] { };

            for (int x=0;x<xsize;x++)
            {
                for(int y=0;y<ysize;y++)
                {
                    centrePoints[x][y].y = y * squareLength;
                    centrePoints[x][y].x = x * squareLength;
                }
            }

        }

        /// Returns point in centre of chosen grid square.
        vec2 GetPoint(int x, int y)
        {
            return new vec2(centrePoints[x][y].x, centrePoints[x][y].y);
        }


    }
}
