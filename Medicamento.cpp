#include "Medicamento.h"

Medicamento::Medicamento() {}

//Construtor que inicia o tipo
Medicamento::Medicamento(int tipo) : Insumo(tipo)
{
    dosagem = "";
    administracao = "";
    disponibilizacao = "";
}

//Retorna a descrição
string Medicamento::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Dosagem: " + dosagem + "\nAdministracao: " + administracao +
                       "\nDisponibilizacao: " + disponibilizacao + "\n\n";

    return descricao;
}

//Lê os atributos da entrada padrão
void Medicamento::lerAtributos()
{
    Insumo::lerAtributos();

    cout << "\nDigite a dosagem do medicamento: ";
    getline(cin.ignore(), dosagem);

    cout << "\nDigite a forma de administracao: ";
    getline(cin, administracao);

    cout << "\nDigite a forma de disponibilizacao: ";
    getline(cin, disponibilizacao);
}

//Ler e salvar no arquivo
void Medicamento::lerInsumos(ifstream &fp)
{
    Insumo::lerInsumos(fp);

    getline(fp.ignore(), dosagem);
    getline(fp, administracao);
    getline(fp, disponibilizacao);
}
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