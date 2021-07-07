#include "Menu.h"

int main()
{
    Menu menu;

    menu.lerArquivo();

    while (true)
    {
        menu.exibeMenu();

        int opcao, opcao2;

        cin >> opcao;
        system("clear");

        if (opcao == 0)
            break;

        cout << "[1] - Confirmar\n" << "[2] - Voltar ao menu\n\n";
        cin >> opcao2;
        getchar();
        system("clear");

        if(opcao2 == 1)
        {
            switch (opcao)
            {
                case 1:
                    menu.exibeMenu1();
                    break;

                case 2:
                    menu.exibeMenu2();
                    break;

                case 3:
                    menu.exibeMenu3();
                    break;

                case 4:
                    menu.exibeMenu4();
                    break;

                case 5:
                    menu.exibeMenu5();
                    break;

                case 6:
                    menu.exibeMenu6();
                    break;
                
                case 7:
                    menu.exibeMenu7();
                    break;
            }

            menu.voltarMenu();
        }
    }

    return 0;
}