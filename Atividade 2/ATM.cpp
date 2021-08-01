#include <iostream>

int main(void){
    std::cout << "\n\n       Welcome to VVS's Bank";
    std::cout << "\n------------------------------------";

    int accnum = 12345;
    int PIN = 54321;

    int accEnt = 0;
    int PINent = 0;

    int auth = 0; // 0 - Not Auth , 1 - Auth

    while (accEnt != accnum and PINent != PIN){
        std::cout << "\nPlease enter your account number: ";
        std::cin >> accEnt;
        
        std::cout << "Enter your PIN: ";
        std::cin >> PINent;
        std::cout << "---------------------------------------\n";
        if (accEnt != accnum and PINent != PIN){
            std::cout << "Invalid User";
        }
        else{
            auth = 1;
        }
    };
    if(auth == 1){

        int menuchoice = 0;

        std::cout << "Main Menu: \n";
        std::cout << "  1 - View my balance \n";
        std::cout << "  2 - Withdraw Cash \n";
        std::cout << "  3 - Deposit Funds\n";
        std::cout << "  4 - Exit\n";
        std::cout << "Enter a choice: ";

        std::cin >> menuchoice;
    }
    return 0;
}