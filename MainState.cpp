#include "MainState.hpp"
#include <iostream>

MainState::MainState() {}

void MainState::run() {

    applicationWindow.clear( sf::Color(200, 200, 200) );

    while( applicationWindow.isOpen() ){
        sf::Event event;

        // random event except type 0 (closed)
        event.type = sf::Event::GainedFocus;

        applicationWindow.pollEvent(event);

            if (event.type == sf::Event::Closed)
                applicationWindow.close();

            if( applicationWindow.hasFocus() ) {
                // Color Picker
                matrix.checkPressing( );

                // Pattern
                pattern.checkPressing(matrix.getColor());
            }

        this->render();

    }
}

void MainState::render() {
    matrix.changeBarColor();

    matrix.setCopiedColor(pattern.getSavedColor());
    matrix.renderShape(applicationWindow, sf::Mouse::getPosition(applicationWindow) );
    pattern.renderPattern(applicationWindow, sf::Mouse::getPosition(applicationWindow) );
    applicationWindow.display();
}
