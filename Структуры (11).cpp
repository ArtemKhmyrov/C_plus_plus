#include<iostream>//библиотека дл€ потока ввода-вывода
#include<string>//библиотека дл€ структуры

using namespace std;//директива

struct date//создаем структуру
{
	int day;//день
	int month;//мес€ц
	int year;//год
};

date STR_date(string str) //конвертируем из стринг в инт
{
	date data;//переменна€	
	string str1 = str.substr(0, 2);//день
	const char *sd = str1.c_str();//вызываем
	int dd = atoi(sd);//конвертируем
	data.day = dd;//день
	str1 = str.substr(3, 2);//мес€ц
	sd = str1.c_str();//вызываем
	dd = atoi(sd);//конвертируем
	data.month = dd;//мес€ц
	str1 = str.substr(6, 4);//год
	sd = str1.c_str();//вызываем
	dd = atoi(sd);//конвертируем 
	data.year = dd;//год
	return data;//оператор 2
}

bool vis(int y)//високосный год
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);//проверка на високосный год
}

int EndOfMonth(int m, int y)//поиск конца мес€ца
{
	switch (m)//оператор 3
	{
		//дл€ определени€ сколько дней в мес€це
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;//нечетные кейсы 
	case 4: case 6: case 9: case 11: return 30;//четные кейсы
	case 2://на февраль (28 дней)
		if //условие если
			(vis(y))
			return 29;//условие если
		else //условие иначе
			return 28;//оператор 4
	}
}

date Next(date x, int n) //оператор 1
{
	date y = x;
	if (x.day + n > EndOfMonth(x.month, x.year))//условие если
	{
		x.day += n - EndOfMonth(x.month, x.year);
		while (x.day + n > EndOfMonth(x.month, x.year) - 1) //цикл 
		{
			x.day -= EndOfMonth(x.month, x.year);//день
		}
		x.month += n / (EndOfMonth(x.month, x.year)) + 1;//мес€ц суммируем с n
	}
	else//условие иначе
		x.day += n;

	if (x.month > 12)//условие если
	{

		x.month = x.month + n / (EndOfMonth(x.month, x.year)) - 12;//к мес€цу
		x.year += n / 365 + 1;//к году прибавл€ем 1
	}
	return x;//оператор
}

void print(date x)//оператор который выводит все на экран при условии
{
	if (x.day < 10) cout << "0" << x.day << ".";//условие если
	else cout << x.day << ".";//условие иначе
	if (x.month < 10) cout << "0" << x.month << ".";//условие если
	else cout << x.month << ".";//условие иначе
	if (x.year < 10) cout << "000" << x.year;//условие елси
	else if (x.year < 100) cout << "00" << x.year;//условие иначе
	else if (x.year < 1000) cout << "0" << x.year;//условие иначе
	else//условие иначе
		cout << x.year;//вывод
	cout << endl;//отступ
}

int correct(string str) //оператор 1
{//проверка корректности данных
	if (str.length() != 10) return -1;
	for (string::size_type i = 0; i < str.length(); i++)//цикл
		if (i != 2 && i != 5) //условие если
		{
			if (!isdigit(str[i])) return -1;//если
		}
	date data = STR_date(str);
	if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;//условие если день
	if (data.month <= 0 || data.month > 12) return -3;//условие если мес€ц
	if (data.year == 0) return -4; //условие если год
	return 1;//оператор 2
}

int main()//оператор 1
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	string str; //структура
	int n;//переменна€
	cout << "¬ведите число в формате dd.mm.yyyy." << endl;//вывод
	getline(cin, str);//ввод
	cout << "¬ведите число";//вывод
	cin >> n;//ввод
	int fl = correct(str);
	if (fl == -1) cout << "ќшибка" << endl;//увсловие если
	else if (fl == -2) cout << "Ќекорректна€ форма записи дн€" << endl;//вывод
	else if (fl == -3) cout << "Ќекорректна€ форма записи мес€ца" << endl;//¬ывод
	else if (fl == -4) cout << "Ќекорректна€ форма записи года" << endl;//вывод
	else//условие иначе
	{
		date data = STR_date(str);
		date N_date = Next(data, n);//следующа€ дата
		print(N_date);//вывести
	}
	system("pause");//задержка консоли
	return 0;//оператор 2
}