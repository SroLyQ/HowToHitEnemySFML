#include "Bullet.h"

Bullet::Bullet(float speed,sf::Vector2f position)
{
	this->speed = speed;
	this->isDestroyBool = false;
	this->dmg = 50.0f;
	body.setSize(sf::Vector2f(10.0f, 10.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);

}

void Bullet::Update(float deltaTime)
{
	if (body.getPosition().x > 1080 || body.getPosition().x < 0) {
		isDestroyBool = true;
	}
	body.move(speed * deltaTime, 0.0);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Bullet::setDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}

