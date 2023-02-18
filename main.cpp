
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Grass.h"
#include"Sand.h"
#include"Road.h"
#include "Car.h"
#include "Obstacle.h"
using namespace sf;

int main()
{
	srand(time(0));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(width,height), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setPosition(Vector2i{ (1920 - (int)width) / 2, 0 });
	window.setFramerateLimit(FPS);

	GrassLayer grass1, grass2;
	grasslayerInit(grass1, Vector2f{ 0.f,0.f }, "Grass-Murova.jpg" , 0.f);
	grasslayerInit(grass2, Vector2f{ 0.f,-height }, "Grass-Murova.jpg", 0.f);
	SandLayer sand1, sand2;
	sandlayerInit(sand1, Vector2f{ 50.f,0.f }, "Sand.jpg",600.f-550.f);
	sandlayerInit(sand2, Vector2f{ 50.f,-height}, "Sand.jpg", 600.f-550.f);
	RoadLayer road1, road2;
	roadlayerInit(road1, Vector2f{100.f,0.f }, "Road4.png" ,500.f-400.f);
	roadlayerInit(road2, Vector2f{ 100.f,-height }, "Road4.png", 500.f - 400.f);
	Car car;
	carInit(car,car_start_pos, "Car.png");
	Obstalce obs1, obs2, obs3;
	obstalceInit(obs1,"Box.png");
	obstalceInit(obs2, "Sedan1.png");
	obstalceInit(obs3, "Gelik.png");
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		Grassillusion(grass1);
		Grassillusion(grass2);
		Sandillusion(sand1);
		Sandillusion(sand2);
		Roadillusion(road1);
		Roadillusion(road2);
		CarDrive(car);
		obsUpdate(obs1);
		obsUpdate(obs2);
		obsUpdate(obs3);
		//проверка столкновений игрока с припятствиями
		FloatRect carHitBox = car.sprite.getGlobalBounds();
		FloatRect obs1HitBox = obs1.sprite.getGlobalBounds();
		if (carHitBox.intersects(obs1HitBox)) {

		}
		// Отрисовка окна 
		window.clear();
		grassLayerDraw(window, grass1);
		grassLayerDraw(window, grass2);
		SandLayerDraw(window, sand1);
		SandLayerDraw(window, sand2);
		roadLayerDraw(window, road1);
		roadLayerDraw(window, road2);
		CarDraw(window, car);
		ObsDraw(window, obs1);
		ObsDraw(window, obs2);
		ObsDraw(window, obs3);
		window.display();
	}

	return 0;
}