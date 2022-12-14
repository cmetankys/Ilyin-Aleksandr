/* 5 лабароторная работа 7 вариант 1 задание 
* 
Дана строка длинной не более 100 символов. Отсортировать слова в ней в алфавитном порядке
*/
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>

void bubbleSort(std::vector<std::string>& str) {
	for (size_t i{}; i + 1 < str.size(); ++i) {
		for (size_t j{}; j + 1 < str.size() - i; ++j) {
			// сортируем элементы по первому символу строки
			// приравниваем полученный символ к нижнему регистру, т. к. 
			// Прописные и строчные символы имеют разный номер в используемой таблице символов
			if (std::tolower((str[j + 1])[0]) < std::tolower((str[j])[0])) {
				std::swap(str[j], str[j + 1]);
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Введите строку (Для завершения ввода, перед тем как нажать Enter нажмите Ctrl + Z - эта последовательность добавляет EOF символ, необходимый для объявления конца строки): " << std::endl;
	std::string str{};
	std::vector<std::string> str_arr{};
	while (std::cin >> str) {
		// добавление строк в дин. массив
		str_arr.push_back(str);
	}
	// сортировка
	bubbleSort(str_arr);
	// очищение строки перед повторным использованием 
	str.clear();
	// объединение строк из std::vector'а в одну строку для вывода
	for (std::string st : str_arr) str += st + " ";
	std::cout << str << std::endl;
}