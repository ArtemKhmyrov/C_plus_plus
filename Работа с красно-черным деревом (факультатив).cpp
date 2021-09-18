#include <iostream>//библиотека для потока ввода-вывода 
#include <cstdlib>//библиотека ств 

/*
Красно-чёрное дерево - самобалансирующееся двоичное дерево поиска с операциями вставки и удаления узла.
*/

using namespace std;//директива 

enum status { INIT, INSERT, DELETE, PRINT, EXIT };//создаем структуру действий 
enum color { RED, BLACK };//создаем структуру крассно черного дерева 

struct node//Структура, описывающая узел дерева
{
	int inf;//переменная 
	node *parent;//родитель 
	color color;//Цвет 
	node *left;//левый 
	node *right;//правый 
};

class RBTree//Класс, описывающий дерево и его функции
{
	node *root; //Корень дерева
	node *q;
public:
	RBTree()
	{
		q = NULL;//обнуляем 
		root = NULL;//обнуляем 
	}

	node* successor(node *);
	node* uncle(node *);
	node* sibling(node *);
	node* find(int x);
	node* BSTReplace(node *);

	bool hasRedChild(node *);

	void swapColors(node*, node*);
	void swapValues(node *, node *);
	void moveDown(node *p, node *nParent);
	void insert();
	void insertFixUp(node *);
	void leftRotate(node *);
	void rightRotate(node *);
	void delet();
	void deleteFixUp(node *);
	void deletNode(node *);
	void printNode(node *);
	void disp();
	void display(node *);
	void find();
};

node *RBTree::uncle(node *p)
{
	if (p->parent == NULL || p->parent->parent == NULL)
	{
		return NULL;
	}

	if (p == p->parent->left)
	{
		return p->parent->parent->right;
	}
	else
	{
		return p->parent->parent->left;
	}
}

node *RBTree::sibling(node *p)
{
	if (p->parent == NULL)
	{
		return NULL;
	}

	if (p == p->parent->left)
	{
		return p->parent->right;
	}
	else
	{
		return p->parent->left;
	}
}

bool RBTree::hasRedChild(node *p)
{
	return (p->right != NULL && p->right->color == RED ||
		p->left != NULL && p->left->color == RED);
}

void RBTree::swapColors(node* n1, node* n2)
{
	color tmp;

	tmp = n1->color;
	n1->color = n2->color;
	n2->color = tmp;
}

void RBTree::swapValues(node *n1, node *n2)
{
	int tmp;
	tmp = n1->inf;
	n1->inf = n2->inf;
	n2->inf = tmp;
}

void RBTree::insert()
{
	int i = 0;
	cout << "Введите число для вставки: ";
	int n;
	cin >> n;
	cout << endl;
	node *p, *q;

	node *t = new node;
	t->inf = n;
	t->left = NULL;
	t->right = NULL;
	t->color = RED;
	p = root;
	q = NULL;

	if (root == NULL)//Если дерево абсолютно пустое, то новый элемент становится его корнем
	{
		t->parent = NULL;
		t->color = BLACK;
		root = t;
	}//иначе 
	else
	{
		while (p != NULL)//цикл, пока корень не пустой 
		{
			q = p;
			if (p->inf < t->inf)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}
		printNode(q);

		t->parent = q;

		if (q->inf < t->inf)
		{
			q->right = t;
		}
		else
		{
			q->left = t;
		}
	}
	insertFixUp(t);
}

void RBTree::insertFixUp(node *t)
{
	/*
	Вставляемый элемент всегда красный, а корень должен быть черным
	*/
	if (root == t)//условие если 
	{
		t->color = BLACK;//черный корень
		return;
	}

	node *par = t->parent;
	node *grandPar = t->parent->parent;
	node *unc = uncle(t);

	if (par->color != BLACK)//условие если: цвет родителя не равен черному цвету 
	{
		if (unc != NULL && unc->color == RED)
		{
			par->color = BLACK;
			unc->color = BLACK;
			grandPar->color = RED;
			insertFixUp(grandPar);
		}
		else
		{
			if (par == par->parent->left)
			{
				if (t == t->parent->left)
				{
					swapColors(par, grandPar);
				}
				else
				{
					leftRotate(par);
					swapColors(t, grandPar);
				}

				rightRotate(grandPar);
			}
			else
			{
				if (t == t->parent->left)
				{
					rightRotate(par);
					swapColors(t, grandPar);
				}
				else
				{
					swapColors(par, grandPar);
				}

				leftRotate(grandPar);
			}
		}
	}
}

