#include "Huge.h"

#include <iostream>

#include <string>
using std::string;

void HugeInteger::input(string num){
    size = num.size();
    int k = 0;

    for(int i = size; i > 0; i--){
        if(!isdigit(num[i - 1])){
            number[0] = '0';
            return;
        }
    }
    for(int j = size; j > 0 ; j--){
        number[k] = num[j -1];
        k++;
    }
}
void HugeInteger::output(){
    for(int i = size; i > 0 ; i--){
        std::cout << number[i -1];
    }
    std::cout << std::endl;
}

void HugeInteger::add(HugeInteger num2){
    int greater = size > num2.size ? size: num2.size;
    int sum, rest = 0;

    for(int i = 0; i < greater; i++){
        sum = (number[i] - '0') + (num2.number[i] - '0') + rest;

        if(i < num2.size ){
            if(sum > 9){
            number[i] = '0' + (sum - 10);
            rest = 1;
            }else{
            number[i] = '0' + sum;
            rest = 0;
        }
        }
    }
    if(rest == 1){
        size ++;
        number[size - 1] = '0' + 1;
    }

    
}

bool HugeInteger::isEqualTo(HugeInteger num2){
    if(size != num2.size) return false;

    for(int i = 0; i < size; i++){
        if(number[i] != num2.number[i]) return false;
    }
    return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger num2){
    if(size != num2.size) return true;

    for(int i = 0; i < size; i++){
        if(number[i] != num2.number[i]) return true;
    }
    return false;
}

bool HugeInteger::isGreaterThan(HugeInteger num2){
    if(size > num2.size) return true;

    for(int i = 0; i < size; i++){
        if(number[i] > num2.number[i]) return true;
    }
    return false;
}

bool HugeInteger::isGreaterThanOrEqual(HugeInteger num2){
    if(size > num2.size) return true;

    for(int i = 0; i < size; i++){
        if(number[i] > num2.number[i]) return true;
    }
    if(isEqualTo(num2)) return true;
    return false;
}

bool HugeInteger::isLessThan(HugeInteger num2){
    if(size > num2.size) return false;

    for(int i = 0; i < size; i++){
        if(number[i] > num2.number[i]) return false;
    }
    if(isEqualTo(num2)) return false;
    return true;
}

bool HugeInteger::isLessThanOrEqual(HugeInteger num2){
    if(size > num2.size) return false;

    for(int i = 0; i < size; i++){
        if(number[i] > num2.number[i]) return false;
    }
    return true;
}