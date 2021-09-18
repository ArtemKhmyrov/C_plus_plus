#include <iostream>//библиотека в=дл€ потока ввода-вывода
#include <math.h>//библиотека математических функций
using namespace std;//директива
int main() //оператор 1
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int N = 100;//объ€вление переменной
	double eps;//переменна€
	cout << "eps="; cin >> eps;//вывод
	double a, S = 0; //начальные услови€
	int n = 0;//переменна€
	do//цикл
	{
		n++;
		a = -1 / (2 * n + 1 * (2 * n + 1));//формула
		S += a;
	} while (abs(a) > eps && n <= N);//цикл
	cout << "ќтвет S:" << S << endl;//вывод
	cout << "ќтвет n:" << n << endl;//вывод
	system("pause");//задержка консоли
	return 0;//оператор 2
}