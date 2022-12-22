#include <SFML/Graphics.hpp>
#include <iostream>

// Declaring the SFML namespace
using namespace sf;
using namespace std;

int main() {
	
	Window window(VideoMode(800,600), "My window");

	// I'd like to set it to Fullscreen but, this requires a valid video mode
	// Style::Fullscreen

	// TODO:
	// call: static const std::vector<VideoMode>& sf::VideoMode::getFullscreenModes	()
	// returns: Array containing all the supported fullscreen modes
	// How? Learn about the events, whenever the key 'f' is pressed make it fullscreen

	// run the program as long as the window is open
	while (window.isOpen()) {

		// check all the window's events that were triggered since the last iteration of
		// the game loop
		Event event;

		// Get the size of the window every iterarion of the game loop
		// Call: Vector2u sf::Window::getSize()	const
		Vector2u size = window.getSize();
		cout << "Window size: " << size.x << "," << size.y << endl;

		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == Event::Closed) {
				window.close();	
			}
		}
	}

	return 0;
}
