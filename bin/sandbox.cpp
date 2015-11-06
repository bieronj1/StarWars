#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cmath>
#include <vector>
#include "PlayerShip.hpp"

/*
Astro-Loot Proof of Concept
*/

class Asteroid;
class Item;
class Enemy;

class LocalScan {
	public:
	std::vector<Asteroid> asteroids;
	std::vector<Item> items;
	std::vector<Enemy> enemies;
};



class Item : public sf::Drawable{
	
	 public:
	float lx;
	float ly;
	float vx;
	float vy;
	float r;
	
	Item(float tlx, float tly, float tvx, float tvy, float tr){
		lx=tlx;
		ly=tly;
		vx=tvx;
		vy=tvy;
		r=tr;
	}
	
	//update object location for new frame
	void update(){
		lx+=vx;
		ly+=vy;
	}
	void setRenderOffset(float x, float y){
		offx=x;
		offy=y;
	}
	private:
	float offx=0; float offy=0;
	 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::CircleShape c;
		c.setRadius(r);
		c.setFillColor(sf::Color::Cyan);
		c.setPosition(lx+offx, ly+offy);
        target.draw(c);
    }
	
};

class Enemy : public sf::Drawable{
	
	 public:
	float lx;
	float ly;
	float vx;
	float vy;
	float r;
	
	Enemy(float tlx, float tly, float tvx, float tvy, float tr){
		lx=tlx;
		ly=tly;
		vx=tvx;
		vy=tvy;
		r=tr;
	}
	
	//update object location for new frame
	void update(){
		lx+=vx;
		ly+=vy;
	}
	void setRenderOffset(float x, float y){
		offx=x;
		offy=y;
	}
	private:
	float offx=0; float offy=0;
	 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::CircleShape c;
		c.setRadius(r);
		c.setFillColor(sf::Color::Red);
		//DO NOT TOUCH THIS LINE
		c.setPosition(lx+offx, ly+offy);//DO NOT TOUCH THIS LINE
        target.draw(c);
    }
	
};

//based on http://totologic.blogspot.fr/2014/01/accurate-point-in-triangle-test.html
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
		
		/*

		*/
		
		
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


sf::ConvexShape collisionAsteroidPlayerBox(float pslx, float psly, float pso, float alx, float aly, float ar){
		//Expand the player ship hitbox so that it considers the whole asteroid,
		//not just the center point.
		float tx1, tx2, tx3, ty1, ty2, ty3;
		
		//nose of ship is p1
		tx1 = pslx + (30+ar)*std::cos(pso);
		ty1 = psly + (30+ar)*std::sin(pso);
		//std::cout<<std::sqrt((alx-tx1)*(alx - tx1)+(aly-ty1)*(aly-ty1))<<std::endl; 
		tx2 = pslx + ((-15-ar) * std::cos(pso)) - ((-15-ar) * std::sin(pso));
		ty2 = psly + ((-15-ar) * std::sin(pso)) + ((-15-ar) * std::cos(pso));
		tx3 = pslx + ((-15-ar) * std::cos(pso)) - ((15+ar) * std::sin(pso));
		ty3 = psly + ((-15-ar) * std::sin(pso)) + ((15+ar) * std::cos(pso));
		//return collisionTrianglePoint(alx, aly, tx1, ty1, tx2, ty2, tx3, ty3);
		
		sf::ConvexShape polygon;
		polygon.setPointCount(3);
		polygon.setPoint(0, sf::Vector2f(tx1,ty1));
		polygon.setPoint(1, sf::Vector2f(tx2, ty2));
		polygon.setPoint(2, sf::Vector2f(tx3, ty3));
		polygon.setFillColor(sf::Color::Yellow);
		polygon.setPosition(pslx+1150,psly+1150);
        return polygon;
}


