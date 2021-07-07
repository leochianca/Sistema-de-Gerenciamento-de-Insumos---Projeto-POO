#include "Vacina.h"

Vacina::Vacina() {}

//Construtor que inicia os atributos
Vacina::Vacina(int tipo, string nome, string nomeF, string data, int quant, float valor, int quantD, string inter, string tec)
: Insumo(tipo, nome, nomeF, data, quant, valor)
{
    quantidadeDoses = quantD;
    intervalo = inter;
    tecnologia = tec;
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

//Salvar no arquivo
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