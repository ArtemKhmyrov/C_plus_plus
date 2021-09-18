#include <iostream>//���������� ��� ������ �����-������

using namespace std;//���������

struct spisok //������� ���������
{ 
	int i;//���������� 
	spisok *next;//���������� 
	spisok *back;//����������
};

void push(spisok *&h, spisok *&c, int m)//�������� ����
{ 
	spisok *C = new spisok;//�������� ������
	C->i = m;//������������
	C->next = NULL;//��������
	if (!h && !c) //������� ����
	{
		C->back = NULL;//��������
		h = C;//������������
	}
	else //������� �����
	{
		c->next = C;//�������������
		C->back = c;//�������������
	}
	c = C;//��������������
}

spisok *chetnye(spisok *h, spisok *c) //��������� 
{ 
	spisok *k = h;//���� ������ �������
	while (k) //���� ����
	{
		if (k->i % 2 == 0) //������� ����
			break;//���������� 
		k = k->next;//�����������
	}
	return k;//����������
}

void print(spisok *h, spisok *c)//�������� ����
{ 
	spisok *k = h;//����
	while (k)//���� ���� 
	{
		cout << k->i << " ";//�����
		k = k->next;//��������������
	}
}

void delEte(spisok *&h, spisok *&c, spisok *C) //�������� ����
{ //������� ����� C
	if (C == h && C == c) //���� ������������ ������� ������
		h = c = NULL;//��������
	else if (C == h) //������� ����
	{ 
		h = h->next;//��������� ��������� �������
		h->back = NULL;//��������
	}
	else if (C == c) //������� ����
	{ 
		c = c->back;//��������� ����������
		c->next = NULL;//��������
	}
	else //������� �����
	{
		C->next->back = C->back;//������������ � ����������� 
		C->back->next = C->next;//������������ � ���������� 
	}
	delete C;//�������
}

void result(spisok *&h, spisok *&c, int n) //�������� ����
{ 
	spisok *C = NULL;//��������
	C = chetnye(h, c);//������������
	while (C != NULL) //���� ���� 
	{
		delEte(h, c, C);//������� 
		C = chetnye(h, c);//������������
	}
	print(h, c);//����������
}


int main() //�������� ��� ����
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n, m;//����������
	spisok *a = NULL;//�������������
	spisok *b = NULL;//�������������
	cout << "������� ���������� ���������" << endl;//�����
	cin >> n;//����
	cout << "������� ��������" << endl;//�����
	for (int i = 0; i < n; i++)//�������
	{ 
		cin >> m;//����
		push(a, b, m);//������
	}
	cout << "�����: " << endl;//�����
	result(a, b, n);//�����
	system("pause");//�������� �������
	return 0;//�������� ����������
}
