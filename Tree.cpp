#include <iostream>
#include <string>
using namespace std;

struct tree //создаем структуру дерева
{
	int inf;
	tree* right;//правый ребенок
	tree* left;//левый 
	tree* parent;//родитель

};

tree* node(int x)//начальный узел
{
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;

}



void straight(tree* tr) //прямой
{
	if (NULL == tr) return;  //условие если дерево пустое, выходим
	{
		cout << tr->inf << " ";//заносим дерево в переменную
		straight(tr->left);//кладем личинку в левую ветку
		straight(tr->right);//кладем в правую
	}
}


void back(tree* tr)//обратный
{
	if (NULL == tr) return;//если дерево пустое - выходим
	{
		back(tr->left);//кладем в левый узел
		back(tr->right);//кладем в правый узел
		cout << tr->inf << " ";//выводим дерево
	}
}

void inorder(tree* tr)//симметричный обход
{
	if (tr)
	{
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);

	}

}

void insert(tree*& tr, int x) //вставка
{
	tree* n = node(x);
	if (!tr) tr = n; //если дерево пустое - корень
	else {
		tree* y = tr;
		while (y) //ищем куда вставлять
		{
			if (n->inf >= y->inf) //правая ветка
				if (y->right)
					y = y->right;
				else
				{
					n->parent = y; //узел становится правым ребенком
					y->right = n;
					break;

				}
			else if (n->inf < y->inf)//левая ветка

				if (y->left)
					y = y->left;
				else
				{
					n->parent = y;//узел становится левым ребенком
					y->left = n;
					break;

				}

		}

	}

}



tree* find(tree* tr, int x)//поиск
{
	if (!tr || x == tr->inf)//нашли или дошли до конца ветки
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);//ищем по левой ветке
	else
		return find(tr->right, x);//ищем по правой ветке

}



tree* Min(tree* tr)//поиск min
{
	if (!tr->left) return tr;//нет левого ребенка
	else return Min(tr->left);//идем по левой ветке до конца

}

tree* Max(tree* tr)//поиск max
{
	if (!tr->right) return tr;//нет правого ребенка
	else return Max(tr->right);//идем по правой ветке до конца

}

tree* Next(tree* tr, int x) //поиск следующего
{
	tree* n = find(tr, x);

	if (n->right)//если есть правый ребенок
		return Min(n->right);//min по правой ветке
	tree* y = n->parent; //родитель
	while (y && n == y->right) //пока не дошли до корня или узел - правый ребенок
	{
		n = y;//идем вверх по дереву
		y = y->parent;

	}
	return y;//возвращаем родителя

}

tree* Prev(tree* tr, int x)//поиск предыдущего
{
	tree* n = find(tr, x);
	if (n->left)//если есть левый ребенок
		return Max(n->left);//max по левой ветке
	tree* y = n->parent;//родитель
	while (y && n == y->left)//пока не дошли до корня или узел - левый ребенок
	{
		n = y;//идем вверх по дереву
		y = y->parent;

	}
	return y;//возвращаем родителя

}

void supdel(tree* L, tree* p) {
	if (L) { // Если доп. ветка существет
		insert(p, L->inf); // Функция добавления
		if (L->left) // Если существует левый ребенок, смещаемся к нему
			supdel(L->left, p);
		if (L->right) // Если существует правый ребенок, смещаемся к нему
			supdel(L->right, p);
	}
}

