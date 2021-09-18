#include <iostream>//библиотека дл€ потока ввода-вывода
#include <time.h>//библиотека дл€ рандомных чисел
#include <stdio.h>//библиотека дл€ различных операций
#include <stdlib.h>//библиотека дл€ выделени€ пам€ти

using namespace std;//директива стд

int main()//оператор 1
{

	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
	int N, C, A;//объ€вл€ем переменную 
	cout << "¬ведите N: ";//вывод
	cin >> N;//ввод
	int *a = new int [N];//удел€ем место дл€ массива
	srand ((unsigned)time(NULL));//рандомное число
	for (int i = 0; i < N; i++) //цикл дл€ вы€влени€ числа 
	{
		a[i] = rand() % 15;//подбор чисел 
		cout << a[i] << " ";//вывод массивов
	}
	cout << endl;

	if (N % 2 == 0)
	{
		A = N / 2 - 1;
		C = a[A+1];
		a[A + 1] = a[A];
		a[A] = C;
		for (int B = 0; B < N; B++)
		{
			cout << a[B] << " ";
		
		}
	}																

	if (N % 2 != 0)
	{
		A = (N - 1) / 2;
		C = a[A];
		a[A] = a[0];
		a[0] = C;
		for(int G = 0; G < N; G++)
		{
			cout << a[G] << " ";

		}
	}

	cout << endl;//нова€ строка 

	system("pause");//задержка консоли
	return 0;//оператор 2
}












