#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
//#include <iostream>
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
	bool gravityMode = false;

	sf::RenderWindow window;
	sf::Event evt;

	//background
	sf::Texture bg_Tex;
	sf::Sprite bg_Spr;

public:
	void initApp(void);
	int update(void);

	//getters
	bool getGravityMode();
};

#endif //APP_HPP
