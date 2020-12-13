#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Bullet
{
public:
	Bullet(float speed,sf::Vector2f position);
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setDestroy(bool isDestroy);

	float GetDmg() { return dmg; }
	bool isDestroy() { return isDestroyBool; }
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;

	bool isDestroyBool;
	float speed;
	float dmg;
};

