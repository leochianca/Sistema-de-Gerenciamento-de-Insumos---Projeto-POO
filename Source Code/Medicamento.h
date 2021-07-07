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
		Medicamento(int, string, string, string, int, float, string, string, string);

		void setDosagem(string);
		void setAdministracao(string);
		void setDisponibilizacao(string);

		string getDosagem();
		string getAdministracao();
		string getDisponibilizacao();

		void salvarInsumos(ofstream &fp);
		
		string getDescricao();
};