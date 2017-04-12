using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    public class Scene
    {
        List<GameObject2D> m_objects = new List<GameObject2D>();
        //GameObject2D[] m_objects;

        float m_initTime = 0;

        public float initTime { get { return m_initTime; } }// set { m_initTime = value; } }

        public Scene()
        {
            m_initTime = Game1.totalTime;

        }

        public void ClearCollisionEvents()
        {
            for (int i=0;i<m_objects.Count;i++)
            {
                m_objects[i].ClearCollisionEvents();
            }
        }

        public void Render(SpriteBatch sprBatch)
        {
            //Game1.levelStart = false;

            for (int i=0;i<m_objects.Count;i++)
            {
                if(m_objects[i].visible)
                {
                    m_objects[i].Render(sprBatch);
                }
                
            }

            if (m_initTime == 0)
            {
                m_initTime = Game1.totalTime;
            }
        }

        public void Update(GameTime gameTime)
        {
            for (int i = 0; i < m_objects.Count; i++)
            {
                
                // Identify Collisions
                if (m_objects[i].collisions)
                {
                    for (int a = 0; a < m_objects.Count; a++)
                    {
                        if (a != i)
                        {
                            if (_2DUtil.CheckCollision(m_objects[i].boundingBox, m_objects[a].boundingBox))
                            {
                                //_2DUtil.ResolveCollision(m_objects[i], m_objects[a]);

                                if(!m_objects[i].collisionEvents.Contains(m_objects[a]))
                                {
                                    m_objects[i].AddCollisionEvent(m_objects[a]);

                                }
                                if (!m_objects[a].collisionEvents.Contains(m_objects[i]))
                                {
                                    m_objects[a].AddCollisionEvent(m_objects[i]);

                                }
                                //m_objects[i].pos2D = new Vector2(m_objects[i].lastPosNoCol.X, m_objects[i].lastPosNoCol.Y);



                            }
                            else
                            {
                                //m_objects[i].lastPosNoCol = new Vector2(m_objects[i].pos2D.X, m_objects[i].pos2D.Y);
                                //m_objects[a].lastPosNoCol = new Vector2(m_objects[a].pos2D.X, m_objects[a].pos2D.Y);
                            }


                        }
                    }
                }
                // Update objects
                if (m_objects[i].active)
                {
                    m_objects[i].Update(gameTime);
                }


                m_objects[i].ClearCollisionEvents();
                /*
            else
            {
                for (int a = 0; a < m_objects.Count; a++)
                {
                    if (a != i)
                    {
                        if (_2DUtil.CheckCollision(m_objects[i], m_objects[a]))
                        {
                            m_objects[i].AddCollisionEvent(m_objects[a]);
                            m_objects[a].AddCollisionEvent(m_objects[i]);
                            //m_objects[i].pos2D = new Vector2(m_objects[i].lastPosNoCol.X, m_objects[i].lastPosNoCol.Y);

                        }


                    }
                }
            }
            */



            }


            Game1.levelStart = false;

            

        }
        public void AddObject(GameObject2D obj)
        {
            m_objects.Add(obj);
        }
    }
}
