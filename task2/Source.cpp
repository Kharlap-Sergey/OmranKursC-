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
			cout << "введите n и m - размерность матрицы\n";
			int n, m;
			cin >> n >> m;
			fstream out;
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
			char* inf = reshow("input.txt");
			cout << inf << endl << endl;
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


