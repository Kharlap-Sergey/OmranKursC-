#include <iostream>
#include <fstream>
using namespace std;

fstream out;
ifstream in;

struct Matrix {
	int n, m; // размерность матрицы
	double* values; // ссылка на элементы матрицы 
};

struct Element {
	int i, j; // индексы элемента
	double value; // значение элемента
};

Matrix* read(const char* filename); // функция, читабщая матрицу из файла.
void print(const char* filename, Matrix* matr); // функция, выводящая ответ.
void swapMaxElements(Matrix* matr);
char* echo(const char* file);
void ansver();
