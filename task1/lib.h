#include <fstream> 
#include <iostream>

using namespace std;

const int NUMW = 100; // lines text is in words
const int NW = 200; // word lenght
const int MAXLEN = NUMW * NW + 10; // вычисление максимальной длинны текста

struct StringList { //структура, котора€ хранит список строк
	char* strings[NUMW]; // массив указателей на char, сам список
	int wordCount = 0;// количество записаных слов
};

char* read(const char* filename); // функци€, читающа€ текст из файла
StringList* extractWords(char* text); // функци€, делюща€ текст на слова и дабовл€юща€ их в WordList
bool isRussianLetter(char c);// функци€, провер€юща€ символ, на пренадлежность русскому €зыку
bool isPrefixExist(char* prefix, char* word);// функци€, провер€юща€ наличие приставки в слове
char* getAns(char* prefix, char* word);// функци€, отдел€юща€ приставку от слова
char* reshow(const char* file);// функци€, показывающа€ состо€ние файла.
void ansver();// функци€, выполн€юща€ подсчет ответа.
