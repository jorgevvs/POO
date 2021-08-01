#include <iostream>
#include <string>
#include <algorithm>


int main()
{
    std::string s1 = "Uma string qualquer";

    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '?'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), ';'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), ','), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '.'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '!'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), ':'), s1.end());
    s1.erase(remove(s1.begin(), s1.end(), '-'), s1.end());
        
    std::cout << s1 << std::endl;
 return 0;
}
