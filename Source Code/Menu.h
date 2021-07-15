#include "Controler.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "Epi.h"

#pragma once

class Menu
{
	private:
		Controler control;

	public:
		Menu();

		Controler& getControl();

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