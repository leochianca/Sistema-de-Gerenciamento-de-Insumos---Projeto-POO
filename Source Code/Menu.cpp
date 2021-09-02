#include "Menu.h"
#include "Persistencia.h"
#include <algorithm>

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
        int tipo;
        char opcao, cadastrarNovamente = 'S';
        string nomeProduto;

        while(toupper(cadastrarNovamente) == 'S')
        {
                bool achouInsumo = false;
                
                cout << "Tipos de insumo disponiveis\n\n" << "[1] - Vacina\n"
                        << "[2] - Medicamento\n" << "[3] - Epi\n\n" << "Digite o tipo de insumo: ";
                cin >> tipo;
                getchar();

                system("CLS");

                if(tipo >= 1 && tipo <= 3)
                {
                        cout << "Digite o nome: ";
                        getline(cin, nomeProduto);

                        if(!control.retornaInsumos(control.getLocal(0)).empty())
                        {
                                for(int i=0; i<control.retornaInsumos(control.getLocal(0)).size(); i++)
                                {
                                        if(control.retornaInsumos(control.getLocal(0))[i]->getNomeProduto() == nomeProduto)
                                        {
                                                achouInsumo = true;
                                                
                                                cout << "\nInsumo ja encontrado\n" << "Deseja adicionar quantidade?[S/N] ";
                                                cin >> opcao;

                                                if(toupper(opcao) == 'S')
                                                {
                                                        int quant;
                                                        
                                                        cout << "\nDigite a quantidade: ";
                                                        cin >> quant;

                                                        cout << "\nAdicionando quantidade...\n";
                                                        control.retornaInsumos(control.getLocal(0))[i]->addQuantidadeItens(quant);
                                                }
                                                
                                                break;
                                        }
                                }
                        }
                        
                        if(!achouInsumo) control.cadastraInsumos(criacaoInsumo(tipo, nomeProduto), 0);
                }
                else cout << "***Tipo invalido***\n";

                cout << "\nDeseja cadastrar outro insumo?[S/N] ";
                cin >> cadastrarNovamente;
                system("CLS");
        }
}
void Menu::exibeMenu2()
{
        string nome;
        char consultaNovamente = 'S';

        while(toupper(consultaNovamente) == 'S')
        {
                bool achouLocal = false;
                
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                achouLocal = true;

                                if(control.retornaInsumos(control.getLocal(i)).empty()) cout << "***Este local nao tem insumos***\n\n";
                                else control.consultaInsumos(control.getLocal(i));
                        }
                }

                if(!achouLocal) cout << "***Local nao encontrado***\n\n";

                cout << "Deseja consultar outro local?[S/N] ";
                cin >> consultaNovamente;
                getchar();
                system("CLS");
        }
}
void Menu::exibeMenu3()
{
        string nome;
        char consultaNovamente = 'S';

        while(toupper(consultaNovamente) == 'S')
        {
                bool achouLocal = false;
                
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                achouLocal = true;

                                if(control.retornaInsumos(control.getLocal(i)).empty()) cout << "***Este local nao tem insumos***\n\n";
                                else control.consultaInsumosDescricao(control.getLocal(i));
                        }
                }

                if(!achouLocal) cout << "***Local nao encontrado***\n\n";

                cout << "Deseja consultar outro local?[S/N] ";
                cin >> consultaNovamente;
                getchar();
                system("CLS");
        }
}
void Menu::exibeMenu4()
{
        string nome;
        char consultaNovamente = 'S';
        int tipo;

        while(toupper(consultaNovamente) == 'S')
        {
                bool achouLocal = false;
                
                cout << "Digite o nome do local (UF do Estado ou Ministerio da Saude): ";
                getline(cin, nome);
                cout << endl;

                transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

                for (int i = 0; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {
                                achouLocal = true;

                                if(control.retornaInsumos(control.getLocal(i)).empty()) cout << "***Este local nao tem insumos***\n\n";
                                else
                                {
                                        cout << "Digite o tipo de insumo que deseja consultar: \n"
                                        << "\n[1] - Vacina\n" << "[2] - Medicamento\n" << "[3] - Epi\n" << endl;

                                        cin >> tipo;
                                        cout << endl;
                                        
                                        control.consultaInsumosTipo(control.getLocal(i), tipo);
                                }
                        }
                }

                if(!achouLocal) cout << "***Local nao encontrado***\n\n";

                cout << "Deseja consultar outro local?[S/N] ";
                cin >> consultaNovamente;
                getchar();
                system("CLS");
        }
}
void Menu::exibeMenu5()
{
        int quant;
        string nome, distribuir;
        char distribuiNovamente = 'S';

        while(toupper(distribuiNovamente) == 'S')
        {
                bool achouLocal = false, achouInsumo = false, temInsumo = false;
                
                cout << "Digite o nome do local (UF do Estado) que deseja distribuir os insumos: ";
                getline(cin, nome);

                transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

                for (int i = 1; i < 28; i++)
                {
                        if (control.getLocal(i).getNome() == nome)
                        {   
                                achouLocal = true;

                                cout << endl << "Os insumos disponiveis no Ministerio da Saude sao: \n" << endl;

                                control.consultaInsumos(control.getLocal(0));
                                
                                cout << "\nDigite o nome do insumo: ";
                                getline(cin, distribuir);

                                for(int k=0; k<control.retornaInsumos(control.getLocal(0)).size(); k++)
                                {
                                        if(control.retornaInsumos(control.getLocal(0))[k]->getNomeProduto() == distribuir) 
                                        {
                                                achouInsumo = true;

                                                cout << "Digite a quantidade a ser distribuida: ";
                                                cin >> quant;

                                                if(control.retornaInsumos(control.getLocal(0))[k]->getQuantidadeItens() < quant)
                                                {
                                                        cout << "\nQuantidade indisponivel\n";
                                                        break;
                                                }

                                                if(!control.retornaInsumos(control.getLocal(i)).empty())
                                                {
                                                        for(int j=0; j<control.retornaInsumos(control.getLocal(i)).size(); j++)
                                                        {
                                                                if(control.retornaInsumos(control.getLocal(i))[j]->getNomeProduto() == distribuir)
                                                                {
                                                                        temInsumo = true;
                                                                        cout << "\nInsumo ja encontrado\n" << "Adicionando quantidade...\n";
                                                                        control.retornaInsumos(control.getLocal(i))[j]->addQuantidadeItens(quant);
                                                                        control.retornaInsumos(control.getLocal(0))[k]->retiraQuantidadeItens(quant);
                                                                        break;
                                                                }
                                                        }
                                                }

                                                if(!temInsumo)
                                                {
                                                        cout << "\nDistribuindo...\n";
                                                        control.distribuiInsumos(i, distribuir, quant);
                                                }

                                                if(control.retornaInsumos(control.getLocal(0))[k]->getQuantidadeItens() == 0)
                                                        control.apagaInsumo(control.getLocal(0), control.retornaInsumos(control.getLocal(0))[k]);

                                                break;
                                        }
                                }

                                if(!achouInsumo)
                                {
                                        cout << "\nInsumo nao encontrado\n";
                                        break;
                                }
                        }
                }

                if(!achouLocal) cout << "\n***Local nao encontrado***\n";

                cout << "\nDeseja distribuir novamente?[S/N] ";
                cin >> distribuiNovamente;
                getchar();
                system("CLS");
        }
}
void Menu::exibeMenu6()
{
        string nome, nomeInsumo;
        char apagaNovamente = 'S';
        
        while(toupper(apagaNovamente) == 'S')
        {
                bool achouLocal = false, achouInsumo = false;
                
                cout << "Digite o nome do local (UF do Estado ou MDS): ";
                getline(cin, nome);

                transform(nome.begin(), nome.end(), nome.begin(), ::toupper);

                for(int i = 0; i < 28; i++)
                {
                        if(control.getLocal(i).getNome() == nome)
                        {
                                achouLocal = true;

                                if(control.retornaInsumos(control.getLocal(i)).empty())
                                {
                                        cout << "\n***Este local nao tem insumos***\n";
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
                                                        achouInsumo = true;

                                                        cout << "\nApagando...\n";
                                                        control.apagaInsumo(control.getLocal(i), control.retornaInsumos(control.getLocal(i))[j]); 

                                                        break;
                                                }
                                        }

                                        if(!achouInsumo) cout << "\n***Insumo nao encontrado***\n";
                                }

                                break;
                        }
                }

                if(!achouLocal) cout << "\n***Local nao encontrado***\n";

                cout << "\nDeseja apagar outro insumo?[S/N] ";
                cin >> apagaNovamente;
                getchar();
                system("CLS");
        }
}
void Menu::exibeMenu7()
{
        Persistencia pers;
        
        for(int i = 0; i < 28; i++)     pers.salvarArquivo(control.retornaInsumos(control.getLocal(i)), control.getLocal(i));

        cout << "Salvando...\n\n" << "Pressione Enter para voltar ao Menu\n";
        getchar();
        system("CLS");
}

