#include "app.hpp"

Ball ball[BALL_LIMIT];

void App::initApp(void)
{
	srand(time(NULL));
	
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Bouncing Balls - By lucassobreiro", sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	
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
			switch(evt.type)
			{
				case (sf::Event::Closed):
				{
					return 0;	
					break;
				}

				case (sf::Event::KeyPressed):
				{
					switch(evt.key.code)
					{
						case (sf::Keyboard::Enter):
						{
							gravityMode = !gravityMode;
							for(int a = 0; a<BALL_LIMIT && gravityMode; a++)
								ball[a].setGravity(0.f);
							break;
						}

						case (sf::Keyboard::Escape):
						{
							return 0;
							break;
						}
					
						default:
							break;
					}
					break;
				}

				default:
					break;
			}
		}
		
		for(int a = 0; a<BALL_LIMIT; a++)
			ball[a].movement();

		//draw
		window.draw(bg_Spr);
		for(int a = 0; a<BALL_LIMIT; a++)
			window.draw(ball[a].getRec());
		window.display();
	}
}

//getters
bool App::getGravityMode()
{
	return gravityMode;
}

