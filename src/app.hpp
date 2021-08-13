#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <time.h>
#include "ball.hpp"

//window size
#define W_WIDTH 1024
#define W_HEIGHT 768
 
//ball limit
#define BALL_LIMIT 32

class App
{
private:
	sf::RenderWindow window;
	sf::Event evt;

	//background
	sf::Texture bg_Tex;
	sf::Sprite bg_Spr;

public:
	void initApp(void);
	int update(void);
};

#endif //APP_HPP
