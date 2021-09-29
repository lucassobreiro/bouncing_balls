#ifndef BALL_HPP
#define BALL_HPP

#include "app.hpp"

class Ball
{
private:
	static const int size = 32;
	static const int maxGravity = 12;
	
	float jumpStrength;
	float speed, gravity = 0.f;
	double b_sin, b_cos;

	sf::RectangleShape rec;

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
