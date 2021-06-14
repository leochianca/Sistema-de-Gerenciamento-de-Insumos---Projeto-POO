#include "Controler.h"
#include "Menu.h"

//Construtor que inicia os nomes dos locais em ordem alfabetica
Controler::Controler()
{
    locais[0].setNome("MDS");
    locais[1].setNome("AC");
    locais[2].setNome("AL");
    locais[3].setNome("AP");
    locais[4].setNome("AM");
    locais[5].setNome("BA");
    locais[6].setNome("CE");
    locais[7].setNome("DF");
    locais[8].setNome("ES");
    locais[9].setNome("GO");
    locais[10].setNome("MA");
    locais[11].setNome("MT");
    locais[12].setNome("MS");
    locais[13].setNome("MG");
    locais[14].setNome("PA");
    locais[15].setNome("PB");
    locais[16].setNome("PR");
    locais[17].setNome("PE");
    locais[18].setNome("PI");
    locais[19].setNome("RJ");
    locais[20].setNome("RN");
    locais[21].setNome("RS");
    locais[22].setNome("RO");
    locais[23].setNome("RR");
    locais[24].setNome("SC");
    locais[25].setNome("SP");
    locais[26].setNome("SE");
    locais[27].setNome("TO");
}

//Retorna o local
Local& Controler::getLocal(int index)
{
    return locais[index];
}

//Cadastra os insumos no local do indice [index]
void Controler::cadastraInsumos(Insumo* insu, int index)
{
    if (!retornaInsumos(locais[index]).empty())
    {
        for (int i = 0; i < retornaInsumos(locais[index]).size(); i++)
        {
            if (insu->getNomeProduto() == retornaInsumos(locais[index])[i]->getNomeProduto())
            {
                cout << "\n***Insumo ja encontrado***\n"
                     << "Adicionando quantidade...\n";

                retornaInsumos(locais[index])[i]->addQuantidadeItens(insu->getQuantidadeItens());

                return;
            }
        }
    }

    locais[index].setInsumo(insu);
}

//Consulta os insumos do local passado
void Controler::consultaInsumos(Local loc)
{
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        cout << retornaInsumos(loc)[i]->getConsulta();
    }
}

//Consulta a descrição dos insumos do local passado
void Controler::consultaInsumosDescricao(Local loc)
{
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        cout << retornaInsumos(loc)[i]->getDescricao();
    }
}

//Consulta os insumos por tipo do local passado
void Controler::consultaInsumosTipo(Local loc, int tipo)
{
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        if (retornaInsumos(loc)[i]->getTipo() == tipo)
        {
            cout << retornaInsumos(loc)[i]->getDescricao();
        }
    }
}

//retorna a lista de insumos do local passado
vector<Insumo *> Controler::retornaInsumos(Local loc)
{
    return loc.getInsumo();
}

//Distribui insumos do Ministerio da Saude para o local do indice [index]
void Controler::distribuiInsumos(int index, string nome)
{
    Insumo* insumo;
    Menu menu;
    int quant, estoque;
    bool flag = false;

    for (int i = 0; i < retornaInsumos(locais[0]).size(); i++)
    {
        if (retornaInsumos(locais[0])[i]->getNomeProduto() == nome)
        {
            flag = true;
            cout << "\n***Achou INSUMO***\n\n"
                 << "\nDigite a quantidade a ser distribuida: ";
            cin >> quant;

            estoque = retornaInsumos(locais[0])[i]->getQuantidadeItens();

            if (estoque < quant)
            {
                cout << "\n***Quantidade indisponivel***\n";
            }
            else
            {

                insumo = retornaInsumos(locais[0])[i];
                insumo->setQuantidadeItens(quant);

                cout << "\nDistribuindo...\n";

                cadastraInsumos(menu.criacaoInsumoES(insumo), index);

                retornaInsumos(locais[0])[i]->setQuantidadeItens(estoque - quant);

                if(retornaInsumos(locais[0])[i]->getQuantidadeItens() == 0)
                    apagaInsumo(locais[0], retornaInsumos(locais[0])[i]);

                return;
            }
        }
    }

    if (!flag)
    {
        cout << "\n***Insumo nao encontrado***\n";
        return;
    }
}

//Apaga o insumo passado como parametro do local passado como parametro
void Controler::apagaInsumo(Local &loc, Insumo* insu)
{
    loc.excluirInsumo(insu);
}