void Delete(tree*& tr, tree* v)//удаление узла
{
	tree* p = v->parent;
	//if (!p) tr = NULL; //дерево содержит один узел
	//else 
	if (tr->left && tr->right && !tr->parent) { // Если есть левый и правый, но нет родителя / (Корень)
		tree* L = tr->left; // Создаем дубликат левой ветки
		tree* R = tr->right; // И правой
		tr->inf = R->inf; // Копируем информацию правой ветки как основную
		tr->left = R->left;
		tr->right = R->right;
		supdel(L, tr); // И на нее цепляем значение 
	}
	else if (!tr->left && tr->right && !tr->parent) { // Если нет левого и родителя, но есть правый / (Корень)
		tree* R = tr->right;
		tr->inf = R->inf;
		tr->left = NULL;
		tr->right = R->right;
	}
	else if (tr->left && !tr->right && !tr->parent) { // Если нет правого и родителя, но есть левый / (Корень)
		tree* L = tr->left;
		tr->inf = L->inf;
		tr->left = L->left;
		tr->right = NULL;
	}
	else if (!v->left && !v->right) //если нет детей
	{
		if (p->left == v) //указатель у родителя меняем на NULL
			p->left = NULL;
		if (p->right == v)
			p->right = NULL;
		delete v;

	}
	else if (!v->left || !v->right)//если только один ребенок
	{
		if (!p)//если удаляем корень, у которого 1 ребенок
		{
			if (!v->left)//если есть правый ребенок
			{
				tr = v->right; //он становится корнем
				v->parent = NULL;

			}
			else //аналогично для левого
			{

				tr = v->left;
				v->parent = NULL;

			}

		}
		else
		{
			if (!v->left) //если есть правый ребенок
			{
				if (p->left == v) //если удаляемый узел явл. левым ребенком
					p->left = v->right; //ребенок удаляемого узла становится левым ребенком

				else
					p->right = v->right; ////ребенок удаляемого узла становится правым

				v->right->parent = p; //родителем ребенка становится его "дед"

			}
			else //аналогично для левого ребенка
			{
				if (p->left == v)
					p->left = v->left;
				else
					p->right = v->left;
				v->left->parent = p;

			}
			delete v;

		}

	}
	else //есть оба ребенка
	{
		tree* succ = Next(tr, v->inf);//следующий за удаляемым узлом
		v->inf = succ->inf; //присваиваем значение
		if (succ->parent->left == succ)//если succ левый ребенок
		{
			succ->parent->left = succ->right; //его правый ребенок становится левым

			if (succ->right) //если этот ребенок существует
				succ->right->parent = succ->parent; //его родителем становится "дед"

		}
		else //аналогично если succ - правsq ребенок
		{
			succ->parent->right = succ->right;
			if (succ->right)
				succ->right->parent = succ->parent;

		}
		delete succ;

	}


}



int main()
{
	setlocale(LC_ALL, "RUS");//русская клавиатура
	int n, x, t;//переменные
	cout << "Введите количество элементов "; cin >> n;
	tree* tr = NULL;//дерево пустое в которое будем все пихать
	for (int i = 0; i < n; i++)//цикл для вывода
	{
		cout << i << ": ";
		cin >> x;//вводим элементы
		insert(tr, x);//вставляем наши элементы

	}

	cout << "Симметричный обход ";
	inorder(tr);//вызов симметричного обхода
	cout << endl;
	cout << "Прямой обход ";
	straight(tr);//вызов прямого обхода
	cout << endl;
	cout << "Обратный обход ";
	back(tr);//вызов обратного обхода
	cout << endl;
	cout << endl;


	cout << "Введите элемент, который хотите удалить "; cin >> x;//вводим элементы
	if (find(tr, x))//если мы находим нужный нам элемент то
	{
		Delete(tr, find(tr, x));//удаляем
		cout << "Симметричный обход ";
		inorder(tr);//вызов сим. обхода
		cout << endl;
		cout << "Прямой обход ";
		straight(tr);//вызов прямого обхода
		cout << endl;
		cout << "Обратный обход ";
		back(tr);//вызов обратного обхода
		cout << endl;
	}
	else cout << "Элемент не найден\n";//иначе вывод об ошибке
	cout << endl;





	cout << "Введите элемент, который хотите найти " << endl;
	cin >> x;//вводим количество 
	if (find(tr, x))//поиск по заданному элементу z 
	{
		cout << "Такой элемент имеется - " << x << endl;//если есть - выводим этот элемент
	}
	else//иначе
	{
		cout << "Нет ни одного совпадения по заданному ключу " << endl;//вывод
	}


	cout << "Введите элемент, который хотите вставить " << endl;
	cin >> t;//вводим количество 
	insert(tr, t);//поиск по заданному элементу t

	cout << "Симметричный обход ";
	inorder(tr);//вызов сим. обхода
	cout << endl;
	cout << "Прямой обход ";
	straight(tr);//вызов прямого обхода
	cout << endl;
	cout << "Обратный обход ";
	back(tr);//вызов обратного обхода
	cout << endl;
	cout << "Элементы были вставлены " << endl;





	system("pause");//задержка консоли
	return 0;//звершение программы

}