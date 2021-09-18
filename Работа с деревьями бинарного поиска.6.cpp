#include <iostream>//���������� ��� ������ �����-������
#include <string>//���������� �����
#include<algorithm>//���������� ��������

using namespace std;//���������

struct tree //������� ���������
{
	int inf;//���������� 
	tree *right;//������ ����� 
	tree *left;//����� �����
	tree *parent;//��� ��������� 

};

tree *node(int x) //��������� ����
{
	tree *n = new tree;//��������� ������
	n->inf = x;//�������������� 
	n->left = n->right = NULL;//������������� 
	n->parent = NULL;//������������� 
	return n;//���������� 

}


void insert(tree *&tr, int x) //�������� ���� ��� ������� 
{
	tree *n = node(x);//�������������� 
	if (!tr) tr = n; //���� ������ ������, �� ��� ������
	else //������� ����� 
	{
		tree *y = tr;//�������������� 
		while (y) //���� ���� 
		{ 
			if (n->inf > y->inf) //������ �����
				if (y->right)//������� ���� 
						y = y->right;//��������� 
	      else //������� ���� 
	      {
	      n->parent = y;//�������� ����������� �����
	      y->right = n;// ��������� 
	      break;//��������� 
	      }
	      else if (n->inf < y->inf)//������� ����� 
	      
				if (y->left)//������� ���� 
				{
					y = y->left;//����� ����� 
				}
		   else //������� ����� 
		   {
			 n->parent = y;//�������� ������ ����� �������
			 y->left = n;//���������
			 break;//���������� 
		  
		   }
		}
	}
}
//������������ �����
void postorder(tree *tr)//�������� ����
{
	if (tr) //������� ����
	{
		postorder(tr->left);//����
		cout << tr->inf << " ";//�����
		postorder(tr->right);//�����

	}

}
//���������� ������ ������
int TreeHeight(tree *&tr)//�������� ���
{
	if (tr == 0)//������� ����
		return 0;//���������� 
	int left, right;//���������� 
	if (tr->left != NULL) //������� ���� �� ����� 0
	{
		left = TreeHeight(tr->left);//�������������� 
	}
	else//������� ����� 
		left = -1;//����� ����� 
	if (tr->right != NULL) //������� ���� �� ����� 0
	{
		right = TreeHeight(tr->right);//�������������� 
	}
	else//������� �����
		right = -1;//������ �����
	int max = left > right ? left : right;//��������� �������� 
	max += 1;//���������� 1
	return max;//���������� 

}

int main()//�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 
	int n, x;//���������� 
	cout << "������� ���������� ��������� " << endl; //�����
	cin >> n;//����
	tree *tr = NULL;//�������� 
	for (int i = 0; i < n; i++) //���� 
	{
		cout << "������� ���������� ���������" "[" << i << "]";//�����
		cin >> x;//����
		insert(tr, x);//����� ������� 
	}
	postorder(tr);//����� ������� 
	cout << endl;//������ 
	cout << "������ ������ " << TreeHeight(tr) << endl;//�����
	system("pause");//�������� �������
	return 0;//���������� 
}