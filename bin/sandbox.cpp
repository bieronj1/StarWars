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

//based on http://totologic.blogspot.fr/2014/01/accurate-point-in-triangle-test.html
bool collisionTrianglePoint(float px, float py, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3){

		float d = ((ty2-ty3)*(tx1-tx3)+(tx3-tx2)*(ty1-ty3));
		float a = 
	
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
		c.setPosition(lx+offx, ly+offy);
        target.draw(c);
    }

};

/*
class PlayerShip : public sf::Drawable{
  public:
	float lx;
	float ly;
	float offx=0;
	float offy=0;
	float vx;
	float vy;
	float orientation;//0 is straight towards (1.0)
	float fthrust;//forward thrust
	float sthrust;//stopping thrust
	float lthrust;//lateral thrust
	float trate;//turnrate, in rotations per frame
	PlayerShip(float tlx, float tly, float tft, float tlt, float tr){
		lx=tlx;
		ly=tly;
		vx=0;
		vy=0;
		fthrust = tft;
		lthrust = tlt;
		sthrust= tft;
		trate=tr;
		orientation=0.0;
	}
	
	//update object location for new frame
	void update(){
		lx+=vx;
		ly+=vy;
	}
	
	void faster(){
		vx+=fthrust*(std::cos(orientation));
		vy+=fthrust*(std::sin(orientation));
	}
	
	void reverse(){
		vx-=lthrust*(std::cos(orientation));
		vy-=lthrust*(std::sin(orientation));
	}
	
	void slower(){

		if(vy*vy+vx*vx<0.5){
			vx/=1.5;
			vy/=1.5;
		}
		else{
			vx+=-1*sthrust*(vx/std::sqrt(vy*vy+vx*vx));
			vy+=-1*sthrust*(vy/std::sqrt(vy*vy+vx*vx));	
		}
	}
	
	void turnRight(){
		orientation+=trate;
		if(orientation>=2*M_PI)
			orientation-=2*M_PI;
	}
	
	void turnLeft(){
		orientation-=trate;
		if(orientation<0)
			orientation+=2*M_PI;		
	}
	
	void latRight(){
		vx+=fthrust*(std::cos(orientation+M_PI/2));
		vy+=fthrust*(std::sin(orientation+M_PI/2));
	}
	
	void latLeft(){
		vx+=fthrust*(std::cos(orientation-M_PI/2));
		vy+=fthrust*(std::sin(orientation-M_PI/2));
	}
	
	void magicTurn(){
		float speed = std::sqrt(vx*vx+vy*vy);
		vx=speed*std::cos(orientation);
		vy=speed*std::sin(orientation);
	}
	void setRenderOffset(float x, float y){
		offx=x;
		offy=y;
	}
	
	private:
	 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::ConvexShape polygon;
		polygon.setPointCount(3);
		polygon.setPoint(0, sf::Vector2f(30,0));
		polygon.setPoint(1, sf::Vector2f(-15, -15));
		polygon.setPoint(2, sf::Vector2f(-15, 15));
		polygon.setFillColor(sf::Color::Green);
		polygon.setPosition(lx+offx,ly+offy);
		polygon.rotate(orientation*180/M_PI);
        target.draw(polygon);
    }

};
*/

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
		Asteroid a(std::rand()%100,std::rand()%100,0,0,20);
		asteroids.push_back(a);}
	}
	
	~GridSquare(){
		return;
		
	}
	
	void update(){
		;
		for(int i = 0; i<asteroids.size(); i++){
			asteroids[i].update();
			//CODE FOR MOVING ASTEROIDS BETWEEN GRIDSQUARES GOES HERE
		}

		if(playerIsHere){
		std::cout<<ps->lx<<","<<ps->ly<<std::endl;
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
				DL->playerIsHere=true;
				DL->ps=ps;
				playerIsHere=false;
				ps=NULL;
			}
		}
		if(playerIsHere){
			if(ps->lx>100&&ps->ly<0){
				ps->lx-=100;
				ps->ly+=100;
				UR->playerIsHere=true;
				UR->ps=ps;
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

		if(playerIsHere){std::cout<<ps->lx<<","<<ps->ly<<std::endl;
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
	
	//collision detection
	//player - asteroid
	if(playerIsHere){
		//local asteroids
		for(int i=0; i<asteroids.size(); i++){
			float ar = asteroids[i].r;
			float ax = asteroids[i].lx;
			float ay = asteroids[i].ly;
			float px = ps->lx;
			float py = ps->ly;
			float dp1, dp2, dp3;
			dp1 = std::sqrt((px-15-ax)*(px-15-ax)+(py-15-ay)*(py-15-ay));
			dp2 = std::sqrt((px-15-ax)*(px-15-ax)+(py+15-ay)*(py+15-ay));
			dp3 = std::sqrt((px+30-ax)*(px+30-ax)+(py-ay)*(py-ay));
			if(dp1+dp2+dp3 <= 75+ar){
				//ps->collide(asteroids[i]);
				std::cout<<dp1+dp2+dp3<<std::endl;
				asteroids[i].collide();
			}
		}
		
	}
	
	
	}
	

	PlayerShip* ps = NULL; //only needs to be valid if playerIsHere==true
	
	std::vector<Asteroid> asteroids;//POTENTIAL MEMORY LEAK
	
	void drawOnWindow(sf::RenderWindow* win, float x, float y){
		for(int i = 0; i<asteroids.size(); i++){
			asteroids[i].setRenderOffset(x,y);
			win->draw(asteroids[i]);
		}
		if(playerIsHere){
			ps->setRenderOffset(x,y);
			win->draw(*ps);
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
			std::cout<<pi<<","<<pj<<std::endl;
			while(pj<12){shiftRight();pj++;std::cout<<"RIGHT!"<<std::endl;}
			while(pj>12){shiftLeft();pj--;std::cout<<"LEFT!"<<std::endl;}
			while(pi<12){shiftDown();pi++;std::cout<<"DOWN!"<<std::endl;}
			while(pi>12){shiftUp();pi--;std::cout<<"UP!"<<std::endl;}
			//std::cout<<pi<<","<<pj<<std::endl;
		}
	}
	
	void shiftUpPublic(){shiftUp();}
	
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
		//build far right
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
//not used
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
	
	private:
	 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::CircleShape c;
		c.setRadius(r);
		c.setFillColor(sf::Color::Red);
		c.setPosition(lx, ly);
        target.draw(c);
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
	
	if(QWEASD[1]){pc.faster();}
	if(QWEASD[4]){
		if(SHIFT)
			pc.slower();
		else
			pc.reverse();
	}
	if(QWEASD[3]){pc.turnLeft();}
	if(QWEASD[5]){pc.turnRight();}
	if(QWEASD[0]){pc.latLeft();}
	if(QWEASD[2]){pc.latRight();}
	bool zoom = false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		zoom=true;
	}
	App.clear(sf::Color::Black);
	pc.update();
	sf::View camera(sf::FloatRect(0,0,800,600));
	

	world.update();
	camera.move(1250-450+pc.lx,1250-350+pc.ly);
	camera.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	if(zoom){
	camera.zoom(5);}
	App.setView(camera);
	world.drawOnWindow(&App);
	//all code before is legacy
	//draw scores
App.display();

  }
  // Done.
  return 0;

}