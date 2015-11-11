#include "Weapon.hpp"

Weapon::Weapon(int xtype, int xcdtime, int xdmg, int xspd, int xrad){
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
			cd += cdtime/10.0f;
			return true;
		}
		return false;
}

std::string Weapon::getData(){
		return (ZeroPadNumber(type) + ZeroPadNumber(cdtime) + ZeroPadNumber(dmg) + ZeroPadNumber(spd) + ZeroPadNumber(rad));
}

void Weapon::inputData(std::string s){
		type = atoi(s.substr(0,3).c_str());
		cdtime = atoi(s.substr(3,6).c_str());
		dmg = atoi(s.substr(6,9).c_str());
		spd = atoi(s.substr(9,12).c_str());
		rad = atoi(s.substr(12,15).c_str());
}

