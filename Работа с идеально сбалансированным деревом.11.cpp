#include <iostream>//библиотека для потока ввода-вывода 
#include <fstream>//библиотекая для строк 
#include <cmath>//библиотека для математических функций 
#include <queue>//библиотека для использование очереди 

using namespace std;//директива 

struct tree//создаем структуру дерева 
{
	int inf;//переменная 
	tree *right;//правая ветка 
	tree *left;//левая 
};

tree *node(int x)//дерево создаем 
{
	tree *n = new tree;//выделяем память 
	n->inf = x;//преобразование 
	n->left = n->right = NULL;//инициализация 
	return n;//завершение 
}

void Tree(tree *&tr, int n) //оператор войд 
{
	int x;//переменная 
	if (n > 0)//условие если 
	{
		cout << "введите элемент: ";//вывод
		cin >> x;//ввод
		tr = node(x);//преобразование 
		int nl = n / 2;//переменные 
		int nr = n - nl - 1;//переменные 
		Tree(tr->left, nl);//левая ветка запись 
		Tree(tr->right, nr);//правая ветка запись

	}

}

void create(tree *tr, int k) //оператор войд
{
	if (!tr); //условие если 
	else//условие иначе 
	{
		int R;//переменная 
		queue<tree*> rep, next;//очередь
		tree *r = tr;//преобразование 
		rep.push(r);//запись 
		 R = NULL;//обнуляем
		while (rep.size()) //цикл пока 
		{
			if (R == NULL)//условие если 
			{
				
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)//цикл
					cout << " ";//вывод

			}
			tree *exp = rep.front();//преобразование 
			rep.pop();//запись
			R++;//+!
			if (exp)//условие если
			{
				cout << exp->inf;//вывод
				next.push(exp->left);//левая ветвь запись
				next.push(exp->right);//запись в правую ветвь
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)//Цикл 
					cout << " ";//Вывод

			}

			if (!exp)//условие если
			{
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)//цикл
					cout << " ";//вывод
				cout << " ";//вывод

			}
			if (rep.empty())//условие если 
			{
				cout << endl;//отступ
				swap(rep, next);//меняем местами 
				R = NULL;//обнуляем 
				k--;//-1
			}
		}
	}
}

int main()//оператор инт менй 
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры 
	tree *tr = NULL;//инициализация 
	int n, k, x;//переменные 
	cout << "введите количество элементов ";//вывод
	cin >> n;//ввод
	Tree(tr, n);//вывод
     k = int(log((float)n) / log((float)2.0));
	create(tr, k);//вывод
	cout << endl;//вывод
	system("pause");//задержка консоли 
	return 0;//завершение 
}