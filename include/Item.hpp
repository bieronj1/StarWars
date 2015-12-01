class Item : public sf::Drawable{
	
	 public:
	float lx;
	float ly;
	float vx;
	float vy;
	float r;
	float m=1;
	float damage=5;
	bool tag_for_delete = false;
	Item(float tlx, float tly, float tvx, float tvy, float tr, float mass=1, float dam=0){
		lx=tlx;
		ly=tly;
		vx=tvx;
		vy=tvy;
		r=tr;
		m=mass;
		damage=dam;
	}
	
	//update object location for new frame
	void update(){
		//checks to see if we are exceeding max speed
		if(vx>=100){vx=99;}
		if(vx<=-100){vx=-99;}
		if(vy>=100){vy=99;}
		if(vy<=-100){vy=-99;}
		//update location
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
		
		if(damage==0){c.setFillColor(sf::Color::Cyan);}
		else{c.setFillColor(sf::Color::Red);}
		c.setPosition(lx+offx, ly+offy);
        c.setOrigin(r,r);
		target.draw(c);
    }
	
};
