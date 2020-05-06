#include "lib.h"


int main() {
	setlocale(LC_ALL, "rus");
	system("chcp 1251");

	while (true) {
		cout << "������� 1 - ��� ���������� ����������\n\
������� 2 - ��� ������ ��������� ������;\n\
������� 3 - ��� ��������� ������� ������;\n\
������� 4 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
		int step;
		cin >> step;
		switch (step) {
		case 1: {
			cout << "������� ����� ���� ',' �������������� '.'\n";
		    char *words = new char[MAXLEN];
			cin.get();
			cin.get(words, MAXLEN - 10, '.');
			cin.get();
			cout << "������� ��������� ���� ',' �������������� '.'\n";
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

			cout << "���������:";
			cout << prefixes << endl;;
			cout << "�����:\n";
			cout << words << endl << endl;
			break;
		}
		case 3: {
			cout << "����� ���������\n\n";
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

