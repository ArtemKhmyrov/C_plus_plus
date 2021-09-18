#include <iostream>//библиотека для потока ввода-вывода
#include <cmath>//библиотека математических функций

using namespace std;//директива

template <typename X>//заголовок
X **create(X c, int n, int m)//ввод переменных
{
	X **a = new X *[n];//выделение памяти
	for (int i = 0; i < n; i++)//строчка
	{
		a[i] = new X[m];//выделение памяти
	}
	for (int i = 0; i < n; i++)//строчка
	{
		for (int j = 0; j < m; j++)//столбец
		{
			cout << "Введите число ";//вывод
			cin >> a[i][j];//ввод

		}
	}

	return a;//оператор 1 
}



template <typename x>//заголовок
void print(x **a, int n, int m)//переменные
{
	for (int i = 0; i < n; i++, cout << endl)//строчка
	{
		for (int j = 0; j < m; j++)//столбец
		{
			cout << a[i][j] << " ";//вывод массива на экран
		}
	}
	cout << endl;//отступ
}

template <typename x>//заголовок
x **change(x **a, int n, int m, int v)//переменные
{
	for (int i = 0; i < n; i++)//цикл для создания строчки
	{
		if (i % 2 != 0)//условие если
		{
			for (int g = 0; g < m; g++)//цикл для столбцов
			{
				a[i][g] = v;//присваиваем другое число к строке
			}
		}

	}
	return a;//оператор 2
}




int main()//оператор 3
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int n, m, w;//ввод переменных
	cout << "Введите n: ";//вывод
	cout << endl;//отступ
	cin >> n;//ввод
	cout << "Введите m: ";//вывод
	cout << endl;//отступ
	cin >> m;//ввод
	cout << "Введите w: ";//вывод
	cin >> w;//ввод
	char c;//тип
	do//оператор 4
	{
		cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";//вывод
		int k;//переменная
		cin >> k;//ввод
		switch (k)//оператор 5 
		{
		case 1://кейс 
		{
			int c = 1;//переменнвя
			int **a = create(c, n, m);//создать массив в функции
			cout << "INT:\n";//вывод
			print(a, n, m);//функция вывода
			a = change(a, n, m, w);//вернуться к заданному оператору 
			cout << "New:\n";//вывод
			print(a, n, m);//вывод
			break;//завершение 
		}
		case 2://кейс 
		{
			double c1 = 1;//переменнвя
			double **a1 = create(c1, n, m);//создать массив в функции
			cout << "DOUBLE:\n";//вывод
			print(a1, n, m);//функция вывода
			a1 = change(a1, n, m, w);//вернуться к заданному оператор
			cout << "New:\n";//вывод
			print(a1, n, m);//вывод
			break;//завершение 
		}
		case 3://кейс 
		{
			char c2 = 1;//переменнвя
			char **a2 = create(c2, n, m);//создать массив в функции
			cout << "CHAR:\n";//вывод
			print(a2, n, m);//функция вывода
			a2 = change(a2, n, m, w);//вернуться к заданному оператор
			cout << "New:\n";//вывод
			print(a2, n, m);//вывод
			break;//завершение 

		}
		case 4://кейс 
		{
			float c3 = 1;//переменнвя
			float **a3 = create(c3, n, m);//создать массив в функции
			cout << "FLOAT:\n";//вывод
			print(a3, n, m);//функция вывода
			a3 = change(a3, n, m, w);//вернуться к заданному оператор
			cout << "New:\n";//вывод
			print(a3, n, m);//вывод
			break;//завершение 
		}
		default: cout << "Неправильно введены данные\n";//вывод
		}
		cout << "Еще раз? Y - да, N - нет\n";//вывод
		cin >> c;//ввод




	} while (c != 2);//оператор 6
	system("pause");//задержка консоли
	return 0;//оператор 7
}


