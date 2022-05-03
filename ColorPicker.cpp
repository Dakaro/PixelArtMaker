#include "ColorPicker.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

ColorMatrix::ColorMatrix(){

    selectedColor.setPosition(90, 400);
    selectedColor.setSize( sf::Vector2f(40, 40) );

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){
            colorPixel[i][j] = rectangleButton(sf::Vector2f(20, 20), sf::Vector2f(21*j, 21*i),
                                               sf::Color( mainBarColor , i*16, j*16),
                                               sf::Color( 100, 100, 100),
                                               sf::Color( 200 , 200, 200) );
        }
        colorBar[i] = rectangleButton(sf::Vector2f(20, 20), sf::Vector2f(21*i, 350),
                                      sf::Color( 16*i , 100, 100),
                                      sf::Color( 100, 100, 100),
                                      sf::Color( 200 , 200, 200) );
    }

}

void ColorMatrix::renderShape(sf::RenderWindow &target, sf::Vector2i mousePos) {

    target.draw(selectedColor);

    // color matrix change
    for(int i = 0; i < 16; ++i){
        for(int j = 0; j < 16; ++j){
            colorPixel[i][j].updateColor( mousePos );
            colorPixel[i][j].render(target);
        }

        // color bar change
        colorBar[i].updateColor( mousePos );
        colorBar[i].render(target);
    }




}

void ColorMatrix::changeBarColor() {
    mainBarColor %= 256;

    for(int i = 0; i < 16; ++i){
        for( int j = 0; j < 16; ++j){
            colorPixel[i][j].updateColor(sf::Color(mainBarColor, 16*i, 16*j) );
        }
    }

}

void ColorMatrix::checkPressing() {

    for( int i = 0; i < 16; ++i ){
        for( int j = 0; j < 16; ++j ){
            if( colorPixel[i][j].isPressed() ){
                selectedColor.setFillColor(sf::Color( mainBarColor, i*16, j*16 ) );
            }
        }

        if( colorBar[i].isPressed() ){
            mainBarColor = i*16;
        }

    }

}

ColorMatrix::~ColorMatrix(){}