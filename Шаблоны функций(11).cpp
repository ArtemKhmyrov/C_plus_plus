#include <iostream>//���������� ��� ������ �����-������
#include <cmath>//���������� �������������� �������

using namespace std;//���������

template <typename X>//���������
X **create(X c, int n, int m)//���� ����������
{
	X **a = new X *[n];//��������� ������
	for (int i = 0; i < n; i++)//�������
	{
		a[i] = new X[m];//��������� ������
	}
	for (int i = 0; i < n; i++)//�������
	{
		for (int j = 0; j < m; j++)//�������
		{
			cout << "������� ����� ";//�����
			cin >> a[i][j];//����

		}
	}

	return a;//�������� 1 
}



template <typename x>//���������
void print(x **a, int n, int m)//����������
{
	for (int i = 0; i < n; i++, cout << endl)//�������
	{
		for (int j = 0; j < m; j++)//�������
		{
			cout << a[i][j] << " ";//����� ������� �� �����
		}
	}
	cout << endl;//������
}

template <typename x>//���������
x **change(x **a, int n, int m, int v)//����������
{
	for (int i = 0; i < n; i++)//���� ��� �������� �������
	{
		if (i % 2 != 0)//������� ����
		{
			for (int g = 0; g < m; g++)//���� ��� ��������
			{
				a[i][g] = v;//����������� ������ ����� � ������
			}
		}

	}
	return a;//�������� 2
}




int main()//�������� 3
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int n, m, w;//���� ����������
	cout << "������� n: ";//�����
	cout << endl;//������
	cin >> n;//����
	cout << "������� m: ";//�����
	cout << endl;//������
	cin >> m;//����
	cout << "������� w: ";//�����
	cin >> w;//����
	char c;//���
	do//�������� 4
	{
		cout << "������� ���:\n1 - int\n2 - double\n3 - char\n4 - float\n";//�����
		int k;//����������
		cin >> k;//����
		switch (k)//�������� 5 
		{
		case 1://���� 
		{
			int c = 1;//����������
			int **a = create(c, n, m);//������� ������ � �������
			cout << "INT:\n";//�����
			print(a, n, m);//������� ������
			a = change(a, n, m, w);//��������� � ��������� ��������� 
			cout << "New:\n";//�����
			print(a, n, m);//�����
			break;//���������� 
		}
		case 2://���� 
		{
			double c1 = 1;//����������
			double **a1 = create(c1, n, m);//������� ������ � �������
			cout << "DOUBLE:\n";//�����
			print(a1, n, m);//������� ������
			a1 = change(a1, n, m, w);//��������� � ��������� ��������
			cout << "New:\n";//�����
			print(a1, n, m);//�����
			break;//���������� 
		}
		case 3://���� 
		{
			char c2 = 1;//����������
			char **a2 = create(c2, n, m);//������� ������ � �������
			cout << "CHAR:\n";//�����
			print(a2, n, m);//������� ������
			a2 = change(a2, n, m, w);//��������� � ��������� ��������
			cout << "New:\n";//�����
			print(a2, n, m);//�����
			break;//���������� 

		}
		case 4://���� 
		{
			float c3 = 1;//����������
			float **a3 = create(c3, n, m);//������� ������ � �������
			cout << "FLOAT:\n";//�����
			print(a3, n, m);//������� ������
			a3 = change(a3, n, m, w);//��������� � ��������� ��������
			cout << "New:\n";//�����
			print(a3, n, m);//�����
			break;//���������� 
		}
		default: cout << "����������� ������� ������\n";//�����
		}
		cout << "��� ���? Y - ��, N - ���\n";//�����
		cin >> c;//����




	} while (c != 2);//�������� 6
	system("pause");//�������� �������
	return 0;//�������� 7
}


