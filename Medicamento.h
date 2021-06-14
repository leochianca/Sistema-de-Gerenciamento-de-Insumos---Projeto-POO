#include "Insumo.h"

#pragma once

class Medicamento : public Insumo
{
	private:
		string dosagem;
		string administracao;
		string disponibilizacao;

	public:
		Medicamento();
		Medicamento(int);

		void setDosagem(string);
		void setAdministracao(string);
		void setDisponibilizacao(string);

		string getDosagem();
		string getAdministracao();
		string getDisponibilizacao();

		void lerInsumos(ifstream &fp);
		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
		void lerAtributos();
};