#include <iostream>//���������� ��� ������ �����-������ 
#include <fstream>//����������� ��� ����� 
#include <cmath>//���������� ��� �������������� ������� 
#include <queue>//���������� ��� ������������� ������� 

using namespace std;//��������� 

struct tree//������� ��������� ������ 
{
	int inf;//���������� 
	tree *right;//������ ����� 
	tree *left;//����� 
};

tree *node(int x)//������ ������� 
{
	tree *n = new tree;//�������� ������ 
	n->inf = x;//�������������� 
	n->left = n->right = NULL;//������������� 
	return n;//���������� 
}

void Tree(tree *&tr, int n) //�������� ���� 
{
	int x;//���������� 
	if (n > 0)//������� ���� 
	{
		cout << "������� �������: ";//�����
		cin >> x;//����
		tr = node(x);//�������������� 
		int nl = n / 2;//���������� 
		int nr = n - nl - 1;//���������� 
		Tree(tr->left, nl);//����� ����� ������ 
		Tree(tr->right, nr);//������ ����� ������

	}

}

void create(tree *tr, int k) //�������� ����
{
	if (!tr); //������� ���� 
	else//������� ����� 
	{
		int R;//���������� 
		queue<tree*> rep, next;//�������
		tree *r = tr;//�������������� 
		rep.push(r);//������ 
		 R = NULL;//��������
		while (rep.size()) //���� ���� 
		{
			if (R == NULL)//������� ���� 
			{
				
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)//����
					cout << " ";//�����

			}
			tree *exp = rep.front();//�������������� 
			rep.pop();//������
			R++;//+!
			if (exp)//������� ����
			{
				cout << exp->inf;//�����
				next.push(exp->left);//����� ����� ������
				next.push(exp->right);//������ � ������ �����
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)//���� 
					cout << " ";//�����

			}

			if (!exp)//������� ����
			{
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)//����
					cout << " ";//�����
				cout << " ";//�����

			}
			if (rep.empty())//������� ���� 
			{
				cout << endl;//������
				swap(rep, next);//������ ������� 
				R = NULL;//�������� 
				k--;//-1
			}
		}
	}
}

int main()//�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 
	tree *tr = NULL;//������������� 
	int n, k, x;//���������� 
	cout << "������� ���������� ��������� ";//�����
	cin >> n;//����
	Tree(tr, n);//�����
     k = int(log((float)n) / log((float)2.0));
	create(tr, k);//�����
	cout << endl;//�����
	system("pause");//�������� ������� 
	return 0;//���������� 
}