#include <algorithm>

int* bubblesort(int array[]);
const int pixs = 2000;
int ind = 0;
int limit = pixs -1;
int midpt = (pixs + ind)/2;
const int begin = 0;
const int end = pixs;

struct
{
    int posx[pixs];
    int heighty[pixs];
}line;

void merge(int array[], const int begin, const int mid, const int end);
void mergesort(int array[], const int begin, const int end, sf::RenderWindow& window, sf::RectangleShape rectangle);
void view(sf::RenderWindow& window, sf::RectangleShape rectangle, int ind);

