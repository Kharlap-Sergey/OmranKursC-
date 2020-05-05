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

int main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251");

	while (true) {
		cout << "введите 1 - для перезаписи информации\n\
введите 2 - для показа записаных данных;\n\
введите 3 - для обработки входных данных;\n\
введите 4 - для пока результатов;\nиначе программа будет завершнена\n";
		int step;
		cin >> step;
		switch (step) {
		case 1: {
			cout << "введите n и m - размерность матрицы\n";
			int n, m;
			cin >> n >> m;
			out.open("input.txt");
			out << n << ' ' << m << '\n';
			double boof;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin >> boof;
					out << boof << ' ';
				}
				out << endl;
			}
			out << '/';
			out << endl;

			break;
		}
		case 2: {
			char* inf = echo("input.txt");
			cout << inf << endl << endl;
			break;
		}

		case 3: {
			cout << "ответ подсчитан\n\n";
			ansver();
			break;
		}
		case 4: {
			char* ans = echo("output.txt");
			cout << ans << endl << endl;
			break;
		}
		default:
			return 0;
			break;
		}
	}
	
	return 0;
}


void ansver() {
	Matrix* matrix = read("input.txt");
	swapMaxElements(matrix);
	print("output.txt", matrix);
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}
Element* findMaxElemeintInMainDiagonal(Matrix* matr) {
	Element* maxElement = new Element;
	maxElement->i = 0;
	maxElement->j = 0;
	maxElement->value = *(matr->values);

	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			if (i == j) {
				double currentVal = *(matr->values + i * matr->m + j);
				if (maxElement->value < currentVal) {
					maxElement->value = currentVal;
					maxElement->i = i;
					maxElement->j = j;
				}
			}	
		}
	}

	return maxElement;
}
Element* findMinElemeintInSecondaryDiagonal(Matrix* matr) {
	Element* minElement = new Element;
	minElement->i = 0;
	minElement->j = matr->m - 1;
	minElement->value = *(matr->values+matr->m - 1);

	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			if (i+j == matr->m-1) {
				
				double currentVal = *(matr->values + i * matr->m + j);
				if (minElement->value > currentVal) {
					minElement->value = currentVal;
					minElement->i = i;
					minElement->j = j;
				}
			}
		}
	}
	return minElement;
}

void swapMaxElements(Matrix* matr) {
	Element* mainEl = findMaxElemeintInMainDiagonal(matr);
	Element* secondaryEl = findMinElemeintInSecondaryDiagonal(matr);
	*(matr->values + mainEl->i * matr->m + mainEl->j) = secondaryEl->value;
	*(matr->values + secondaryEl->i * matr->m + secondaryEl->j) = mainEl->value;
}

Matrix* read(const char* filename) {
	Matrix* matr = new Matrix;

	in.open(filename);
	in >> matr->n;
	in >> matr->m;
	double* mass = new double[matr->n * matr->m + 1];
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			in >> *(mass + i * matr->m + j);
		}
	}
	in.close();

	matr->values = mass;
	return matr;
}


void print(const char* filename, Matrix* matr) {

	out.open(filename);
	out << matr->n << ' ';
	out << matr->m << endl;;
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			out << *(matr->values + i * matr->m + j) << ' ';
		}
		out << endl;
	}
	out << '/';
	out.close();
}