//Cria um novo insumo para o Ministerio da Saude
Insumo* Menu::criacaoInsumo(int tipo, string nomeProduto)
{
        Insumo *insumo;

        //Atributos em comum
        string nomeFabricante, dataVencimento;
        int quantidadeItens;
        float valorUnitario;

        //Atributos Vacina
        int quantidadeDoses;
        string intervalo = "", tecnologia;

        //Atributos Medicamento
        string dosagem, administracao, disponibilizacao;

        //Atributos Epi
        string descricaoEpi, tipoEpi;

        cout << "\nDigite o nome do fabricante: ";
        getline(cin, nomeFabricante);

        cout << "\nDigite a data de vencimento: ";
        getline(cin, dataVencimento);

        cout << "\nDigite a quantidade de itens: ";
        cin >> quantidadeItens;

        cout << "\nDigite o valor unitario: ";
        cin >> valorUnitario;

        switch (tipo)
        {
        case 1: cout << "\nDigite a quantidade de doses: ";
                cin >> quantidadeDoses;
                getchar();

                if (quantidadeDoses > 1)
                {
                        cout << "\nDigite o intervalo entre as doses: ";
                        getline(cin, intervalo);
                }

                cout << "\nDigite a tecnologia da vacina: ";
                getline(cin, tecnologia);

                insumo = new Vacina(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, quantidadeDoses, intervalo, tecnologia);
                break;
        case 2: cout << "\nDigite a dosagem do medicamento: ";
                getline(cin.ignore(), dosagem);

                cout << "\nDigite a forma de administracao: ";
                getline(cin, administracao);

                cout << "\nDigite a forma de disponibilizacao: ";
                getline(cin, disponibilizacao);

                insumo = new Medicamento(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, dosagem, administracao, disponibilizacao);
                break;
        case 3: cout << "\nDigite o tipo do Epi: ";
                getline(cin.ignore(), tipoEpi);

                cout << "\nDigite a descricao do Epi: ";
                getline(cin, descricaoEpi);

                insumo = new Epi(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, descricaoEpi, tipoEpi);
                break;
        }

        return insumo;
}

