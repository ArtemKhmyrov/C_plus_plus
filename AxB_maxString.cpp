#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

ifstream in("input.txt");

struct alphavit
{
	string i;  //для буквы храним тут основную букву
	vector<string>letter; //для хранения смежных букв
	bool start = false;
	bool end = false;
};

struct ret //нашлась ли строка или размер строки
{
	bool fl = false;
	int m = 0;
};


ret maxString(vector <string> str, vector <alphavit> ID, int pos) 
{
	ret A;
	vector <string> x;
	string l;
	int s, e;

	for (int i = 0; i < ID.size(); i++) // Находим номера стартового и конечного элемента
		if (ID[i].start == true)
			s = i;
		else if (ID[i].end == true)
			e = i;

	x.push_back(ID[s].i); // Загружаем стартовый символ

	for (int i = pos; i < str.size(); i++) { // Пробегаемся по всей строке
		bool fl = false;
		for (int j = 0; j < x.size(); j++) // Сравниваем букву со смежным алфовитом
			if (str[i] == x[j])
			{
				l = str[i];
				A.fl = true;
				A.m = i - pos;
				fl = true;
				if (str[i] == ID[e].i) 
				{
					fl = false;
					A.m = i + 1 - pos;
				}
				x.clear();
				break;
			}


		for (int k = 0; k < ID.size(); k++) // Перезаписываем смежный алфавит
			if (l == ID[k].i)
				for (int j = 0; j < ID[k].letter.size(); j++)
					x.push_back(ID[k].letter[j]);
		if (fl == false)
			break;
	}
	return A;
}


int main()
{
	string smezh_letter;//Смежные буквы храним
	vector<alphavit>XXX;//А сюда загружаем все структуры
	string strock;//для хранения строки 
	alphavit english;//структура алфавита(в нее загружатся буквы) (заполнили б и загрузили в ХХХ)
	setlocale(LC_ALL, "RUS");
	int perem;
	in >> strock;
	ret maxletter;

	while (in.peek()!= EOF)
	{
			in >> english.i; //считываем букву
			in >> perem;//кол смежных
			for (int i = 0; i < perem; i++)//смежные для буквы
			{
				in >> smezh_letter;
				english.letter.push_back(smezh_letter);

			}

			in >> smezh_letter;
			if (smezh_letter == "true")
				english.start = true;
			else 
				english.start = false;


			in >> smezh_letter;
			if (smezh_letter == "true")
				english.end = true;
			else
				english.end = false;
			XXX.push_back(english);
			english.letter.clear();//очищаем вспомог вектор в котором хранили все смежные для буквы
	}
	cout << " 1 - задание " << endl;

	cout << "Строка " << strock << endl;
	for (int i = 0; i < XXX.size(); i++)
	{

		cout << "\nБуква " << XXX[i].i << endl;
		cout << "Смежные ";
		for (int j = 0; j < XXX[i].letter.size(); j++)
			cout << XXX[i].letter[j] << " ";
		cout << "\nНачальная " << XXX[i].start << endl;
		cout << "Конечная " << XXX[i].end << endl;

	}


	cout << "2 - задание" << endl;

	cout << "Введите номер позиции 0-" << strock.size() - 1 << ": ";
	cin >> perem;
	vector<string>strockpopolam;
		for (int i = 0; i < strock.size(); i++) {
			strockpopolam.push_back(strock.substr(i, 1));
		}
	maxletter = maxString(strockpopolam, XXX, perem);
	cout << "\n Нашлась ли необходимая строка: ";
	if (maxletter.fl)
		cout << "Да";
	else
		cout << "Нет";
	cout << "\n Максимальная длина строки, начиная с позиции [" << perem << "]: " << maxletter.m;
	cout << "\n Найденная строка: ";
	for (int i = perem; i < perem + maxletter.m; i++)
		cout << strockpopolam[i] << " ";
	cout << "\n" << endl;

	
	system("pause");
	return 0;
}