#include <iostream>//библиотека дл€ потока ввода-вывода
#include <string>//библиотека дл€ строк

using namespace std;//директива

struct stack//создаем структуру
{ 
	int i;//вводим переменную
	stack *next;//стэк
};

void push(stack *&h, int x)//оператор войд
{ 
	stack *r = new stack;//выдел€ем пам€ть дл€ нового стека
	r->i = x;//переход в след элемент
	r->next = h;//ѕереход в след элемент
	h = r;//инициализаци€
}

void delEte(stack *&h) //оператор войд
{ 
	int i = h->i;//нова€ переменна€
	stack *r = h;//стэк
	h = h->next;//инициализаци€
	delete r;//удал€ем
}

int result(string str) //оператор инт
{
	stack *R = NULL; //инициализаци€
	for (int i = 0; i < str.length(); i++) //цикл дл€ добавлени€ скобок в стек
	{ 
		if (str[i] == '(')//условие если
			push(R, str[i]);//записываем 
		else if (str[i] == ')') //условие иначе
		{
			if (R == NULL)//инициализируем
				return 0;//завершение
			else delEte(R);//условие иначе
		}
	}
	if (R == NULL) //провер€ем, пустой стек или нет
		return 1;//все правильно
	else 
		return 2;//что-то не так
}

int main()//оператор инт мейн
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	string str;//вводим переменную
	cout << "¬ведите строку" << endl;//вывод
	cin >> str;//ввод

	if (result(str) == 0)//условие если
		cout << "«акрывающих скобок больше, чем открывающих" << endl;//вывод
	else if (result(str) == 1) //условие если
		cout << "¬сЄ правильно" << endl;//вывод
	else if (result(str) == 2) //условие если
		cout << "ќткрывающих скобок больше, чем закрывающих" << endl;//вывод
	cout << endl;//отступ
	system("pause");//задержка консоли
	return 0;//завершение 
}