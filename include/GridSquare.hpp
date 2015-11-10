/*
ANY CHANGES TO THIS FILE AFTER 11/9 SHOULD BE LOGGED HERE.  NO CHANGES WITHOUT CONSULTING JAMIE
*/
#include "PlayerShip.hpp"
#include "Weapon.hpp"
#include "CDetect.hpp"
#include "Item.hpp"
#include "Enemy.hpp"
#include "Asteroid.hpp"

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
		if(std::rand()%8==0){
		Asteroid a(std::rand()%100,std::rand()%100,std::rand()%100/100.0f - 0.5,std::rand()%100/100.0f - 0.5,40);
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
		for(int i = 0; i<items.size(); i++){
			items[i]->update();
		}
		for(int i = 0; i<enemies.size(); i++){
			enemies[i]->update();
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