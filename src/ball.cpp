#include "ball.hpp"

extern App app;

void Ball::initRec(void)
{
	tex.loadFromFile("res/ball.png");

	rec.setSize(sf::Vector2f(size, size));
	rec.setPosition(sf::Vector2f(rand()%W_WIDTH - size, rand()%W_HEIGHT - size));
	rec.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
	rec.setTexture(&tex);
	
	speed = rand()%8+4;
	jumpStrength = -rand()%15-8;
	newAngle(rand()%360);
}

void Ball::newAngle(float angle)
{
	//pi divided by 180
	const double piDBy180 = 0.01745329251;

	b_sin = sin(angle * piDBy180);
	b_cos = cos(angle * piDBy180);
}

void Ball::movement(void)
{
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if(app.getGravityMode())
		{
			gravity += 0.2f;
			if(gravity > maxGravity)
				gravity = maxGravity;
			rec.move(b_cos * speed, gravity);
		}
		else
		{
			rec.move(b_cos * speed, b_sin * speed);
		}
	}
	
	//bounce
	if(rec.getPosition().x < 0)
	{
		rec.setPosition(0, rec.getPosition().y);
		b_cos -= b_cos * 2;
	}
	if(rec.getPosition().x > W_WIDTH - size)
	{
		rec.setPosition(W_WIDTH - size, rec.getPosition().y);
		b_cos -= b_cos * 2;
	}
	if(rec.getPosition().y < 0)
	{
		rec.setPosition(rec.getPosition().x, 0);
		b_sin -= b_sin * 2;
		gravity = 0.f;
	}
	if(rec.getPosition().y > W_HEIGHT - size)
	{
		rec.setPosition(rec.getPosition().x, W_HEIGHT - size);
		b_sin -= b_sin * 2;
		gravity = jumpStrength;
	}
}

//getters
sf::RectangleShape Ball::getRec(void)
{
	return rec;
}

//setters
void Ball::setGravity(float f_gravity)
{
	gravity = f_gravity;
}

