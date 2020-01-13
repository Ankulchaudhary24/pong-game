#include "bat.h"

Bat::Bat(float startX,float startY)
{
    position.x=startX;
    position.y=startY;

    batShape.setSize(sf::Vector2f(50,5));
    batShape.setPosition(position);
}

    FloatRect Bat::getPosition()
    {
        return batShape.getGlobalBounds();
    }

    RectangleShape Bat::getShape()
    {
        return batShape;
    }

    void Bat::moveLeft()
    {
        position.x-=batSpeed;
        if(position.x<0){
            position.x=0;
        }
    }

    void Bat::moveRight()
    {
        position.x+=batSpeed;
                if(position.x>973){
            position.x=973;
        }
    }

    void Bat::update()
    {
        batShape.setPosition(position);
    }

