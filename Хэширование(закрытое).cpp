#include <iostream>//библиотека для потока ввода вывода
#include <fstream>//библиотека для строк
#include <string>//для строк 
#include <vector>//для векторов 
#include <iomanip>//структур
#include <algorithm>//алгоритмов

// Основная — линейное хеширование, вспомогательная — метод деления по году

using namespace std;//директива 

ifstream in("input.txt");//входной файл
ofstream out("output.txt");//выводной файл

struct date //структура времени
{
	int dd, mm, yy;//переменные для даты 
};

struct people//структура для человека 
{ 
	string Surname;//переменные 
	string Position;
	date Birthday;//переменная 
	int Experience;//переменные 
	int Salary;
};

date Str_to_Date(string str) //перевод из строки в время
{
	date x;//переменная 
	string t = str.substr(0, 2);//позиция 
	x.dd = atoi(t.c_str());//чтение \перевод
	t = str.substr(3, 2);
	x.mm = atoi(t.c_str());
	t = str.substr(6, 4);
	x.yy = atoi(t.c_str());
	return x;//завершение 
}

vector<people> inFile() //создание вектора людей
{ 
	vector <people> x;
	people t;
	while (in.peek() != EOF)
	{
		in >> t.Surname;
		in >> t.Position;
		string tmp;
		in >> tmp;
		t.Birthday = Str_to_Date(tmp);
		in >> t.Experience;
		in >> t.Salary;
		x.push_back(t);
	}
	return x;
}

void print(people x) 
{
	out << setw(10) << left << x.Surname << " ";
	out << left << setw(15) << x.Position << " ";
	if (x.Birthday.dd < 10)
		out << '0' << x.Birthday.dd << '.';
	else
		out << left << x.Birthday.dd << '.';
	if (x.Birthday.mm < 10)
		out << '0' << x.Birthday.mm << '.';
	else
		out << x.Birthday.mm << '.';
	out << left << setw(6) << x.Birthday.yy << " ";
	out << left << setw(2) << x.Experience << " ";
	out << left << setw(10) << x.Salary << endl;
}

void create(vector<int> &hesh, vector<people> x, int m) //создание хэш-таблицы
{
	int k, counter = 0, f;
	for (int i = 0; i < x.size(); i++)
	{
		int tmp = x[i].Birthday.yy;
		k = tmp % m;
		counter = 0;
		for (int i1 = k; i1 < hesh.size(); i1++)
		{
			f = k + counter;
			if (hesh[f] == NULL)
			{
				hesh[f] = tmp;
				break;
			}
			else
				counter++;
		}
	}
}

void print(vector<int> hesh) //вывод хэш-таблицы
{
	cout << "Таблица : " << endl;
	for (int i = 0; i < hesh.size(); i++)
		cout << hesh[i] << endl;
}

void search(vector<int> hesh, vector<people> a, int X, int m) // поиск необходимого элемента и его вывод
{
	bool flag = false;
	for (int i = 0; i < hesh.size(); i++)
	{
		if (hesh[i] == X)
		{
			cout << "Данные перемещены в output" << endl;
			for (int j = 0; j < a.size(); j++)
				if (a[j].Birthday.yy == X)
				{
					print(a[j]);
				}
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "Такой элемент не был найден" << endl;
}

int main() //оператор инт мейн 
{
	setlocale(LC_ALL, "RUS");
	vector<people> x;
	x = inFile();
	cout << "Введите размер таблицы :" << endl;
	int m;
	cin >> m;
	vector<int> hesh(m, NULL);
	create(hesh, x, m);
	print(hesh);
	cout << "Введите искомый элемент: " << endl;
	int X;
	cin >> X;
	search(hesh, x, X, m);
	system("pause");
	return 0;
}

//комментарии решил не писать, отвечу на ходу 