class Asteroid : public sf::Drawable{
  public:
	float lx;
	float ly;
	float vx;
	float vy;
	float r;
	bool collision = false;
	Asteroid(float tlx, float tly, float tvx, float tvy, float tr){
		lx=tlx;
		ly=tly;
		vx=tvx;
		vy=tvy;
		r=tr;
	}
	
	//update object location for new frame
	void update(){
		lx+=vx;
		ly+=vy;
		//collision = false;
	}
	
	void collide(){
		collision = true;
	}
	
	void setRenderOffset(float x, float y){
		offx=x;
		offy=y;
	}
	
	private:
	float offx=0; float offy=0;
	 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::CircleShape c;
		c.setRadius(r);
		c.setFillColor(sf::Color::Blue);
		if(collision){c.setFillColor(sf::Color::Red);}
		c.setPosition(lx+offx-r, ly+offy-r);
        target.draw(c);
		sf::CircleShape ct;
		ct.setRadius(5);
		ct.setFillColor(sf::Color::Yellow);
		//if(collision){c.setFillColor(sf::Color::Red);}
		ct.setPosition(lx+offx-5, ly+offy-5);
        target.draw(ct);		
    }

};


class GridSquare{
	public:
	bool playerIsHere = false;
	//U=up, D=down, L=left, R=right
	GridSquare* U = NULL;
	GridSquare* D = NULL;
	GridSquare* L = NULL;
	GridSquare* R = NULL;
	GridSquare* UL = NULL;
	GridSquare* UR = NULL;
	GridSquare* DL = NULL;
	GridSquare* DR = NULL;
	
	GridSquare(){
		if(std::rand()%4==0){
		Asteroid a(std::rand()%100,std::rand()%100,std::rand()%100/100.0f - 0.5,std::rand()%100/100.0f - 0.5,20);
		asteroids.push_back(a);}
	}
	
	void addAsteroid(float lx, float ly, float vx, float vy, float r){
		Asteroid* a = new Asteroid(lx,ly,vx,vy,r);
		asteroids.push_back(*a);
		//std::cout<<"NEW "<<lx<<","<<ly<<std::endl;
	}
	
	void addItem(Item* i){items.push_back(i);}
	
	void addEnemy(Enemy* e){enemies.push_back(e);}
	
	~GridSquare(){
		return;
	}
	
