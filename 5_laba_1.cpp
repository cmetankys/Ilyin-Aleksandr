/* 5 ������������ ������ 7 ������� 1 ������� 
* 
���� ������ ������� �� ����� 100 ��������. ������������� ����� � ��� � ���������� �������
*/
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>

void bubbleSort(std::vector<std::string>& str) {
	for (size_t i{}; i + 1 < str.size(); ++i) {
		for (size_t j{}; j + 1 < str.size() - i; ++j) {
			// ��������� �������� �� ������� ������� ������
			// ������������ ���������� ������ � ������� ��������, �. �. 
			// ��������� � �������� ������� ����� ������ ����� � ������������ ������� ��������
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
	std::cout << "������� ������ (��� ���������� �����, ����� ��� ��� ������ Enter ������� Ctrl + Z - ��� ������������������ ��������� EOF ������, ����������� ��� ���������� ����� ������): " << std::endl;
	std::string str{};
	std::vector<std::string> str_arr{};
	while (std::cin >> str) {
		// ���������� ����� � ���. ������
		str_arr.push_back(str);
	}
	// ����������
	bubbleSort(str_arr);
	// �������� ������ ����� ��������� �������������� 
	str.clear();
	// ����������� ����� �� std::vector'� � ���� ������ ��� ������
	for (std::string st : str_arr) str += st + " ";
	std::cout << str << std::endl;
}