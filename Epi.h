#include "Insumo.h"

#pragma once

class Epi : public Insumo
{
	private:
		string descricaoEpi;
		string tipoEpi;

	public:
		Epi();
		Epi(int);

		void setDescricaoepi(string);
		void setTipoEpi(string);

		string getDescricaoepi();
		string getTipoEpi();

		void lerInsumos(ifstream &fp);
		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
		void lerAtributos();
};