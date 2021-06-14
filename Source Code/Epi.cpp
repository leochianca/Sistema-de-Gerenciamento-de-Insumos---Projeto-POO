#include "Epi.h"

Epi::Epi() {}

//Construtor que inicia o tipo
Epi::Epi(int tipo) : Insumo(tipo)
{
    descricaoEpi = "";
    tipoEpi = "";
}

//Retorna a descrição
string Epi::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Descricao: " + descricaoEpi + "\nTipo: " + tipoEpi + "\n\n";

    return descricao;
}

//Ler os atributos da entrada padrão
void Epi::lerAtributos()
{
    Insumo::lerAtributos();

    cout << "\nDigite o tipo do Epi: ";
    getline(cin.ignore(), tipoEpi);

    cout << "\nDigite a descricao do Epi: ";
    getline(cin, descricaoEpi);
}

//Ler e salvar no arquivo
void Epi::lerInsumos(ifstream &fp)
{
    Insumo::lerInsumos(fp);

    getline(fp.ignore(), descricaoEpi);
    getline(fp, tipoEpi);
}
void Epi::salvarInsumos(ofstream &fp)
{
    Insumo::salvarInsumos(fp);

    fp << descricaoEpi << endl
       << tipoEpi << endl << endl;
}

//Sets
void Epi::setDescricaoepi(string descricaoEpi)
{
    this->descricaoEpi = descricaoEpi;
}
void Epi::setTipoEpi(string tipoEpi)
{
    this->tipoEpi = tipoEpi;
}

//Gets
string Epi::getDescricaoepi()
{
    return descricaoEpi;
}
string Epi::getTipoEpi()
{
    return tipoEpi;
}