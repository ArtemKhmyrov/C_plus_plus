#include <iostream>//���������� ��� ������ �����-������
using namespace std;//���������
struct queue //������� ���������
{
	int inf;//����������
	queue *next;//����������
};
void push(queue *&h, queue *&t, int x) //�������� ����
{
	queue *r = new queue;//�������� ������ 
	r->inf = x;//� ��������� �������
	r->next = NULL;//�������������
	if (!h && !t)//������� ����
		h = t = r;//� ������ � �����
	else//������� ����
	{
		t->next = r;// �������������
		t = r;//�������������
	}
}
int pop(queue *&h, queue *&t)//�������� ��� 
{
	queue *r = h;//�������������
	int i = h->inf;//����������
	h = h->next;// � ���� �������
	if (!h)//������� ����
		t = NULL;//�������������
	delete r;//��������
	return i;//����������
}
int main() //�������� ��� ����
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n;//���������� 
	cout << "������� ���������� ���������: " << endl;//�����
	cin >> n;//����
	queue *head = NULL;//�������������
	queue *tail = NULL;//�������������
	cout << "������� ��������: " << endl;//�����
	for (int i = 0; i < n; i++)//����
	{
		int x;//���������� 
		cin >> x;//����
		push(head, tail, x);//������
	}
	int min = head->inf, max = head->inf;//���� ����������� � ������������ ��������
	queue *head1 = NULL;//������������� 
	queue *tail1 = NULL;//�������������
	while (head)//���� ����
	{
		int x = pop(head, tail);//�������������
		if (x < min)//������� ����
			min = x;//�������������
		if (x > max)//������� ����
			max = x;//�������������
		push(head1, tail1, x);//����������
	}
	queue *head2 = NULL;//�������������
	queue *tail2 = NULL;//�������������
	while (head1)//���� ����
	{
		int x = pop(head1, tail1);//�������������
		if (x == max)//������� ����
			push(head2, tail2, min);//������
		push(head2, tail2, x);//������
	}
	while (head2)//���� ����
	{
		cout << pop(head2, tail2) << " ";//�����
	}
	system("pause");//�������� �������
	return 0;//�������� 
}