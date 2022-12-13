/*
Задание: Дана последовательность натрульных чисел {fj} j = 1...n(n<=10000).
Если в последовательности нет чисел, все цифры которых одинаковы,
упорядочить последовательность по невозрастанию (убыванию).
*/

#include <iostream>
#include <string>
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите количество чисел в последовательности: ";
	long long array_size{};
	std::cin >> array_size;
	std::cout << "Введите " << array_size << " чисел, где каждое число меньше 9'223'372'036'854'775'807" << std::endl;
	long long* array = new long long[array_size];
	for (int i{}; i < array_size; ++i) {
		std::cout << "Введите " << i + 1 << "ый элемент: ";
		std::cin >> array[i];
	}
	std::cout << std::endl;
	// check - переменная необходимая для проверки условий.
	// если число состоит полностью из одинаковых цифр, переменная
	// из true меняется на false.
	bool check{ true };
	//	переменная для внутренней проверки значения
	//	если value_check - меняется на false - переменная не из одинаковых цифр и check - не меняется
	//	иначе check - false
	for (int i = 0; i < array_size; ++i) {
		// при получении нового значения переменная value_check всегда true
		bool value_check{true};
		std::string value{ std::to_string(array[i]) };
		// j = 1 - т. к. для проверки на одинаковые значения используется 0ая цифра
		for (int j{ 1 }; j < value.length(); ++j) {
			//	если переменная не состоит из одинаковы цифр => value_check = false
			//	и переменная check остается true
			if (value[0] != value[j]) {
				value_check = false;
				break;
			}
		}
		if (value_check) {
			check = false;
			break;
		}
	}
	// Если переменная check осталась true => в последовательности нет искомых чисел
	if (check) {
		std::cout << "В последовательности НЕ найдены числа, цифры которых полностью одинаковы!" << std::endl;
		for (int i = 0; i + 1 < array_size; ++i) {
			for (int j = 0; j + 1 < array_size - i; ++j) {
				if (array[j] < array[j + 1]) {
					std::swap(array[j], array[j + 1]);
				}
			}
		}

	}
	// Иначе, check = false => в последовательности найдены искомые числа и выводится неотсортированная последовательность
	else {
		std::cout << "В последовательности НАЙДЕНЫ числа, цифры которых одинаковы!" << std::endl;
	}

	for (int i = 0; i < array_size; ++i) {
		std::cout << i << ": [" << array[i] << "], ";
	}
	std::cout << std::endl;
	delete[] array;
}
