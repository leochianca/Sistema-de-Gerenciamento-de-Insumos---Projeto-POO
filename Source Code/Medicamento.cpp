#include "Medicamento.h"

Medicamento::Medicamento() {}

//Construtor que inicia os atributos
Medicamento::Medicamento(int tipo, string nome, string nomeF, string data, int quant, float valor, string dos, string adm, string disp)
: Insumo(tipo, nome, nomeF, data, quant, valor)
{
    dosagem = dos;
    administracao = adm;
    disponibilizacao = disp;
}


//Retorna a descrição
string Medicamento::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Dosagem: " + dosagem + "\nAdministracao: " + administracao +
                       "\nDisponibilizacao: " + disponibilizacao + "\n\n";

    return descricao;
}

//Salvar no arquivo
void Medicamento::salvarInsumos(ofstream &fp)
{
    Insumo::salvarInsumos(fp);
    
    fp << dosagem << endl
       << administracao << endl
       << disponibilizacao << endl
       << endl;
}

//Sets
void Medicamento::setDosagem(string dosagem)
{
    this->dosagem = dosagem;
}
void Medicamento::setAdministracao(string administracao)
{
    this->administracao = administracao;
}
void Medicamento::setDisponibilizacao(string disponibilizacao)
{
    this->disponibilizacao = disponibilizacao;
}

//Gets
string Medicamento::getDosagem()
{
    return dosagem;
}
string Medicamento::getAdministracao()
{
    return administracao;
}
string Medicamento::getDisponibilizacao()
{
    return disponibilizacao;
}