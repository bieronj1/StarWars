/*
ANY CHANGES TO THIS FILE AFTER 11/9 SHOULD BE LOGGED HERE.  NO CHANGES WITHOUT CONSULTING JAMIE
*/
#include "PlayerShip.hpp"
#include "Weapon.hpp"
#include "CDetect.hpp"
#include "Item.hpp"
#include "Enemy.hpp"
#include "Asteroid.hpp"

float inline dotProduct(float x1, float x2, float y1, float y2){
	return x1*y1 + x2*y2;
}

inline float distance(float x1, float y1, float x2, float y2){
	return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


inline void asteroidBounce(Asteroid* a, Asteroid* b, float ax, float ay, float bx, float by){
	
	float am = a->r * a->r * M_PI;
	float bm = b->r * b->r * M_PI;
	float avx = a->vx;
	float avy = a->vy;
	float bvx = b->vx;
	float bvy = b->vy;
	a->vx = avx - (2*bm/(am+bm))*dotProduct(avx-bvx, avy-bvy, ax-bx, ay-by)/((ax-bx)*(ax-bx)+(ay-by)*(ay-by))*(ax-bx);
	a->vy = avy - (2*bm/(am+bm))*dotProduct(avx-bvx, avy-bvy, ax-bx, ay-by)/((ax-bx)*(ax-bx)+(ay-by)*(ay-by))*(ay-by);
	b->vx = bvx - (2*am/(am+bm))*dotProduct(bvx-avx, bvy-avy, bx-ax, by-ay)/((bx-ax)*(bx-ax)+(by-ay)*(by-ay))*(bx-ax);
	b->vy = bvy - (2*am/(am+bm))*dotProduct(bvx-avx, bvy-avy, bx-ax, by-ay)/((bx-ax)*(bx-ax)+(by-ay)*(by-ay))*(by-ay);
	
	if(distance(ax,ay,bx,by)<a->r+b->r){
		float e = a->r+b->r-distance(ax,ay,bx,by);
		if(b->vx==0 && b->vy==0){std::cout<<"Division by zero!"<<std::endl;}
		b->r-=e;
	}
	
}

inline void asteroidBounce(Asteroid* a, Item* b, float ax, float ay, float bx, float by){
	if(ax==bx && ay==by){
		std::cout<<"Caught division by zero"<<std::endl;
		return;
	}
	
	
	float am = a->r * a->r * M_PI;
	float bm = b->m;
	float avx = a->vx;
	float avy = a->vy;
	float bvx = b->vx;
	float bvy = b->vy;
	
	a->vx = avx - (2*bm/(am+bm))*dotProduct(avx-bvx, avy-bvy, ax-bx, ay-by)/((ax-bx)*(ax-bx)+(ay-by)*(ay-by))*(ax-bx);
	a->vy = avy - (2*bm/(am+bm))*dotProduct(avx-bvx, avy-bvy, ax-bx, ay-by)/((ax-bx)*(ax-bx)+(ay-by)*(ay-by))*(ay-by);
	b->vx = bvx - (2*am/(am+bm))*dotProduct(bvx-avx, bvy-avy, bx-ax, by-ay)/((bx-ax)*(bx-ax)+(by-ay)*(by-ay))*(bx-ax);
	b->vy = bvy - (2*am/(am+bm))*dotProduct(bvx-avx, bvy-avy, bx-ax, by-ay)/((bx-ax)*(bx-ax)+(by-ay)*(by-ay))*(by-ay);

	
	if(distance(a->lx,a->ly,b->lx,b->ly)<a->r+b->r){
		float e = a->r+b->r-distance(ax,ay,bx,by);
		if(b->vx==0 && b->vy==0){std::cout<<"Division by zero!"<<std::endl;}
		b->lx+=(e)*(b->vx/std::sqrt(b->vx*b->vx + b->vy*b->vy));
		b->ly+=(e)*(b->vy/std::sqrt(b->vx*b->vx + b->vy*b->vy));
	}
	
}


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
		//Asteroid a(0.0,0.0,0.0,0.0,40.0);
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
	
	//Update had to be redone as two methods, because an object could be caught in multiple updates otherwise
	void update1(){
		if(playerIsHere){ps->update();}
		
		for(int i = 0; i<asteroids.size(); i++){
			asteroids[i].update();
		}
		for(int i = 0; i<items.size(); i++){
			items[i]->update();
		}
		for(int i = 0; i<enemies.size(); i++){
			enemies[i]->update();
		}
	}
	
	void update2(){

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
		//{std::cout<<"Items Moved"<<std::endl;}
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
			
			//Collision Detection: Asteroid - Asteroid
			
			for(int j=0;j<asteroids.size();j++){
				Asteroid* b = &asteroids[j];
				float bx = b->lx;
				float by = b->ly;
				float br = b->r;
				for(int i=j+1; i<asteroids.size(); i++){
					float ar = asteroids[i].r;
					float ax = asteroids[i].lx;
					float ay = asteroids[i].ly;
					if(distance(ax,ay,bx,by)<=ar+br){
						asteroidBounce(&asteroids[i],&asteroids[j],ax,ay,bx,by);
					}
				}
				
				if(UR!=NULL){
					for(int i=0; i<UR->asteroids.size(); i++){
						float ar = UR->asteroids[i].r;
						float ax = UR->asteroids[i].lx-100;
						float ay = UR->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							asteroidBounce(&(UR->asteroids[i]),&asteroids[j],ax,ay,bx,by);
						}
					}
				}
				
				if(R!=NULL){
					for(int i=0; i<R->asteroids.size(); i++){
						float ar = R->asteroids[i].r;
						float ax = R->asteroids[i].lx;
						float ay = R->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							asteroidBounce(&(R->asteroids[i]),&asteroids[j],ax,ay,bx,by);
						}
					}
				}
				
				if(D!=NULL){
					for(int i=0; i<D->asteroids.size(); i++){
						float ar = D->asteroids[i].r;
						float ax = D->asteroids[i].lx+100;
						float ay = D->asteroids[i].ly;
						if(distance(ax,ay,bx,by)<=ar+br){
							asteroidBounce(&(D->asteroids[i]),&asteroids[j],ax,ay,bx,by);
						}
					}
				}
				
				if(DR!=NULL){
					for(int i=0; i<DR->asteroids.size(); i++){
						float ar = DR->asteroids[i].r;
						float ax = DR->asteroids[i].lx+100;
						float ay = DR->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							
							asteroidBounce(&(DR->asteroids[i]),&asteroids[j],ax,ay,bx,by);

						}
					}
				}
				
				if(b->r<5){asteroids.erase(asteroids.begin()+j);}
			}
			
			//{std::cout<<"A-A CD Done"<<std::endl;}
			//collision detection: item - asteroids
			for(int j=0;j<items.size();j++){
				//std::cout<<"Defining b"<<std::endl;
				Item* b = items[j];
				float bx = b->lx;
				float by = b->ly;
				float br = b->r;
				//std::cout<<"b Defined"<<std::endl;
				//FIXED? error is in below loop
				for(int i=0; i<asteroids.size(); i++){
					float ar = asteroids[i].r;
					float ax = asteroids[i].lx;
					float ay = asteroids[i].ly;
					if(distance(ax,ay,bx,by)<=ar+br){
						if(b->m>0)//apply physical collision
						{	//std::cout<<"Collide"<<std::endl;
							asteroids[i].collide();
							asteroidBounce(&asteroids[i],b,ax,ay,bx,by);
							//std::cout<<"Collided"<<std::endl;
							}
						if(b->damage>0)//apply damage (reduction in radius)
						{asteroids[i].r-=b->damage;b->tag_for_delete=true;}
					}
				}
						//std::cout<<"X"<<std::endl;
				if(1){//does not help
				if(UL!=NULL){
					for(int i=0; i<UL->asteroids.size(); i++){
						float ar = UL->asteroids[i].r;
						float ax = UL->asteroids[i].lx-100;
						float ay = UL->asteroids[i].ly-100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(UL->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{UL->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}
				
				if(U!=NULL){
					for(int i=0; i<U->asteroids.size(); i++){
						float ar = U->asteroids[i].r;
						float ax = U->asteroids[i].lx-100;
						float ay = U->asteroids[i].ly;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(U->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{U->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}				
				
				if(UR!=NULL){
					for(int i=0; i<UR->asteroids.size(); i++){
						float ar = UR->asteroids[i].r;
						float ax = UR->asteroids[i].lx-100;
						float ay = UR->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(UR->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{UR->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}

				if(L!=NULL){
					for(int i=0; i<L->asteroids.size(); i++){
						float ar = L->asteroids[i].r;
						float ax = L->asteroids[i].lx;
						float ay = L->asteroids[i].ly-100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(L->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{L->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}
								}
								if(1){//does not help
				if(R!=NULL){
					for(int i=0; i<R->asteroids.size(); i++){
						float ar = R->asteroids[i].r;
						float ax = R->asteroids[i].lx;
						float ay = R->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(R->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{R->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}

				if(DL!=NULL){
					for(int i=0; i<DL->asteroids.size(); i++){
						float ar = DL->asteroids[i].r;
						float ax = DL->asteroids[i].lx-100;
						float ay = DL->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(DL->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{DL->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}
				
				if(D!=NULL){
					for(int i=0; i<D->asteroids.size(); i++){
						float ar = D->asteroids[i].r;
						float ax = D->asteroids[i].lx+100;
						float ay = D->asteroids[i].ly;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(D->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{D->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}
				
				if(DR!=NULL){
					for(int i=0; i<DR->asteroids.size(); i++){
						float ar = DR->asteroids[i].r;
						float ax = DR->asteroids[i].lx+100;
						float ay = DR->asteroids[i].ly+100;
						if(distance(ax,ay,bx,by)<=ar+br){
							if(b->m>0)//apply physical collision
							{asteroidBounce(&(DR->asteroids[i]),b,ax,ay,bx,by);}
							if(b->damage>0)//apply damage (reduction in radius)
							{DR->asteroids[i].r-=b->damage;b->tag_for_delete=true;}
						}
					}
				}
								}
				
				if(b->tag_for_delete){items.erase(items.begin()+j);j--;}
			}//{std::cout<<"A-I CD Done"<<std::endl;}

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
