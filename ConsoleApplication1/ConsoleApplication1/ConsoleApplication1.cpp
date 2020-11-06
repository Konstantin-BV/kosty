﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "MyList.h"
using namespace std;

int main()

{
	setlocale(LC_ALL, "Russian");
	int i = 0, w, k, t;
	




	MyList temp;
	int s;
	cout << "Вводите элементы списка, когда введёте все нажмите -0\n";
	cin >> s;
	while (s != -0)
	{
		temp.push_back(s);
		cin >> s;
	}
		cout << "Введите 1 добавление в конец списка\n"; // menu
		cout << "Введите 2 добавление в начало списка\n";
		cout << "Введите 3 удаление последнего элемента\n";
		cout << "Введите 4 удаление первого элемента\n";
		cout << "Введите 5 добавление элемента по индексу\n";
		cout << "Введите 6 получение элемента по индексу\n";
		cout << "Введите 7 удаление элемента по индексу\n";
		cout << "Введите 8 получение размера списка\n";
		cout << "Введите 9 вывод элементов списка в консоль через разделитель\n";
		cout << "Введите 10 удаление всех элементов списка\n";
		cout << "Введите 11 замена элемента по индексу на передаваемый элемент\n";
		cout << "Введите 12 проверка на пустоту списка\n";
		cout << "Введите 13 для того, чтобы перемешать спискок\n";
		cout << "Введите 0 для того, чтобы выйти\n";


	std::cin >> w;
	while (w != 0) //menu
	{
		switch (w) {
		case 1:
			cout << "Вводите число, которое хотите добавить\n";
			std::cin >> s;
			temp.push_back(s);
			break;
		case 2:
			cout << "Вводите число, которое хотите добавить\n";
			std::cin >> s;
			temp.push_front(s);

			break;
		case 3:
			temp.pop_back();
			break;
		case 4:
			void pop_front();
			break;
		case 5:
			std::cin >> s;
			std::cin >> k;
			temp.insert(s, k);
			break;
		case 6:
			std::cin >> k;
			cout << temp.at(k);
			break;
		case 7:
			std::cin >> k;
			temp.remove(k);
			break;
		case 8:
			temp.get_size();
			break;
		case 9:
			temp.print_to_console();
			cout << "\n";
			break;
		case 10:
			temp.clear();
			break;
		case 11:
			std::cin >> s;
			std::cin >> k;
			temp.set(k,s);
			break;
		case 12:
			temp.isEmpty();
			break;
		case 13:
		{
			temp.reverse();
			break;
		}
	}
		cout << "Введите 1 добавление в конец списка\n";  //menu
		cout << "Введите 2 добавление в начало списка\n";
		cout << "Введите 3 удаление последнего элемента\n";
		cout << "Введите 4 удаление первого элемента\n";
		cout << "Введите 5 добавление элемента по индексу\n";
		cout << "Введите 6 получение элемента по индексу\n";
		cout << "Введите 7 удаление элемента по индексу\n";
		cout << "Введите 8 получение размера списка\n";
		cout << "Введите 9 вывод элементов списка в консоль через разделитель\n";
		cout << "Введите 10 удаление всех элементов списка\n";
		cout << "Введите 11 замена элемента по индексу на передаваемый элемент\n";
		cout << "Введите 12 проверка на пустоту списка\n";
		cout << "Введите 13 для того, чтобы перемешать спискок\n";
		cout << "Введите 0 для того, чтобы выйти\n";

		std::cin >> w;

	}

	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

