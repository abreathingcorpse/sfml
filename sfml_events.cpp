#include <SFML/Graphics.hpp>
#include <iostream>

// Declaring the SFML namespace
using namespace sf;
using namespace std;

int main() {
// The sf::Event Type, I'll need to do the basic structure first

	// First, we need to define a Window
	Window window(VideoMode(600,400), "Testing events");

	// Will become true if the program has asked the user if he'd actually want to quit the game 
	bool asked_quitting = false;

	while (window.isOpen()) {

		// Declare the event union
		Event event;

		// while there are pending events...
		while (window.pollEvent(event)) {

			// check the type of the event...
			switch (event.type) {
				// window closed
				case Event::Closed:
					window.close();
					break;

				case Event::LostFocus:
					// TODO: The Game attempts to pause when closing with MOD+W
					cout << "Lost Focus -> Game shall pause." << endl;
					break;

				// key pressed gets triggered whenever ANY key is pressed
				case Event::KeyPressed:
					if (!asked_quitting && event.key.code == Keyboard::Escape) {
						cout << "Are you sure you want to quit? " << 
						"[Y/<Any other key>]" << endl;
						asked_quitting = true;
						break;
					}
					if (asked_quitting && event.key.code == Keyboard::Y) {
						window.close();
						break;
					} else { // TODO: The Game unpauses whenever ANY key is
						// pressed
						cout << "Unpausing the game" << endl;
						asked_quitting = false;
						break;
					}
	
				// we don't process other types of events
				default:
					break;
			}
		}

	}

// The JoystickButtonPressed and JoystickButtonReleased events, simply print the information in
// the event.joystickButton member.

// The JoystickMoved event, simply print the information within the event.joystickMove event and
// attempt to find a sweet spot of when the axis actually moved on a controller.

// The JoystickConnected and JoystickDisconnected events, the focus should move from keyboard to
// Joystick when it detects that one is connected. It should also print the input from two Joysticks
// and if the player 1 removes the Joystick, the Joystick of player 2 should still be working.
	return 0;
}