	void update(){
		for(int i = 0; i<asteroids.size(); i++){
			asteroids[i].update();
		}

		if(playerIsHere){
		//std::cout<<ps->lx<<","<<ps->ly<<std::endl;
			if(ps->lx<0&&ps->ly<0){
				ps->lx+=100;
				ps->ly+=100;
				UL->playerIsHere=true;
				UL->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx<0&&ps->ly>100){
				ps->lx+=100;
				ps->ly-=100;
				UR->playerIsHere=true;
				UR->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx>100&&ps->ly<0){
				ps->lx-=100;
				ps->ly+=100;
				DL->playerIsHere=true;
				DL->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx>100&&ps->ly>100){
				ps->lx-=100;
				ps->ly-=100;
				DR->playerIsHere=true;
				DR->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx<0){
				ps->lx+=100;
				U->playerIsHere=true;
				U->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx>100){
				ps->lx-=100;
				D->playerIsHere=true;
				D->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->ly<0){
				ps->ly+=100;
				L->playerIsHere=true;
				L->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->ly>100){
				ps->ly-=100;
				R->playerIsHere=true;
				R->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		//move asteroids to other gridsquares
		for(int i=0; i<asteroids.size(); i++){
			if(asteroids[i].lx<0&&asteroids[i].ly<0){
				asteroids[i].lx+=100;
				asteroids[i].ly+=100;
				if(UL!=NULL){UL->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].lx<0&&asteroids[i].ly>100){
				asteroids[i].lx+=100;
				asteroids[i].ly-=100;
				if(UR!=NULL){UR->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].lx>100&&asteroids[i].ly<0){
				asteroids[i].lx-=100;
				asteroids[i].ly+=100;
				if(DL!=NULL){DL->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].lx>100&&asteroids[i].ly>100){
				asteroids[i].lx-=100;
				asteroids[i].ly-=100;
				if(DR!=NULL){DR->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].lx<0){
				asteroids[i].lx+=100;
				if(U!=NULL){U->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].lx>100){
				asteroids[i].lx-=100;
				if(D!=NULL){D->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].ly<0){
				asteroids[i].ly+=100;
				if(L!=NULL){L->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
			if(asteroids[i].ly>100){
				asteroids[i].ly-=100;
				if(R!=NULL){R->addAsteroid(asteroids[i].lx, asteroids[i].ly, asteroids[i].vx, asteroids[i].vy, asteroids[i].r);}
				asteroids.erase(asteroids.begin()+i);
				i--;
				continue;
			}
		}
		

	for(int i=0; i<items.size(); i++){
			if(items[i]->lx<0&&items[i]->ly<0){
				items[i]->lx+=100;
				items[i]->ly+=100;
				if(UL!=NULL){UL->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->lx<0&&items[i]->ly>100){
				items[i]->lx+=100;
				items[i]->ly-=100;
				if(UR!=NULL){UR->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->lx>100&&items[i]->ly<0){
				items[i]->lx-=100;
				items[i]->ly+=100;
				if(DL!=NULL){DL->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->lx>100&&items[i]->ly>100){
				items[i]->lx-=100;
				items[i]->ly-=100;
				if(DR!=NULL){DR->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->lx<0){
				items[i]->lx+=100;
				if(U!=NULL){U->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->lx>100){
				items[i]->lx-=100;
				if(D!=NULL){D->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->ly<0){
				items[i]->ly+=100;
				if(L!=NULL){L->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
			if(items[i]->ly>100){
				items[i]->ly-=100;
				if(R!=NULL){R->addItem(items[i]);}
				items.erase(items.begin()+i);
				i--;
				continue;
			}
		}
		
		for(int i=0; i<enemies.size(); i++){
			if(enemies[i]->lx<0&&enemies[i]->ly<0){
				enemies[i]->lx+=100;
				enemies[i]->ly+=100;
				if(UL!=NULL){UL->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->lx<0&&enemies[i]->ly>100){
				enemies[i]->lx+=100;
				enemies[i]->ly-=100;
				if(UR!=NULL){UR->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->lx>100&&enemies[i]->ly<0){
				enemies[i]->lx-=100;
				enemies[i]->ly+=100;
				if(DL!=NULL){DL->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->lx>100&&enemies[i]->ly>100){
				enemies[i]->lx-=100;
				enemies[i]->ly-=100;
				if(DR!=NULL){DR->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->lx<0){
				enemies[i]->lx+=100;
				if(U!=NULL){U->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->lx>100){
				enemies[i]->lx-=100;
				if(D!=NULL){D->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->ly<0){
				enemies[i]->ly+=100;
				if(L!=NULL){L->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
			if(enemies[i]->ly>100){
				enemies[i]->ly-=100;
				if(R!=NULL){R->addEnemy(enemies[i]);}
				enemies.erase(enemies.begin()+i);
				i--;
				continue;
			}
		}

		
	//collision detection
	//player - asteroid
	if(playerIsHere){
		//local asteroids
		for(int i=0; i<asteroids.size(); i++){
			float ar = asteroids[i].r;
			float ax = asteroids[i].lx;
			float ay = asteroids[i].ly;
			if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax, ay, ar)){
				asteroids[i].collide();
			}
		}
		

		if(UL!=NULL){
			for(int i=0; i<UL->asteroids.size(); i++){
				float ar = UL->asteroids[i].r;
				float ax = UL->asteroids[i].lx;
		float ay = UL->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax-100, ay-100, ar)){
					UL->asteroids[i].collide();
				}
			}
		}
		
		if(U!=NULL){
			for(int i=0; i<U->asteroids.size(); i++){
				float ar = U->asteroids[i].r;
				float ax = U->asteroids[i].lx;
				float ay = U->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax-100, ay, ar)){
					U->asteroids[i].collide();
				}
			}
		}
		
		if(UR!=NULL){
			for(int i=0; i<UR->asteroids.size(); i++){
				float ar = UR->asteroids[i].r;
				float ax = UR->asteroids[i].lx;
				float ay = UR->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax-100, ay+100, ar)){
					UR->asteroids[i].collide();
				}
			}
		}
		
		if(L!=NULL){
			for(int i=0; i<L->asteroids.size(); i++){
				float ar = L->asteroids[i].r;
				float ax = L->asteroids[i].lx;
				float ay = L->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax, ay-100, ar)){
					L->asteroids[i].collide();
				}
			}
		}
		if(R!=NULL){
			for(int i=0; i<R->asteroids.size(); i++){
				float ar = R->asteroids[i].r;
				float ax = R->asteroids[i].lx;
				float ay = R->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax, ay+100, ar)){
					R->asteroids[i].collide();
				}
			}
		}
		
		if(DL!=NULL){
			for(int i=0; i<DL->asteroids.size(); i++){
				float ar = DL->asteroids[i].r;
				float ax = DL->asteroids[i].lx;
				float ay = DL->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax+100, ay-100, ar)){
					DL->asteroids[i].collide();
				}
			}
		}
		
		if(D!=NULL){
			for(int i=0; i<D->asteroids.size(); i++){
				float ar = D->asteroids[i].r;
				float ax = D->asteroids[i].lx;
				float ay = D->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax+100, ay, ar)){
					D->asteroids[i].collide();
				}
			}
		}
		
		if(DR!=NULL){
			for(int i=0; i<DR->asteroids.size(); i++){
				float ar = DR->asteroids[i].r;
				float ax = DR->asteroids[i].lx;
				float ay = DR->asteroids[i].ly;
				if(collisionAsteroidPlayer(ps->lx, ps->ly, ps->orientation, ax+100, ay+100, ar)){
					DR->asteroids[i].collide();
				}
			}
		}
		
	}
	
	
	}
	

	PlayerShip* ps = NULL; //only needs to be valid if playerIsHere==true
	
	std::vector<Asteroid> asteroids;//POTENTIAL MEMORY LEAK
	std::vector<Item*> items;
	std::vector<Enemy*> enemies;
	
	void drawOnWindow(sf::RenderWindow* win, float x, float y){
		for(int i = 0; i<asteroids.size(); i++){
			asteroids[i].setRenderOffset(x,y);
			win->draw(asteroids[i]);
		}
		for(int i = 0; i<items.size(); i++){
			items[i]->setRenderOffset(x,y);
			win->draw(*items[i]);
		}
		for(int i = 0; i<enemies.size(); i++){
			enemies[i]->setRenderOffset(x,y);
			win->draw(*enemies[i]);
		}
		if(playerIsHere){
			ps->setRenderOffset(x,y);
			win->draw(*ps);
			//win->draw(collisionAsteroidPlayerBox(ps->lx, ps->ly, ps->orientation, 0, 0, 20));
		}
	}
};

class GameWorld {
	
	public:
	GridSquare* board[25][25]; //list of pointers -> easy to shift
	// IT IS STORED [ROW][COL] AND DON'T FORGET!!!!

	int xshifts = 0;
	int yshifts = 0;
	
	GameWorld(PlayerShip * ps){
		for(int i=0; i<25; i++){
			for(int j=0; j<25; j++){
				board[i][j] = new GridSquare();
			}
		}
		board[12][12]->playerIsHere=true;
		board[12][12]->ps=ps;

		for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
				if(i>0&&j>0){
				board[i][j]->UL=board[i-1][j-1];}
				if(i>0){
				board[i][j]->U=board[i-1][j];}
				if(i>0&&j<24){
				board[i][j]->UR=board[i-1][j+1];}
				if(j>0){
				board[i][j]->L=board[i][j-1];}
				if(j<24){
				board[i][j]->R=board[i][j+1];}
				if(i<24&&j>0){
				board[i][j]->DL=board[i+1][j-1];}
				if(i<24){
				board[i][j]->D=board[i+1][j];}
				if(i<24&&j<24){
				board[i][j]->DR=board[i+1][j+1];}
			}
		}
		
	}
	
	//This method draws everything on the board into the 2500X2500 RenderWindow
	void drawOnWindow(sf::RenderWindow* win){
		for(int i=0; i<25; i++){
			for(int j=0; j<25; j++){
				board[i][j]->drawOnWindow(win,i*100.0f,j*100.0f);
			}
		}
		board[12][12]->drawOnWindow(win,1200,1200);//draw the player on top	
		
	}
	
	//if anyone wants this code changed, ask Jamie to do it!
	
	void update(){
		for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
				board[i][j]->update();
			}
		}
		
		
		
		if(board[12][12]->playerIsHere==false){
			//std::cout<<"ENTER LOOPS"<<std::endl;
			int pi=-1;
			int pj=-1;
			for(int i=0;i<25;i++){
				for(int j=0;j<25;j++){
					if(board[i][j]->playerIsHere){
						pi=i;
						pj=j;
					}
				}
			}
			if(pi==-1 || pj==-1)
				{std::cout<<"PLAYER SHIP LOST"<<std::endl; exit(1);}
			//std::cout<<pi<<","<<pj<<std::endl;
			while(pj<12){shiftRight();pj++;std::cout<<"RIGHT!"<<std::endl;}
			while(pj>12){shiftLeft();pj--;std::cout<<"LEFT!"<<std::endl;}
			while(pi<12){shiftDown();pi++;std::cout<<"DOWN!"<<std::endl;}
			while(pi>12){shiftUp();pi--;std::cout<<"UP!"<<std::endl;}
			//std::cout<<pi<<","<<pj<<std::endl;
		}
	}
	//never call this method (unless you are debugging and everything is on fire)
	void shiftUpPublic(){return;}
	
