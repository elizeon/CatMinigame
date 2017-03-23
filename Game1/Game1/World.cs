using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game1
{
    class World
    {
        private static Player m_player;
        public static Player player
        {
            get { return m_player; }
            set { m_player = value; }
        }
    }
}
