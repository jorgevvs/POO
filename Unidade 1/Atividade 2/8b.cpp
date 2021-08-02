#include <iostream>
int main()
{
    int i = 0;
    int j = 0; 

    for(int i = 5; i >= 1; --i){
        for(int j = 1; j <= i; ++j)
        {
           std:: cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}