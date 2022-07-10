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
    sf::RectangleShape matrixSelect;
    sf::RectangleShape barSelect;
    sf::Text selectedText;
    sf::Text selectedColorText;
    sf::Font font;
    sf::Color pickedColor;
    rectangleButton rubber;
    rectangleButton copyColor;

public:

    ColorMatrix();
    ~ColorMatrix();
    void setColor(sf::Color color);
    void setCopiedColor(sf::Color color);
    void changeBarColor();
    void renderShape(sf::RenderWindow &target, sf::Vector2i mousePos);
    void checkPressing();
    sf::Color getColor();
};


#endif