/*
В поддереве ищет узел, который не имеет левого ребенка
*/
node* RBTree::successor(node *p)
{
	node *tmp = p;

	while (tmp->left != NULL)
	{
		tmp = tmp->left;
	}

	return tmp;
}

node *RBTree::BSTReplace(node *p)
{
	if (p->left != NULL && p->right != NULL)
	{
		return successor(p->right);
	}

	if (p->left == NULL && p->right == NULL)
	{
		return NULL;
	}

	if (p->right != NULL)
	{
		return p->right;
	}
	else
	{
		return p->left;
	}
}

void RBTree::deletNode(node *p)//цикл для удаления элемента в дереве
{
	node *u = BSTReplace(p);

	bool upBlack = ((u == NULL || u->color == BLACK) && (p->color == BLACK));
	node *par = p->parent;

	if (u == NULL)
	{
		if (p == root)
		{
			root = NULL;
		}
		else
		{
			if (upBlack)
			{
				deleteFixUp(p);
			}
			else
			{
				if (sibling(p) != NULL)
				{
					sibling(p)->color = RED;
				}
			}

			if (p == p->parent->left)
			{
				p->parent->left = NULL;
			}
			else
			{
				p->parent->right = NULL;
			}
		}

		delete p;
		cout << "Узел удален" << endl;
		return;
	}

	if (p->left == NULL || p->right == NULL)
	{
		if (p == root)
		{
			p->inf = u->inf;
			p->left = p->right = NULL;
			delete u;
			cout << "Узел удален" << endl;
		}
		else
		{
			if (p == p->parent->left)
			{
				p->parent->left = u;
			}
			else
			{
				p->parent->right = u;
			}

			delete p;
			cout << "Узел удален" << endl;
			u->parent = par;

			if (upBlack)
			{
				deleteFixUp(u);
			}
			else
			{
				u->color = BLACK;
			}
		}
		return;
	}

	swapValues(u, p);
	deletNode(u);
}


void RBTree::delet()
{
	if (root == NULL)
	{
		cout << "Дерево и так пустое, удалять нечего" << endl;
		return;
	}

	int x;
	cout << "Введите значение узла для удаления: ";
	cin >> x;
	cout << endl;

	node *p;
	p = root;
	node *y = NULL;
	node *q = NULL;
	bool isFound = false;

	p = find(x);

	if (p == NULL)
	{
		cout << "Искомый элемент не найден" << endl;
		return;
	}
	else
	{
		cout << "Удаляемый элемент: " << p->inf << endl;
		printNode(p);
		deletNode(p);
	}
}

void RBTree::deleteFixUp(node *t)
{
	if (t == root)
	{
		return;
	}

	node *sib = sibling(t);
	node *par = t->parent;

	if (sib == NULL)
	{
		deleteFixUp(par);
	}
	else
	{
		if (sib->color == RED)
		{
			par->color = RED;
			sib->color = BLACK;

			if (sib == sib->parent->left)
			{
				rightRotate(par);
			}
			else
			{
				leftRotate(par);
			}

			deleteFixUp(t);
		}
		else
		{
			if (hasRedChild(sib))
			{
				if (sib->left != NULL && sib->left->color == RED)
				{
					if (sib == sib->parent->left)
					{
						sib->left->color == sib->color;
						sib->color = par->color;
						rightRotate(par);
					}
					else
					{
						sib->left->color == sib->color;
						rightRotate(sib);
						leftRotate(par);
					}
				}
				else
				{
					if (sib == sib->parent->left)
					{
						sib->right->color == sib->color;
						leftRotate(sib);
						rightRotate(par);
					}
					else
					{
						sib->right->color == sib->color;
						sib->color = par->color;
						leftRotate(par);
					}
				}

				par->color = BLACK;
			}
			else
			{
				sib->color = RED;

				if (par->color == BLACK)
				{
					deleteFixUp(par);
				}
				else
				{
					par->color = BLACK;
				}
			}
		}
	}
}

