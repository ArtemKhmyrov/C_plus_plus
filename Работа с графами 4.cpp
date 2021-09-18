#include<iostream>//библиотека для потока ввода-вывода 
#include<cstdlib>//библиотека стд
#include <algorithm>//библиотека для алгоритмов 
#include<vector>//библиотека векторов

using namespace std;//директива 

void dfs(vector<vector<int>> &Gr, vector<int> &used, int x)//рекурсивный обход в глубину
{
	used[x] = 1;//переменная 
	for (int i = 0; i < Gr[x].size(); i++) //цикл
	{
		if (!used[Gr[x][i]]) //условие если 
		{
			dfs(Gr, used, Gr[x][i]);//обходим граф 
		}
	}
}

int main()//оператор инт мейн 
{
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры 
	cout << "Введите количество вершин: ";//вводим количество вершин
	int n; //переменные 
	cin >> n;//ввод
	vector<vector<int> > Gr(n);//создаем векторное пространство 
	vector <int> used(n);//создаем дополнительный вектор 
	cout << "Введите количество ребер: ";//вводим количество ребер
	int m; //переменные 
	cin >> m; //ввод

	cout << "Вводите пары смежных вершин:" << endl;//вывод

	for (int i = 0; i < m; i++)//цикл 
	{
		int perv, vtor;//переменные 
		cin >> perv >> vtor;//ввод

		Gr[perv].push_back(vtor);//создание списка смежности
		Gr[vtor].push_back(perv);//cоздание списка смежности
	}
	dfs(Gr, used, 0);//вызываем функцию 
	if (find(used.begin(), used.end(), 0) == used.end()) //проверка является граф связанным илип нет
		cout << "Граф связанный" << endl;//вывод
	else cout << "Граф не связанный" << endl;//условие иначе 
	system("pause");//задержка консоли 
	return 0;//завершение 
}