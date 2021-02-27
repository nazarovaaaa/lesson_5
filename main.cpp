#include<iostream>
#include "matrix.h"
using namespace std;
template<typename T>
void fill(T* array_, size_t row, size_t column) {
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			*array_ = j;
			array_++;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	size_t a, b;
	cout << "Размеры матрицы:\n";
	cin >> a >> b;
	cout << "Матрица: \n";
	matrix<char> matr1(a, b);
	cin >> matr1;
	cout << "Размеры матрицы:\n";
	cin >> a >> b;
	cout << "Матрица: \n";
	matrix<char> matr2(a, b);
	cin >> matr2;
	//matr1 = matr2;
	cout <<'\n' << matr1 << "\n\n" << matr2<<"\n\n";
	cout << "Ответ:\n" << matr1 * matr2;


	//Проверка отсутствия утечки памяти

	//for(int i=0;i<100000;i++)
	//{
	//	//matrix<int> temp(5, 5);
	//	//cin >> temp;
	//	//cout << temp;
	//	int old_matrix0[50][30];
	//	int old_matrix1[30][40];
	//	fill(*old_matrix0, 50, 30);
	//	fill(*old_matrix1, 30, 40);
	//	matrix<int> matrix__(50, 30, *old_matrix0);
	//	matrix<int> matrix_(30, 40, *old_matrix1);
	//	cout << matrix__ << '\n';
	//	cout << matrix_ << '\n';
	//	matrix<int> a = matrix__ * matrix_;
	//	matrix__ = matrix_;
	//	cout << a;
	//}
	system("pause");
	return 0;
}