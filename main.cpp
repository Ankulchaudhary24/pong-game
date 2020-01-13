#include <iostream>
#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"
#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;
int main()
{
    int windowWidth =1024;
    int windowHeight =768;

    RenderWindow window(VideoMode(windowWidth,windowHeight),"PONG");

    int score=0;
    int lives=3;

    Bat bat(windowWidth/2,3*windowHeight/4);

    Ball ball(windowWidth/2,1);

    Text hud;

    Font font;
    font.loadFromFile("DS-DIGIT.ttf");

    hud.setFont(font);

    hud.setCharacterSize(75);

    hud.setFillColor(sf::Color::White);

    while(window.isOpen())
    {

        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }

        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }

        else if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if(ball.getPosition().top > windowHeight)
        {
        ball.hitBottom();
        lives--;

        if(lives < 1){
            score=0;
            lives=3;
        }
    }

    if(ball.getPosition().top <0){
        ball.reboundBatOrTop();
        score++;
    }

    if(ball.getPosition().left<0 || ball.getPosition().left+10>windowWidth)
    {
      ball.reboundSides();
    }

    if(ball.getPosition().intersects(bat.getPosition()))
    {
        ball.reboundBatOrTop();
    }

    ball.update();
bat.update();

// Update the HUD text
std::stringstream ss;
ss << "Score:" << score <<setw(35)<< "Lives:" << lives;
hud.setString(ss.str());
 window.clear(Color(100, 0,2,255));

        window.draw(bat.getShape());

        window.draw(ball.getShape());

        // Draw our score
        window.draw(hud);

        // Show everything we just drew
        window.display();
    }
    return 0;
}
