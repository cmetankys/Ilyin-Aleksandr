/* 5 лабароторная работа 7 вариант 2 задание
Задание:
Дан файл, содержащий русский текст, размер текста не превышает
10 kb. Найти в тексте N (N <= 100) самых длинных слов, содержащих
заданную букву и не содержащих другую заданную букву. Записать найденные слова в текстовый файл в порядке НЕ возростания длины.
Все найденные слова должны быть разными. Число N вводить из файла.
*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
void bubbleSort(std::vector<std::string>& values) {
	for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
		for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
			if (values[idx_j + 1].length() > values[idx_j].length()) {
				swap(values[idx_j], values[idx_j + 1]);
			}
		}
	}
}
// Функиця для удаления кратчайшей строки из std::vector'а
void removeShortest(std::vector<std::string>& strs) {
	// длина кратчайшей строки
	size_t s_length{ strs[0].length() };
	// индекс кратчайшей строки
	int s_number{};
	// перебераем все элементы, и получаем индекс элемента с кратчайшей строкой
	for (size_t i{ 1 }; i < strs.size(); ++i) {
		if (s_length > strs[i].length()) {
			s_length = strs[i].length();
			s_number = i;
		}
	}
	// Удаляем элемент под индексом (Метод .erasse нуждается в передаче итератора, а не
	// номера элемента, поэтому передаем strs.begin() + s_number - strs.begin()
	// - нулевой итератор + необходимый нам индекс
	strs.erase(strs.begin() + s_number);
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите обязательный символ: ";
	char requiredSymbol{};
	std::cin >> requiredSymbol;
	std::cout << "Введите необязательный символ: ";
	char unrequiredSymbol{};
	std::cin >> unrequiredSymbol;
	// файловый поток ввода
	std::ifstream fin{ "input.txt" };
	// контейнер для хранения обрабатываемых строк
	std::vector<std::string> strings{};
	// временная строковая переменная
	std::string tempStr{};
	// переменная, которая получает последнее значение из файлового потока ввода => 
	// необходимое количество удовлетворяющих условию строк
	int countOfWords{};
	while (fin >> tempStr) {
		if (tempStr.find(requiredSymbol) != std::string::npos and tempStr.find(unrequiredSymbol) == std::string::npos) {
			strings.push_back(tempStr);
		}
	}
	countOfWords = std::stoi(tempStr);
	// сортируем массив в порядке возростания
	std::sort(strings.begin(), strings.end());
	// получаем диапазон проверяемых значений
	auto last = std::unique(strings.begin(), strings.end());
	// очищаем от неуникальных значений
	strings.erase(last, strings.end());
	// Отбрасываем кратчайшие строки до необходимого количества
	while (strings.size() != countOfWords) {
		removeShortest(strings);
	}
	// сортируем элементы по длине строк, в невозростающем порядке
	bubbleSort(strings);
	// создание потока файлового вывода
	std::ofstream fout{ "output.txt", std::fstream::trunc };
	// вывод полученных значений из std::vector'а
	for (std::string str : strings) {
		fout << str << std::endl;
	}
}