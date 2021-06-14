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
		Vacina(int);

		void setQuantidadeDoses(int);
		void setIntervalo(string);
		void setTecnologia(string);

		int getQuantidadeDoses();
		string getIntervalo();
		string getTecnologia();

		void lerInsumos(ifstream &fp);
		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
		void lerAtributos();
};