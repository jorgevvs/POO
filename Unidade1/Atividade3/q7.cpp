#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void minum(char * );

int main()
{
    char str[] = "O DinHeiro Não TrAz FELICIDADE";

    minum(str);

    cout << str << endl;

    return 0;
}

void minum(char * str){
    int i = 0;
    while(str[i])
    {
        if(str[i] == std::toupper(str[i]) && std::isalpha(str[i]) == 1024)
        str[i]+= 32;
        ++i;
    }
}