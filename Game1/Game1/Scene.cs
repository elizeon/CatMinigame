using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Game1
{
    class Scene
    {
        List<GameObject2D> m_objects = new List<GameObject2D>();
        //GameObject2D[] m_objects;
        Enemy[] m_enemies; // May find unnecessary - if enemy update deals with everything

        public void Render(SpriteBatch sprBatch)
        {
            for (int i=0;i<m_objects.Count;i++)
            {
                if(m_objects[i].visible)
                {
                    m_objects[i].Render(sprBatch);
                }
                
            }
        }

        public void Update(GameTime gameTime)
        {
            for (int i = 0; i < m_objects.Count; i++)
            {
                // Update objects
                if (m_objects[i].active)
                {
                    m_objects[i].Update(gameTime);
                }
                // Resolve Collisions
                if (m_objects[i].collisions)
                {
                    for (int a = 0; a < m_objects.Count; a++)
                    {
                        if (a != i)
                        {
                            if (_2DUtil.CheckCollision(m_objects[i].boundingBox, m_objects[a].boundingBox))
                            {
                                //_2DUtil.ResolveCollision(m_objects[i], m_objects[a]);
                                m_objects[i].AddCollisionEvent(m_objects[a]);
                                m_objects[a].AddCollisionEvent(m_objects[i]);
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


            

        }
        public void AddObject(GameObject2D obj)
        {
            m_objects.Add(obj);
        }
    }
}
