#include <iostream>

int sum(int &);

int main(void){
    int num = -1;

    std::cout << sum(num) << std::endl;
    std::cout << sum(num) << std::endl;
    std::cout << sum(num) << std::endl;
    

    return 0;
}

int sum(int & x){
    x = x+1;
    return x;
}