#include "ColorPicker.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <string>

ColorMatrix::ColorMatrix(){

    if (!font.loadFromFile("fonts\\FredokaOne-Regular.ttf"))
    {
        std::cout << "font loading error" << std::endl;
    }

    selectedText.setFont(font);
    selectedText.setCharacterSize(40);
    selectedText.setString("selected: ");
    selectedText.setPosition(20, 390);

    selectedColorText.setFont(font);
    selectedColorText.setCharacterSize(30);
    selectedColorText.setPosition(20, 430);

    selectedColor.setPosition(200, 390);
    selectedColor.setSize( sf::Vector2f(40, 40) );

    // select on matrix and bar
    matrixSelect.setPosition(151, 151);
    matrixSelect.setSize(sf::Vector2f(7, 7) );
    barSelect.setPosition(322, 357);
    barSelect.setSize( sf::Vector2f(7,7) );



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

    target.clear(sf::Color(200, 200, 200) );
    target.draw(selectedColor);
    target.draw(selectedText);
    target.draw(selectedColorText);

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

    target.draw(barSelect);
    target.draw(matrixSelect);


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
                matrixSelect.setPosition(j*21 + 7, i*21 + 7);
                selectedColorText.setString("R: " + std::to_string(mainBarColor) + " G: " + std::to_string(i*16) + " B: " + std::to_string(j*16));
            }
        }

        if( colorBar[i].isPressed() ){
            mainBarColor = i*16;
            barSelect.setPosition(i*21 + 7, 357);
        }
    }
}


ColorMatrix::~ColorMatrix(){}