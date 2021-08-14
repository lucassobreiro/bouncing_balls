#ifndef BALL_HPP
#define BALL_HPP

#include "app.hpp"

class Ball
{
private:
	const float size = 32.f;
	const float maxGravity = 12.f;
	
	float jumpStrength;
	float speed, gravity = 0.f;
	double b_sin, b_cos;

	sf::RectangleShape rec;
	sf::Texture tex;

public:
	void initRec(void);
	void newAngle(float angle);
	void movement(void);

	//Getters
	sf::RectangleShape getRec(void);

	//Setters
	void setGravity(float f_gravity);

};

#endif //BALL_HPP
