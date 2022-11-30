/*2 лабораторная работа 7 вариант 1 задание
Задача:
Ввести натуральные числа A, B и C. Если A кратно B и B больше C, то вывести A / b + C, если A кратно B и B меньше C,
то вывести A / B - C, в остальных случаях вывести (A + B) * C.
*/

#include <iostream>
int main() {
    setlocale(LC_ALL, "ru");
    int A{}, B{}, C{};
    double answer{};
    std::cout << "Введите число A: ";
    std::cin >> A;
    std::cout << "Введите число B: ";
    std::cin >> B;
    std::cout << "Введите число C: ";
    std::cin >> C;
    // Конструкция if позволяет изменять ход выполнения программы.
    // В зависимости от удовлетворения/неудовлетворения условиям
    // блок {...} соответственное выполняется или невыполняется.
    if (A % B == 0 && B > C) {
        std::cout << "A кратно B и B больше C" << std::endl;
        answer = A / B + C;
        std::cout << "A / B + C = " << answer << std::endl;
    }
    else if (A % B == 0 && B < C) {
        std::cout << "A кратно B и B меньше C" << std::endl;
        answer = A / B - C;
        std::cout << "A / B + C = " << answer << std::endl;
    }
    else {
        std::cout << "Иной вариант" << std::endl;
        answer = (A + B) * C;
        std::cout << "(A + B) * C = " << answer << std::endl;
    }
}