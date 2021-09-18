#include <iostream>//библиотека для потока ввода-вывода
#include <fstream> //БИБЛИОТЕКА ДЛЯ СТРОК 
#include <cmath>//библиотека для математических функций
#include <queue>||,b,kbjntrf 

using namespace std;//директива

struct tree //создаем структуру дерева 
{
	int inf;//переменная 
	tree *right;//право
	tree *left;//лево

};

tree *node(int x) //какая то шляпа
{
	tree *n = new tree;//выделение памяти 
	n->inf = x;//преобразование 
	n->left = n->right = NULL;//инициализация 
	return n;//завершение 

}

void Tree(tree *&tr, int n)//оператор войд
{
	int x, nl, nr;//переменная 
	if (n > 0) //условие если 
	{
			cout << "введите элемент: " ;//Вывод
			cin >> x;//ввод
		tr = node(x);//преобразование 
		 nl = n / 2;//количество на 2 
		 nr = n - nl - 1;//еще - 1
		Tree(tr->left, nl);//запись в лево
		Tree(tr->right, nr);//запись в право
	}
}

int list(tree *tr)//подсчет листов
{
	int t;//переменная
	if (!tr)//условие если
		return 0;//завершение 
	if (!tr->left && !tr->right)//условие если
		return 1;//завершение 
	t =  list(tr->left) + list(tr->right);//суммируем 
	return t;//завершение 
}

int main() //оператор инт мейн 
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры 
	tree *tr = NULL;//инициализация 
	int n, x;//переменные 
	cout << "введите количество элементов: ";//вывод
	cin >> n;//ввод
	Tree(tr, n);//вызов функции 
	cout << endl;//отступ 
	cout << "количество листьев: " << list(tr) << endl;//Вывод
	cout << endl;//отступ 
	system("pause");//задержка консоли 
	return 0;//завершение 
}