#include <SFML/Graphics.hpp>

// Declaring the SFML namespace
using namespace sf;

// Define the constant parameters
float TRIANGLE_BASE = 18.0f;
float TRIANGLE_HEIGHT = 20.0f;
float TAILCUT_HEIGHT = 4.0f; // Must: TAILCUT_HEIGHT < TRIANGLE_HEIGHT

// Declare a ConvexShape for the character
ConvexShape character;
// NOTE: The area before the main() is to declare stuff only,
// any attempts to run anything outside of it will result in an out of scope issue

int main() {
	
	// Make the character's ConvexShape a Point Count of 4 and define those points.
	// NOTE: this needs to be inside the main(), since main() runs before any calls outside
	// of its scope
	character.setPointCount(4);
	character.setPoint(0, Vector2f(TRIANGLE_BASE / 2, TRIANGLE_HEIGHT - TAILCUT_HEIGHT ));
	character.setPoint(1, Vector2f(0.0, TRIANGLE_HEIGHT));
	character.setPoint(2, Vector2f(TRIANGLE_BASE / 2, 0));
	character.setPoint(3, Vector2f(TRIANGLE_BASE, TRIANGLE_HEIGHT));
	
	// Declare the window
	RenderWindow window(VideoMode(800,600), "Tailcutted triangle");

	while(window.isOpen()) {
		window.clear(Color::Black);
		window.draw(character);
		window.display();
		
		// check all the window's events that were triggered since the last iteration of
		// the game loop
		Event event;

		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == Event::Closed) {
				window.close();	
			}
		}
	}
} // main()
