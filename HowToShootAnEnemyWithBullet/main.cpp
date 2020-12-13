#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	sf::RectangleShape player;
	player.setSize(sf::Vector2f(20.0f, 40.0f));
	std::vector<Enemy> enemies;
	enemies.push_back(Enemy (sf::Vector2f(900.0f, 360.0f)));
	float speed = 1.0f;
	float delayShoot = 500.0f;
	std::vector<Bullet> bullets;
	player.setFillColor(sf::Color::Magenta);
	sf::Clock clock,clock2;
	float deltaTime;
	float clockDelayS;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		clockDelayS = clock2.getElapsedTime().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				player.move(sf::Vector2f(-speed, 0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				player.move(sf::Vector2f(speed, 0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				player.move(sf::Vector2f(0, -speed));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				player.move(sf::Vector2f(0, speed));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (clockDelayS > delayShoot) {
					bullets.push_back(Bullet(150.0f,player.getPosition()));
					clock2.restart();
				}
			}
			for (Bullet& bullet : bullets) {
				bullet.Update(deltaTime);
			}
			if (enemies.size() > 0) {
				Collider temp = enemies[0].GetCollider();
				for (Bullet& bullet : bullets){
					if (bullet.GetCollider().CheckCollision(temp)) {
						bullet.setDestroy(true);
						enemies[0].setHp(bullet.GetDmg());
					}

				}
				for (int i = 0;i < bullets.size();i++) {
					if (bullets[i].isDestroy()) {
						bullets.erase(bullets.begin() + i);
					}
				}
				if (enemies[0].GetHp() <= 0) {
					enemies.erase(enemies.begin());
				}
			}
		window.clear();
		for (Bullet& bullet : bullets) {
			bullet.Draw(window);
		}
		if (enemies.size() > 0) {
			enemies[0].Draw(window);
		}
		window.draw(player);
		window.display();
	}
	return 0;    
}