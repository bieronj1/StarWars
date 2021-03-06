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