	void checkLinks(){
		for(int i=1; i<24; i++){
			for(int j=1; j<24; j++){
				if(board[i][j]->UL != board[i-1][j-1]){std::cout<<"broken UL"<<std::endl;}
				if(board[i][j]->U != board[i-1][j]){std::cout<<"broken U"<<std::endl;}
				if(board[i][j]->UR != board[i-1][j+1]){std::cout<<"broken UR"<<std::endl;}
				if(board[i][j]->L != board[i][j-1]){std::cout<<"broken L"<<std::endl;}
				if(board[i][j]->R != board[i][j+1]){std::cout<<"broken R"<<std::endl;}
				if(board[i][j]->DL != board[i+1][j-1]){std::cout<<"broken DL"<<std::endl;}
				if(board[i][j]->D != board[i+1][j]){std::cout<<"broken DL"<<std::endl;}
				if(board[i][j]->DR != board[i+1][j+1]){std::cout<<"broken DL"<<std::endl;}
				
			}
		}
		
	}
	
	private:
	void shiftLeft(){
		xshifts--;
		//destroy far left
		for(int row=0;row<25;row++){
			delete board[row][0];
			board[row][1]->L=NULL;
			board[row][1]->UL=NULL;
			board[row][1]->DL=NULL;
		}
		//shift middle
		for(int col=1; col<25; col++){
			for(int row = 0; row<25; row++){
				board[row][col-1]=board[row][col];
			}
		}
		//build far right
		for(int row=0; row<25; row++){
			board[row][24] = new GridSquare();
		}
		//establish links (Right)
		board[0][23]->R=board[0][24];
		board[0][23]->DR=board[1][24];
		for(int row=1; row<24; row++){
			board[row][23]->UR=board[row-1][24];
			board[row][23]->R=board[row][24];
			board[row][23]->DR=board[row+1][24];
		}
		board[24][23]->UR=board[23][24];
		board[24][23]->R=board[24][24];
		//establish links (Left)
		board[0][24]->L=board[0][23];
		board[0][24]->DL=board[1][23];
		for(int row=1; row<24; row++){
			board[row][24]->UL=board[row-1][23];
			board[row][24]->L=board[row][23];
			board[row][24]->DL=board[row+1][23];
		}
		board[24][24]->UL=board[23][23];
		board[24][24]->L=board[24][23];
		//establish links (vertical)
		for(int row=0; row<24; row++){
			board[row][24]->D=board[row+1][24];
			board[row+1][24]->U=board[row][24];
		}
		
	}
	
