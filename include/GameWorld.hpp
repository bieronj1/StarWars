#include "GridSquare.hpp"

class GameWorld {
	
	public:
	GridSquare* board[25][25]; //list of pointers -> easy to shift
	// IT IS STORED [ROW][COL] AND DON'T FORGET!!!!
	scoreHolder* scoreholder;
	int xshifts = 0;
	int yshifts = 0;
	int FPS;
	GameWorld(PlayerShip * ps, int fps=120, scoreHolder* sh = NULL){
		FPS=fps;
		scoreholder = sh;
		if(scoreholder == NULL)std::cout<<"FUCK"<<std::endl;
		for(int i=0; i<25; i++){
			for(int j=0; j<25; j++){
				board[i][j] = new GridSquare(FPS, scoreholder);
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
	
	void addItem(Item* item, float x, float y){
		int i = (int) x;
		i /= 100;
		int j = (int) y;
		j/=100;
		
		//Sanity check (In honor of Professor Peers)
		if(i<0 || i>24 || j<0 || j>24){
			std::cout<<"Attempted to add an item in invalid position."<<std::endl;
			return;
		}
		item->lx = x-i;
		item->ly = y-j;
		board[i][j]->addItem(item);
	}
	
	void addEnemy(Enemy* enemy, float x, float y){
		int i = (int) x;
		i /= 100;
		int j = (int) y;
		j/=100;
		
		//Sanity check (In honor of Professor Peers)
		if(i<0 || i>24 || j<0 || j>24){
			std::cout<<"Attempted to add an enemy in invalid position."<<std::endl;
			return;
		}
		enemy->lx = x-i;
		enemy->ly = y-j;
		board[i][j]->addEnemy(enemy);
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
				board[i][j]->update1();
			}
		}
		for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
				board[i][j]->update2();
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
			while(pj<12){shiftRight();pj++;}
			while(pj>12){shiftLeft();pj--;}
			while(pi<12){shiftDown();pi++;}
			while(pi>12){shiftUp();pi--;}
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
		
			scoreholder->racescore= std::sqrt(xshifts*xshifts+yshifts*yshifts);
		
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
			board[row][24] = new GridSquare(FPS, scoreholder);
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
		
		scoreholder->racescore= std::sqrt(xshifts*xshifts+yshifts*yshifts);
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
			board[row][0]= new GridSquare(FPS, scoreholder);
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
		
		scoreholder->racescore= std::sqrt(xshifts*xshifts+yshifts*yshifts);
		std::cout<<scoreholder->score<<":"<<scoreholder->racescore<<std::endl;
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
			board[24][col]= new GridSquare(FPS, scoreholder);
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
		
		scoreholder->racescore= std::sqrt(xshifts*xshifts+yshifts*yshifts);
		for(int col=0;col<25;col++){
			delete board[24][col];
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
			board[0][col] = new GridSquare(FPS, scoreholder);
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