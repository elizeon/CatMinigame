/*
 * Source https://gist.github.com/rkachowski/324608
 * 
 * 
 * http://www.metanetsoftware.com/technique/tutorialA.html
 * If we can find an axis along which the projection of the two shapes does not overlap, then the shapes don't overlap. 
 * In 2D, each of these potential separating axes is perpendicular to one of the faces (edges) of each shape. 

 *  
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    public class OBB
    {

        Vector2 m_origin;
        public Vector2 origin
        {
            get { return m_origin; }
            set { m_origin = value; }
        }
        Vector2[] m_axis;
        /// <summary>
        /// Axis the box is on.
        /// </summary>
        public Vector2[] axis
        {
            get { return m_axis; }
        }
        Vector2 m_halfWidths;
        public Vector2 halfWidths
        {
            get { return m_halfWidths; }
            set { m_halfWidths = value; }
        }
        float m_angle;
        public float angleInRadians
        {
            get { return m_angle; }
            set
            {
                float newAxis = 0;
                // PI is 180 degrees

                // less than 180 but more than -180 degrees?
                if (value < Math.PI && value > -Math.PI)

                {
                    newAxis = value;
                }
                // More than or equal to 180 degrees?
                if (value >= Math.PI)
                {
                    // Get remainder of dividing angle by 180 degrees
                    // Multiply by 2
                    // Get absolute value
                    // Subtract 180 degrees
                    newAxis = (float)(Math.Abs((value % Math.PI * 2)) - Math.PI);
                }
                // Less than or equal to -180 degrees?
                if (value <= -Math.PI)
                {
                    // Get remainder of dividing angle by 180 degrees
                    // Multiply by 2
                    // Get absolute value
                    // Add 180 degrees
                    newAxis = (float)(Math.Abs((value % Math.PI * 2)) + Math.PI);

                }

                m_angle = newAxis;


                m_axis[0].X = (float)Math.Cos(m_angle);
                m_axis[0].Y = (float)Math.Sin(m_angle);
                m_axis[1].Y = (float)Math.Cos(m_angle);
                m_axis[1].X = -(float)Math.Sin(m_angle);

            }
        }

        public OBB(Vector2 iOrigin, float iAngleInRadians, Vector2 iHalfWidths)
        {
            m_origin = iOrigin;
            m_angle = iAngleInRadians;
            m_halfWidths = iHalfWidths;

            m_axis = new Vector2[2];
            m_axis[0] = new Vector2();
            m_axis[1] = new Vector2();



        }

        public bool Intersects(OBB OtherOBB)
        {
            return OBB.Intersects(this, OtherOBB);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        private Rectangle GetDestinationRect()
        {
            int X = (int)(m_origin.X);
            int Y = (int)(m_origin.Y);
            int width = (int)(m_halfWidths.X * 2);
            int height = (int)(m_halfWidths.Y * 2);
            return new Rectangle(X, Y, width, height);
        }


        public void Draw(Texture2D NullTexture, SpriteBatch sb)
        {
            Vector2 norm = halfWidths;
            norm.Normalize();
            sb.Draw(NullTexture, GetDestinationRect(), null, Color.White, m_angle, Vector2.One / 2, SpriteEffects.None, 1f);


        }

        public static bool Intersects(OBB a, OBB b)
        {

            float 
                rf,

                rs;
            float[,] R = new float[2, 2];
            float[,] AbsR = new float[2, 2];


            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    R[i, j] = Vector2.Dot(a.axis[i], b.axis[j]);
                    AbsR[i, j] = Math.Abs(R[i, j]) + 0.00001f;
                }

            }

            Vector2 translation = b.origin - a.origin;

            //bring translation into First's local coordinate system
            translation = new Vector2(Vector2.Dot(translation, a.axis[0]), Vector2.Dot(translation, a.axis[1]));

            //Test if axes FirstX or FirstY separate the OBBs

            rf = a.halfWidths.X;
            rs = b.halfWidths.X * AbsR[0, 0] + b.halfWidths.Y * AbsR[0, 1];

            if (Math.Abs(translation.X) > (rf + rs))
            {
                return false;

            }


            rf = a.halfWidths.X;
            rs = b.halfWidths.Y * AbsR[0, 0] + b.halfWidths.Y * AbsR[1, 1];

            if (Math.Abs(translation.Y) > (rf + rs))
                return false;

            //Test if axes SecondX or SecondY separate the OBBs

            rf = a.halfWidths.X * AbsR[0, 0] + a.m_halfWidths.Y * AbsR[1, 0];
            rs = b.halfWidths.X;

            if (Math.Abs(translation.X * R[0, 0] + translation.Y * R[1, 0]) > (rf + rs))
                return false;


            rf = a.halfWidths.X * AbsR[0, 1] + a.m_halfWidths.Y * AbsR[1, 1];
            rs = b.halfWidths.Y;

            if (Math.Abs(translation.Y * R[0, 1] + translation.Y * R[1, 1]) > (rf + rs))
                return false;

            //no separating axis - OBBs must therefore be intersecting
            return true;
        }
    }
}