#include "Controler.h"

#pragma once

class Menu
{
	private:
		Controler control;

	public:
		Menu();

		void lerArquivo();
		void salvarArquivo(vector<Insumo*>, Local);

		void exibeMenu();
		void exibeMenu1();
		void exibeMenu2();
		void exibeMenu3();
		void exibeMenu4();
		void exibeMenu5();
		void exibeMenu6();
		void exibeMenu7();

		Insumo* criacaoInsumo(int, string);
		Insumo* criacaoInsumoES(Insumo*);
};