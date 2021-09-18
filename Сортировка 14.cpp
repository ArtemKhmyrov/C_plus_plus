#include <iostream>//библиотека для потока ввода-вывода
#include <string>//библиотека для строк
#include <fstream>//библиотека для строк
#include <vector>//библиотека для векторов
#include <iomanip>//стандартная библиотека для сортировки

using namespace std;//директива

ifstream in("input.txt");//чтение
ofstream out("output.txt");//запись

struct date//создаем структуру
{ 
	int day, month, year;//вводим переменныу
};

struct workers //создаем структуру для человека
{ 
	string name;//имя
	string position;//номер
	date birth;//дата
	int experience;//стаж
	string salary;//зарплата
};

date str_to_int(string str1)//структура для перевода даты
{ 
	date work; string str; const char *sd; int dd;
	str = str1.substr(0, 2); //переводим из стринг в инт день
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//чтение
	work.day = dd;//запись
	str = str1.substr(3, 2); //переводим из стринг в инт месяц
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//чтение
	work.month = dd;//запись
	str = str1.substr(6, 4); //переводим из стринг в инт год
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//чтение 
	work.year = dd;//запись

	return work;//завершаем
}

void sel_sort(workers *a, int k)//сортировка выбором
{ 
	for (int i = 0; i < k - 1; i++)//цикл
	{
		int min = i;//переменная
		for (int j = i + 1; j < k; j++)//цикл
		{
			if (a[j].salary < a[min].salary)//условие если
				min = j;//присваиваем
			else if (a[j].salary == a[min].salary)//условие если
				if (a[j].birth.year < a[min].birth.year)//условие если
					min = j;//присваиваем
				else if (a[j].birth.year == a[min].birth.year)//условие если
					if (a[j].experience < a[min].experience)//условие если
						min = j;//присваиваем
		}
		if (min != i) //условие если
		{
			swap(a[i], a[min]);//свапаем
			min = i;//присваиваем
		}
	}
	for (int i = 0; i < 20; i++)//Цикл
	{
		out << setw(15) << left << a[i].name << setw(15) << left << a[i].position;//выравниваем
		if (a[i].birth.day < 10) out << left << '0' << a[i].birth.day << '.';//
		else out << left << a[i].birth.day << '.';//условие иначе
		if (a[i].birth.month < 10) out << '0' << a[i].birth.month << '.';//условие если
		else out << a[i].birth.month << '.';
		out << left << setw(6) << a[i].birth.year << left << setw(6) << a[i].experience << left << setw(10) << a[i].salary << '\n';//выравнивание
	}
}

int main()//оператор
{
	int n = 20; string str;//переменная 
	workers a[20]; //создание массива сотрудников
	for (int i = 0; i < n; i++) 
	{
		in >> a[i].name;//имя
		in >> a[i].position;//позиция
		in >> str;
		a[i].birth = str_to_int(str);//дата
		in >> a[i].experience;//стаж
		in >> a[i].salary;//зарплата
	}
	sel_sort(a, 20); //вызов сортировки
	in.close();//закрываем
	out.close();//закрываем
	system("pause");//задержка системы
	return 0;//завершение
}