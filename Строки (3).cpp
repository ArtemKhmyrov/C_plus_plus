//Дано предложение. Удалить все слова, в которых встречаются ВСЕ буквы заданного слова.

#include <iostream> //библиотека для потока ввода-вывода
#include <string> //библиотека для работы со строками
using namespace std; //директива

int main()//оператор 1
{
	int c;
	do
	{
		setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
		string str, slovo, nxtwrd, punct = "!?,.:;- "; //переменные
		int count = 0, r = 0; //переменные константы 
		cout << "Введите предложение\n"; //вывод
		getline(cin, str); //ввод
		cout << "Введите слово\n"; //вывод
		getline(cin, slovo); //ввод
		str += '.';//стр + с точкой
		string::size_type pos = 0, k;
		string::size_type max = 0;
		k = str.find_first_of(punct); //находит конец первого слова
		while (k != string::npos) //цикл нахождения слов
		{
			nxtwrd = str.substr(pos, k - pos); //копирует данное слово
			for (int i = 0; i < nxtwrd.length(); i++) //проверяет буквы в слове
				if (slovo.find_first_of(nxtwrd[i]) != string::npos)//если нашел слово
					r++;//+1
			if (r == nxtwrd.length())//условие если
				str.erase(pos, k - pos);//удаление
			r = 0;//обнуляем 
			if (pos < str.length() - 1)//условие если
			{
				if (ispunct(str[k]) && isspace(str[k + 1])) pos = k + 2;  //если после знака препинания есть пробел
				else pos = k + 1;//иначе
				k = str.find_first_of(punct, pos); //ищем конец следующего слова
			}
			else k = string::npos;//иначе
		}
	
		cout << "Новое предложение\n" << str << endl; //вывод
		cout << "Хотите перезапустить программу? " << endl;
		cout << "Если да, нажмите 1" << endl;
		cout << "Если нет, нажмите 2 " << endl;
		cin >> c;
		system("pause"); //задержка консоли
		return 0;//оператор 2
	} while (c != 2);
}