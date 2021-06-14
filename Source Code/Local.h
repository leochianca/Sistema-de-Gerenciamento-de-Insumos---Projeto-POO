#include "Insumo.h"
#include <vector>

#pragma once

class Local
{
	private:
		string nomeLocal;
		int indexLocal;
		vector<Insumo *> insumos;

	public:
		Local();

		void setInsumo(Insumo *);
		void setNome(string);

		vector<Insumo *> getInsumo();
		string getNome();

		void excluirInsumo(Insumo*);
};