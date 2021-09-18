#include <iostream>//библиотека для потока ввода-вывода

using namespace std;//директива

struct spisok//создаем структуру
{ 
	int i;//переменная
	spisok *next;//следующие 
	spisok *back;//предыдущие
};

void push(spisok *&h, spisok *&f, int z) //оператор войд
{ 
	spisok *r = new spisok;//выделяем память
	r->i = z;//
	r->next = NULL;//инициализация

	if (!h and !f) //условие если
	{
		r->back = NULL;//инициализация
		h = r;//приравнивание
	}
	else //условие иначе

	{
		f->next = r;//приравнивание следующего элемента
		r->back = f;//приравнивание предыдущего элемента
	}
	f = r;//преобразование
}

spisok *chetnye(spisok *h, spisok *f)//структура 
{ 
	spisok *w = h;//преобразование 
	while (w) //цикл пока
	{
		if (w->i % 2 !=1)//условие если (для четного элемента)
		break;//завершение
		w = w->next;//преобразование 
	}
	return w;//завершение 
}

void print(spisok *h, spisok *f)//оператор войд
{ 
	spisok *w = h;//преобразование
	while (w) //цикл пока 
	{
		cout << w->i << " ";//вывод
		w = w->next;//преобразование 
	}
}

void result(spisok *&h, spisok *&f, int n) //оператор войд
{ //функция для изменения списка
	spisok *R = NULL;//инициализация
	spisok *k = NULL;//инициализация 
	spisok *w = h; //преобразование 
	int z;//переменные
	R = chetnye(w, f);//преобразование 
	while (R != NULL)//цикл пока 
	{
		k = R->back;//преобразование
		while (w != R)//цикл пока 
		{
			swap(R->i, k->i);//меняем местами элементы
			k = k->back;//преобразование 
			R = R->back;//преобразование 
		}
		w = w->next;//преобразование 
		R = chetnye(w, f);//преобразование 
	}
	print(h, f);//добавляем 
}

int main() //оператор инт мейн 
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int n, z;//переменные
	spisok *a = NULL;//инициализация
	spisok *b = NULL;//инициализация
	cout << "Введите количество элементов" << endl;//вывод
	cin >> n;//ввод
	cout << "Введите элементы" << endl;//вывод
	for (int i = 0; i < n; i++) //цикл
	{ 
		cin >> z;//ввод
		push(a, b, z);//запись
	}
	result(a, b, n);//вывод
	system("pause");//задержка консоли
	return 0;//завершение 
}