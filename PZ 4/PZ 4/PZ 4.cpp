#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

void CreateMatrix(int** arr, int rows, int cols);
void InputMatrix(int** arr, int rows, int cols);
void ShowMatrix(int** arr, int rows, int cols);
void DeleteMatrix(int** arr, int rows);

void Exercise1_2();
void Exercise_3();
void Exercise_4();
void Exercise_5();

int main()
{
	setlocale(LC_ALL, "rus");
	int choice;

	do {
		int Input()
			;
		cout << "\n\tВыберите задание( 0 -- выйти ):" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Задание 1 и 2" << endl;
			Exercise1_2();
			break;
		case 2:
			cout << "Задание 1 и 2" << endl;
			Exercise1_2();
			break;
		case 3:
			cout << "Задание 3" << endl;
			Exercise_3();
			break;
		case 4:
			cout << "Задание 4" << endl;
			Exercise_4();
			break;
		case 5:
			cout << "Задание 5" << endl;
			Exercise_5();
			break;
		case 0:
			cout << "До свидания!" << endl;
			exit;
		}

	} while (choice != 0);

	return 0;

}
void CreateMatrix(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}
void InputMatrix(int** arr, int rows, int cols) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 20 - 10;
		}
	}
}
void ShowMatrix(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void DeleteMatrix(int** arr, int rows) {
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void InputArray(int* arr, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 - 5;
	}
}
void ShowArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

void Exercise1_2() {

	int rows, cols;
	cout << "\nВведите количество строк матрицы: " << endl;
	cin >> rows;
	cout << "Введите количество столбцов матрицы: " << endl;
	cin >> cols;
	int** arr = new int* [rows];

	CreateMatrix(arr, rows, cols);
	InputMatrix(arr, rows, cols);
	ShowMatrix(arr, rows, cols);

	int sum = 0;
	double average_value;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	average_value = sum / rows / cols;
	cout << "Сумма всех элементов матрицы = " << sum << endl;
	cout << "Среднее значение = " << average_value << endl;
	DeleteMatrix(arr, rows);
}

void Exercise_3() {
	int first_rows, first_cols, second_rows, second_cols;
	cout << "\nВведите количество строк первой матрицы: " << endl;
	cin >> first_rows;
	cout << "Введите количество столбцов первой матрицы: " << endl;
	cin >> first_cols;
	int** first_arr = new int* [first_rows];

	CreateMatrix(first_arr, first_rows, first_cols);
	InputMatrix(first_arr, first_rows, first_cols);
	ShowMatrix(first_arr, first_rows, first_cols);

	cout << "\nВведите количество строк второй матрицы: " << endl;
	cin >> second_rows;
	cout << "Введите количество столбцов второй матрицы: " << endl;
	cin >> second_cols;
	int** second_arr = new int* [second_rows];

	CreateMatrix(second_arr, second_rows, second_cols);
	InputMatrix(second_arr, second_rows, second_cols);
	ShowMatrix(second_arr, second_rows, second_cols);
	if (first_cols == second_rows) {
		int rezult_rows = first_rows, rezult_cols = second_cols;
		int** rezult_arr = new int* [rezult_rows];
		CreateMatrix(rezult_arr, rezult_rows, rezult_cols);

		for (int i = 0; i < first_rows; i++)
		{
			for (int j = 0; j < second_cols; j++)
			{
				rezult_arr[i][j] = 0;
				for (int k = 0; k < rezult_rows; k++)
				{
					rezult_arr[i][j] += first_arr[i][k] * second_arr[k][j];
				}
			}
		}
		cout << "Итоговая матрица, полученная из перемножения первой и второй: " << endl;
		ShowMatrix(rezult_arr, rezult_rows, rezult_cols);
		DeleteMatrix(rezult_arr, rezult_rows);
	}
	else {
		cout << "Матрицы не могут быть перемножены(Количество столбцов первой м-цы должно быть равно количеству строк другой)" << endl;
	}
	DeleteMatrix(first_arr, first_rows);
	DeleteMatrix(second_arr, second_rows);

}

void Exercise_4() {
	int size, temp, step = 0;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	int* arr = new int[size];

	InputArray(arr, size);
	ShowArray(arr, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
				step++;
			else
				arr[j - step] = arr[j];
		}
		size -= step;
		step = 0;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	cout << endl;
	ShowArray(arr, size);
	cout << endl;
	cout << arr[(size - 1) / 2] << endl;
	delete[] arr;
}

void Exercise_5() {
	int rows, cols, size;
	cout << "\nВведите количество строк матрицы: " << endl;
	cin >> rows;
	cout << "Введите количество столбцов матрицы: " << endl;
	cin >> cols;
	int** matr = new int* [rows];

	CreateMatrix(matr, rows, cols);
	InputMatrix(matr, rows, cols);
	ShowMatrix(matr, rows, cols);
	size = rows * cols;
	int* arr = new int[size];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i * cols + j] = matr[i][j];
		}
	}
	int temp;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

	ShowArray(arr, size);

	cout << endl;
	cout << "Медиана матрицы равна: " << arr[(size - 1) / 2] << endl;
	cout << "Наименьший элемент матрицы равен: " << arr[0] << endl;
	cout << "Наибольший элемент матрицы равен: " << arr[size - 1] << endl;

	delete[] arr;
	DeleteMatrix(matr, rows);
}
