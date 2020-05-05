#include "lib.h"

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
	minElement->value = *(matr->values + matr->m - 1);

	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			if (i + j == matr->m - 1) {

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

	ifstream in;
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
	ofstream out;
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