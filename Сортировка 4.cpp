#include<iostream> //библиотека для потока ввода вывода
#include<fstream> //библиотека для строк
#include<string>  //для строк
#include<vector> //векторная библиотека
#include<iomanip> //стандартная библиотека

using namespace std;//директива


struct Worker//создаем структуру
{
	string secondname;//фамилия
	string position;//номер
	string date;//дата
	int experience = 0;
	int salary = 0;
};

vector<Worker> inFile()//вводим в файил(запись)
{

	ifstream in("input.txt");//считываем с файла
	vector<Worker> x;//создаем вектор х
	if (in) //условие если
	{
		while (in.peek() != EOF)//цикл ваил
		{
			Worker temp;//
			in >> temp.secondname;//считываем
			in >> temp.position;//считываем
			in >> temp.date;//считываем
			in >> temp.experience;//считываем
			in >> temp.salary;//считываем
			x.push_back(temp);
		}
		in.close();//закрываем файл
	}
	else//условие если
	{
		cerr << "Не удалось открыть файл" << endl;//не удалось открыть
	}

	return x;//завершаем
}

void print(vector<Worker> & workers)//запись
{

	ofstream out("output.txt");//запись в новый файл
	if (out)//условие если
	{
		for (Worker x : workers)//цикл
		{
			out << x.secondname << " ";
			out << x.position << " ";
			out << x.date << " ";

			out << endl;
		}
		out.close();//закрываем
	}
	else //условие иначе
	{
		cerr << "Не удалось открыть файл" << endl;//ошибка открытия файла
	}

}


void Puzirek(vector<Worker> & x)//цикл сортировки (блочная)
{
	for (int i = 0; i < x.size(); i++) //цикл
	{
		for (int j = x.size() - 1; j > i; j--)//цикл
		{
			if (x[j - 1].experience > x[j].experience)//условие если
			{
				Worker a = x[j - 1];//идем через костыли
				x[j - 1] = x[j];//присваиваем
				x[j] = a;//присваиваем
			}
		}
	}
}

void blsort(vector<Worker> & workers)//оператор сортировки
{

	int P = 4, m = 0, k = 0;//вводим переменные

	vector<Worker> v;//вектор 1
	vector<Worker> b;//вектор 2
	vector<Worker> n;//вектор 3
	vector<Worker> a;//вектор 4

	int min = INT_MAX;//минимальная переменная(чтобы не вылетал за вектор)
	int max = INT_MIN;//максимальная переменная
	for (int i = 0; i < workers.size(); i++)//цикл
	{
		if (max < workers[i].experience) //условие если
		{
			max = workers[i].experience;//сортируем
		}
		if (min > workers[i].experience) //Условие если
		{
			min = workers[i].experience;//сортируем
		}
	}

	m = (max - min) / P;//формула для корзинной сортировки

	for (int i = 0; i < workers.size(); i++)//цикл
	{

		Worker w = workers[i];

		if (w.experience < (min + (1 * m))) //условие если
		{
			v.push_back(w);
		}
		else if (w.experience < (min + (2 * m))) //условие если
		{
			b.push_back(w);
		}
		else if (w.experience < (min + (3 * m))) //условие если
		{
			n.push_back(w);
		}
		else //условие иначе
		{
			a.push_back(workers[i]);
		}
	}

	workers.clear();//очищаем

	Puzirek(v);//вектор 1
	Puzirek(b);//вектор 2
	Puzirek(n);//вектор 3
	Puzirek(a);//вектор 4

	for (Worker w : v)//для первого вектора
		workers.push_back(w);

	for (Worker w : b)//для второго вектора
		workers.push_back(w);

	for (Worker w : n)//для третьего вектор
		workers.push_back(w);

	for (Worker w : a)//для четвертого вектора
		workers.push_back(w);

}

int main() //оператор
{
	vector<Worker> x;//переменная х
	x = inFile();//файл
	blsort(x);
	print(x);//считывание
	system("pause");//задержка консоли
	return 0;//завершение
}