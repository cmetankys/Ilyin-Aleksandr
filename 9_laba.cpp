/*9 лабораторная работа 7 вариант
*Воспользуйтесь первым принципом ООП, абстракцией, и сформируйте класс, включив в него только минимальный набор переменных (полей) для заданного вашим вариантом объекта.
*Используйте второй принцип ООП, инкапсуляцию, чтобы не допустить некорректного ввода параметров.
*Добавьте в класс функции (методы), которые позволят решить задачу. Продемонстрируйте решение.
*Разбивать класс на файлы можете по желанию.
*Найти диагональ куба.
*/
#include<iostream>
#include<cmath>
#include<string>
class Cube {
	double diagonal;
public:
	void setEdge(int edge) {
		if (edge >= 0) {
			diagonal = sqrt(3) * edge;
		}
		else {
			std::cout << "Грань куба должна иметь значение >= 0!" << std::endl;
		}
	}
	double getDiagonal() {
		return diagonal;
	}
};
int main() {
	setlocale(LC_ALL, "ru");
	int edge;
	Cube cube;
	std::cout << "Введите грань куба: ";
	std::cin >> edge;
	cube.setEdge(edge);
	std::cout << "Диагональ куба: " << cube.getDiagonal();
}

