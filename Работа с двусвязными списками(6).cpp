#include <iostream>//���������� ��� ������ �����-������

using namespace std;//���������

struct spisok//������� ���������
{ 
	int i;//����������
	spisok *next;//��������� 
	spisok *back;//����������
};

void push(spisok *&h, spisok *&f, int z) //�������� ����
{ 
	spisok *r = new spisok;//�������� ������
	r->i = z;//
	r->next = NULL;//�������������

	if (!h and !f) //������� ����
	{
		r->back = NULL;//�������������
		h = r;//�������������
	}
	else //������� �����

	{
		f->next = r;//������������� ���������� ��������
		r->back = f;//������������� ����������� ��������
	}
	f = r;//��������������
}

spisok *chetnye(spisok *h, spisok *f)//��������� 
{ 
	spisok *w = h;//�������������� 
	while (w) //���� ����
	{
		if (w->i % 2 !=1)//������� ���� (��� ������� ��������)
		break;//����������
		w = w->next;//�������������� 
	}
	return w;//���������� 
}

void print(spisok *h, spisok *f)//�������� ����
{ 
	spisok *w = h;//��������������
	while (w) //���� ���� 
	{
		cout << w->i << " ";//�����
		w = w->next;//�������������� 
	}
}

void result(spisok *&h, spisok *&f, int n) //�������� ����
{ //������� ��� ��������� ������
	spisok *R = NULL;//�������������
	spisok *k = NULL;//������������� 
	spisok *w = h; //�������������� 
	int z;//����������
	R = chetnye(w, f);//�������������� 
	while (R != NULL)//���� ���� 
	{
		k = R->back;//��������������
		while (w != R)//���� ���� 
		{
			swap(R->i, k->i);//������ ������� ��������
			k = k->back;//�������������� 
			R = R->back;//�������������� 
		}
		w = w->next;//�������������� 
		R = chetnye(w, f);//�������������� 
	}
	print(h, f);//��������� 
}

int main() //�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n, z;//����������
	spisok *a = NULL;//�������������
	spisok *b = NULL;//�������������
	cout << "������� ���������� ���������" << endl;//�����
	cin >> n;//����
	cout << "������� ��������" << endl;//�����
	for (int i = 0; i < n; i++) //����
	{ 
		cin >> z;//����
		push(a, b, z);//������
	}
	result(a, b, n);//�����
	system("pause");//�������� �������
	return 0;//���������� 
}