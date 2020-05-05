#include <fstream>
#include <iostream>

const int NUMW = 100; // lines text is in words
const int NW = 200; // word lenght
const int MAXLEN = NUMW * NW + 10;


using namespace std;
ifstream in;
ofstream out;

char* words;
char* prefixes;
struct WordList{
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
			cout << "введите слова чере ',' оканчивающиеся '.'\n";
		    words = new char[MAXLEN];
			cin.get();
			cin.get(words, MAXLEN - 10, '.');
			cin.get();
			cout << "введите преставки чере ',' оканчивающиеся '.'\n";
			prefixes = new char[MAXLEN];
			cin.get(prefixes, MAXLEN - 10, '.');
			cin.get();

			out.open("prefixes.txt");
			out << prefixes << '/';
			out.close();
			out.open("words.txt");
			out << words << '/';
			out.close();
			break;
		}
		case 2: {
			char* words = echo("words.txt");
			char* prefixes = echo("prefixes.txt");

			cout << "преставки:";
			cout << prefixes << endl;;
			cout << "слова:\n";
			cout << words << endl << endl;
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
	words = read("words.txt");
	prefixes = read("prefixes.txt");

	WordList* wordsList = extractWords(words);
	WordList* prefixesList = extractWords(prefixes);

	out.open("output.txt");
	for (int i = 0; i < prefixesList->AmountWords; i++) {
		if (strlen(prefixesList->values[i]) == 0) continue;
		out << (prefixesList->values[i]) << ":\n";
		for (int j = 0; j < wordsList->AmountWords; j++) {
			if (isPrefixExist(prefixesList->values[i], wordsList->values[j])) {
				out << getAns(prefixesList->values[i], wordsList->values[j]) << " ";
			}
		}
		out << '\n';
		
	}
	out << '/';
	out.close();
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}
bool isPrefixExist(char* prefix, char* word) {
	if (strlen(prefix) >= strlen(word)) return false;
	
	for (int i = 0; prefix[i] != '\0'; i++) {
		if (prefix[i] != word[i]) return false;
	}
	return true;
}

char* getAns(char* prefix, char* word) {
	char *ans = new char[NW + 2];
	int len = 0;
	for (int i = 0; prefix[i] != '\0'; i++) {
		ans[len] = prefix[i];
		len++;
	}
	ans[len] = '-';
	len++;
	for (int j = len - 1; word[j] != '\0'; j++) {
		ans[len] = word[j];
		len++;
	}
	ans[len] = '\0';
	return ans;
}

bool isRussianLetter(char c) {
	bool ans = 'а' <= c && c <= 'я';
	return ans;
}

WordList* extractWords(char* text) {
	WordList* ans = new WordList;
	ans->AmountWords = 0;
	bool isWordStart = false;
	char* boof = new char[NW + 1];
	int len = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (isRussianLetter(text[i])) {
			boof[len] = text[i];
			len++;
			isWordStart = true;
		}
		else {
			if (isWordStart) {
				boof[len] = '\0';
				ans->values[ans->AmountWords] = boof;
				ans->AmountWords++;
				isWordStart = false;
				len = 0;
				boof = new char[NW + 1];
			}
		}
	}
	boof[len] = '\0';
	ans->values[ans->AmountWords] = boof;
	ans->AmountWords++;

	return ans;
}

char* read(const char* filename) {
	in.open(filename);
	char* pointer = new char[MAXLEN];
	in.get(pointer, MAXLEN - 10, '.');
	in.close();
	return pointer;
}