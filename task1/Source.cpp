#include "lib.h"


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
		    char *words = new char[MAXLEN];
			cin.get();
			cin.get(words, MAXLEN - 10, '.');
			cin.get();
			cout << "введите преставки чере ',' оканчивающиеся '.'\n";
			char *prefixes = new char[MAXLEN];
			cin.get(prefixes, MAXLEN - 10, '.');
			cin.get();

			fstream out;
			out.open("prefixes.txt");
			out << prefixes << '/';
			out.close();
			out.open("words.txt");
			out << words << '/';
			out.close();
			break;
		}
		case 2: {
			char *words = reshow("words.txt");
			char *prefixes = reshow("prefixes.txt");

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
			char* ans = reshow("output.txt");
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

