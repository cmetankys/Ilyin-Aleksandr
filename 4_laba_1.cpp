/* 4 лабароторная работа 1 задание 7 вариант
Задание: Дана последовательность натрульных чисел {fj} j = 1...n(n<=10000).
Если в последовательности нет чисел, все цифры которых одинаковы,
упорядочить последовательность по невозрастанию (убыванию).
*/
#include <iostream>
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите 10 чисел, где каждое число меньше 10,000" << std::endl;
	const int ARRAY_SIZE{ 10 };
	int array[ARRAY_SIZE] = {};
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << "Введите " << i << "ый элемент: ";
		std::cin >> array[i];
	}
	std::cout << std::endl;
		// n - переменная для упрощения доступа к array[i]
		int n{};
	// check - переменная необходимая для проверки условий.
	// если число состоит полностью из одинаковых цифр, переменная
	// из true меняется на false.
	bool check{ true };
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		n = array[i];
		if (n == 11 || n == 111 || n == 1111) {
			check = false;
		}
		else if (n == 22 || n == 222 || n == 2222) {
			check = false;
		}
		else if (n == 33 || n == 333 || n == 3333) {
			check = false;
		}
		else if (n == 44 || n == 444 || n == 4444) {
			check = false;
		}
		else if (n == 55 || n == 555 || n == 5555) {
			check = false;
		}
		else if (n == 66 || n == 666 || n == 6666) {
			check = false;
		}
		else if (n == 77 || n == 777 || n == 7777) {
			check = false;
		}
		else if (n == 88 || n == 888 || n == 8888) {
			check = false;
		}
		else if (n == 99 || n == 999 || n == 9999) {
			check = false;
		}
	}
	// Если переменная check осталась true => в последовательности нет искомых чисел
	if (check) {
		std::cout << "В последовательности НЕ найдены числа, цифры которых полностью одинаковы!" << std::endl;
		// temp - переменная для того, чтобы поменять элементы местами
		int temp{};
		for (int i = 0; i < ARRAY_SIZE; ++i) {
			for (int j = 0; j < ARRAY_SIZE - 1; ++j) {
				if (array[j] < array[j + 1]) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}
	// Иначе, check = false => в последовательности найдены исковые числа
	// и выводится неотсортированная последовательность
	else {
		std::cout << "В последовательности НАЙДЕНЫ числа, цифры которых одинаковы!" << std::endl;
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << i << ": [" << array[i] << "], ";
	}
	std::cout << std::endl;
}