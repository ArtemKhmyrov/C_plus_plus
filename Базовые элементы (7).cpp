#include <iostream> //библиотека дл€ потока ввода-вывода 
#include <cmath> //библиотека математических функций 
using namespace std; //директива 

int main() //оператор 1 
{
	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры 
	double x, y;//введение двух переменных
	cout <<"¬ведите х у, через пробел\n ";//вывод
	cin >>x >>y;
	double c = exp(sqrt(log(((x*x) + (y*y)) / ((cos(x)*cos(x) + cos(pow(x, 2)))))));//формула вычитани€
	cout << "F(x,y) равна:" << c << endl;//вывод
	system("pause"); //задержка консоли 
	return 0; //оператор 2 
}