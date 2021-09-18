#include <iostream>//���������� ��� ������ �����-������
#include <vector>//���������� �������������� �������

using namespace std;//���������

struct point//�������� ���������
{
	double x, y;//���������� ����������
};

point enter() //�������� 1
{
	setlocale(LC_ALL, "RUS"); //������������� ������� ����������
	struct point a;
	cin >> a.x >> a.y;//����
	return a;//�������� 2
}

double square(struct point a, struct point b, struct point �) //�������
{ 
	return abs((�.x - a.x) * (b.y - a.y) - (�.y - a.y) * (b.x - a.x));//���� ����� ������������ ������
}

int main() //�������� 1
{
	setlocale(LC_ALL, "RUS"); //������������� ������� ����������
	int n;//���������� 
	cout << "������� ���������� ������������" << endl;//�����
	point a = enter(), b = enter(), c = enter();  //�����������
	cout << "������� ���������� �����" << endl;//�����
	cin >> n;//����
	vector<point> d(n);
	for (int i = 0; i < n; i++)//����
	{
		cout << "������� ���������� �����" << endl;//�����
		d[i] = enter(); //�����
		if (square(a, b, d[i]) + square(a, c, d[i]) + square(b, c, d[i]) + square(a, b, c))//������� ���� (�����������), ����� ���������� ��������
			cout << "�����������" << endl;//�����
		else
			cout << "�� �����������" << endl;//�����
	}
	system("pause");//�������� �������
	return 0;//�������� 2
}