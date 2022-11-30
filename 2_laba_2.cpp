﻿/*2 лабораторная работа 7 вариант 2 задание
Задание: Ввести натуральное число N, обозначающее номер дня недели.
Используя оператор switch вывести название всех дней недели.
Предусмотреть обработку ошибочного ввода N.
*/

#include<iostream>
int main() {
	setlocale(LC_ALL, "ru");
	int day{};
	std::cout << "[1 - Понедельник, 2 - Вторник, 3 - Среда, 4 - Четверг, 5 - Пятница, 6 - Суббота, 7 - Воскресенье]" << std::endl;
	std::cout << "Введите номер дня недели: ";
	std::cin >> day;
	// Конструкция switch, позволяет изменять ход программы в зависимости от переданного аргумента.
	switch (day) {
	case 1:
		std::cout << "Понедельник";
		break;
	case 2:
		std::cout << "Вторник";
		break;
	case 3:
		std::cout << "Среда";
		break;
	case 4:
		std::cout << "Четверг";
		break;
	case 5:
		std::cout << "Пятница";
		break;
	case 6:
		std::cout << "Суббота";
		break;
	case 7:
		std::cout << "Воскресенье";
		break;
		// Если аргумент switch не находит подходящего case'а, выполняется default - дефолтное поведение.
	default:
		std::cout << "Неправильный номер дня недели!";
		break;
	}
	std::cout << std::endl;
}