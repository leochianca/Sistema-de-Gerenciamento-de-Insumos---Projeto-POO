#include "Insumo.h"

#pragma once

class Epi : public Insumo
{
	private:
		string descricaoEpi;
		string tipoEpi;

	public:
		Epi();
		Epi(int, string, string, string, int, float, string, string);


		void setDescricaoepi(string);
		void setTipoEpi(string);

		string getDescricaoepi();
		string getTipoEpi();
		
		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
};