void RBTree::moveDown(node *p, node *nParent)
{
	if (p->parent != NULL)
	{

		if (p == p->parent->left)
		{
			p->parent->left = nParent;
		}
		else
		{
			p->parent->right = nParent;
		}
	}
	nParent->parent = p->parent;
	p->parent = nParent;
}

void RBTree::leftRotate(node *p)
{
	node *newParent = p->right;

	if (p == root)
	{
		root = newParent;
	}

	moveDown(p, newParent);
	p->right = newParent->left;

	if (newParent->left != NULL)
	{
		newParent->left->parent = p;
	}

	newParent->left = p;
}

void RBTree::rightRotate(node *p)
{
	node *nParent = p->left;

	if (p == root)
	{
		root = nParent;
	}

	moveDown(p, nParent);
	p->left = nParent->right;

	if (nParent->right != NULL)
	{
		nParent->right->parent = p;
	}

	nParent->right = p;
}

void RBTree::printNode(node *t)
{
	cout << endl;
	cout << "Элемент: " << t->inf << endl;
	cout << "Цвет: ";
	if (t->color == RED)
	{
		cout << "Красный" << endl;
	}
	else
	{
		cout << "Черный" << endl;
	}

	if (t->parent != NULL)
	{
		cout << "Родитель: " << t->parent->inf << endl;
	}
	else
	{
		cout << "Родителя нет" << endl;
	}

	if (t->right != NULL)
	{
		cout << "Правый ребенок: " << t->right->inf << endl;
	}
	else
	{
		cout << "Правого ребенка нет" << endl;
	}
	if (t->left != NULL)
	{
		cout << "Левый ребенок: " << t->left->inf << endl;
	}
	else
	{
		cout << "Левого ребенка нет" << endl;
	}
	cout << endl;
}

void RBTree::disp()
{
	display(root);
}

void RBTree::display(node *p)
{
	if (root == NULL)
	{
		cout << "Пустое дерево" << endl;
		return;
	}

	if (p != NULL)
	{
		printNode(p);

		if (p->left)
		{
			display(p->left);
		}
		if (p->right)
		{
			display(p->right);
		}
	}
}

node *RBTree::find(int x)
{
	if (root == NULL)
	{
		return NULL;
	}

	node *p;
	p = root;
	bool isFound = false;

	//Поиск ключа в дереве
	while (p != NULL && isFound == false)
	{
		if (p->inf == x)
		{
			isFound = true;
		}

		if (isFound == false)
		{
			if (p->inf < x)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}
	}

	if (isFound == false)
	{
		return NULL;
	}
	else
	{
		return p;
	}
}

void RBTree::find()
{
	if (root == NULL)
	{
		cout << "Пустое дерево" << endl;
		return;
	}

	int x;
	cout << "Введите значение узла для поиска: ";
	cin >> x;
	cout << endl;

	node *p;
	p = root;
	bool isFound = false;

	//Поиск ключа в дереве
	while (p != NULL && isFound == false)
	{
		if (p->inf == x)
		{
			isFound = true;
		}

		if (isFound == false)
		{
			if (p->inf < x)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}
	}

	if (isFound == false)
	{
		cout << "Искомый элемент не найден" << endl;
		return;
	}
	else
	{
		cout << "Искомый элемент: " << p->inf << endl;
		printNode(p);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int choice = -1;
	status st = INIT;
	RBTree rbt;

	cout << "Красно-черное дерево" << endl << endl;

	while (st != EXIT)//цикл для создания условий программы 
	{
		cout << "1. Вставить элемент в дерево" << endl;
		cout << "2. Удалить элемент из дерева" << endl;
		cout << "3. Распечатать дерево" << endl;
		cout << "4. Найти элемент в дереве" << endl;
		cout << "5. Завершение программы" << endl;

		cout << "Введите пункт меню: ";
		cin >> choice;
		cout << endl;
		switch (choice)//кейсы 
		{
		case 1: rbt.insert();
			break;
		case 2: rbt.delet();
			break;
		case 3: rbt.disp();
			break;
		case 4: rbt.find();
			break;
		case 5: st = EXIT;
			break;
		default: cout << "Ошибка! Введите допустимое число" << endl;
		}
		cout << endl;
	}
}