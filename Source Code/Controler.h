#include "Local.h"

#pragma once

class Controler
{
	private:
		Local locais[28];

	public:
		Controler();

		Local& getLocal(int);

		void cadastraInsumos(Insumo*, int);

		void consultaInsumos(Local);
		void consultaInsumosDescricao(Local);
		void consultaInsumosTipo(Local, int tipo);

		vector<Insumo *> retornaInsumos(Local);

		void distribuiInsumos(int, string);
		void apagaInsumo(Local&, Insumo*);
};