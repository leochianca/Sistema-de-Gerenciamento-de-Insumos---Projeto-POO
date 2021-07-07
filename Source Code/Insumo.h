#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#pragma once

class Insumo
{
	protected:
		string nomeProduto;
		string dataVencimento;
		string nomeFabricante;
		int quantidadeItens;
		int tipoInsumo;
		float valorUnitario;

	public:
		Insumo();
		Insumo(int, string, string, string, int, float);

		virtual void salvarInsumos(ofstream &fp);
		
		virtual string getDescricao();
		string getConsulta();

		string getNomeProduto();
		string getDataVencimento();
		string getNomeFabricante();
		int getQuantidadeItens();
		int getTipo();
		float getValorUnitario();

		void setNomeProduto(string);
		void setDataVencimento(string);
		void setNomeFabricante(string);
		void setQuantidadeItens(int);
		void setTipo(int);
		void setValorUnitario(float);

		void addQuantidadeItens(int);
};