#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <string>
using std::string;


class HugeInteger
{
public:

    void input(string);

    void output();

    void add(HugeInteger);

    bool isEqualTo(HugeInteger);
    bool isNotEqualTo(HugeInteger);
    
    bool isGreaterThan(HugeInteger);
    bool isGreaterThanOrEqual(HugeInteger);

    bool isLessThan(HugeInteger);
    bool isLessThanOrEqual(HugeInteger);
    

private:
    char number[40];
    int size;
};

#endif