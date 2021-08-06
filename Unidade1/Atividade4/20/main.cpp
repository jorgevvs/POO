#include "Cupom.h"
#include <iostream>

int main(void){
   Cupom novoCupom("Mouse Corsair","RGB 10000DPI",-5 , -130.00);
   
   std::cout << "\n==============================================" << std::endl;
   std::cout << "============== Loja do Jorgevvs ==============" << std::endl;
   std::cout << "==============================================" << std::endl;

   std::cout << "\nO produto " << novoCupom.getId() << " com " << novoCupom.getDesc() << " no valor de R$" << novoCupom.getPreco() << " está indisponível!!" << std::endl;

   std::cout << "\nModificando valores..." << std::endl;

   novoCupom.setId("Teclado HyperX");
   novoCupom.setDesc("Switch Blue");
   novoCupom.setPreco(300);
   novoCupom.setQuant(3);

   std::cout << "\nO produto " << novoCupom.getId() << " no valor de R$" << novoCupom.getPreco() << " está disponível!!" << std::endl;
   std::cout << "Sua compra de " << novoCupom.getQuant() << " items, terá o valor total de R$"<< novoCupom.calculaCupom() << std::endl;

   std::cout << "==============================================\n" << std::endl;

   std::cout << "Fazendo a compra de 10 produtos você receberá um desconto de 5% no valor de cada item!!!" << std::endl;

   std::cout << "\nAlterando quantidade...\n" << std::endl;

   novoCupom.setQuant(10);
   novoCupom.setPreco(novoCupom.getPreco() - (novoCupom.getPreco() * 0.05));

   std::cout << "Sua compra de " << novoCupom.getQuant() << " items, terá o valor total de R$"<< novoCupom.calculaCupom() << std::endl;

   std::cout << "\n============== Volte Sempre ==============" << std::endl;

   return 0;
} // g++ -Wall -std=c++17 main.cpp Cupom.cpp -o main && ./main