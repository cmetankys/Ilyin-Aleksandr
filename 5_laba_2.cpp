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
// Алгоритм пузырьковой сортировки
void bubbleSort(std::string values[], int size) {
	for (size_t i = 0; i + 1 < size; ++i) {
		for (size_t j = 0; j + 1 < size - i; ++j) {
			if (values[j + 1].length() > values[j].length()) {
				swap(values[j], values[j + 1]);
			}
		}
	}
}
// Функция для удаления одинаковых слов
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
	// Microsoft Visual C++ нуждается в установке приведенных ниже параметров,
	// для корректной работы с потоками ввода/вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите требуемый символ: ";
	char requiredSymbol{};
	std::cin >> requiredSymbol;
	std::cout << "Введите нетребуемый символ: ";
	char unrequiredSymbol{};
	std::cin >> unrequiredSymbol;
	// файловый поток ввода
	std::ifstream fin{ "input.txt" };
	// массив для хранения обрабатываемых строк
	const int SIZE{ 100 };
	std::string strings[SIZE]{};
	// временная строковая переменная
	std::string tempStr{};
	// переменная, которая получает последнее значение из файлового потока ввода => 
	// необходимое количество удовлетворяющих условию строк
	int countOfWords{};
	int wordsNumber{};
	// получаем все символы в виде слова, до первого пробела
	while (fin >> tempStr) {
		// проверяем слово на наличие необходимой буквы и отсутствие ненужной
		if (tempStr.find(requiredSymbol) != std::string::npos and tempStr.find(unrequiredSymbol) == std::string::npos) {
			strings[wordsNumber] = tempStr;
			++wordsNumber;
		}
	}
	// получаем количество слов из файла, как последнее слово
	countOfWords = std::stoi(tempStr);
	// очищаем от неуникальных значений
	delNonUnique(strings, SIZE);
	// сортируем элементы по длине строк, в не возростающем порядке
	bubbleSort(strings, SIZE);
	// создание потока файлового вывода
	std::ofstream fout{ "output.txt", std::fstream::trunc };
	// вывод полученных значений в файл
	for (size_t i{}; i < SIZE, countOfWords > 0; ++i) {
		if (!strings[i].empty()) {
			fout << strings[i] << std::endl;
			--countOfWords;
		}
	}
}