	void shiftRight(){
		xshifts++;
		//destroy far left
		for(int row=0;row<25;row++){
			delete board[row][24];
			board[row][23]->R=NULL;
			board[row][23]->UR=NULL;
			board[row][23]->DR=NULL;
		}
		//shift middle
		for(int col=23; col>=0; col--){
			for(int row = 0; row<25; row++){
				board[row][col+1]=board[row][col];
			}
		}
		//build far left
		for(int row=0; row<25; row++){
			board[row][0]= new GridSquare();
		}
		//establish links (Right)
		board[0][0]->R=board[0][1];
		board[0][0]->DR=board[1][1];
		for(int row=1; row<24; row++){
			board[row][0]->UR=board[row-1][1];
			board[row][0]->R=board[row][1];
			board[row][0]->DR=board[row+1][1];
		}
		board[24][0]->UR=board[23][1];
		board[24][0]->R=board[24][1];
		//establish links (Left)
		board[0][1]->L=board[0][0];
		board[0][1]->DL=board[1][0];
		for(int row=1; row<24; row++){
			board[row][1]->UL=board[row-1][0];
			board[row][1]->L=board[row][0];
			board[row][1]->DL=board[row+1][0];
		}
		board[24][1]->UL=board[23][0];
		board[24][1]->L=board[24][0];
		//establish links (vertical)
		for(int row=0; row<24; row++){
			board[row][0]->D=board[row+1][0];
			board[row+1][0]->U=board[row][0];
		}
		
	}
	
