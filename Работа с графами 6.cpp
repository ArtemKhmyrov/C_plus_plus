#include <iostream>//библиотека для потока ввода-вывода 
#include <vector>//библиотека векторов 
#include <queue>//библиотека для очереди 

using namespace std;//директива 


void bfs(vector<vector<int>> &Gr, vector<int> &used, int x)// обход в глубину
{ 
	used[x] = 1; // отмечаем, что вершина посещена
	queue<int>b;//векторная переменная 
	b.push(x);//очередь 
	while (!b.empty())//цикл пока 
	{
		int y = b.front();//преобразованная переменная 
		b.pop();//стек
		for (int i = 0; i < Gr[y].size(); i++) //цикл
		{ 
			if (!used[Gr[y][i]]) //условие если 
			{
				b.push(Gr[y][i]);// вызываем смежные
				used[Gr[y][i]] = 1;//отмечаем вершину 
			}
		}
	}
}

int main() //оператор инт мейн
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры 
	int n, m, x;//переменные 
	cout << "Количество вершин графа: ";//вывод
	cin >> n;//ввод
	cout << "Количество ребер графа: ";//вывод
	cin >> m;//ввод
	vector <vector<int>> Gr(n);//Вектор 
	vector<int>used(n);//вектор 
	vector<int>check(n);//вектор
	cout << "Введите пары смежаных вершин  ";//вывод
	int a, b;//переменные 
	for (int i = 0; i < m; i++)//цикл
	{ 
		cin >> a >> b;//ввод
		Gr[a].push_back(b);//создаем список смежности
	}
	cout << "Введите вершину в которую существует путь: ";//вывод
	cin >> x;//ввод
	for (int k = 0; k < n; k++) //цикл 
	{
		if (k != x)//условие если 
		{
			bfs(Gr, used, k);//вызываем функцию
			if (used[x] == 1) cout << k << " ";//проверяем существует путь или нет
		}
		used.clear();//обнуляем 
		used.resize(n);//вставляем элемент
	}
	system("pause");//задержка консоли 
	return 0;//завершение 
}