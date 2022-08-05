#include <iostream>
#include "include/SFML/Graphics.hpp"
#include "sort.h"




int main(){

    sf::RenderWindow window(sf::VideoMode(pixs,600),"Sorting");

    srand(time(NULL));

    for (int i = 0; i < pixs; i++)
    {
        int high = 1 + rand()%(600);
        line.posx[i] = i;
        line.heighty[i] = high;

    }
    // std::cout << line.heighty[32] << std::endl;

    sf::Texture texture;
    texture.loadFromFile("download.png");
    sf::Sprite sprite(texture);
    
    sf::RectangleShape rectangle(sf::Vector2f(2, 120)); //initialize with random height
    rectangle.setFillColor(sf::Color(235,39,45));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){window.close();}

        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        for(int i = 0; i < pixs; i++)
        {
            rectangle.setFillColor(sf::Color(235,39,45));
            if (i == ind)
            {
                rectangle.setFillColor(sf::Color::Green);
            }
            
            rectangle.setPosition(line.posx[i], 600);
            rectangle.setSize(sf::Vector2f(2,line.heighty[i]));
            rectangle.setRotation(180); // i assume to invert the order
            window.draw(rectangle);
            
        }

        /*Finish up the logic for bubble sort*/
        

        window.display();
        if (line.heighty[ind]<line.heighty[ind+1])
        {
            std::swap(line.heighty[ind], line.heighty[ind+1]);
        }
        ind++;

        if (ind>=limit)
        {
            ind =0;
            limit--;
        }
            
    }

    return 0;
}