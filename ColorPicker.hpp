#ifndef PIXELARTMAKER_COLORPICKER_H
#define PIXELARTMAKER_COLORPICKER_H

#include "Button.hpp"
#include <SFML/Graphics.hpp>
class ColorMatrix{

private:
    rectangleButton colorPixel[17][17];
    rectangleButton colorBar[17];
    int mainBarColor = 255;
    sf::RectangleShape  selectedColor;
    sf::Vector2i matrixPos;
    sf::Vector2i barPos;

public:

    ColorMatrix();
    ~ColorMatrix();
    void selectFromBar();
    void selectColorPixel();
    void changeBarColor();
    void renderShape(sf::RenderWindow &target, sf::Vector2i mousePos);
    void checkPressing();
    void setMatrixPos();
    void setBarPos();
};


#endif

