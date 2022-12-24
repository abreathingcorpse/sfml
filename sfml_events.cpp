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

	// Check how many Joysticks are connected, if any
	unsigned int connected_joysticks = 0;
	for (int i=0; i < 8; i++) {
		if (Joystick::isConnected(i)) {
			connected_joysticks += 1;
		}	
	}

	while (window.isOpen()) {

		// Declare the event union
		Event event;

		// while there are pending events...
		while (window.pollEvent(event)) {

			// ifs instead of a switch was used due to the
			// event.joystickConnect.joystickId giving me the number of 
			// the keyboard, I believe it was coming from the event.key.code
			// According to the following link:
			// https://www.geeksforgeeks.org/switch-vs-else/
			// A switch is not actually ran from top to botton, I believe that's
			// causing issues

			// window closed
			if (event.type == Event::Closed) {
				if (paused) {
					cout << "Removing pause." << endl;
					paused = false;
				}
				window.close();
			}
			
			// TODO: For some reason whenever I close with MOD+W
			// The Game loses focus before closing. Need to check
			// if this is due to Qtile or this happens on Windows too.
			if (event.type == Event::LostFocus) {
				cout << "Pausing the Game." << endl;
				paused = true;
			}

			// key pressed gets triggered whenever ANY key is pressed
			if (event.type == Event::KeyPressed) {
				if (!asked_quitting && event.key.code == Keyboard::Escape) {
					cout << "Are you sure you want to quit? " << 
					"[Y/<Any other key>]" << endl;
					asked_quitting = true;
					// This break is required because you want the game
					// to stop processing this KeyPressed process here and 
					// to process the next event
					break;
				}

				if (asked_quitting && event.key.code == Keyboard::Y) {
					window.close();
				} else if (asked_quitting){ 
					cout << "Unpausing the game" << endl;
					asked_quitting = false;
				}  
			}

			// If no Joysticks, use Keyboard Mode 
			if (event.type == Event::JoystickDisconnected) {
				connected_joysticks -= 1;
				if (connected_joysticks < 1) {
					cout << "Switching to Keyboard Mode." << endl;
				}
			}
			if (event.type == Event::JoystickConnected) {
				cout << "Switching to Joystick Mode." << endl;
				connected_joysticks += 1;
			}

			// The JoystickButtonPressed event, simply print the information in
			// the event.joystickButton member.
			if (event.type == Event::JoystickButtonPressed) {
				cout << "Joystick ID: " << event.joystickButton.joystickId
				<< " pressed the button: " << event.joystickButton.button << endl;
			}
// FUTURE IMPLEMENTATIONS:
// The JoystickButtonReleased events, simply print the information in
// the event.joystickButton member.

// The JoystickMoved event, simply print the information within the event.joystickMove event and
// attempt to find a sweet spot of when the axis actually moved on a controller.
// It should also print the input from two Joysticks

		} // window.pollEvent(event)


	} // window.isOpen()
	return 0;
}
