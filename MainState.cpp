#include "MainState.hpp"
#include <iostream>
MainState::MainState() {}

void MainState::run() {

    applicationWindow.clear( sf::Color(200, 200, 200) );

    while( applicationWindow.isOpen() ){
        sf::Event event;
        applicationWindow.pollEvent(event);

            if (event.type == sf::Event::Closed)
                applicationWindow.close();

            // Color Picker
            matrix.checkPressing();

            // Pattern
            pattern.checkPressing( matrix.getColor() );

        this->render();
    }
}

void MainState::render() {
    matrix.changeBarColor();

    matrix.renderShape(applicationWindow, sf::Mouse::getPosition(applicationWindow) );
    pattern.renderPattern(applicationWindow, sf::Mouse::getPosition(applicationWindow) );
    applicationWindow.display();
}
