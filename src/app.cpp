#include "app.hpp"

std::vector<Ball> ball;
Ball ballB;

void App::initApp(std::string bg_File)
{
	srand(time(NULL));
	std::cout << "Bouncing Balls\nBy Lucas Sobreiro" << std::endl;

	for(int a = 0; a<ballLimit; a++)
		ball.push_back(ballB);

	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Bouncing Balls", sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(true);
	
	if(!bg_Tex.loadFromFile(bg_File) || !ball_Tex.loadFromFile("res/ball.png"))
		window.close();
	bg_Tex.setSmooth(true);
	bg_Rec.setTexture(&bg_Tex);
	bg_Rec.setSize(sf::Vector2f(W_WIDTH, W_HEIGHT));

	for(int a = 0; a<ballLimit; a++)
		ball[a].initRec();
	update();
}

void App::update(void)
{
	while(window.isOpen())
	{
		while(window.pollEvent(evt))
		{
			switch(evt.type)
			{
				case (sf::Event::Closed):
				{
					window.close();	
					break;
				}

				case (sf::Event::KeyPressed):
				{
					switch(evt.key.code)
					{
						case (sf::Keyboard::Enter):
						{
							gravityMode = !gravityMode;
							for(int a = 0; a<ballLimit && gravityMode; a++)
								ball[a].setGravity(0.f);
							break;
						}

						case (sf::Keyboard::Up):
						{
							ballLimit ++;
							ball.push_back(ballB);
							ball[ballLimit - 1].initRec();
							std::cout << ballLimit << std::endl; 
							break;
						}

						case (sf::Keyboard::Down):
						{
							if(ballLimit > 0)
							{
								ballLimit --;
								ball.pop_back();
								std::cout << ballLimit << std::endl; 
							}
							break;
						}

						case (sf::Keyboard::Escape):
						{
							window.close();
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
		
		for(int a = 0; a<ballLimit; a++)
			ball[a].movement();

		//draw
		window.clear(sf::Color::White);
		window.draw(bg_Rec);
		for(int a = 0; a<ballLimit; a++)
			window.draw(ball[a].getRec());
		window.display();
	}
}

//getters
bool App::getGravityMode()
{
	return gravityMode;
}

sf::Texture* App::getBallTexture()
{
	return &ball_Tex;
}

