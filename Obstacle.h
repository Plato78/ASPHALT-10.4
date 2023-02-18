#pragma once
#include "settings.h"


struct Obstalce {
	sf::Texture texture;
	sf::Sprite sprite;
};
void spawn(Obstalce& obs) {
	int x, y;
	int s = rand() % 4;
	if (s == 0) x = 100;
	else if (s == 1) x = 200;
	else if (s == 2) x = 300;
	else if (s == 3) x = 400;
	y = rand() % 951 - 800;
	obs.sprite.setPosition(x, y);
}
void obstalceInit(Obstalce& obs, std::string fileName) {
	obs.texture.loadFromFile(fileName);
	obs.sprite.setTexture(obs.texture);
	spawn(obs);

}
void  obsUpdate(Obstalce& obs) {
	obs.sprite.move(0.f,3.f);
	if (obs.sprite.getPosition().y >= height) {
		spawn(obs);
	}

}
void ObsDraw(sf::RenderWindow& window, const Obstalce& obs) {
	window.draw(obs.sprite);

}