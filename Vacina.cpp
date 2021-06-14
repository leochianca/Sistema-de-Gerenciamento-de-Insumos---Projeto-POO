#include "Vacina.h"

Vacina::Vacina() {}

//Construtor que inicia o tipo
Vacina::Vacina(int tipo) : Insumo(tipo)
{
    quantidadeDoses = 0;
    intervalo = "";
    tecnologia = "";
}

//Retorna a descrição
string Vacina::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Tecnologia: " + tecnologia + "\nQuantidade de doses: " +
                       to_string(quantidadeDoses) + "\n";

    if (quantidadeDoses > 1)
        descricao += "Intervalo entre as doses: " + intervalo + "\n\n";
    else
        descricao += "\n";

    return descricao;
}

//Lê os atributos da entrada padrão
void Vacina::lerAtributos()
{
    Insumo::lerAtributos();

    cout << "\nDigite a quantidade de doses: ";
    cin >> quantidadeDoses;
    getchar();

    if (quantidadeDoses > 1)
    {
        cout << "\nDigite o intervalo entre as doses: ";
        getline(cin, intervalo);
    }

    cout << "\nDigite a tecnologia da vacina: ";
    getline(cin, tecnologia);
}

//Ler e salvar no arquivo
void Vacina::lerInsumos(ifstream &fp)
{
    Insumo::lerInsumos(fp);
    
    getline(fp.ignore(), tecnologia);
    fp >> quantidadeDoses;

    if(quantidadeDoses > 1)
        getline(fp.ignore(), intervalo);
}
void Vacina::salvarInsumos(ofstream &fp)
{   
    Insumo::salvarInsumos(fp);
    
    fp << tecnologia << endl << quantidadeDoses << endl;

    if (quantidadeDoses > 1)
        fp << intervalo << endl;

    fp << endl;
}

//Gets
int Vacina::getQuantidadeDoses()
{
    return quantidadeDoses;
}
string Vacina::getIntervalo()
{
    return intervalo;
}
string Vacina::getTecnologia()
{
    return tecnologia;
}

//Sets
void Vacina::setQuantidadeDoses(int quantidadeDoses)
{
    this->quantidadeDoses = quantidadeDoses;
}
void Vacina::setIntervalo(string intervalo)
{
    this->intervalo = intervalo;
}
void Vacina::setTecnologia(string tecnologia)
{
    this->tecnologia = tecnologia;
}