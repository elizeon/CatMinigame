using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework.Input;

namespace Game1
{
    static class Input
    {
        // Controls
        public static class Controls
        {
            public static Keys goUp = Keys.W;
            public static Keys goDown = Keys.S;
            public static Keys goLeft = Keys.A;
            public static Keys goRight = Keys.D;
        } 
        



        static KeyboardState m_state;
        /// <summary>
        /// The keyboard state.
        /// </summary>
        static public KeyboardState keyState
        {
            get { return m_state;  }
        }
        
        static public void Update()
        {
            m_state = Keyboard.GetState();
        }
    }
}
