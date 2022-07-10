#ifndef PIXELARTMAKER_PATTERN_H
#define PIXELARTMAKER_PATTERN_H

#include "Button.hpp"
#include <SFML/Graphics.hpp>

class PatternMatrix{

private:
    rectangleButton patternPixel[16][16];
    rectangleButton resetButton;
    rectangleButton saveButton;
    sf::Font font;
    sf::Color savedColor;

public:
    PatternMatrix();
    ~PatternMatrix();
    void renderPattern(sf::RenderWindow &target, sf::Vector2i mousePos);
    void resetPattern();
    sf::Color getSavedColor();
    sf::Color const getPixelColor(int i, int j);
    void saveImage();
    void checkPressing(sf::Color color);


};

#endif //PIXELARTMAKER_PATTERN_H
