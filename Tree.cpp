#include <iostream>
#include <string>
using namespace std;

struct tree //������� ��������� ������
{
	int inf;
	tree* right;//������ �������
	tree* left;//����� 
	tree* parent;//��������

};

tree* node(int x)//��������� ����
{
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;

}



void straight(tree* tr) //������
{
	if (NULL == tr) return;  //������� ���� ������ ������, �������
	{
		cout << tr->inf << " ";//������� ������ � ����������
		straight(tr->left);//������ ������� � ����� �����
		straight(tr->right);//������ � ������
	}
}


void back(tree* tr)//��������
{
	if (NULL == tr) return;//���� ������ ������ - �������
	{
		back(tr->left);//������ � ����� ����
		back(tr->right);//������ � ������ ����
		cout << tr->inf << " ";//������� ������
	}
}

void inorder(tree* tr)//������������ �����
{
	if (tr)
	{
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);

	}

}

void insert(tree*& tr, int x) //�������
{
	tree* n = node(x);
	if (!tr) tr = n; //���� ������ ������ - ������
	else {
		tree* y = tr;
		while (y) //���� ���� ���������
		{
			if (n->inf >= y->inf) //������ �����
				if (y->right)
					y = y->right;
				else
				{
					n->parent = y; //���� ���������� ������ ��������
					y->right = n;
					break;

				}
			else if (n->inf < y->inf)//����� �����

				if (y->left)
					y = y->left;
				else
				{
					n->parent = y;//���� ���������� ����� ��������
					y->left = n;
					break;

				}

		}

	}

}



tree* find(tree* tr, int x)//�����
{
	if (!tr || x == tr->inf)//����� ��� ����� �� ����� �����
		return tr;
	if (x < tr->inf)
		return find(tr->left, x);//���� �� ����� �����
	else
		return find(tr->right, x);//���� �� ������ �����

}



tree* Min(tree* tr)//����� min
{
	if (!tr->left) return tr;//��� ������ �������
	else return Min(tr->left);//���� �� ����� ����� �� �����

}

tree* Max(tree* tr)//����� max
{
	if (!tr->right) return tr;//��� ������� �������
	else return Max(tr->right);//���� �� ������ ����� �� �����

}

tree* Next(tree* tr, int x) //����� ����������
{
	tree* n = find(tr, x);

	if (n->right)//���� ���� ������ �������
		return Min(n->right);//min �� ������ �����
	tree* y = n->parent; //��������
	while (y && n == y->right) //���� �� ����� �� ����� ��� ���� - ������ �������
	{
		n = y;//���� ����� �� ������
		y = y->parent;

	}
	return y;//���������� ��������

}

tree* Prev(tree* tr, int x)//����� �����������
{
	tree* n = find(tr, x);
	if (n->left)//���� ���� ����� �������
		return Max(n->left);//max �� ����� �����
	tree* y = n->parent;//��������
	while (y && n == y->left)//���� �� ����� �� ����� ��� ���� - ����� �������
	{
		n = y;//���� ����� �� ������
		y = y->parent;

	}
	return y;//���������� ��������

}

void supdel(tree* L, tree* p) {
	if (L) { // ���� ���. ����� ���������
		insert(p, L->inf); // ������� ����������
		if (L->left) // ���� ���������� ����� �������, ��������� � ����
			supdel(L->left, p);
		if (L->right) // ���� ���������� ������ �������, ��������� � ����
			supdel(L->right, p);
	}
}

