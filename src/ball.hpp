#ifndef BALL_HPP
#define BALL_HPP

#include "app.hpp"

class Ball
{
private:
	const float size = 32.f;

	float speed;
	double b_sin, b_cos;

	sf::RectangleShape rec;
	sf::Texture tex;

public:
	void initRec(void);
	void newAngle(float angle);
	void movement(void);

	//Getters
	sf::RectangleShape getRec(void);

};

#endif //BALL_HPP
