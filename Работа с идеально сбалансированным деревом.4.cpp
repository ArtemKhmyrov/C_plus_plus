#include <iostream>//���������� ��� ������ �����-������
#include <fstream> //���������� ��� ����� 
#include <cmath>//���������� ��� �������������� �������
#include <queue>||,b,kbjntrf 

using namespace std;//���������

struct tree //������� ��������� ������ 
{
	int inf;//���������� 
	tree *right;//�����
	tree *left;//����

};

tree *node(int x) //����� �� �����
{
	tree *n = new tree;//��������� ������ 
	n->inf = x;//�������������� 
	n->left = n->right = NULL;//������������� 
	return n;//���������� 

}

void Tree(tree *&tr, int n)//�������� ����
{
	int x, nl, nr;//���������� 
	if (n > 0) //������� ���� 
	{
			cout << "������� �������: " ;//�����
			cin >> x;//����
		tr = node(x);//�������������� 
		 nl = n / 2;//���������� �� 2 
		 nr = n - nl - 1;//��� - 1
		Tree(tr->left, nl);//������ � ����
		Tree(tr->right, nr);//������ � �����
	}
}

int list(tree *tr)//������� ������
{
	int t;//����������
	if (!tr)//������� ����
		return 0;//���������� 
	if (!tr->left && !tr->right)//������� ����
		return 1;//���������� 
	t =  list(tr->left) + list(tr->right);//��������� 
	return t;//���������� 
}

int main() //�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 
	tree *tr = NULL;//������������� 
	int n, x;//���������� 
	cout << "������� ���������� ���������: ";//�����
	cin >> n;//����
	Tree(tr, n);//����� ������� 
	cout << endl;//������ 
	cout << "���������� �������: " << list(tr) << endl;//�����
	cout << endl;//������ 
	system("pause");//�������� ������� 
	return 0;//���������� 
}