#include <fstream> 
#include <iostream>

using namespace std;

const int NUMW = 100; // lines text is in words
const int NW = 200; // word lenght
const int MAXLEN = NUMW * NW + 10; // ���������� ������������ ������ ������

struct StringList { //���������, ������� ������ ������ �����
	char* strings[NUMW]; // ������ ���������� �� char, ��� ������
	int wordCount = 0;// ���������� ��������� ����
};

char* read(const char* filename); // �������, �������� ����� �� �����
StringList* extractWords(char* text); // �������, ������� ����� �� ����� � ����������� �� � WordList
bool isRussianLetter(char c);// �������, ����������� ������, �� �������������� �������� �����
bool isPrefixExist(char* prefix, char* word);// �������, ����������� ������� ��������� � �����
char* getAns(char* prefix, char* word);// �������, ���������� ��������� �� �����
char* reshow(const char* file);// �������, ������������ ��������� �����.
void ansver();// �������, ����������� ������� ������.