	void shiftUp(){
		yshifts--;
		//destroy far top
		for(int col=0;col<25;col++){
			delete board[0][col];
			board[1][col]->U=NULL;
			board[1][col]->UL=NULL;
			board[1][col]->UR=NULL;
		}
		//shift middle
		for(int row=1; row<25; row++){
			for(int col = 0; col<25; col++){
				board[row-1][col]=board[row][col];
			}
		}
		//build far bottom
		for(int col=0; col<25; col++){
			board[24][col]= new GridSquare();
		}
		//establish links (Down)
		board[23][0]->D=board[24][0];
		board[23][0]->DR=board[24][1];
		for(int col=1; col<24; col++){
			board[23][col]->DL=board[24][col-1];
			board[23][col]->D=board[24][col];
			board[23][col]->DR=board[24][col+1];
		}
		board[23][24]->DL=board[24][23];
		board[23][24]->D=board[24][24];
		//establish links (Up)
		board[24][0]->U=board[23][0];
		board[24][0]->UR=board[23][1];
		for(int col=1; col<24; col++){
			board[24][col]->UL=board[23][col-1];
			board[24][col]->U=board[23][col];
			board[24][col]->UR=board[23][col+1];
		}
		board[24][24]->UL=board[23][23];
		board[24][24]->U=board[23][24];
		//establish links (horizontal)
		for(int col=0; col<24; col++){
			board[24][col]->R=board[24][col+1];
			board[24][col+1]->L=board[24][col];
		}
		
	}
	
