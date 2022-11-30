/* 4 лабароторная работа 2 задание 7 вариант
Задание: Ввести последовательность натуральных чисел {Aj}j=1...n(n<=1000).
Упорядочить последовательность по неубыванию суммы цифр числа,
числа с одинаковыми суммами цифр дополнительно упорядочить по
неубыванию наибольшей цифры числа, числа с одинаковыми суммами цифр и
одинаковыми наибольшими цифрами дополнительно упорядочить по
неубыванию самого числа
*/
#include <iostream>
#include <string>
int main() {
	setlocale(LC_ALL, "ru");
	const int ARRAY_SIZE{ 10 };
	int array[10] = {};
	std::cout << "Введите 10 чисел, каждое из которых меньше или равно 1,000: " << std::endl;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << "Введите " << i << "ый элемент последовательности: ";
		std::cin >> array[i];
	}
	for (int i = 0; i + 1 < ARRAY_SIZE; ++i) {
		for (int j = 0; j < ARRAY_SIZE - 1; ++j) {
			std::string first{ std::to_string(array[j]) }, second{ std::to_string(array[j + 1]) };
			// переменные для нахождения суммы цифр выбранного элемента
			int first_sum{}, second_sum{};
			// цикл foreach, который перебирает каждый элемент в заданном контейнере (массивы, строки, списки и тд.)
			for (char ch : first) {
				first_sum += ch - '0';
			}
			for (char ch : second) {
				second_sum += ch - '0';
			}
			int temp{};
			// Если суммы цифр чисел выбранного элемента и следующего за ним равны,
			// то ищем максимальную цифру в числе
			if (first_sum == second_sum) {
				// Выбираем первое число для first_max	и первое число для second_max
				int first_max{ first[0] - '0' }, second_max{ second[0] - '0' };
				for (char ch : first) {
					int n{ ch - '0' };
					// Если первое число меньше следующего, максимальным становится следующее
					if (n > first_max) {
						first_max = n;
					}
				}
				for (char ch : second) {
					int n{ ch - '0' };
					if (n > second_max) {
						second_max = n;
					}
				}
				// Сравниваем максимальную цифру числа и если они равны
				if (first_max == second_max) {
					// сортируем числа
					if (array[j] > array[j + 1]) {
						temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
				// Если максимальные цифры чисел НЕ равны, проводим сортировку
				else {
					if (first_max > second_max) {
						temp = array[j + 1];
						array[j + 1] = array[j];
						array[j] = temp;
					}
				}
			}
			// Если суммы чисел НЕ равны, проводим сортировку
			else if (first_sum > second_sum) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << i << ": [" << array[i] << "], ";
	}
	std::cout << std::endl;
}