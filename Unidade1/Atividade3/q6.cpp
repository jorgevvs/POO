#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool upper(char * );

int main()
{
    char str[] = "o dinheiro não traz felicidade";
    char str2[] = "O dinheiro Não Traz Felicidade";

    cout << upper(str) << endl;
    cout << upper(str2) << endl;

    return 0;
}

bool upper(char * str){
    int i = 0;
    while(str[i])
    {
        if(isupper(str[i]))
        return true;
        ++i;
    }
    return false;
} // função retorna 0 se não houver letra maiuscula e 1 se houver;