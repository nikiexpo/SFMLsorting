#include <iostream>
#include "include/SFML/Graphics.hpp"
#include "sort.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(pixs,600),"Sorting");

    srand(time(NULL));

    for (int i = 0; i < pixs; i++)
    {
        int high = 1 + rand()%(600);
        line.posx[i] = i;
        line.heighty[i] = high;

    }
    sf::Texture texture;
    texture.loadFromFile("download.png");
    sf::Sprite sprite(texture);
    
    sf::RectangleShape rectangle(sf::Vector2f(2, 120)); //initialize with random height
    rectangle.setFillColor(sf::Color(235,39,45));
    std::cout<<line.heighty[0]<<std::endl;

    while(window.isOpen())
    {
         sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){window.close();}

        }
       // mergesort 
       int curr_size =1;
       int left_start;

       
        while(curr_size<=pixs-1)
       {
            for(left_start=0;left_start<pixs-1;left_start+=2*curr_size)
            {
                int mid = std::min(left_start + curr_size -1, pixs-1);
                int right_end = std::min(left_start + 2*curr_size -1, pixs-1);

                merge(line.heighty, left_start, mid, right_end);
            
                window.clear(sf::Color::Black);
                window.draw(sprite);

                for(int i = 0; i < pixs; i++)
                {
                    rectangle.setFillColor(sf::Color(235,39,45));
                    rectangle.setPosition(line.posx[i], 600);
                    rectangle.setSize(sf::Vector2f(2,line.heighty[i]));
                    rectangle.setRotation(180); // invert the rectangle
                    window.draw(rectangle);
                    
                }

                window.display();
            }
            curr_size = 2*curr_size;
       }


    }
    std::cout<<line.heighty[0]<<std::endl;
    return 0;
}

// help from geeksforgeeks
void merge(int array[], const int begin, const int mid, const int end)
{
    // number of positions 
    int const sizeArray1 = mid - begin + 1;
    int const sizeArray2 = end - mid;

    // initializing array indicies

    int indexArray1 = 0,
        indexArray2 = 0,
        indexArray = begin;

    // temporary arrays
    int *leftArray = new int[sizeArray1],
        *rightArray = new int[sizeArray2]; // uses the same datatype prefix
    
    // copy data into temp arrays
    for(int i =0; i< sizeArray1; i++){leftArray[i] = array[begin+i];}
    for(int i =0; i<sizeArray2; i++){rightArray[i] = array[mid+i+1];}

    while (indexArray1 < sizeArray1 && indexArray2 < sizeArray2)
    {
        if(leftArray[indexArray1]<= rightArray[indexArray2])
        {
            array[indexArray] = leftArray[indexArray1];
            indexArray1++;
        }
        else 
        {
            array[indexArray] = rightArray[indexArray2];
            indexArray2++;
        }
        indexArray++;
    }

    // copying the remaining elements
    // left
    while(indexArray1<sizeArray1)
    {
        array[indexArray] = leftArray[indexArray1];
        indexArray1++;
        indexArray++;
    }
    // right
    while (indexArray2<sizeArray2)
    {
        array[indexArray] = rightArray[indexArray2];
        indexArray2++;
        indexArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
    
}


