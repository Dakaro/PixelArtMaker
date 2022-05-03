#include "MainState.hpp"
#include <iostream>
MainState::MainState() {}

void MainState::run() {

    applicationWindow.clear( sf::Color(200, 200, 200) );

    while( applicationWindow.isOpen() ){
        sf::Event event;
        while (applicationWindow.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                applicationWindow.close();

            // Color Picker
            matrix.checkPressing();


        }
        this->render();
    }
}

void MainState::render() {
    matrix.changeBarColor();

    matrix.renderShape(applicationWindow, sf::Mouse::getPosition(applicationWindow) );
    applicationWindow.display();
}
