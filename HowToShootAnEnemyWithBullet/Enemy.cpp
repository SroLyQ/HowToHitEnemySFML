#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)
{
	this->hp = 150.0f;
	body.setSize(sf::Vector2f(20.0f, 60.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::Red);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy::setHp(float dmg)
{
	this->hp -= dmg;
}
