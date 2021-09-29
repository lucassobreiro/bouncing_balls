#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include "ball.hpp"

//window size
#define W_WIDTH 1280
#define W_HEIGHT 720

class App
{
private:
	int ballLimit = 32;
	bool gravityMode = true;

	sf::RenderWindow window;
	sf::Event evt;

	sf::Texture bg_Tex, ball_Tex;
	sf::RectangleShape bg_Rec;

	void update(void);

public:
	void initApp(std::string bg_File);

	//getters
	bool getGravityMode();
	sf::Texture* getBallTexture();
};

#endif //APP_HPP
