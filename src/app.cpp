#include "app.hpp"

Ball ball[BALL_LIMIT];

void App::initApp(void)
{
	srand(time(NULL));
	
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Bouncing Balls - By lucassobreiro", sf::Style::Close);
	window.setFramerateLimit(60);
	
	bg_Tex.loadFromFile("res/bg.png");
	bg_Spr.setTexture(bg_Tex);

	for(int a = 0; a<BALL_LIMIT; a++)
		ball[a].initRec();
	update();
}

int App::update(void)
{
	while(true)
	{
		while(window.pollEvent(evt))
		{
			if(evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return 0;
		}
		
		for(int a = 0; a<BALL_LIMIT; a++)
			ball[a].movement();

		//draw
		window.clear(sf::Color::White);
		window.draw(bg_Spr);
		for(int a = 0; a<BALL_LIMIT; a++)
			window.draw(ball[a].getRec());
		window.display();
	}
}

