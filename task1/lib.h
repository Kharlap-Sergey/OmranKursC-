#include <fstream>
#include <iostream>

using namespace std;

const int NUMW = 100; // lines text is in words
const int NW = 200; // word lenght
const int MAXLEN = NUMW * NW + 10;

struct WordList {
	char* values[NUMW];
	int AmountWords = 0;
};

char* read(const char* filename); // функция, читающая текст из файла.
WordList* extractWords(char* text);
bool isRussianLetter(char c);

bool isPrefixExist(char* prefix, char* word);
char* getAns(char* prefix, char* word);
char* echo(const char* file);
void ansver();
