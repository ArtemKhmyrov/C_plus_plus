#include <iostream>//библиотека для потока ввода-вывода
#include <vector>//библиотека математических функций
#include <cmath>//библиотека математических функций

using namespace std;//директива

struct  frac //создаем структуру
{
	int a, b;//переменные
};

int gcd(int a, int b)//оператор 1
{
	
	a = abs(a);//возвращение модуля
	b = abs(b);//возвращение модуля
	while (b != 0) //цикл	
	{
		a %= b;//присвоение
		swap(a, b);//свапаем
	}
	
	return a;//оператор 2
}


frac red(frac с) //оператор 1
{
	
	int g = gcd(с.a, с.b);
	с.a /= g;// присвоение  деление а 
	с.b /= g;//присвоение  деление б 
	return с;//оператор 2
}

frac input() //оператор 1
{
	cout << "Введите числа" << endl;//вывод
	frac f;//переменная 
	char c;// тип
	cin >> f.a >> c >> f.b;//ввод
	return red(f);//оператор 2
}

void output(frac f)//оператор 
{
	cout << f.a << '/' << f.b;//вывод
}

frac sum_fr(frac x, frac y) //оператор 1
{
	frac sum;//переменная
	sum.a = x.a * y.b + y.a * x.b;//сумма а 
	sum.b = x.b * y.b;//сумма б
	sum = red(sum);//сумма
	cout << "Результат" << endl;//вывод
	return sum;//оператор 2
}

frac diff_fr(frac x, frac y)//оператор 1
{
	frac d;//переменная
	d.a = x.a * y.b - y.a * x.b;// от а 
	d.b = x.b * y.b;// от б
	d = red(d);
	cout << "Результат" << endl;//вывод
	return d;//оператор 2
}

frac prod_fr(frac x, frac y)//оператор 1
{
	frac p;//переменная
	p.a = x.a * y.a;// от а
	p.b = x.b * y.b;//от б
	p = red(p);
	cout << "Результат" << endl;//вывод
	return p;//оператор 2
}

frac quot_fr(frac x, frac y)//оператор 1
{
	frac q;//переменная
	swap(y.a, y.b);//свапаем
	q = prod_fr(x, y);

	return q;//оператор 2
}

double frac_to_double(frac x)//оператор 1
{
	cout << "Результат" << endl;//вывод
	return 1.0 * x.a / x.b; //оператор 2
}

frac double_to_frac(double x)//оператор 1
{
	frac f;//переменная
	int w_part = (int)x;
	int fr_part = (int)((x - w_part) * 1000);

	f.a = w_part * 1000 + fr_part;//присвоение а
	f.b = 1000;//присвоение б
	cout << "Результат" << endl;//вывод
	return (red(f));//оператор 2
}

int main()//оператор 1

{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int c;//переменные локальные 
	do 
	{
		frac a, b;//переменные глобальные
		a = input();//ввод
		b = input();//ввод


		output(sum_fr(a, b));//вывод
		cout << endl;//отступ
		output(diff_fr(a, b));//вывод
		cout << endl;//отступ
		output(prod_fr(a, b));//вывод
		cout << endl;//отступ
		output(quot_fr(a, b));//вывод
		cout << endl;//отступ
		cout << frac_to_double(a) << endl;//вывод
		cout << frac_to_double(b) << endl;//вывод
		output(double_to_frac(15.123));//вывод
		cout << endl;//отступ
		cout << "Хотите перезапустить программу?" << endl;//вывод
		cout << "Если да, нажмите 1 " << endl;//вывод
		cout << "Если нет,нажмите 2 " << endl;//вывод
		cin >> c;//ввод
	} 
	while (c != 2);//цикл
	system("pause");//задержка консоли
	return 0;//оператор 2
}
