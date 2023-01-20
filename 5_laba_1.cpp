/*5 лабораторная работа 7 вариант 1 задание
Дана строка длинной не более 100 символов. Отсортировать слова в ней в алфавитном порядке
*/
#include<iostream>
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите строку <= 100 символов: ";
	const int SIZE(100);
	char str[SIZE];
	gets_s(str, 100);
	char words[SIZE][SIZE];
	int count;
	for (size_t i; i < SIZE; ++i) {
		for (size_t j; j < SIZE; ++j) {
			words[i][j] = str[count];
			if (str[count] == ' ') {
				count++;
				break;
			}
			count++;
		}
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
	strcpy_s(str, "");
	for (size_t i; i < 100; ++i) {
		strcat_s(str, words[i]);
	}
	std::cout << str;
}