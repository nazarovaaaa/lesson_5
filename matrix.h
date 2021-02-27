#pragma once
#include <utility>
#include <iostream>
using namespace std;

template<typename T>
class matrix {
public:

	matrix(size_t row, size_t column)
		: column_num(column), row_num(row)
	{
		column_num = column;
		row_num = row;
		matrix_pointer = new T*[row];
		for (size_t i = 0; i < row; i++) {
			matrix_pointer[i] = new T[column];
		}
	}


	matrix(const matrix<T>& temp)
		: column_num(temp.column_num), row_num(temp.row_num)
	{
		column_num = temp.column_num; 
		row_num = temp.row_num;
		matrix_pointer = new T *[row_num];
		for (size_t i = 0; i < row_num; i++) {
			matrix_pointer[i] = new T[column_num];
			for (size_t j = 0; j < column_num; j++) {
				*(*(matrix_pointer + i) + j) = *(*(temp.matrix_pointer + i) + j);
			}
		}
	}



	matrix(size_t row, size_t column, T* _matrix)
		: column_num(column), row_num(row) 
	{
		column_num = column;
		row_num = row;
		matrix_pointer = new T *[row];
		for (size_t i = 0; i < row; i++) {
			matrix_pointer[i] = new T[column];
			for (size_t j = 0; j < column; j++) {
				*(*(matrix_pointer + i) + j) = *_matrix;
				_matrix++;
			}
		}
	}

	~matrix() {
		for (size_t i = 0; i < row_num; i++) {
			delete[] matrix_pointer[i];
		}
		delete[] matrix_pointer;
	}



	T& operator() (size_t i, size_t j) {
		return *(*(matrix_pointer + i) + j);
	}



	T& operator() (size_t i, size_t j) const {
		return *(*(matrix_pointer + i) + j);
	}

	matrix<T>& operator=(const matrix<T>& temp)
//		: column_num(temp.column_num), row_num(temp.row_num)
	{
		this->~matrix();
		column_num = temp.column_num;
		row_num = temp.row_num;
		matrix_pointer = new T *[row_num];
		for (size_t i = 0; i < row_num; i++) {
			matrix_pointer[i] = new T[column_num];
			for (size_t j = 0; j < column_num; j++) {
				*(*(matrix_pointer + i) + j) = *(*(temp.matrix_pointer + i) + j);
			}
		}
		return *this;
	}


	matrix<T> operator*(const matrix<T>& other) {
		matrix<T> temp(this->row_num, other.get_column());
		for (size_t i = 0; i < this->row_num; i++) {
			for (size_t i_ = 0; i_ < other.get_column(); i_++) {
				T temp_num = 0;
				for (size_t j = 0; j < this->column_num; j++) {
					temp_num += other(j, i_) * (*(*(this->matrix_pointer + i) + j));
				}
				temp(i, i_) = temp_num;
			}
		}
		return move(temp);
	}

	size_t get_row() const{
		return row_num;
	}
	size_t get_column() const{
		return column_num;
	}

private:
	size_t column_num = 0, row_num = 0;
	T** matrix_pointer = nullptr;
};


template<typename T>
ostream& operator<< (ostream &out,const matrix<T>& temp) {
	size_t row = temp.get_row(), column = temp.get_column();
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != column; j++) {
			out << temp(i, j) << ' ';
		}
		out << "\n";
	}
	return out;
}

template<typename T>
istream& operator>> (istream &in, matrix<T>& temp) {
	size_t row = temp.get_row(), column = temp.get_column();
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != column; j++) {
			in >> temp(i, j);
		}
	}
	return in;
}


