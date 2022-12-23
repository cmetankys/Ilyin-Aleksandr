#pragma once
namespace func {
	// Константа количества элементов в массиве для НЕдиагональных элементов
	int const NON_DIAGONAL_LENGTH{ 10 };
	// Константа количества элементов в массив для ДИАГОНАЛЬНЫХ элементов
	int const DIAGONAL_LENGTH{ 4 };
	// Т. К. NON_DIAGONAL_LENGTH = 10 => массив заполняет оставшиеся 8 значений нулями
	int nonDiagonal[NON_DIAGONAL_LENGTH]{ 1, 2 };
	int diagonal[DIAGONAL_LENGTH]{ 2, 3, 4, 5 };
	int** makeMatrix(size_t n) {
		// создание двумерного массива
		// int** cols - является одномерных массивом, элементы
		// которого также являются одномерными массивами
		int** cols = new int* [n];
		for (size_t i = 0; i < n; i++) {
			// заполняем элементы cols одномерными массивами
			cols[i] = new int[n];
		}

		return cols;
	}
	bool checkDiagonal(int** arr, size_t size) {
		for (size_t i{}; i < size; ++i) {
			for (size_t j{}; j < size; ++j) {
				// Проверям каждый диагональный элемент
				if (j == i) {
					// k - индекс для прохождения по элементам ряда
					for (size_t k{}; k < size; ++k) {
						// если выбранный элемент ряда больше диагонального и выбран НЕ диагональный элемент
						// возвращаем false и тем самым выходим из функции
						if (arr[i][k] >= arr[i][j] && j != k) {
							return false;
						}
					}
				}
			}
		}
		// если мы не вышли из функции с false, => все элементы наибольшие в своих строках
		// и возвращаем true
		return true;
	}
	void fillMatrix(int** arr, size_t size) {
		// получаем уникальный seed генератора псевдо-рандомных чисел для каждого запуска программы
		srand(time(NULL));
		for (size_t i{}; i < size; ++i) {
			for (size_t j{}; j < size; ++j) {
				if (i == j) {
					// Заполняем диагональные элементы, значениями из необходимого массива
					arr[i][j] = diagonal[rand() % DIAGONAL_LENGTH];
				}
				else {
					// Заполняем недиагональные элементы, значениями из необходимого массива
					arr[i][j] = nonDiagonal[rand() % NON_DIAGONAL_LENGTH];
				}
			}
		}
	}
	void replaceNullToDiagonalMul(int** arr, size_t size, int diagonalMul) {
		for (size_t i{}; i < size; ++i) {
			for (size_t j{}; j < size; ++j) {
				if (arr[i][j] == 0) {
					arr[i][j] = diagonalMul;
				}
			}
		}
	}
	int getDiagonalMul(int** arr, size_t size) {
		int diagonalMul{ arr[0][0] };

		for (size_t i{ 1 }; i < size; ++i) {
			for (size_t j{ 1 }; j < size; ++j) {
				if (i == j) {
					diagonalMul *= arr[i][j];
				}
			}
		}
		return diagonalMul;
	}
	// функция для вывода матрицы в консоль
	void showSquadMatrix(int** arr, size_t size) {
		// проходим по всем элементам матрицы
		for (size_t i{}; i < size; ++i) {
			for (size_t j{}; j < size; ++j) {
				// и выводим их на экран
				std::cout << "[" << arr[i][j] << "]  ";
			}
			std::cout << std::endl << std::endl;
		}
	}

}

