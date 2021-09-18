//Создать структуру Hotel, содержащую следующие данные: ФИО туриста, дату прибытия и дату отъезда. Определить сколько дней каждый турист проведет в отеле. Необходима проверка на корректность ввода дат.



#include <iostream>//библиотека для потока ввода -вывода
#include <string>//библиотека для работы со строками

using namespace std;//директива

struct Hotel//создание структуры
{ 
	string fio;//объявление переменных
	int day1;//день въезда
	int month1;//месяц въезда
	int year1;//год въезда
	int day2;//день выезда
	int month2;//месяц выезда
	int year2;//год выезда
};

Hotel STR1_Hotel(string str1, string str2, string fio)//оператор 1
{
	Hotel hot;

	//для въезда
	string str = str1.substr(0, 2); //переводим из стринг в инт 
	const char *sd = str.c_str();//указывает на строку с завершающим нулем ( строку стиля C)
	int dd = atoi(sd);//конвертируем
	hot.day1 = dd;//день
	str = str1.substr(3, 2); //переводим из стринг в инт
	sd = str.c_str();//возвращает 
	dd = atoi(sd);//конвертируем
	hot.month1 = dd;//месяц
	str = str1.substr(6, 4); //переводим из стринг в инт 
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//конвертируем
	hot.year1 = dd;//год

	//для выезда
	str = str2.substr(0, 2); //переводим из стринг в инт 
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//конвертируем
	hot.day2 = dd;//день
	str = str2.substr(3, 2); //переводим из стринг в инт 
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//конвертируем
	hot.month2 = dd;//месяц
	str = str2.substr(6, 4); //переводим из стринг в инт 
	sd = str.c_str();//возвращаем
	dd = atoi(sd);//конвертируем
	hot.year2 = dd;//год

	hot.fio = fio; //инициалы

	return hot;//оператор 2
}

bool vis(int y) //проверка на високосный год
{ 
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);//цикл проверки
}

int EndOfMonth(int m, int y)//поиск конца месяца
{ 
	switch (m)//оператор 3
	{
		//для определения сколько дней в месяце
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

int correct(string str1, string str2, string fio) //проверка корректности данных
{ 
	if (str1.length() != 10) //условие если
		return -1;//оператор 5
	for (string::size_type i = 0; i < str1.length(); i++)//цикл
		if (i != 2 && i != 5) //условие если
		{
			if (!isdigit(str1[i]))//условие если
				return -1;//оператор 6
		}
	Hotel data = STR1_Hotel(str1, str2, fio);//структура (въезд выезд ФИО)
	if (data.day1 <= 0 || data.day1 > EndOfMonth(data.month1, data.year1))//условие если
		return -2;//оператор 7
	if (data.month1 <= 0 || data.month1 > 12)//месяц
		return -3;//оператор 8
	if (data.year1 == 0)//год
		return -4;//оператор 9
	if (str2.length() != 10)//выезд
		return -1;//оператор 10
	for (string::size_type i = 0; i < str2.length(); i++)//цикл
		if (i != 2 && i != 5)
		{
			if (!isdigit(str2[i]))
				return -1;//оператор 11
		}
	if (data.day2 <= 0 || data.day2 > EndOfMonth(data.month2, data.year2))//условие если
		return -2;//оператор 12 
	if (data.month2 <= 0 || data.month2 > 12)//месяц
		return -3;//оператор 14
	if (data.year2 == 0)//год
		return -4;//оператор 15
	return 1;//оператор 16
}

Hotel search(Hotel x)//оператор 17
{
	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
	Hotel y = x;
	int k = 0;//переменная 
	while (y.day1 != y.day2 || y.month1 != y.month2 || y.year1 != y.year2) //цикл
	{
		if (y.day1 < EndOfMonth(y.month1, y.year1)) //условие если
		{ 
			//не конец месяца
			y.day1++;
			k++;
		}
		else if (y.month1 < 12) //условие иначе
			
		{ 
			//конец месяца, но не конец года
			y.day1 = 1;
			y.month1++;
			k++;
		}
		else //условие иначе
		{ 
			//конец года
			y.day1 = 1;
			y.month1 = 1;
			y.year1++;
			k++;
		}
	}
	cout << y.fio << " провёл в отеле " << k << " дней" << '\n';//вывод
	return y;//оператор 18
}


int main()//оператор 19
{
	int c;//локальная переменная
	do//оператор
	{	
		
			setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
			string str1, str2, fio;//строки 
			cout << "Введите имя туриста\n";//вывод
			getline(cin, fio);//ввод данных ФИО
			cout << "Введите дату въезда в формате xx.yy.zzzz\n";//вывод
			getline(cin, str1);//ввод данных из потока въезда
			cout << "Введите дату отъезда в формате xx.yy.zzzz\n";//вывод
			getline(cin, str2);//ввод данных из потока выезда
			int fl = correct(str1, str2, fio);
			if (fl == -1)//условие если
				cout << "Некорректный ввод даты\n";//вывод
			else if (fl == -2)//условие если
				cout << "Некорректный день\n";//вывод
			else if (fl == -3)//условие если
				cout << "Некорректный месяц\n";//вывод
			else if (fl == -4)//условие если
				cout << "Некорректный год\n";//вывод
			else//условие если
			{
				Hotel Otvet = STR1_Hotel(str1, str2, fio);//структура
				Hotel Days = search(Otvet);//структура
			}
			
		
			std::cout << "Хотите перезапустить программу?" << endl;//вывод
		std::cout << "Если да, нажмите 1" << endl;//вывод
		std::cout << "Если нет, нажмите 2" << endl;//вывод
		cin >> c;//ввод

		
	}
	while (c != 2);//цикл
	system("pause");//задержка консоли
	return 0;//оператор 20
}
		
	
	

