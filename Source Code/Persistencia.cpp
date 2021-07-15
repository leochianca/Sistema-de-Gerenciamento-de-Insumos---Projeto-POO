#include "Persistencia.h"

Persistencia::Persistencia(){}

//Ler e salvar no arquivo
void Persistencia::lerArquivo(Controler &control)
{
    ifstream fp("insumos.txt");
    Insumo* insumo;

    //Atributos comuns
    string nomeLocal, nomeProduto, nomeFabricante, dataVencimento;
    int tipo, quantidadeItens;
    float valorUnitario;

    //Atributos vacina
    int quantidadeDoses;
    string tecnologia, intervalo = "";

    //Atributos medicamento
    string dosagem, administracao, disponibilizacao;

    //Atributos epi
    string descricaoEpi, tipoEpi;

    if(!fp.good())
    {
        return;
    }
    else
    {
        while(fp >> nomeLocal >> tipo)
        {
            fp.ignore();
            getline(fp, nomeProduto);
            getline(fp, nomeFabricante);
            fp >> dataVencimento >> quantidadeItens >> valorUnitario;

            switch(tipo)
            {
                case 1: getline(fp.ignore(), tecnologia);
                        fp >> quantidadeDoses;

                        if(quantidadeDoses > 1)
                                getline(fp.ignore(), intervalo);

                        insumo = new Vacina(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, quantidadeDoses, intervalo, tecnologia);
                        break;

                case 2: getline(fp.ignore(), dosagem);
                        getline(fp, administracao);
                        getline(fp, disponibilizacao);
                        
                        insumo = new Medicamento(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, dosagem, administracao, disponibilizacao);
                        break;

                case 3: getline(fp.ignore(), descricaoEpi);
                        getline(fp, tipoEpi);

                        insumo = new Epi(tipo, nomeProduto, nomeFabricante, dataVencimento, quantidadeItens, valorUnitario, descricaoEpi, tipoEpi);
                        break;
            }
            
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
void Persistencia::salvarArquivo(vector<Insumo*> insumos, Local loc)
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