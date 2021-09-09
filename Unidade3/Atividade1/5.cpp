#include <iostream>
using std::cout;
using std::endl;

int main(void){
  for (int i = 33; i <= 126; i++){
    cout << i << ": ";
    char ascii = i;
    cout << ascii << endl;
  }
  
  return 0;
}