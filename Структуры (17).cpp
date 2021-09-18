#include <iostream>//���������� ��� ������ �����-������
#include <vector>//���������� �������������� �������
#include <cmath>//���������� �������������� �������

using namespace std;//���������

struct  frac //������� ���������
{
	int a, b;//����������
};

int gcd(int a, int b)//�������� 1
{
	
	a = abs(a);//����������� ������
	b = abs(b);//����������� ������
	while (b != 0) //����	
	{
		a %= b;//����������
		swap(a, b);//�������
	}
	
	return a;//�������� 2
}


frac red(frac �) //�������� 1
{
	
	int g = gcd(�.a, �.b);
	�.a /= g;// ����������  ������� � 
	�.b /= g;//����������  ������� � 
	return �;//�������� 2
}

frac input() //�������� 1
{
	cout << "������� �����" << endl;//�����
	frac f;//���������� 
	char c;// ���
	cin >> f.a >> c >> f.b;//����
	return red(f);//�������� 2
}

void output(frac f)//�������� 
{
	cout << f.a << '/' << f.b;//�����
}

frac sum_fr(frac x, frac y) //�������� 1
{
	frac sum;//����������
	sum.a = x.a * y.b + y.a * x.b;//����� � 
	sum.b = x.b * y.b;//����� �
	sum = red(sum);//�����
	cout << "���������" << endl;//�����
	return sum;//�������� 2
}

frac diff_fr(frac x, frac y)//�������� 1
{
	frac d;//����������
	d.a = x.a * y.b - y.a * x.b;// �� � 
	d.b = x.b * y.b;// �� �
	d = red(d);
	cout << "���������" << endl;//�����
	return d;//�������� 2
}

frac prod_fr(frac x, frac y)//�������� 1
{
	frac p;//����������
	p.a = x.a * y.a;// �� �
	p.b = x.b * y.b;//�� �
	p = red(p);
	cout << "���������" << endl;//�����
	return p;//�������� 2
}

frac quot_fr(frac x, frac y)//�������� 1
{
	frac q;//����������
	swap(y.a, y.b);//�������
	q = prod_fr(x, y);

	return q;//�������� 2
}

double frac_to_double(frac x)//�������� 1
{
	cout << "���������" << endl;//�����
	return 1.0 * x.a / x.b; //�������� 2
}

frac double_to_frac(double x)//�������� 1
{
	frac f;//����������
	int w_part = (int)x;
	int fr_part = (int)((x - w_part) * 1000);

	f.a = w_part * 1000 + fr_part;//���������� �
	f.b = 1000;//���������� �
	cout << "���������" << endl;//�����
	return (red(f));//�������� 2
}

int main()//�������� 1

{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int c;//���������� ��������� 
	do 
	{
		frac a, b;//���������� ����������
		a = input();//����
		b = input();//����


		output(sum_fr(a, b));//�����
		cout << endl;//������
		output(diff_fr(a, b));//�����
		cout << endl;//������
		output(prod_fr(a, b));//�����
		cout << endl;//������
		output(quot_fr(a, b));//�����
		cout << endl;//������
		cout << frac_to_double(a) << endl;//�����
		cout << frac_to_double(b) << endl;//�����
		output(double_to_frac(15.123));//�����
		cout << endl;//������
		cout << "������ ������������� ���������?" << endl;//�����
		cout << "���� ��, ������� 1 " << endl;//�����
		cout << "���� ���,������� 2 " << endl;//�����
		cin >> c;//����
	} 
	while (c != 2);//����
	system("pause");//�������� �������
	return 0;//�������� 2
}
