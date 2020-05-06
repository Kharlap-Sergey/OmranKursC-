#include <iostream>
#include <fstream>
using namespace std;

struct Matrix {
	int n, m; // размерность матрицы
	double* values; // ссылка на элементы матрицы 
};

struct Element {
	int i, j; // индексы элемента
	double value; // значение элемента
};

Matrix* read(const char* filename); // функци€, читабща€ матрицу из файла.
void print(const char* filename, Matrix* matr); // функци€, вывод€ща€ ответ.
void swapMaxElements(Matrix* matr);// функци€, наход€ща€€ и мен€юща€ местами элементы, согласно условию задани€
char* reshow(const char* file);// функци€, показывающа€ состо€ние файла.
void ansver();// функци€, выполн€юща€ подсчет ответа.
