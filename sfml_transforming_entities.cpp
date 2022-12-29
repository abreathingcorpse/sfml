#include <SFML/Graphics.hpp>

// Declaring the SFML namespace
using namespace sf;

// Define the constant parameters
float TRIANGLE_BASE = 18.0f;
float TRIANGLE_HEIGHT = 20.0f;
float TAILCUT_HEIGHT = 4.0f; // Must: TAILCUT_HEIGHT < TRIANGLE_HEIGHT

// Declare a ConvexShape for the character
ConvexShape character;
// Define the rotation angle
float angle = 45;

int main() {
	
	// Make the character's ConvexShape a Point Count of 4 and define those points.
	// NOTE: this needs to be inside the main(), since main() runs before any calls outside
	// of its scope
	character.setPointCount(4);
	character.setPoint(0, Vector2f(TRIANGLE_BASE / 2, TRIANGLE_HEIGHT - TAILCUT_HEIGHT ));
	character.setPoint(1, Vector2f(0.0, TRIANGLE_HEIGHT));
	character.setPoint(2, Vector2f(TRIANGLE_BASE / 2, 0));
	character.setPoint(3, Vector2f(TRIANGLE_BASE, TRIANGLE_HEIGHT));
	// The rotations look clunkly, so I'll try to change the origin of the character
	character.setOrigin(TRIANGLE_BASE / 2, TRIANGLE_HEIGHT / 2);
	// The update to the origin cuts the initial print of the character on the RenderWindow
	character.setPosition(TRIANGLE_BASE / 2, TRIANGLE_HEIGHT / 2);
	
	// Declare the window
	RenderWindow window(VideoMode(800,600), "Transforming entities");

	while(window.isOpen()) {
		window.clear(Color::Black);
		window.draw(character);
		window.display();
		
		// check all the window's events that were triggered since the last iteration of
		// the game loop
		Event event;

		// ---------------------- OUT OF SCOPE ----------------------------------
		// I've come to the realization that this is an implementation that's
		// out of scope for this project, because by pressing the D key the character
		// went flying as fast as it could. Therefore this requires a Game Loop set up

		// TODO: Use the sf::Keyboard instead of the Event::KeyPressed
		// https://www.sfml-dev.org/tutorials/2.5/window-inputs.php
		// Keep in mind the character.setRotation(angle), it'll have to be sum of
		// vectors or something
		/*if (Keyboard::isKeyPressed(Keyboard::D)) {
			character.move(Vector2f(1.0,0));
			character.setRotation(90.f);
		}*/

		// TODO: Bounding boxes
		// You'll have to implement Collision Detection sometime
		// ---------------------------------------------------------------------

		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == Event::Closed) {
				window.close();	
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::D) {
				character.move(Vector2f(1.0,0));
				character.setRotation(90.f);
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::S) {
				character.move(Vector2f(0,1));
				character.setRotation(180.f);
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::R) {
				character.rotate(angle);
			}
		}
	}
} // main()
