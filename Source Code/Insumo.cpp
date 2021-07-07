#include "Insumo.h"
#include <sstream>

Insumo::Insumo() {}

//Construtor que inicia os atributos
Insumo::Insumo(int tipo, string nome, string nomeF, string data, int quant, float valor)
{
    tipoInsumo = tipo;
    nomeProduto = nome;
    nomeFabricante = nomeF;
    dataVencimento = data;
    quantidadeItens = quant;
    valorUnitario = valor;
}


//Retorna a descrição
string Insumo::getDescricao()
{
    
    stringstream sstream;

    sstream << valorUnitario;

    string valor = sstream.str();
    
    string descricao = "Nome: " + nomeProduto + "\nData de vencimento: " + dataVencimento + "\nNome do fabricante: " + nomeFabricante +
                       "\nQuantidade de itens: " + to_string(quantidadeItens) + "\nValor unitario: R$ " + valor + "\nTipo do insumo: " + 
                       to_string(tipoInsumo) + "\n";

    return descricao;
}

//Retorna nome e quantidade
string Insumo::getConsulta()
{
    string consulta = "Nome: " + nomeProduto + "\nQuantidade de itens: " + to_string(quantidadeItens) + "\n\n";

    return consulta;
}

//Gets
string Insumo::getNomeProduto()
{
    return nomeProduto;
}
string Insumo::getDataVencimento()
{
    return dataVencimento;
}
string Insumo::getNomeFabricante()
{
    return nomeFabricante;
}
float Insumo::getValorUnitario()
{
    return valorUnitario;
}
int Insumo::getQuantidadeItens()
{
    return quantidadeItens;
}
int Insumo::getTipo()
{
    return tipoInsumo;
}

//Sets
void Insumo::setNomeProduto(string nome)
{
    nomeProduto = nome;
}
void Insumo::setDataVencimento(string data)
{
    dataVencimento = data;
}
void Insumo::setNomeFabricante(string nomeF)
{
    nomeFabricante = nomeF;
}
void Insumo::setValorUnitario(float valor)
{
    valorUnitario = valor;
}
void Insumo::setQuantidadeItens(int quantidade)
{
    quantidadeItens = quantidade;
}

//Adiciona quantidade
void Insumo::addQuantidadeItens(int quantidade)
{
    quantidadeItens += quantidade;
}

//Salvar no arquivo
void Insumo::salvarInsumos(ofstream &fp)
{
    fp << tipoInsumo << endl << nomeProduto
       << endl << nomeFabricante  << endl 
       << dataVencimento << endl << quantidadeItens 
       << endl << valorUnitario << endl;
}