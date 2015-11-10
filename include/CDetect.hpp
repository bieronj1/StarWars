/*
This file holds collision detection methods.  It should have no dependencies.
*/

bool collisionTrianglePoint(float px, float py, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3){
		double d = ((ty2-ty3)*(tx1-tx3)+(tx3-tx2)*(ty1-ty3));
		double a = ((ty2-ty3)*(px-tx3)+(tx3-tx2)*(py-ty3))/d;
		double b = ((ty3-ty1)*(px-tx3)+(tx1-tx3)*(py-ty3))/d;
		double c = 1-a-b;
		//std::cout<<"("<<a<<","<<b<<","<<c<<")"<<std::endl;
		return (0<=a&&a<=1&&0<=b&&b<=1&&0<=c&&c<=1);
		
}

bool collisionAsteroidPlayer(float pslx, float psly, float pso, float alx, float aly, float ar){
		//Expand the player ship hitbox so that it considers the whole asteroid,
		//not just the center point.
		
		
		float tx1, tx2, tx3, ty1, ty2, ty3, 
		tx1l, ty1l, tx1r, ty1r,
		tx2u, ty2u, tx3u, ty3u,
		tx2d, ty2d, tx3d, ty3d;
		
		//nose of ship is p1
		tx1 = pslx + (30)*std::cos(pso);
		ty1 = psly + (30)*std::sin(pso);
		tx1l = pslx + (30)*std::cos(pso) - (-ar) * std::sin(pso);
		ty1l = psly + (30)*std::sin(pso) + (-ar) * std::cos(pso);
		
		tx1r = pslx + (30)*std::cos(pso) - (ar) * std::sin(pso);
		ty1r = psly + (30)*std::sin(pso) + (ar) * std::cos(pso);
		
 
		tx2 = pslx + ((-15) * std::cos(pso)) - ((-15) * std::sin(pso));
		ty2 = psly + ((-15) * std::sin(pso)) + ((-15) * std::cos(pso));
		tx3 = pslx + ((-15) * std::cos(pso)) - ((15) * std::sin(pso));
		ty3 = psly + ((-15) * std::sin(pso)) + ((15) * std::cos(pso));
		
		tx2u = pslx + ((-15) * std::cos(pso)) - ((-15-ar) * std::sin(pso));
		ty2u = psly + ((-15) * std::sin(pso)) + ((-15-ar) * std::cos(pso));
		tx3u = pslx + ((-15) * std::cos(pso)) - ((15+ar) * std::sin(pso));
		ty3u = psly + ((-15) * std::sin(pso)) + ((15+ar) * std::cos(pso));
		
		tx2d = pslx + ((-15-ar) * std::cos(pso)) - ((-15) * std::sin(pso));
		ty2d = psly + ((-15-ar) * std::sin(pso)) + ((-15) * std::cos(pso));
		tx3d = pslx + ((-15-ar) * std::cos(pso)) - ((15) * std::sin(pso));
		ty3d = psly + ((-15-ar) * std::sin(pso)) + ((15) * std::cos(pso));
		
		
		//if(collisionTrianglePoint(alx, aly, tx1l, ty1l, tx2u, ty2u, tx3, ty3))std::cout<<"A"<<std::endl;;
		//if(collisionTrianglePoint(alx, aly, tx1r, ty1r, tx2, ty2, tx3u, ty3u))std::cout<<"B"<<std::endl;;
		//if(collisionTrianglePoint(alx, aly, tx1, ty1, tx2d, ty2d, tx3d, ty3d))std::cout<<"C"<<std::endl;;
		//if((tx1-alx)*(tx1-alx)+(ty1-aly)*(ty1-aly)<ar*ar)std::cout<<"D"<<std::endl;;
		//if((tx2-alx)*(tx2-alx)+(ty2-aly)*(ty2-aly)<ar*ar)std::cout<<"E"<<std::endl;;
		//if((tx3-alx)*(tx3-alx)+(ty3-aly)*(ty3-aly)<ar*ar)std::cout<<"F"<<std::endl;;
		
		
		
		
		bool collide = false;
		collide = collisionTrianglePoint(alx, aly, tx1l, ty1l, tx2u, ty2u, tx3, ty3) ||
		collisionTrianglePoint(alx, aly, tx1r, ty1r, tx2, ty2, tx3u, ty3u) ||
		collisionTrianglePoint(alx, aly, tx1, ty1, tx2d, ty2d, tx3d, ty3d) || 
		(tx1-alx)*(tx1-alx)+(ty1-aly)*(ty1-aly)<ar*ar ||
		(tx2-alx)*(tx2-alx)+(ty2-aly)*(ty2-aly)<ar*ar ||
		(tx3-alx)*(tx3-alx)+(ty3-aly)*(ty3-aly)<ar*ar;
		return collide;
	}