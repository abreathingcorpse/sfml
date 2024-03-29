#include <SFML/Graphics.hpp>
#include <iostream>

// Declaring the SFML namespace
using namespace sf;
using namespace std;

// This is toggled between true/false whenever the player presses F
bool fullscreen_flag = false;

// Receives the referece address to window, as well as the fullscreen_flag
// Toggles between default and Fullscreen mode
void toggle_fullscreen(Window& window, bool fullscreen_flag) {
	if (fullscreen_flag) {
		VideoMode DesktopVideoMode = VideoMode::getDesktopMode();
		window.create(DesktopVideoMode, "My window", Style::Fullscreen);
	} else {
		window.create(VideoMode(800,600), "My window");
	}
}

int main() {
	
	// Declare the window
	Window window;

	// TODO: Currently the user can't realize it's in fullscreen mode
	// It needs to, at least, render a black color
	toggle_fullscreen(window, fullscreen_flag);

	// Get the size of the window 
	// Call: Vector2u sf::Window::getSize()	const
	// TODO: Call this again whenever the Event::Resized gets triggered
	Vector2u size = window.getSize();
	cout << "Original Window size: " << size.x << "," << size.y << endl;

	// run the program as long as the window is open
	while (window.isOpen()) {

		// check all the window's events that were triggered since the last iteration of
		// the game loop
		Event event;

		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == Event::Closed) {
				window.close();	
			}
			// The window toggles between the default and fullscreen mode
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::F) {
				fullscreen_flag = !fullscreen_flag;
				toggle_fullscreen(window, fullscreen_flag);
			}
			// TODO:
			// call:
			// static const std::vector<VideoMode>& VideoMode::getFullscreenModes	()
			// returns: Array containing all the supported fullscreen modes
			// When? whenever the key 'V'
		}
	}

	return 0;
}
