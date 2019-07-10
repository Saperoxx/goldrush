#include "Rozgrywka.h"
int  main() {

	srand(time(NULL));

	bool Graj = false;

	sf::RenderWindow window(sf::VideoMode(1260, 768), "Gold rush");
	Rozgrywka rozgrywka(window);
	//Zegar
	sf::Clock clock;
	float  DelatTime = 0.0;
	//Tworznie sceny gry
	sf::Texture Scena;
	Scena.loadFromFile("cScena.png");
	sf::Sprite scena(Scena);

	sf::Texture texture;
	texture.loadFromFile("start.png");
	sf::Sprite sprite(texture);

	//Muzyka
	sf::Music music;
	music.openFromFile("menu.ogg");
	music.play();

	while (window.isOpen())
	{

		DelatTime = clock.restart().asSeconds();
		//std::cout<<DelatTime<<std::endl;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Space)
			{
				if (Graj && !rozgrywka.isKoniecGry())
				{
					rozgrywka.setSpace(true);
				}

				Graj = true;


			}
		}

		window.clear();
		if (Graj) {
			window.draw(scena);
			rozgrywka.Utworz(window, DelatTime);
			music.setLoop(true);

		}
		if (!Graj)
		{
			window.draw(sprite);
		}
		window.display();
	}

	return 0;
}