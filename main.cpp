﻿#include <iostream>
#include <sstream>
#include <cinttypes>
#include "money.h"

int main() {
	Money a;
	uint32_t x;
	a.ConIn();
begin:
	std::cout << "1. Вывести количетсво фунтов, шиллингов и пенсов\n2. Сложить 2 суммы\n3. Вычесть из большей суммы меньшую\n4. Разделить первую сумму на вторую\n5. Разделить первую сумму на дробное число\n6. Умножить первую сумму на дробное число\n7. Операции сравнения\n8. Показать фунты, шиллинги и пенсы\n" << std::endl;
	std::cin >> x;
	std::cout << std::endl;
	if (x == 1) {
		a.Show();
	}
	if (x == 2) {
		Money a2;
		std::cout << "Введите вторую сумму." << std::endl;
		a2.ConIn();
		a.Plus(&a2);
		//std::cout << "\nРезультат сложения:" << std::endl; 
		//a.Show();
	}
	if (x == 3) {
		Money a2;
		std::cout << "Введите вторую сумму." << std::endl;
		a2.ConIn();
		//std::cout << "\nРезультат вычитания:" << std::endl;
		if (a2.AllSumGet() > a.AllSumGet())
		{
			a2.Minus(&a);
			//a2.Show();
		}
		else {
			a.Minus(&a2);
			//a.Show();
		}
	}
	if (x == 4) {
		Money a2;
		std::cout << "Введите вторую сумму." << std::endl;
		a2.ConIn();
		//std::cout << "\nРезультат деления:" << std::endl;
		//std::cout << 
		a.Div(&a2); //<< std::endl;
	}
	if (x == 5) {
		std::cout << "Введите число:" << std::endl;
		float arg;
		std::cin >> arg;
		//std::cout << "\nРезультат деления:" << std::endl;
		a.DivN(arg);
		//a.Show();
	}
	if (x == 6) {
		std::cout << "Введите число:" << std::endl;
		float arg;
		std::cin >> arg;
		//std::cout << "\nРезультат умножения:" << std::endl;
		a.Mult(arg);
		//a.Show();
	}
	if (x == 7) {
		Money a2;
		std::cout << "Введите вторую сумму." << std::endl;
		a2.ConIn();
		switch (a.Compare(&a2)) {
		case 0:
			std::cout << "Суммы равны" << std::endl; break;
		case 1:
			std::cout << "Первая сумма меньше второй." << std::endl; break;
		case 2:
			std::cout << "Первая сумма больше второй." << std::endl;
		}
	}
	if (x == 8) {
		a.Print();
	}

	std::cout << " \n Нажмите Ввод для завершения программы или любую клавишу для продолжения \n";
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	if (std::cin.get() != '\n') { goto begin; };

	return 0;
}