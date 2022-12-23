/*5 лабораторная работа 7 вариант 1 задание
Дана строка длинной не более 100 символов. Отсортировать слова в ней в алфавитном порядке
*/
#include<iostream>
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите строку <= 100 символов: ";
	const int SIZE{ 100 };
	char str[SIZE]{};
	// ввод 100 символов в переданную строку (str)
	gets_s(str, 100);
	// двумерный массив строк, для дальнейшей возможности сортировки
	char words[SIZE][SIZE]{};
	// переменная-счетчик для получения каждого символа из str
	int count{};
	// проходимся по "словам" двумерного массива 
	for (size_t i{}; i < SIZE; ++i) {
		// проходимся по "буквам" из "слов" двумерного массива
		for (size_t j{}; j < SIZE; ++j) {
			// приравниваем букву из str к jтой букве iтого слова
			words[i][j] = str[count];
			// если буква str = пробелу => переходим в следующее слово words
			if (str[count] == ' ') {
				count++;
				break;
			}
			count++;
		}
		// когда строка заканчивается => выходим из цикла
		if (count > 100) {
			break;
		}
	}
	for (size_t i = 0; i + 1 < SIZE; ++i) {
		for (size_t j = 0; j + 1 < SIZE - i; ++j) {
			if (tolower(words[j + 1][0]) < tolower(words[j][0])) {
				std::swap(words[j], words[j + 1]);
			}
		}
	}
	// очищаем строку
	strcpy_s(str, "");
	// копируем в строку "слова" из двумерного массива
	for (size_t i{}; i < 100; ++i) {
		strcat_s(str, words[i]);
	}
	std::cout << str;
}