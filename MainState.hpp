#ifndef PIXELARTMAKER_MAINSTATE_H
#define PIXELARTMAKER_MAINSTATE_H

#include "ColorPicker.hpp"
#include "Pattern.hpp"

class MainState{
public:

    ColorMatrix matrix;
    PatternMatrix pattern;
    sf::RenderWindow applicationWindow = sf::RenderWindow( sf::VideoMode( 900, 500, 32 ), "Pixel Art Maker" );
    MainState();
    void run();
    void render();

};

#endif
