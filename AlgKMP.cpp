#include <iostream>//главная библиотека
#include <algorithm>//для поисков алгоритмов
#include<vector>//для векторов 
#include<string>//для строк

using namespace std;//директива

vector<int> prefix_function(string s)//префикс функция, тоже самое почти, что и в предыдущем задании
{
	int n = (int)s.size();//переменная для строки
	vector<int> pi(n);//вектор n от p{i}
	for (int i = 1; i < n; ++i) //ходим по pi от i
	{
		int j = pi[i - 1];//
		while (j > 0 && s[i] != s[j])//сравниваем символы пока не дошли до конца 
			j = pi[j - 1]; //если отличия нашли то уменьшаем j и повторяем так много раз
		if (s[i] == s[j])  ++j;//если они совпадают 
		pi[i] = j; // то pi от i теперь равно j + 1 и идем дальше
	}
	return pi;//возвращаем pi при условии что дошли до конца и не нашли совпадений 
}


int Find_Substirng(string pattern, string text)//функция 
{
	int end  = -1;//переменная 
	vector<int> pf = prefix_function(pattern);//вычисляем префиксы
	int marker = 0;//счетчик = 0 

	for (int i = 0; i < text.size(); i++)//идем по строке
	{
		while (marker > 0 && pattern[marker] != text[i]) { marker = pf[marker - 1]; }//пока не дошли до конца 
		if (pattern[marker] == text[i]) marker++;//если символы подстроки и паттерна совпадают то 
		if (marker == pattern.size())//идем и проверяем если дошли до конца подстроки то 
		{
			return end  = i - marker + 1;//возвращаем счетчик  
		}
	}
	return end ;//возвращаем рес 
}


int main()//главная функция 
{
	setlocale(LC_ALL, "RUS");//русская клавиатура
	cout << "Введите строку =>  ";//вывод
	string str;//переменная для строки 
	cin >> str;//ввод строки 
	cout << "Введите подстроку =>  ";//вывод
	string STR;//переменная для строки
	cin >> STR;//ввод
	int marker = Find_Substirng(STR, str);//вызываем функцию под новым именем 
	cout << "Подстрока =>  " << marker << "," << marker + STR.size() - 1  << endl;//вывод на экран 
	cout << endl;//отступ
	system("pause");//задержка консоли
	return 0;//завершение программы 
}

