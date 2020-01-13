#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

class Ball
{
private:
    Vector2f position;
    RectangleShape ballShape;

    float xVelocity =.2f;
    float yVelocity =.2f;

public:
    Ball(float startX, float startY);
    FloatRect getPosition();

    RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update();
};
