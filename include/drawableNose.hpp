class drawableNose: public Nose {
  public:
		
		drawableNose(std::string tname){
			yOffset = 0;
			xOffset = -20;
			name = tname;
		}
		
		sf::ConvexShape returnShape() {
			sf::ConvexShape polygon;
			polygon.setPointCount(3);
			polygon.setPoint(0, sf::Vector2f(10,0));
			polygon.setPoint(1, sf::Vector2f(-5, -5));
			polygon.setPoint(2, sf::Vector2f(-5, 5));
			polygon.setFillColor(sf::Color::Green);

			return polygon;
		};
		
		
		
  private:
	  
	};