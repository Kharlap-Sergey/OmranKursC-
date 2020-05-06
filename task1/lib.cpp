#include "lib.h"

void ansver() {
	char* words = read("words.txt");
	char* prefixes = read("prefixes.txt");

	StringList* wordsList = extractWords(words);
	StringList* prefixesList = extractWords(prefixes);

	ofstream out;
	out.open("output.txt");
	for (int i = 0; i < prefixesList->wordCount; i++) {
		if (strlen(prefixesList->strings[i]) == 0) continue;
		out << (prefixesList->strings[i]) << ":\n";
		for (int j = 0; j < wordsList->wordCount; j++) {
			if (isPrefixExist(prefixesList->strings[i], wordsList->strings[j])) {
				out << getAns(prefixesList->strings[i], wordsList->strings[j]) << " ";
			}
		}
		out << '\n';

	}
	out << '/';
	out.close();
}

char* reshow(const char* file) {
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
	char* ans = new char[NW + 2];
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
	bool ans = 'à' <= c && c <= 'ÿ';
	return ans;
}

StringList* extractWords(char* text) {
	StringList* ans = new StringList;
	ans->wordCount = 0;
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
				ans->strings[ans->wordCount] = boof;
				ans->wordCount++;
				isWordStart = false;
				len = 0;
				boof = new char[NW + 1];
			}
		}
	}
	boof[len] = '\0';
	ans->strings[ans->wordCount] = boof;
	ans->wordCount++;

	return ans;
}

char* read(const char* filename) {
	ifstream in;
	in.open(filename);
	char* pointer = new char[MAXLEN];
	in.get(pointer, MAXLEN - 10, '.');
	in.close();
	return pointer;
}
