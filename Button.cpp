#include <SFML/Graphics.hpp>
#include "Button.hpp"

circleButton::circleButton() {}
rectangleButton::rectangleButton() {}
circleButton::~circleButton() {}
rectangleButton::~rectangleButton() {}
Button::~Button() {}

circleButton::circleButton( float radius, sf::Vector2f position,sf::Color normal, sf::Color hover, sf::Color pressed, sf::Text text, std::string textString){
this->position = position;
this->size = size;

circleShape = sf::CircleShape ( radius ) ;
circleShape.setFillColor( normal );
circleShape.setPosition( position );

this->pressed = pressed;
this->normal = normal;
this->hover = hover;

this->text = text;
this->text.setString(textString);
this->text.setPosition( position );
this->texture = texture;

// DEFAULT (NORMAL) TEXT COLOR
this->text.setFillColor(sf::Color(200, 200, 200));

// SET BUTTON STATE
button_state = DEFAULT;

}
rectangleButton::rectangleButton(sf::Vector2f size, sf::Vector2f position,sf::Color normal, sf::Color hover, sf::Color pressed, sf::Text text,  std::string textString ){
this->position = position;
this->size = size;

rectangleShape = sf::RectangleShape( size ) ;
rectangleShape.setFillColor( normal );
rectangleShape.setPosition( position );

this->pressed = pressed;
this->normal = normal;
this->hover = hover;

this->text = text;
this->text.setString(textString);
this->text.setPosition( centerTextPosition() );

// DEFAULT (NORMAL) BUTTON COLOR
this->text.setFillColor(sf::Color(200, 200, 200));

// SET BUTTON STATE
button_state = DEFAULT;

}

void Button::changeHoverColor(sf::Color color) {
    this->hover = color;
}

void Button::changeNormalColor(sf::Color color) {
    this->normal = color;
}

bool Button::isPressed(){

    if( button_state == PRESSED  )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Button::rightPressed(){
    if( sf::Mouse::isButtonPressed( sf::Mouse::Right ) && button_state == HOVER ){
        return true;
    }
    else{
        return false;
    }
}

sf::Vector2f Button::centerTextPosition() {
    float posX = this->position.x + this->size.x/2 -  (this->text.getGlobalBounds().width - this->text.getGlobalBounds().left)/2 ;
    float posY = this->position.y + this->size.y/2 -  (this->text.getGlobalBounds().height + this->text.getGlobalBounds().top)/2 ;

    return sf::Vector2f(posX, posY);
}

sf::Color Button::getColor() {
    return this->normal;
}

void rectangleButton::render(sf::RenderWindow &target){
        target.draw(rectangleShape);
        target.draw(text);
}

void circleButton::render(sf::RenderWindow &target){

    target.draw(circleShape);
    target.draw(text);
}

void circleButton::updateColor(sf::Vector2i mousePos){
    button_state = DEFAULT;
    if( circleShape.getGlobalBounds().contains( sf::Vector2f (mousePos) ) ){
        button_state = HOVER;
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left )  )
        {
            button_state = PRESSED;
        }
    }

    switch (button_state){
        case DEFAULT:
            circleShape.setFillColor(normal);
            break;

        case PRESSED:
            circleShape.setFillColor(pressed);
            break;

        case HOVER:
            circleShape.setFillColor(hover);
            break;
    }
}

void rectangleButton::updateColor(sf::Vector2i mousePos){
    button_state = DEFAULT;
    if( rectangleShape.getGlobalBounds().contains( sf::Vector2f (mousePos) ) ){
        button_state = HOVER;
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left )  )
        {
            button_state = PRESSED;
        }
    }

    switch (button_state){
        case DEFAULT:
            rectangleShape.setFillColor(normal);
            break;

        case PRESSED:
            rectangleShape.setFillColor(pressed);
            break;

        case HOVER:
            rectangleShape.setFillColor(hover);
            break;
    }
}

void circleButton::updateColor(sf::Color color) {
    circleShape.setFillColor(color);
    normal = color;
}

void rectangleButton::updateColor(sf::Color color) {
    rectangleShape.setFillColor(color);
    normal = color;
}

