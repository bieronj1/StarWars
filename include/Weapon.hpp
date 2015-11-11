#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
#include <sstream>
#include <iomanip>

class Weapon{
  public:
		int type;
		float cd = 0;
		int cdtime;
		int dmg;
		int spd;
		int rad;
		
		
		Weapon(int xtype, int xcd, int xdmg, int xspd, int xrad);
		void updateCD();
		bool fire();
		std::string getData();
		void inputData(std::string s);
		std::string ZeroPadNumber(int num)
		{
    		std::ostringstream ss;
    		ss << std::setw( 3 ) << std::setfill( '0' ) << num;
    		return ss.str();
		}
		

	
	};
