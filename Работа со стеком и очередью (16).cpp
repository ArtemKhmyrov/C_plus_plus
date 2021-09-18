#include <iostream>//библиотека для потока ввода-вывода
using namespace std;//директива
struct queue //создаем структуру
{
	int inf;//переменная
	queue *next;//переменная
};
void push(queue *&h, queue *&t, int x) //оператор войд
{
	queue *r = new queue;//выделяем память 
	r->inf = x;//в следующий элемент
	r->next = NULL;//инициализация
	if (!h && !t)//условие если
		h = t = r;//и голова и хвост
	else//условие если
	{
		t->next = r;// приравнивание
		t = r;//приравнивание
	}
}
int pop(queue *&h, queue *&t)//оператор инт 
{
	queue *r = h;//приравнивание
	int i = h->inf;//переменная
	h = h->next;// в след элемент
	if (!h)//условие если
		t = NULL;//инициализация
	delete r;//удаление
	return i;//завершение
}
int main() //оператор инт мейн
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int n;//переменная 
	cout << "Введите количество элементов: " << endl;//вывод
	cin >> n;//ввод
	queue *head = NULL;//инициализация
	queue *tail = NULL;//инициализация
	cout << "Введите элементы: " << endl;//вывод
	for (int i = 0; i < n; i++)//цикл
	{
		int x;//переменная 
		cin >> x;//ввод
		push(head, tail, x);//запись
	}
	int min = head->inf, max = head->inf;//ищем минимальный и максимальный элементы
	queue *head1 = NULL;//инициализация 
	queue *tail1 = NULL;//инициализация
	while (head)//цикл пока
	{
		int x = pop(head, tail);//приравнивание
		if (x < min)//условие если
			min = x;//приравнивание
		if (x > max)//условие если
			max = x;//приравнивание
		push(head1, tail1, x);//считывание
	}
	queue *head2 = NULL;//инициализация
	queue *tail2 = NULL;//инициализация
	while (head1)//цикл пока
	{
		int x = pop(head1, tail1);//приравнивание
		if (x == max)//условие если
			push(head2, tail2, min);//запись
		push(head2, tail2, x);//запись
	}
	while (head2)//цикл пока
	{
		cout << pop(head2, tail2) << " ";//вывод
	}
	system("pause");//задержка консоли
	return 0;//оператор 
}