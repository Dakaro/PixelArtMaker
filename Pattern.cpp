#include "Pattern.hpp"

PatternMatrix::PatternMatrix() {

    resetButton = rectangleButton( sf::Vector2f(20, 100), sf::Vector2f(10, 10),
                                   sf::Color(10,10,10),
                                   sf::Color(20, 20, 20),
                                   sf::Color(30, 30, 30) );

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){
            patternPixel[i][j] =  rectangleButton( sf::Vector2f( 20, 20), sf::Vector2f(500 + 21 * j, 10 + 21 * i  ),
                                                   sf::Color(255, 255, 255),
                                                   sf::Color(120, 120, 120),
                                                   sf::Color(100, 100, 100) );
        }
    }
}

void PatternMatrix::renderPattern(sf::RenderWindow &target, sf::Vector2i mousePos) {

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j){
            patternPixel[i][j].updateColor(mousePos);
            patternPixel[i][j].render(target);
        }
    }


}

void PatternMatrix::checkPressing(sf::Color color) {

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){

            patternPixel[i][j].changeHoverColor(color);

            if( patternPixel[i][j].isPressed() ){
                patternPixel[i][j].updateColor( color );
            }

        }
    }

}

PatternMatrix::~PatternMatrix() {}
