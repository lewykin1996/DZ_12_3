#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a;
	cout << "Введите размер массива: ";
	cin >> a;
	
	int* arr = new int[a];

	for (int i = 0; i < a; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	std::ofstream file{ "out.txt" };

	if (!file)
	{
		cout << "Ошибка открытия файла\n";
		delete[] arr;
		return 1;
	}

	file << a << endl;

	for (int i = a - 1; i >= 0; i--)
	{
		file << arr[i] << " ";
	}

	file.close();

	delete[] arr;

	return 0;
}