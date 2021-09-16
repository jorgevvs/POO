#include <iostream>
using std::cout;

#include <cstring>
#include <string>
using std::string;

template < class T >
bool comparar(const T &a1, const T &a2){
    if(a1 == a2) return true;
    return false;
}


int main(){
    cout << "5 é igual a 5? " <<  comparar<int>(5,5) << std::endl;
    cout << "10 é igual a 5? " << comparar<int>(10,5) << std::endl;
    cout << "15.5 é igual a 15 + 0.5? " << comparar<double>(15.5, 15+0.5) << std::endl;

    cout << "'IFPB' == 'IFPB'? " << comparar<string>("IFPB", "IFPB") << std::endl;

    return 0;
}