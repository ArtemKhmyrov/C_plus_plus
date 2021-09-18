#include<iostream>//библиотека ввода-вывода
using namespace std;//директива

int main() //оператор 1
{
	const int N = 5; //количество блоков
	for (int i = 1; i <= N; i++) {//блоки
		for (int j = 1; j <= i; j++) //нечетные строки
			cout << j << "   ";//вывод цикла 
		cout << endl;//следующая строчка в выводе 
		for (int j = 1; j <= i; j++) //четные строки
			cout << 9 - 2 * (j - 1) << "   ";//вывод цикла 
		cout << endl;//следующая строчка в выводе 
	}

	system("pause");//задержка консоли 
	return 0;// оператор 2
}