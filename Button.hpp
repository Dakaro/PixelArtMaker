#ifndef PIXELARTMAKER_BUTTON_H
#define PIXELARTMAKER_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button{
protected:

    enum BUTTON_STATES { DEFAULT = 0, PRESSED, HOVER };
    int button_state;

    sf::CircleShape circleShape;
    sf::RectangleShape rectangleShape;

    float radius;
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Color hover;
    sf::Color pressed;
    sf::Color normal;
    sf::Color disable;
    bool selected;
    bool active;

    sf::Text text;
    sf::Texture texture;
public:
    bool isPressed();
    ~Button();


};

class circleButton: public Button{
public:
    circleButton();
    ~circleButton();
    circleButton( float radius, sf::Vector2f position,sf::Color normal, sf::Color hover,sf::Color pressed,sf::Text text = sf::Text(), std::string textString = "");
    void render(sf::RenderWindow &target);
    void updateColor(sf::Vector2i mousePos);
    void updateColor(sf::Color color);
};

class rectangleButton: public Button{
public:
    rectangleButton();
    ~rectangleButton();
    rectangleButton(sf::Vector2f size, sf::Vector2f position,sf::Color normal,sf::Color hover, sf::Color pressed,sf::Text text = sf::Text(), std::string textString = "");
    void render(sf::RenderWindow &target);
    void updateColor(sf::Vector2i mousePos);
    void updateColor(sf::Color color);
};

#endif
