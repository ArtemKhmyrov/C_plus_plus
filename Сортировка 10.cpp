#include <iostream>//библиотека для потока ввода-вывода
#include <string>//библиотека строк
#include <fstream>//библиотека строк
#include <vector>//библиотека для векторов

using namespace std;//директива

struct worker//создаем структуру
{
	string SURNAME; // фамилия
	string POSITION; // должность
	string DATE; //дата рождение
	string EXPERIENCE; // стаж 
	int s; // стаж число
	string SALARY; // зарплата строка
};

bool operator <=(worker a, worker b) //оператор сравнения
{
	if (a.POSITION < b.POSITION) return true;//условие если
	if (a.POSITION == b.POSITION && a.s < b.s) return true;//условие если
	return false;//завершение
}

int main()//оператор
{
	setlocale(LC_ALL, "RUS");//ИСПОЛЬЗОВАНИЕ РУССКОЙ КЛАВИАТУРЫ
	int surname = 0; // самая длинная фвмилия
	int position = 0; // самая длинная должность
	int experience = 0; // самый длинный стаж
	int salary = 0; // самая длинная зарплата
	string inp = "";
	vector<worker> vec;//вектор

	ifstream in("input.txt");//для чтения
	ofstream out("output.txt");//для записи
	

	while (in.peek() != EOF)//цикл ваил
	{
		string inp;//строки
		worker w;//переменная

		getline(in, inp);//считываем

		w.SURNAME = inp.substr(0, inp.find(' ', 0)); //фамилия
		inp.erase(0, inp.find(' ', 0) + 1);
		if (w.SURNAME.length() > surname) surname = w.SURNAME.length();//условие если

		w.POSITION = inp.substr(0, inp.find(' ', 0)); //должность
		inp.erase(0, inp.find(' ', 0) + 1);
		if (w.POSITION.length() > position)position = w.POSITION.length();//условие если

		w.DATE = inp.substr(0, inp.find(' ', 0)); //рождение
		inp.erase(0, inp.find(' ', 0) + 1);

		const char *sd;//вводим переменную
		w.EXPERIENCE = inp.substr(0, inp.find(' ', 0)); // стаж
		if (w.EXPERIENCE.length() > experience) experience = w.EXPERIENCE.length();
		inp.erase(0, inp.find(' ', 0) + 1);
		sd = w.EXPERIENCE.c_str();
		w.s = atoi(sd);

		w.SALARY = inp; // зарплата
		inp.erase();
		vec.push_back(w);
	}

	vector<worker>::iterator i = vec.begin();//оператор
	while (i < vec.end())//цикл ваил
	{
		if (i == vec.begin())//условие если
		{
			i++;//прибавляем
		}
		else if ((*(i - 1)) <= *i) //условие если
		{
			i++;//прибавляем
		}
		else //условие иначе
		{
			swap(*(i - 1), *i);//свапаем
			i--;//отнимаем
		}
	}

	for (vector<worker>::iterator i = vec.begin(); i < vec.end(); i++)//цикл
	{ // вывод вместе с форматированием теста
		if ((*i).SURNAME.length() < surname)//условие если
			for (int j = (*i).SURNAME.length(); j < surname; j++) (*i).SURNAME += " ";//Цикл
		if ((*i).POSITION.length() < position)//условие если
			for (int j = (*i).POSITION.length(); j < position; j++) (*i).POSITION += " ";//цикл
		if ((*i).EXPERIENCE.length() < experience)//условие если
			for (int j = (*i).EXPERIENCE.length(); j < experience; j++) (*i).EXPERIENCE = " " + (*i).EXPERIENCE;//цикл
		if ((*i).SALARY.length() < salary)//условие если
			for (int j = (*i).SALARY.length(); j < salary; j++) (*i).SALARY = " " + (*i).SALARY;//Цикл

		out << (*i).SURNAME << " " << (*i).POSITION << " " << (*i).DATE << " " << (*i).EXPERIENCE << " " << (*i).SALARY << endl;//выводим текст
	}

	in .close();//закрываем
	out.close();//закрываем
	system("pause");//задержка консоли
	return 0;//завершение
}