//Retorna o endereço de control
Controler& Menu::getControl()
{
        return control;
}

//Faz uma copia de um insumo do Ministerio da Saude para distribuir
Insumo* Menu::criacaoInsumoES(Insumo* insumoMS)
{
        Insumo* insumo;

        switch (insumoMS->getTipo())
        {
                case 1: insumo = new Vacina( insumoMS->getTipo(), insumoMS->getNomeProduto(), insumoMS->getNomeFabricante(), insumoMS->getDataVencimento(),
                                             insumoMS->getQuantidadeItens(), insumoMS->getValorUnitario(), ((Vacina*)insumoMS)->getQuantidadeDoses(),
                                             ((Vacina*)insumoMS)->getIntervalo(), ((Vacina*)insumoMS)->getTecnologia() );

                        break;
                case 2: insumo = new Medicamento( insumoMS->getTipo(), insumoMS->getNomeProduto(), insumoMS->getNomeFabricante(), insumoMS->getDataVencimento(),
                                                  insumoMS->getQuantidadeItens(), insumoMS->getValorUnitario(), ((Medicamento*)insumoMS)->getDosagem(),
                                                  ((Medicamento*)insumoMS)->getAdministracao(), ((Medicamento*)insumoMS)->getDisponibilizacao() );

                        break;
                case 3: insumo = new Epi( insumoMS->getTipo(), insumoMS->getNomeProduto(), insumoMS->getNomeFabricante(), insumoMS->getDataVencimento(),
                                          insumoMS->getQuantidadeItens(), insumoMS->getValorUnitario(), ((Epi*)insumoMS)->getDescricaoepi(),
                                          ((Epi*)insumoMS)->getTipoEpi() );

                        break;
        }

        return insumo;
}