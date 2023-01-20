/* 5 лабораторная работа 7 вариарт 2 задание
Задание:
Дан файл, содержащий русский текст, размер текста не превышает
10 kb. Найти в тексте N (N <= 100) самых длинных слов, содержащих
заданную букву и не содержащих другую заданную букву. Записать найденные слова в текстовый файл в порядке НЕ возростания длины.
Все найденные слова должны быть разными. Число N вводить из файла.
*/
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
void bubbleSort(std::string values[], int size) {
	for (size_t i = 0; i + 1 < size; ++i) {
		for (size_t j = 0; j + 1 < size - i; ++j) {
			if (values[j + 1].length() > values[j].length()) {
				swap(values[j], values[j + 1]);
			}
		}
	}
}
void delNonUnique(std::string values[], int size) {
	for (size_t i = 0; i + 1 < size; ++i) {
		for (size_t j = 0; j + 1 < size - i; ++j) {
			if (values[i] == values[j] and i != j) {
				values[j].clear();
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите требуемый символ: ";
	char requiredSymbol;
	std::cin >> requiredSymbol;
	std::cout << "Введите нетребуемый символ: ";
	char unrequiredSymbol;
	std::cin >> unrequiredSymbol;
	std::ifstream fin{ "input1111.txt" };
	const int SIZE(100);
	std::string strings[SIZE];
	std::string tempStr;
	int countOfWords;
	int wordsNumber{};
	while (fin >> tempStr) {
		if (tempStr.find(requiredSymbol) != std::string::npos and tempStr.find(unrequiredSymbol) == std::string::npos) {
			strings[wordsNumber] = tempStr;
			++wordsNumber;
		}
	}
	countOfWords = std::stoi(tempStr);
	delNonUnique(strings, SIZE);
	bubbleSort(strings, SIZE);
	std::ofstream fout{ "output.txt", std::fstream::trunc };
	for (size_t i{}; i < SIZE || countOfWords > 0; ++i) {
		if (!strings[i].empty()) {
			fout << strings[i] << std::endl;
			--countOfWords;
		}
	}
}