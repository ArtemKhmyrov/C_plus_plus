#include <iostream>//библиотека для потока ввода-вывода
#include <string>//библиотека строк
#include<algorithm>//библиотека алгоритм

using namespace std;//директива

struct tree //создаем структуру
{
	int inf;//переменная 
	tree *right;//правая ветвь 
	tree *left;//левая ветвь
	tree *parent;//для родителей 

};

tree *node(int x) //начальный узел
{
	tree *n = new tree;//выделение памяти
	n->inf = x;//преобразование 
	n->left = n->right = NULL;//инициализация 
	n->parent = NULL;//инициализация 
	return n;//завершение 

}


void insert(tree *&tr, int x) //оператор войд для вставки 
{
	tree *n = node(x);//преобразование 
	if (!tr) tr = n; //если дерево пустое, то это корень
	else //условие иначе 
	{
		tree *y = tr;//преобразование 
		while (y) //цикл пока 
		{ 
			if (n->inf > y->inf) //правая ветка
				if (y->right)//условие если 
						y = y->right;//вставляем 
	      else //условие если 
	      {
	      n->parent = y;//родитель становиться узлом
	      y->right = n;// вписываем 
	      break;//звершение 
	      }
	      else if (n->inf < y->inf)//условие иначе 
	      
				if (y->left)//условие если 
				{
					y = y->left;//левая ветка 
				}
		   else //условие инчае 
		   {
			 n->parent = y;//родитель теперь левый ребенок
			 y->left = n;//вписываем
			 break;//завершение 
		  
		   }
		}
	}
}
//симметричный обход
void postorder(tree *tr)//оператор войд
{
	if (tr) //условие если
	{
		postorder(tr->left);//лево
		cout << tr->inf << " ";//вывод
		postorder(tr->right);//правл

	}

}
//определяем высоту дерева
int TreeHeight(tree *&tr)//оператор инт
{
	if (tr == 0)//условие если
		return 0;//завершение 
	int left, right;//переменные 
	if (tr->left != NULL) //условие если не равно 0
	{
		left = TreeHeight(tr->left);//преобразование 
	}
	else//условие иначе 
		left = -1;//левая ветка 
	if (tr->right != NULL) //условие если не равно 0
	{
		right = TreeHeight(tr->right);//преобразование 
	}
	else//условие иначе
		right = -1;//правая ветка
	int max = left > right ? left : right;//определям максимум 
	max += 1;//прибавляем 1
	return max;//завершение 

}

int main()//оператор инт мейн 
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры 
	int n, x;//переменные 
	cout << "Введите количество элементов " << endl; //вывод
	cin >> n;//ввод
	tree *tr = NULL;//обнуляем 
	for (int i = 0; i < n; i++) //цикл 
	{
		cout << "Введите количество элементов" "[" << i << "]";//вывод
		cin >> x;//ввод
		insert(tr, x);//вызов функции 
	}
	postorder(tr);//вызов функции 
	cout << endl;//отступ 
	cout << "высота дерева " << TreeHeight(tr) << endl;//Вывод
	system("pause");//задержка консоли
	return 0;//завершение 
}