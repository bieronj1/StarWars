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
		collision=false;
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
		//c.setPointCount(6);
		c.setFillColor(sf::Color::Blue);
		if(collision){c.setFillColor(sf::Color::Red);}
		c.setPosition(lx+offx-r, ly+offy-r);
        target.draw(c);
		//sf::CircleShape ct;
		//ct.setRadius(5);
		//ct.setFillColor(sf::Color::Yellow);
		//if(collision){c.setFillColor(sf::Color::Red);}
		//ct.setPosition(lx+offx-5, ly+offy-5);
        //target.draw(ct);		
    }

};