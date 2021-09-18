#include <iostream>//библиотека для потока ввода-вывода

using namespace std;//директива

struct spisok //создаем структуру
{ 
	int i;//переменная 
	spisok *next;//переменная 
	spisok *back;//переменная
};

void push(spisok *&h, spisok *&c, int m)//оператор войд
{ 
	spisok *C = new spisok;//выделяем память
	C->i = m;//приравниваем
	C->next = NULL;//обнуляем
	if (!h && !c) //условие если
	{
		C->back = NULL;//обнуляем
		h = C;//приравниваем
	}
	else //условие иначе
	{
		c->next = C;//приравнивание
		C->back = c;//приравнивание
	}
	c = C;//преобразование
}

spisok *chetnye(spisok *h, spisok *c) //структура 
{ 
	spisok *k = h;//ищем четный элемент
	while (k) //цикл пока
	{
		if (k->i % 2 == 0) //условие если
			break;//завершение 
		k = k->next;//преобразуем
	}
	return k;//завершение
}

void print(spisok *h, spisok *c)//оператор войд
{ 
	spisok *k = h;//ищем
	while (k)//цикл пока 
	{
		cout << k->i << " ";//вывод
		k = k->next;//преобразование
	}
}

void delEte(spisok *&h, spisok *&c, spisok *C) //уператор войд
{ //удаляем после C
	if (C == h && C == c) //если единственный элемент списка
		h = c = NULL;//обнуляем
	else if (C == h) //условие если
	{ 
		h = h->next;//проверяем следующий элемент
		h->back = NULL;//обнуляем
	}
	else if (C == c) //условие если
	{ 
		c = c->back;//проверяем предыдущий
		c->next = NULL;//обнуляем
	}
	else //условие иначе
	{
		C->next->back = C->back;//приравниваем к предыдущему 
		C->back->next = C->next;//приравниваем к следующему 
	}
	delete C;//удаляем
}

void result(spisok *&h, spisok *&c, int n) //оператор войд
{ 
	spisok *C = NULL;//обнуляем
	C = chetnye(h, c);//приравниваем
	while (C != NULL) //цикл пока 
	{
		delEte(h, c, C);//удаляем 
		C = chetnye(h, c);//приравниваем
	}
	print(h, c);//записываем
}


int main() //оператор инт мейн
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int n, m;//переменные
	spisok *a = NULL;//инициализация
	spisok *b = NULL;//инициализация
	cout << "Введите количество элементов" << endl;//вывод
	cin >> n;//ввод
	cout << "Введите элементы" << endl;//вывод
	for (int i = 0; i < n; i++)//функция
	{ 
		cin >> m;//ввод
		push(a, b, m);//запись
	}
	cout << "Ответ: " << endl;//вывод
	result(a, b, n);//вывод
	system("pause");//задержка консоли
	return 0;//оператор завершения
}
