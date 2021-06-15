#include "Menu.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "Epi.h"

Menu::Menu()
{
}

//Controla a exibição dos menus no terminal
void Menu::exibeMenu()
{
        cout << "------Bem-vindo ao Sistema de Gerenciamento de Insumos------\n"
             << endl
             << "Digite o numero correspondente a operacao que deseja executar: \n"
             << endl
             << "[0] - Fechar Sistema" << endl
             << "[1] - Cadastrar insumos" << endl
             << "[2] - Consultar insumos disponiveis" << endl
             << "[3] - Consultar descricao dos insumos disponiveis" << endl
             << "[4] - Consultar insumos disponiveis por tipo" << endl
             << "[5] - Distribuir insumos" << endl
             << "[6] - Apagar insumos" << endl
             << "[7] - Salvar insumos" << endl
             << "---------------------------------------------------------------------------" << endl;
}
void Menu::exibeMenu1()
{
        int opcaoVoltar, tipo;

        do
        {
                cout << "Tipos de insumo disponiveis\n\n" << "[1] - Vacina\n"
                     << "[2] - Medicamento\n" << "[3] - Epi\n\n" << "Digite o tipo de insumo: ";
                cin >> tipo;
                getchar();

                system("CLS");

                if(tipo >= 1 && tipo <= 3)
                {
                        control.cadastraInsumos(criacaoInsumo(tipo), 0);
                }
                else
                {
                        cout << "***Tipo invalido***";
                }

                while(true)
                {
                        cout << "\n\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}
void Menu::exibeMenu2()
{
        string nome;
        int opcaoVoltar;
        bool flag = false;

        do
        {
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                flag = true;
                                
                                control.consultaInsumos(control.getLocal(i));
                        }
                }

                if(!flag)
                {
                        cout << "***Local nao encontrado***\n";
                }

                while(true)
                {
                        cout << "\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}
void Menu::exibeMenu3()
{
        string nome;
        int opcaoVoltar;
        bool flag = false;

        do
        {
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                flag = true;
                                
                                control.consultaInsumosDescricao(control.getLocal(i));
                        }
                }

                if(!flag)
                {
                        cout << "***Local nao encontrado***\n";
                }

                while(true)
                {
                        cout << "\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}
void Menu::exibeMenu4()
{
        string nome;
        int tipo, opcaoVoltar;
        bool flag = false;

        do
        {
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                flag = true;

                                cout << "Digite o tipo de insumo que deseja consultar: \n"
                                     << "\n[1] - Vacina\n" << "[2] - Medicamento\n" << "[3] - Epi\n" << endl;

                                cin >> tipo;
                                cout << endl;
                                
                                control.consultaInsumosTipo(control.getLocal(i), tipo);
                        }
                }

                if(!flag)
                {
                        cout << "***Local nao encontrado***\n";
                }

                while(true)
                {
                        cout << "\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}
void Menu::exibeMenu5()
{
        string nome, distribuir;
        int opcaoVoltar;
        bool flag = false;

        do
        {
                cout << "Digite o nome do local (UF do Estado) que deseja distribuir os insumos: ";
                getline(cin, nome);

                for (int i = 1; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {   
                                flag = true;

                                cout << endl << "Os insumos disponiveis no Ministerio da Saude sao: \n" << endl;

                                control.consultaInsumos(control.getLocal(0));
                                
                                cout << "\nDigite o nome do insumo: ";
                                getline(cin, distribuir);

                                control.distribuiInsumos(i, distribuir);
                        }
                }

                if(!flag)
                {
                        cout << "\n***Local nao encontrado***\n";
                }

                while(true)
                {
                        cout << "\n\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}
void Menu::exibeMenu6()
{
        string nome, nomeInsumo;
        int opcaoVoltar;
        bool flag = false, flag2 = false;
        
        do
        {
                cout << "Digite o nome do local (UF do Estado ou MDS): ";
                cin >> nome;
                getchar();
                
                for(int i = 0; i < 28; i++)
                {
                        if(control.getLocal(i).getNome() == nome)
                        {
                                flag = true;

                                if(control.retornaInsumos(control.getLocal(i)).empty())
                                {
                                        cout << "\n***Este local nao tem insumos***";
                                }
                                else
                                {
                                        cout << "\nOs insumos disponiveis no local sao: \n\n";

                                        control.consultaInsumos(control.getLocal(i));

                                        cout << "\nDigite o nome do insumo: ";
                                        getline(cin, nomeInsumo);

                                        for(int j = 0; j < control.retornaInsumos(control.getLocal(i)).size(); j++)
                                        {
                                                if(control.retornaInsumos(control.getLocal(i))[j]->getNomeProduto() == nomeInsumo)
                                                {
                                                     cout << "\nApagando...\n";
                                                     control.apagaInsumo(control.getLocal(i), control.retornaInsumos(control.getLocal(i))[j]); 
                                                     flag2 = true;
                                                     break;
                                                }
                                        }

                                        if(!flag2)
                                           cout << "\n***Insumo nao encontrado***\n";

                                        break;
                                }
                        }
                }

                if(!flag)
                   cout << "\n***Local nao encontrado***\n";

                while(true)
                {
                        cout << "\n\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                           cout << "\n***Opcao invalida***";
                }

        } while(opcaoVoltar);    
}
void Menu::exibeMenu7()
{
        int opcaoVoltar;

        do
        {
                for(int i = 0; i < 28; i++)
                {
                        salvarArquivo(control.retornaInsumos(control.getLocal(i)), control.getLocal(i));
                }

                cout << "Salvando...\n";

                while(true)
                {
                        cout << "\n\n[1] - Voltar ao menu\n";
                        cin >> opcaoVoltar;
                        
                        if(opcaoVoltar == 1)
                        {
                                opcaoVoltar = 0;
                                system("CLS");
                                break;
                        }
                        else
                        {
                                cout << "\n***Opcao invalida***";
                        }
                }

        } while (opcaoVoltar);
}

//Cria um novo insumo para o Ministerio da Saude
Insumo* Menu::criacaoInsumo(int tipo)
{
        Insumo *insumo;

        switch (tipo)
        {
        case 1:
                insumo = new Vacina(tipo);
                break;
        case 2:
                insumo = new Medicamento(tipo);
                break;
        case 3:
                insumo = new Epi(tipo);
                break;
        }

        insumo->lerAtributos();

        return insumo;
}

//Ler e salvar no arquivo
void Menu::lerArquivo()
{
    ifstream fp("insumos.txt");
    Insumo* insumo;
    string nomeLocal;
    int tipo;

    if(!fp.good())
    {
        return;
    }
    else
    {
        while(fp >> nomeLocal >> tipo)
        {
            fp.ignore();

            switch(tipo)
            {
                case 1: insumo = new Vacina(tipo);
                        break;
                case 2: insumo = new Medicamento(tipo);
                        break;
                case 3: insumo = new Epi(tipo);
                        break;
            }

            insumo->lerInsumos(fp);
            
            for(int i = 0; i < 28; i++)
            {
                if(control.getLocal(i).getNome() == nomeLocal)
                {
                    control.cadastraInsumos(insumo, i);
                    break;
                }
            }
        }
    }

    fp.close();
}
void Menu::salvarArquivo(vector<Insumo*> insumos, Local loc)
{
    ofstream fp;
    
    if(loc.getNome() == "MDS")
        fp.open("insumos.txt", ios::out);
    else
        fp.open("insumos.txt", ios::app);

    if(!fp.is_open())
    {
        cout << "*Arquivo nao foi aberto corretamente*" << endl;
        fp.close();
    }
    else
    {
        for(int i = 0; i < insumos.size(); i++)
        {
            fp << loc.getNome() << endl;

            insumos[i]->salvarInsumos(fp);
        }

        fp.close();
    }
}

//Faz uma copia de um insumo do Ministerio da Saude para distribuir
Insumo* Menu::criacaoInsumoES(Insumo* insumoMS)
{
        Insumo* insumo;

        switch (insumoMS->getTipo())
        {
                case 1:
                        insumo = new Vacina(insumoMS->getTipo());
                        insumo->setNomeProduto(insumoMS->getNomeProduto());
                        insumo->setNomeFabricante(insumoMS->getNomeFabricante());
                        insumo->setDataVencimento(insumoMS->getDataVencimento());
                        insumo->setQuantidadeItens(insumoMS->getQuantidadeItens());
                        insumo->setValorUnitario(insumoMS->getValorUnitario());
                        insumo->setValorUnitario(insumoMS->getValorUnitario());
                        ((Vacina *)insumo)->setQuantidadeDoses(((Vacina *)insumoMS)->getQuantidadeDoses());
                        ((Vacina *)insumo)->setIntervalo(((Vacina *)insumoMS)->getIntervalo());
                        ((Vacina *)insumo)->setTecnologia(((Vacina *)insumoMS)->getTecnologia());

                        break;
                case 2:
                        insumo = new Medicamento(insumoMS->getTipo());
                        insumo->setNomeProduto(insumoMS->getNomeProduto());
                        insumo->setNomeFabricante(insumoMS->getNomeFabricante());
                        insumo->setDataVencimento(insumoMS->getDataVencimento());
                        insumo->setQuantidadeItens(insumoMS->getQuantidadeItens());
                        insumo->setValorUnitario(insumoMS->getValorUnitario());
                        ((Medicamento *)insumo)->setDosagem(((Medicamento *)insumoMS)->getDosagem());
                        ((Medicamento *)insumo)->setAdministracao(((Medicamento *)insumoMS)->getAdministracao());
                        ((Medicamento *)insumo)->setDisponibilizacao(((Medicamento *)insumoMS)->getDisponibilizacao());

                        break;
                case 3:
                        insumo = new Epi(insumoMS->getTipo());
                        insumo->setNomeProduto(insumoMS->getNomeProduto());
                        insumo->setNomeFabricante(insumoMS->getNomeFabricante());
                        insumo->setDataVencimento(insumoMS->getDataVencimento());
                        insumo->setQuantidadeItens(insumoMS->getQuantidadeItens());
                        insumo->setValorUnitario(insumoMS->getValorUnitario());
                        ((Epi *)insumo)->setDescricaoepi(((Epi *)insumoMS)->getDescricaoepi());
                        ((Epi *)insumo)->setTipoEpi(((Epi *)insumoMS)->getTipoEpi());

                        break;
        }

        return insumo;
}
