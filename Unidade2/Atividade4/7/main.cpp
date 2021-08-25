#include "Imovel.h"
#include "ImovelNovo.h"
#include "ImovelVelho.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


int main(){

    Imovel imovel;
    imovel.setEndereco("Solon de Lucena");
    imovel.setPreco(1000.00);

    ImovelNovo novo("São José", 3125.56, 342.63);

    ImovelVelho velho("João Mendes", 2000.00, 500.00);

    cout << "Imóvel na rua " << imovel.getEndereco() << " valor: R$" << imovel.getPreco() << endl;

    cout << "\nImóvel novo na rua " << novo.getEndereco() << " tem adicional no preço de: R$" << novo.getAdicional() << " totalizando: R$" << novo.getPreco() << endl;

    cout << "\nImóvel velho na rua " << velho.getEndereco() << " tem desconto de R$" << velho.getDesconto() << " totalizando: R$" << velho.getPreco() << endl;


    return 0;
} // g++ -Wall -std=c++17 main.cpp Imovel.cpp ImovelNovo.cpp ImovelVelho.cpp -o main && ./main