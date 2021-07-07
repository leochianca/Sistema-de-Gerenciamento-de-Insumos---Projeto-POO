#include "Epi.h"

Epi::Epi() {}

//Construtor que inicia os atributos
Epi::Epi(int tipo, string nome, string nomeF, string data, int quant, float valor, string desc, string tipoE)
: Insumo(tipo, nome, nomeF, data, quant, valor)
{
    descricaoEpi = desc;
    tipoEpi = tipoE;
}


//Retorna a descrição
string Epi::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Descricao: " + descricaoEpi + "\nTipo: " + tipoEpi + "\n\n";

    return descricao;
}

//Salvar no arquivo
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