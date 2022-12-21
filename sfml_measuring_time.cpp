#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode(200, 200), "Measuring time");
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		std::cout << elapsed.asMicroseconds();
	}

}
