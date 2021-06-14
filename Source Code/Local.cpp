#include "Local.h"

Local::Local()
{
    nomeLocal = "";
}

//Sets
void Local::setInsumo(Insumo *insu)
{
    insumos.push_back(insu);
}
void Local::setNome(string nome)
{
    nomeLocal = nome;
}

//Gets
vector<Insumo *> Local::getInsumo()
{
    return insumos;
}
string Local::getNome()
{
    return nomeLocal;
}

//Exclui o insumo do vector
void Local::excluirInsumo(Insumo* insu)
{
    for(int i = 0; i < insumos.size(); i++)
    {
        if(insumos[i]->getNomeProduto() == insu->getNomeProduto())
           {
               delete insumos[i];
               insumos.erase(insumos.begin() + i);
               return;
           }
    }
}