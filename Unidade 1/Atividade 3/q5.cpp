#include <iostream>

using namespace std;


void swap(int & x, int & y);

int main()
{
    int x = 10, y = 20;
 
    cout << x << ' ' << y << endl;

    swap(x,y);

    cout << x << ' ' << y << endl;
    
    return 0;
}

void swap(int & x, int & y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}