#include "Menu.h"
#include "Persistencia.h"

int main()
{
    Menu menu;
    Persistencia pers;

    pers.lerArquivo(menu.getControl());

    while (true)
    {
        menu.exibeMenu();

        int opcao, opcao2;

        cin >> opcao;
        system("CLS");

        if (opcao == 0)
            break;

        cout << "[1] - Confirmar\n" << "[2] - Voltar ao menu\n\n";
        cin >> opcao2;
        getchar();
        system("CLS");

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
        }
    }

    return 0;
}