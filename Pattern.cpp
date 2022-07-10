#include "Pattern.hpp"
#include <iostream>

PatternMatrix::PatternMatrix() {

    font = sf::Font();
    font.loadFromFile("fonts\\FredokaOne-Regular.ttf");

    resetButton = rectangleButton( sf::Vector2f(100, 50), sf::Vector2f(735, 370),
                                   sf::Color(100,100,   100),
                                   sf::Color(20, 20, 20),
                                   sf::Color(30, 30, 30), sf::Text("reset", font, 30), "reset" );

    saveButton = rectangleButton( sf::Vector2f(100, 50), sf::Vector2f(535, 370),
                                  sf::Color(100,100,   100),
                                  sf::Color(20, 20, 20),
                                  sf::Color(30, 30, 30), sf::Text("save", font, 30), "save" );

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){
            patternPixel[i][j] =  rectangleButton( sf::Vector2f( 20, 20), sf::Vector2f(500 + 21 * j, 10 + 21 * i  ),
                                                   sf::Color(255, 255, 255),
                                                   sf::Color(120, 120, 120),
                                                   sf::Color(100, 100, 100) );
        }
    }

    savedColor = sf::Color(255, 255, 255);
}

void PatternMatrix::renderPattern(sf::RenderWindow &target, sf::Vector2i mousePos) {

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j){
            patternPixel[i][j].updateColor(mousePos);
            patternPixel[i][j].render(target);
        }
    }

    resetButton.updateColor(mousePos);
    resetButton.render(target);

    saveButton.updateColor(mousePos);
    saveButton.render(target);

}

void PatternMatrix::saveImage() {

    sf::Image image;

    image.create(160, 160);

    for(int i = 0; i < 160; ++i){
        for( int j = 0; j < 160; ++j ){
            image.setPixel( j, i, patternPixel[i/10][j/10].getColor() );
        }
    }

    image.saveToFile("tempFile.png");

    return;

}


void PatternMatrix::checkPressing(sf::Color color) {

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){

            patternPixel[i][j].changeHoverColor(color);

            if( patternPixel[i][j].isPressed() ){
                patternPixel[i][j].updateColor( color );
            }

            if( patternPixel[i][j].rightPressed() ){
                savedColor = patternPixel[i][j].getColor();
            }

        }
    }

    if( resetButton.isPressed() ) {
        resetPattern();
    }

    if( saveButton.isPressed() ) {
        saveImage();
    }

}

sf::Color PatternMatrix::getSavedColor(){
    return savedColor;
}

void PatternMatrix::resetPattern() {

    for(int i = 0; i < 16; ++i){
        for( int j = 0; j < 16; ++j ){
            patternPixel[i][j].updateColor(sf::Color(255, 255, 255) );
        }
    }

}

sf::Color const PatternMatrix::getPixelColor(int i, int j) {
    sf::Color const tempColor = patternPixel[i][j].getColor();
    return tempColor;
}

PatternMatrix::~PatternMatrix() {}
