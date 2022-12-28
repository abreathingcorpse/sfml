#include <SFML/Graphics.hpp>
#include <iostream>

// Declaring the SFML namespace
using namespace sf;
using namespace std;

// Declare a new font
Font font;
// Declare a text (I guess one could have a different text for different sections of a menu)
Text text;

int main() {
	// Try to load a .ttf file, it should print to cerr if not found
	if (!font.loadFromFile("/usr/share/fonts/TTF/FiraSans-Regular.ttf")) {
		cerr << "Font not found." << endl;
	}
	// select the font
	text.setFont(font);

	// set the string to display
	text.setString("Hello world");
	
	// set the character size
	text.setCharacterSize(18); // in pixels, not points!

	// Declare the window
	RenderWindow window(VideoMode(800,600), "Hello world");

	while(window.isOpen()) {
		window.clear(Color::Black);
		window.draw(text);
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
}
