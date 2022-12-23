#include <SFML/Graphics.hpp>
#include <iostream>

// Declaring the SFML namespace
using namespace sf;
using namespace std;

int main() {

	// First, we need to define a Window
	Window window(VideoMode(600,400), "Testing events");

	// Will become true if the game has asked the player if he'd actually want to quit the game 
	bool asked_quitting = false;
	// Will become true if the game is paused
	bool paused = false;

	while (window.isOpen()) {

		// Declare the event union
		Event event;

		// while there are pending events...
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				if (paused) {
					cout << "Removing pause." << endl;
					paused = false;
				}
				window.close();
			}
			
			if (event.type == Event::LostFocus) {
				cout << "Pausing the Game." << endl;
				paused = true;
			}

			if (event.type == Event::KeyPressed) {
				if (!asked_quitting && event.key.code == Keyboard::Escape) {
					cout << "Are you sure you want to quit? " << 
					"[Y/<Any other key>]" << endl;
					asked_quitting = true;
				}
				if (asked_quitting && event.key.code == Keyboard::Y) {
					window.close();
				} else if (asked_quitting){ 
					cout << "Unpausing the game" << endl;
					asked_quitting = false;
				} 
			}

			if (event.type == Event::JoystickDisconnected) {
				cout << "joystick disconnected: " <<
				event.joystickConnect.joystickId << endl;
				cout << "Switching to Keyboard Mode." << endl;
			}
			if (event.type == Event::JoystickConnected) {
					cout << "joystick connected: " <<
					event.joystickConnect.joystickId << endl;
					cout << "Switching to Joystick Mode." << endl;
			}
			// check the type of the event...
			/*switch (event.type) {

				// window closed
				case Event::Closed:
					if (paused) {
						cout << "Removing pause." << endl;
						paused = false;
					}
					window.close();
					break;

				case Event::LostFocus:
					// TODO: For some reason whenever I close with MOD+W
					// The Game loses focus before closing. Need to check
					// if this is due to Qtile or this happens on Windows too.
					cout << "Pausing the Game." << endl;
					paused = true;
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
					} else if (asked_quitting){ 
						cout << "Unpausing the game" << endl;
						asked_quitting = false;
						break;
					} 

				// TODO: Currently when two joysticks are connected it'll switch
				// to keyboard mode by removing a single controller
				// BUG: For some reason the Event::KeyPressed is making the
				// event.joystickConnect.joystickId is whichever key I press
				case Event::JoystickDisconnected:
					cout << "joystick disconnected: " <<
					event.joystickConnect.joystickId << endl;
					cout << "Switching to Keyboard Mode." << endl;
					break;

				case Event::JoystickConnected:
					cout << "joystick connected: " <<
					event.joystickConnect.joystickId << endl;
					cout << "Switching to Joystick Mode." << endl;
					break;
	
				// we don't process other types of events
				default:
					break;
			}*/
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
