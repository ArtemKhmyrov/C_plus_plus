#include <iostream>//для потока ввода-вывода
#include <string>//для строк
#include<algorithm>//библиотека для алгоритмов

using namespace std;//директива

struct tree //создаем структуру
{
	int inf;//переменная 
	tree* right;//правые ветки
	tree* left;//леевые ветки
	tree* parent;//для родителей

};

tree* node(int x)//начальный узел
{
	tree* n = new tree;//выделение памяти 
	n->inf = x;//
	n->left = n->right = NULL;//инициализация
	n->parent = NULL;//инициализация
	return n;//завершение

}

void insert(tree*& tr, int x)//оператор войд
{
	tree* n = node(x);//преобразование 
	if (!tr) tr = n; //если дерево пустое - корень
	else //условие если
	{
		tree* y = tr;//преобразование 
		while (y)//цикл пока (будем искать куда вставить значение)
		{ 
			if (n->inf > y->inf) //правая ветка
				if (y->right)//условие если 
					y = y->right;//вставляем 
				else //условие иначе 
				{
					n->parent = y; //узел становится правым ребенком
					y->right = n;//вставляем 
					break;//закрытие 

				}
			else if (n->inf < y->inf)//левая ветка

				if (y->left)//условие если 
					y = y->left;//вставляем 
				else //условие иначе 
				{
					n->parent = y;//узел становится левым ребенком
					y->left = n;//вставляем 
					break;//закритие 

				}

		}

	}

}
//симметричный обход
void postorder(tree* tr)//оператор войд
{
	if (tr) //условие если
	{
		postorder(tr->left);//лево
		cout << tr->inf << " ";//вывод
		postorder(tr->right);//право

	}

}

int list(tree* tr)//оператор инт 
{

	if (!tr)//если дерево пустое
		return 0;//закрываем
	int n = 0;//переменная 
	if (tr->left != NULL && tr->right == NULL)//условие если не равно 0
		n = 1;//1

	if (tr->left != NULL)//условие если не равно 0
		n += list(tr->left);//суммируем 
	if (tr->right != NULL)//условие если не равно 0
		n += list(tr->right);//суммирую
	return n;//завершение 
}

int main() //оператор инт мейн
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	int n, x;//переменные 
	cout << "Введите количество элементов: "; //вывод
	cin >> n;//ввод
	tree* tr = NULL;//инициализация
	for (int i = 0; i < n; i++)//цикл
	{
		cout << "Введите номер" "[" << i << "]";//вывод
		cin >> x;//ввод
		insert(tr, x);//вызываем функцию
	}
	postorder(tr);//вызываем функцию
	cout << endl;//отступ
	cout << "количество узлов с левыми потомками " << list(tr) << endl;//вывод
	system("pause");//задержка консоли
	return 0;//вывод
}