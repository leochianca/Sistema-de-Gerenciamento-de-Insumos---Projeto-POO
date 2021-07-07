#include "Insumo.h"

#pragma once

class Vacina : public Insumo
{
	private:
		int quantidadeDoses;
		string intervalo;
		string tecnologia;

	public:
		Vacina();
		Vacina(int, string, string, string, int, float, int, string, string);

		void setQuantidadeDoses(int);
		void setIntervalo(string);
		void setTecnologia(string);

		int getQuantidadeDoses();
		string getIntervalo();
		string getTecnologia();

		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
};