#include <iostream>
using std::cout;
using std::cin;
using std::endl;

using std::defaultfloat;
using std::fixed;

using std::right;
using std::left;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <fstream>
using std::fstream;
using std::ios;

#include <string>
using std::string;

struct REGISTRO{
    int num;
    string nome;
    int quant;
    double preco;
};

REGISTRO registros[8] = {
  {3,  "Lixadeira",         7,      57.98},
  {17, "Martelo",           76,     11.99 },
  {24, "Serra Tico-Tico",   21,     11.00},
  {39, "Cortador de grama", 3,      79.50},
  {56, "Serra Eletrica",    18,     99.99},
  {68, "Chave de fenda",    106,    6.99},
  {77, "Marreta",           11,     21.50},
  {83, "Chave Inglesa",     34,     7.50},
};


bool listarFerramentas(fstream &f){
  REGISTRO c;

  cout << " N DO REGISTRO "
       << "      FERRAMENTA    "
       << "   QUANTIDADE  "
       << "   PREÇO (R$)" << endl;

  cout << fixed;
  f.clear();

  f.seekg(0);
  while (true){
    f.read(reinterpret_cast<char *>(&c), sizeof(REGISTRO));

    if (f.eof())
      break;

    if (c.num > 0)
      cout << setw(7) << c.num << ' ' << setw(24) << right << c.nome << setw(12) << right << setw(13) <<  c.quant << ' ' << setw(14) << right << setprecision(2) << c.preco << endl;

  }
  cout << defaultfloat;

  return true;
}

bool cadastrarFerramenta(fstream &f, REGISTRO &c){
    f.clear();

    f.seekp(c.num * sizeof(REGISTRO));

    f.write(reinterpret_cast<char *>(&c), sizeof(REGISTRO));

    f.flush();

    return true;
}

bool removerFerramenta(fstream &f, int registro){
    REGISTRO c;

    f.clear();

    int linha = 0;
    bool achou = false;

    f.seekg(0);
    while (true){
        f.read(reinterpret_cast<char *>(&c), sizeof(REGISTRO));

        if (f.eof())
        break;

        if (registro == c.num)
        {
        achou = true;
        break;
        }

        linha += 1;
  }

    f.seekp(linha * sizeof(REGISTRO));

    if (achou == true)
    {
        c.num = -1;
        f.write(reinterpret_cast<char *>(&c), sizeof(REGISTRO));
        f.flush();
    }

    return true;
}

void initialize(){
    FILE *cfPtr; 
    cfPtr = fopen("hardware.dat", "w");

    
    for (int i=0;i<101;i++){
        REGISTRO vazio = {i, "", 0, 0.0};
        fwrite (&vazio, sizeof(REGISTRO), 1, cfPtr);
    }

    fclose(cfPtr);
}


int main(){
    initialize();

    fstream fileIO("hardware.dat", std::ios::out | std::ios::in);

    for(int i = 0 ; i < 8; i++){
        cadastrarFerramenta(fileIO, registros[i]);
    }

    if (!fileIO)
        return 1;

    while (1)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Ferramentas." << endl;
        cout << "Opções:" << endl;
        cout << "0 - Listar Todos as ferramentas" << endl;
        cout << "1 - Cadastrar nova ferramenta" << endl;
        cout << "2 - Remover ferramenta" << endl;
        cout << endl
            << "-1 - Sair" << endl;
        cout << "Op: ";

        int op;
        cin >> op;

        switch (op){
        case 0:
        listarFerramentas(fileIO);
        break;

        case 1:{
            REGISTRO c;

            cout << "Cadastrando nova Ferramenta..." << endl;
            cout << "Numero do Registro: ";
            cin >> c.num;
            cout << "Nome: ";
            cin >> c.nome;
            cout << "Quantidade: ";
            cin >> c.quant;
            cout << "Preco: ";
            cin >> c.preco;

            removerFerramenta(fileIO, c.num);
            cadastrarFerramenta(fileIO, c);

            break;
        }
        case 2:{

            int num;
            cout << "Entre com o num do registro: ";
            cin >> num;
            removerFerramenta(fileIO, num);

            REGISTRO c = {num, "" , 0, 0.0};

            cadastrarFerramenta(fileIO, c);

            break;
        }

        case -1:
            fileIO.close();
            exit(0);
        break;

        default:
        break;

        return 0;
        }
    }
}