#include <iostream>//���������� ��� ������ �����-������
#include <string>//���������� ��� �����

using namespace std;//���������

struct stack//������� ���������
{ 
	int i;//������ ����������
	stack *next;//����
};

void push(stack *&h, int x)//�������� ����
{ 
	stack *r = new stack;//�������� ������ ��� ������ �����
	r->i = x;//������� � ���� �������
	r->next = h;//������� � ���� �������
	h = r;//�������������
}

void delEte(stack *&h) //�������� ����
{ 
	int i = h->i;//����� ����������
	stack *r = h;//����
	h = h->next;//�������������
	delete r;//�������
}

int result(string str) //�������� ���
{
	stack *R = NULL; //�������������
	for (int i = 0; i < str.length(); i++) //���� ��� ���������� ������ � ����
	{ 
		if (str[i] == '(')//������� ����
			push(R, str[i]);//���������� 
		else if (str[i] == ')') //������� �����
		{
			if (R == NULL)//��������������
				return 0;//����������
			else delEte(R);//������� �����
		}
	}
	if (R == NULL) //���������, ������ ���� ��� ���
		return 1;//��� ���������
	else 
		return 2;//���-�� �� ���
}

int main()//�������� ��� ����
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	string str;//������ ����������
	cout << "������� ������" << endl;//�����
	cin >> str;//����

	if (result(str) == 0)//������� ����
		cout << "����������� ������ ������, ��� �����������" << endl;//�����
	else if (result(str) == 1) //������� ����
		cout << "�� ���������" << endl;//�����
	else if (result(str) == 2) //������� ����
		cout << "����������� ������ ������, ��� �����������" << endl;//�����
	cout << endl;//������
	system("pause");//�������� �������
	return 0;//���������� 
}