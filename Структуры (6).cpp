#include <iostream>//библиотека для потока ввода-вывода
#include <vector>//библиотека математических функций

using namespace std;//директива

struct point//создание структуры
{
	double x, y;//глобальные переменные
};

point enter() //оператор 1
{
	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
	struct point a;
	cin >> a.x >> a.y;//ввод
	return a;//оператор 2
}

double square(struct point a, struct point b, struct point с) //функция
{ 
	return abs((с.x - a.x) * (b.y - a.y) - (с.y - a.y) * (b.x - a.x));//ищем точку относительно прямой
}

int main() //оператор 1
{
	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
	int n;//переменная 
	cout << "Введите координаты треугольника" << endl;//вывод
	point a = enter(), b = enter(), c = enter();  //треугольник
	cout << "Введите количество точек" << endl;//вывод
	cin >> n;//ввод
	vector<point> d(n);
	for (int i = 0; i < n; i++)//цикл
	{
		cout << "Введите координаты точки" << endl;//вывод
		d[i] = enter(); //точка
		if (square(a, b, d[i]) + square(a, c, d[i]) + square(b, c, d[i]) + square(a, b, c))//условие если (принадлежит), метод повторного сложения
			cout << "Принадлежит" << endl;//вывод
		else
			cout << "Не принадлежит" << endl;//вывод
	}
	system("pause");//задержка консоли
	return 0;//оператор 2
}