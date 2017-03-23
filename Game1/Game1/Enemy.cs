using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;

namespace Game1
{
    class Enemy : GameObject2D
    {

        public Enemy(string newid, string newtype, float newhp) : base(newid, newtype,newhp)
        {

        }

        public override void Update(GameTime gameTime)
        {
            Vector2 source = this.pos2D;
            Vector2 dest =World.player.pos2D;
            
            rotation = _2DUtil.LookAt(source, dest);
        }
    }

}
