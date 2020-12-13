#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void RemovingDuplicateCharacters(char *strs) {
	int point = 0;
	string str = string(strs);

	for (int i = 0; i < size(str); i++) { // удаление повторных символов
		point = 0;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha((unsigned char)str[j])) {
				if (str[j] == str[j + 1]) {
					if (str[j] == '.') {
						point++;
						if (point >= 3)
							str.erase(j, 1);
					}
					else
						str.erase(j, 1);

				}
			}
		}
	}
	strcpy(strs, str.c_str());

	cout << str << endl << endl;
	setlocale(0, "RU");
}

void RegisterControll(char * str) {
	for (int i = 2; i < strlen(str); i++) // выравниваем регистр
	{
		str[0] = toupper(str[0]);

		if (str[i - 2] == '.' || str[i - 1] == '.' || str[i - 2] == '?' || str[i - 1] == '?') {
			str[i] = toupper(str[i]);
		}
		else {
			if (str[i - 1] != ' ')
				str[i] = tolower(str[i]);
			else
				str[i] = str[i];
		}
	}
	cout << str << endl << endl;
	setlocale(0, "RU");
}

void WordStartLetter(char pch[500]) {
	char *pchh = new char(500);
	pchh = strtok(pch, " ,.-");
	while (pchh != NULL) // пока есть лексемы
	{
		string str = string(pchh);
		for (int i = 1; i < size(str); i++) {
			if (str[0] == str[i])
				cout << pchh << "\n";
		}
		pchh = strtok(NULL, " ,.-)*");
	}
	cout << endl;
	setlocale(0, "RU");
}

void NumberRedact(char pch[500]) {
	char vC = ' ';
	char *pchh = new char(500);
	pchh = strtok(pch, " ");
	while (pchh != NULL) // пока есть лексемы
	{
		char varC = ' ';
		for (int i = 1; i < strlen(pchh) - 1; i++) {
			if (isdigit((unsigned char)pchh[i]))
				varC = pchh[i];
			if (pchh[i] == ' ' || pchh[i + 1] == '*' || pchh[i + 1] == ')' || pchh[i + 1] == ',')
				varC = ' ';

			if (varC != ' ') {
				vC = pchh[i + 1];
				pchh[i + 1] = pchh[i];
				pchh[i] = vC;
			}
		}

		cout << pchh << " ";
		pchh = strtok(NULL, " ");
	}
	cout << endl << endl;
	setlocale(0, "RU");
}

bool ReadFile(const char *FileName)
{
	char chS[400];
	char copyStr[500];
	char *pchS;

	ifstream File;
	File.open(FileName);

	if (!File.is_open())  //  Проверили удалось ли открыть файл
	{
		cout << "Открыть файл не удалось! \n";
		return 0;
	}

	while (!File.eof()) // Читаем все строки из файла и выводим их на экран
		File.getline(chS, 500);
	pchS = chS;
	cout << "Исходный текст:\n" << pchS << endl << endl;
	cout << "\n***************************\n";

	cout << "\n***В этой строке удалены все повторные символы***\n";
	RemovingDuplicateCharacters(pchS); // удаление повторных символов
	cout << "***************************\n";

	cout << "\n***В этой строке выравнен регистр букв***\n";
	RegisterControll(pchS); // выравниваем регистр
	cout << "***************************\n";

	cout << "\n***Слова, в которых есть буквы такие же как и первая буква слова***\n";
	strcpy(copyStr, pchS);
	WordStartLetter(copyStr); // выводим слова, в которых есть буквы такие же как и первая буква слова
	cout << "***************************\n";

	cout << "\n***В этой все буквы в словах передвинуты в конец слова***\n";
	NumberRedact(pchS); // перемещаем буквы в словах в конец слова
	cout << "***************************\n";

	File.close();  // Закрываем файл
	return 1;
}

void WriteText() {
	cin.get();

	char chS[500];
	char copyStr[500];
	char *pchS;

	cout << "Введите текст содержащий от 1 до 50 слов, в каждом из которых от 1 до 10 строчных латинских букв и цифр. Между соседними словами произвольное количество пробелов. За последним символом стоит точка.\nВвод: ";
	cin.getline(chS, 500);

	pchS = chS;
	cout << "\n***************************\n";

	cout << "\n***В этой строке удалены все повторные символы***\n";
	setlocale(0, ".866");
	RemovingDuplicateCharacters(pchS); // удаление повторных символов
	cout << "***************************\n";

	cout << "\n***В этой строке выравнен регистр букв***\n";
	setlocale(0, ".866");
	RegisterControll(pchS); // выравниваем регистр
	cout << "***************************\n";

	cout << "\n***Слова, в которых есть буквы такие же как и первая буква слова***\n";
	strcpy(copyStr, pchS);
	setlocale(0, ".866");
	WordStartLetter(copyStr); // выводим слова, в которых есть буквы такие же как и первая буква слова
	cout << "***************************\n";

	cout << "\n***В этой строке все буквы в словах передвинуты в конец слова***\n";
	setlocale(0, ".866");
	NumberRedact(pchS); // перемещаем буквы в словах в конец слова
	cout << "***************************\n";
}

int main()
{
	setlocale(0, "RU");

	int variant;
	cout << "Выберите способ работы со строкой:\n1 - Напечатать текст вручную\n2 - Вывести текст из файла\nВвод: ";
	cin >> variant;

	if (variant == 1) {
		WriteText();
	}
	else if (variant == 2){
		ReadFile("test.txt");
	}

	system("pause");

	return 0;
}