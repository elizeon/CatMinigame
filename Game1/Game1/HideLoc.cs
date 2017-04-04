using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game1
{
    class HideLoc : GameObject2D
    {
        public HideLoc(string newid, string newtype, float newhp) : base(newid, newtype,newhp)
        {

        }

        public HideLoc(HideLoc otherloc) : this(otherloc.id,otherloc.type,otherloc.hp)
        {
            this.scale = otherloc.scale;
            this.animSprite = new AnimatedSprite(otherloc.animSprite);
        }

        public HideLoc(string newid, HideLoc otherloc) : this(otherloc.id, otherloc.type, otherloc.hp)
        {
            this.id = newid;
            this.scale = otherloc.scale;
            this.animSprite = new AnimatedSprite(otherloc.animSprite);
        }
    }
}
