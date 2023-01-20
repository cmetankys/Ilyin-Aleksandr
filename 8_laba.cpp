/*8 лабораторная работа 7 вариант
Дано целое число типа int, выведите на экран содержимое каждого из его байтов, используя знания по указателям. Дайте обоснование полученному результату.*/
#include <iostream>
#include <string>
#include <cstdio>
std::string getBinnary(unsigned char n) {
	std::string buff;
	while (n > 0) {
		buff += std::to_string(n % 2);
		n /= 2;
	}
	return std::string(buff.crbegin(), buff.crend());
}
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите число типа int: ";
	int value;
	std::cin >> value;
	unsigned char* value_p{ ((unsigned char*)&value) };
	for (size_t i{}; i < sizeof(int); ++i, ++value_p) {
		std::string binValue{ getBinnary(*value_p) };
		printf("%p: %s\n", value_p, binValue.c_str());
	}
}
