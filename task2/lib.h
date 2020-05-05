#include <iostream>
#include <fstream>
using namespace std;

fstream out;
ifstream in;

struct Matrix {
	int n, m; // ����������� �������
	double* values; // ������ �� �������� ������� 
};

struct Element {
	int i, j; // ������� ��������
	double value; // �������� ��������
};

Matrix* read(const char* filename); // �������, �������� ������� �� �����.
void print(const char* filename, Matrix* matr); // �������, ��������� �����.
void swapMaxElements(Matrix* matr);
char* echo(const char* file);
void ansver();