	void shiftDown(){
		yshifts++;
		//destroy far left
		for(int col=0;col<25;col++){
			//delete board[24][col];
			board[23][col]->D=NULL;
			board[23][col]->DL=NULL;
			board[23][col]->DR=NULL;

		}
		//shift middle
		for(int row=23; row>=0; row--){
			for(int col = 0; col<25; col++){
				board[row+1][col]=board[row][col];
			}
		}
		//build far right
		for(int col=0; col<25; col++){
			board[0][col] = new GridSquare();
		}
		//establish links (Down)
		board[0][0]->D=board[1][0];
		board[0][0]->DR=board[1][1];
		for(int col=1; col<24; col++){
			board[0][col]->DL=board[1][col-1];
			board[0][col]->D=board[1][col];
			board[0][col]->DR=board[1][col+1];
		}
		board[0][24]->DL=board[1][23];
		board[0][24]->D=board[1][24];
		//establish links (Up)
		board[1][0]->U=board[0][0];
		board[1][0]->UR=board[0][1];
		for(int col=1; col<24; col++){
			board[1][col]->UL=board[0][col-1];
			board[1][col]->U=board[0][col];
			board[1][col]->UR=board[0][col+1];
		}
		board[1][24]->UL=board[0][23];
		board[1][24]->U=board[0][24];
		//establish links (horizontal)
		for(int col=0; col<24; col++){
			board[0][col]->R=board[0][col+1];
			board[0][col+1]->L=board[0][col];
		}
		
	}
	
	
};

static bool QWEASD[6]; //stores keypressed values


int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Hello World - SFML");
  int FPS=30;
  App.setFramerateLimit(FPS); 

	//taken from SFML official site
  sf::Font font;
	if (!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}


	
	App.clear(sf::Color::Black);
  // start main loop

  //all code above is legacy
	int ActiveAsteroidPtr=0;
	int DeadAsteroidPtr=0;
	Asteroid* Asteroids[512];
  
  
  PlayerShip pc(50,50,0.1,0.1,0.05);
  
  GameWorld world(&pc);
  
  while(App.isOpen())
  {
	  
	
	App.clear(sf::Color::Black); //prepare to draw on a clean slate
	  
	 
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }
	
	
	
	//process user input (move to method later)
	QWEASD[0]=sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	QWEASD[1]=sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	QWEASD[2]=sf::Keyboard::isKeyPressed(sf::Keyboard::E);
	QWEASD[3]=sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	QWEASD[4]=sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	QWEASD[5]=sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool SHIFT =sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	
	if(QWEASD[1]){pc.faster();}else{pc.stopThruster();}
	if(QWEASD[4]){
		if(SHIFT)
			pc.slower();
		else
			pc.reverse();
	}
	if(QWEASD[3]){pc.turnLeft();}
	if(QWEASD[5]){pc.turnRight();}
	if(QWEASD[0]){pc.latLeft();}else{pc.stopLeft();}
	if(QWEASD[2]){pc.latRight();}else{pc.stopRight();}
	bool zoom = false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		zoom=true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
		world.checkLinks();
		std::cout<<"Check Complete"<<std::endl;
	}
	App.clear(sf::Color::Black);
	pc.update();
	sf::View camera(sf::FloatRect(0,0,800,600));
	sf::View minimap(sf::FloatRect(0,0,800,600));
	world.update();
	camera.move(1250-450+pc.lx,1250-350+pc.ly);
	minimap.move(1250-450+pc.lx,1250-350+pc.ly);
	camera.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	minimap.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	if(zoom){
	camera.zoom(5);}
	minimap.zoom(1.5);
	camera.setViewport(sf::FloatRect(0,0,1,1));
	minimap.setViewport(sf::FloatRect(0.3333f,0.6666f,0.3333,0.3333));
	App.setView(camera);
	world.drawOnWindow(&App);
	
	sf::RectangleShape minimapback(sf::Vector2f(2500,2500));
	minimapback.setFillColor(sf::Color(25,25,25));
	App.setView(minimap);
	App.draw(minimapback);
	world.drawOnWindow(&App);
	
	
	//all code before is legacy
	//draw scores
App.display();

  }
  // Done.
  return 0;

}