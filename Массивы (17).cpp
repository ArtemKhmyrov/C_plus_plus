#include <iostream>//���������� ��� ������ �����-������
#include <time.h>//���������� ��� ��������� �����
#include <stdio.h>//���������� ��� ��������� ��������
#include <stdlib.h>//���������� ��� ��������� ������

using namespace std;//��������� ���

int main()//�������� 1
{

	setlocale(LC_ALL, "RUS"); //������������� ������� ����������
	int N, C, A;//��������� ���������� 
	cout << "������� N: ";//�����
	cin >> N;//����
	int *a = new int [N];//������� ����� ��� �������
	srand ((unsigned)time(NULL));//��������� �����
	for (int i = 0; i < N; i++) //���� ��� ��������� ����� 
	{
		a[i] = rand() % 15;//������ ����� 
		cout << a[i] << " ";//����� ��������
	}
	cout << endl;

	if (N % 2 == 0)
	{
		A = N / 2 - 1;
		C = a[A+1];
		a[A + 1] = a[A];
		a[A] = C;
		for (int B = 0; B < N; B++)
		{
			cout << a[B] << " ";
		
		}
	}																

	if (N % 2 != 0)
	{
		A = (N - 1) / 2;
		C = a[A];
		a[A] = a[0];
		a[0] = C;
		for(int G = 0; G < N; G++)
		{
			cout << a[G] << " ";

		}
	}

	cout << endl;//����� ������ 

	system("pause");//�������� �������
	return 0;//�������� 2
}