void Delete(tree*& tr, tree* v)//�������� ����
{
	tree* p = v->parent;
	//if (!p) tr = NULL; //������ �������� ���� ����
	//else 
	if (tr->left && tr->right && !tr->parent) { // ���� ���� ����� � ������, �� ��� �������� / (������)
		tree* L = tr->left; // ������� �������� ����� �����
		tree* R = tr->right; // � ������
		tr->inf = R->inf; // �������� ���������� ������ ����� ��� ��������
		tr->left = R->left;
		tr->right = R->right;
		supdel(L, tr); // � �� ��� ������� �������� 
	}
	else if (!tr->left && tr->right && !tr->parent) { // ���� ��� ������ � ��������, �� ���� ������ / (������)
		tree* R = tr->right;
		tr->inf = R->inf;
		tr->left = NULL;
		tr->right = R->right;
	}
	else if (tr->left && !tr->right && !tr->parent) { // ���� ��� ������� � ��������, �� ���� ����� / (������)
		tree* L = tr->left;
		tr->inf = L->inf;
		tr->left = L->left;
		tr->right = NULL;
	}
	else if (!v->left && !v->right) //���� ��� �����
	{
		if (p->left == v) //��������� � �������� ������ �� NULL
			p->left = NULL;
		if (p->right == v)
			p->right = NULL;
		delete v;

	}
	else if (!v->left || !v->right)//���� ������ ���� �������
	{
		if (!p)//���� ������� ������, � �������� 1 �������
		{
			if (!v->left)//���� ���� ������ �������
			{
				tr = v->right; //�� ���������� ������
				v->parent = NULL;

			}
			else //���������� ��� ������
			{

				tr = v->left;
				v->parent = NULL;

			}

		}
		else
		{
			if (!v->left) //���� ���� ������ �������
			{
				if (p->left == v) //���� ��������� ���� ���. ����� ��������
					p->left = v->right; //������� ���������� ���� ���������� ����� ��������

				else
					p->right = v->right; ////������� ���������� ���� ���������� ������

				v->right->parent = p; //��������� ������� ���������� ��� "���"

			}
			else //���������� ��� ������ �������
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
	else //���� ��� �������
	{
		tree* succ = Next(tr, v->inf);//��������� �� ��������� �����
		v->inf = succ->inf; //����������� ��������
		if (succ->parent->left == succ)//���� succ ����� �������
		{
			succ->parent->left = succ->right; //��� ������ ������� ���������� �����

			if (succ->right) //���� ���� ������� ����������
				succ->right->parent = succ->parent; //��� ��������� ���������� "���"

		}
		else //���������� ���� succ - ����sq �������
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
	setlocale(LC_ALL, "RUS");//������� ����������
	int n, x, t;//����������
	cout << "������� ���������� ��������� "; cin >> n;
	tree* tr = NULL;//������ ������ � ������� ����� ��� ������
	for (int i = 0; i < n; i++)//���� ��� ������
	{
		cout << i << ": ";
		cin >> x;//������ ��������
		insert(tr, x);//��������� ���� ��������

	}

	cout << "������������ ����� ";
	inorder(tr);//����� ������������� ������
	cout << endl;
	cout << "������ ����� ";
	straight(tr);//����� ������� ������
	cout << endl;
	cout << "�������� ����� ";
	back(tr);//����� ��������� ������
	cout << endl;
	cout << endl;


	cout << "������� �������, ������� ������ ������� "; cin >> x;//������ ��������
	if (find(tr, x))//���� �� ������� ������ ��� ������� ��
	{
		Delete(tr, find(tr, x));//�������
		cout << "������������ ����� ";
		inorder(tr);//����� ���. ������
		cout << endl;
		cout << "������ ����� ";
		straight(tr);//����� ������� ������
		cout << endl;
		cout << "�������� ����� ";
		back(tr);//����� ��������� ������
		cout << endl;
	}
	else cout << "������� �� ������\n";//����� ����� �� ������
	cout << endl;





	cout << "������� �������, ������� ������ ����� " << endl;
	cin >> x;//������ ���������� 
	if (find(tr, x))//����� �� ��������� �������� z 
	{
		cout << "����� ������� ������� - " << x << endl;//���� ���� - ������� ���� �������
	}
	else//�����
	{
		cout << "��� �� ������ ���������� �� ��������� ����� " << endl;//�����
	}


	cout << "������� �������, ������� ������ �������� " << endl;
	cin >> t;//������ ���������� 
	insert(tr, t);//����� �� ��������� �������� t

	cout << "������������ ����� ";
	inorder(tr);//����� ���. ������
	cout << endl;
	cout << "������ ����� ";
	straight(tr);//����� ������� ������
	cout << endl;
	cout << "�������� ����� ";
	back(tr);//����� ��������� ������
	cout << endl;
	cout << "�������� ���� ��������� " << endl;





	system("pause");//�������� �������
	return 0;//��������� ���������

}