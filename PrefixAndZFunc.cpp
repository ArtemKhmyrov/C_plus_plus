#include <iostream>//сиауты
#include<vector>//вектора
#include <algorithm>//для поиска максимума и минимума
#include<string>//для строки

using namespace std;//директива

//пока не нужно 

//string buildFromZ(z & int[], alphabet char[]) {
//
//
//	string s = ""
//		int prefixLength = 0 // длина префикса, который мы записываем
//		int j // позиция символа в строке, который будем записывать
//		int newCharacter = 0 // индекс нового символа
//		for i = 0 to z.size - 1
//			// мы не пишем какой-то префикс и не будем писать новый
//			if z[i] = 0 and prefixLength = 0
//				if newCharacter < alphabet.size
//					s += alphabet[newCharacter]
//					newCharacter++
//				else
//					s += alphabet[newCharacter - 1]
//					// нам нужно запомнить, что мы пишем префикс 
//					if z[i] > prefixLength
//						prefixLength = z[i]
//						j = 0
//						// пишем префикс
//						if (prefixLength > 0)
//						{
//							s += s[j]
//								j++
//								prefixLength--
//						}
//							
//							return s
//}


vector<int> PrefFunc(string s)//префикс функция 
{
	int n = (int)s.size();//переменная длина строки
	vector<int> pr(n);//новый вектор от n
	for (int i = 1; i < n; ++i)//идем по pr от i
	{
		int j = pr[i - 1];//переменная для подсчета нашего значения
		while (j > 0 && s[i] != s[j])//сравниваем наши значения и смотрим на нашу j пока не найдем отличающиеся
			j = pr[j - 1]; //уменьшаем нашу j на 1 и снова идем смотрим 
		if (s[i] == s[j]) //если совпадают то 
			j++;//переходим к следующему значению 
		pr[i] = j;//если дошли до конца и нет совпадений то 
	}
	return pr;//возвращаемся 
}

vector<int> ZFunc(string s) // з-функция 
{
	int n = (int)s.size();//переменная длина строки
	vector<int> z(n);//новый вектор от n
	for (int i = 1, l = 0, r = 0; i < n; ++i) //цикл для прозодки\создания
	{
		if (i <= r)//если наш элемент находится внутри от {L & R}
			z[i] = min(r - i + 1, z[i - l]);//минимальное значение для {z от i}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])//увеличиваем {z от i} на максимальное значение
			z[i]++;//прибавляем 
		if (i + z[i] - 1 > r)//если мы выходим за предел 
			l = i, r = i + z[i] - 1;//то сдвигаем наши границы
	}
	return z;//возвращаемся 
}



int main()
{
	setlocale(LC_ALL, "RUS");//русская клавиатура
	cout << "Введите элементы: ";//вывод
	string str;//переменная для ввода 
	cin >> str;//вводим наши значения

			cout << "Префикс -> ";//вывод
			for (auto upa : PrefFunc(str))//цикл для вывода префикс функции
			{
				cout << upa << " ";//вывод
			}
			cout << endl;//вывод
	
			cout << "Z -------> ";//вывод
			for (auto upa : ZFunc(str))//цикл для вывода z-функции
			{
				cout << upa << " ";//вывод
			}
			cout << endl;//отступ
	


	system("pause");//хадержка консоли
	return 0;//конец программы 
}

