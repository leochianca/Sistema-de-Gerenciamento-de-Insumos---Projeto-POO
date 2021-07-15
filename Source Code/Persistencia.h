#include "Menu.h"

#pragma once

class Persistencia
{
    public:
        Persistencia();
        void lerArquivo(Controler&);
        void salvarArquivo(vector<Insumo*>, Local);
};