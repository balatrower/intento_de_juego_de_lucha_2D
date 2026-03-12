#include <iostream>
#include <>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works!");

    // 2. The Main Game Loop - runs as long as the window is open
    while (window.isOpen()) {

        // 3. Event Handling (The "Input" phase)
        sf::Event event;
        while (window.pollEvent(event)) {
            // If the user clicks the 'X', close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 4. Update Logic (The "Update" phase)
        // This is where you'd move players or check collisions later.

        // 5. Rendering (The "Draw" phase)
        window.clear(sf::Color::Black); // Pick a background color

        // Everything you draw goes between clear() and display()

        window.display(); // Push everything to the screen
    }

    return 0;
}