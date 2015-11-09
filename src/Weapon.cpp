#include "Weapon.hpp"

Weapon::Weapon(int xtype, float xcdtime, float xdmg, float xspd, float xrad){
		type = xtype;
		cdtime = xcdtime;
		dmg = xdmg;
		spd = xspd;
		rad = xrad;
	}
	
void Weapon::updateCD(){
		cd-=.033f;
		if(cd < 0)
			cd = 0;
}

bool Weapon::fire(){
		if(cd == 0)
		{
			cd += cdtime;
			return true;
		}
		return false;
}

