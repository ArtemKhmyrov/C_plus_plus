#include <iostream>// ���������� ��� ������ �����-������
#include <time.h>//���������� ��� ����� ��������� �����
#include <stdio.h>//���������� ������������� ����� 
#include <stdlib.h>//���������� ��� ��������� ������

using namespace std;//��������� ���

int main()//�������� 1
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	int N;//��������� ����������
	cout << "������� ����� N: ";//�����
	cin >> N;//����
	int *a = new int[N];//�������� ������
	srand((unsigned)time(NULL));// ��������� �����
	for (int i = 0; i < N; i++)// ���� ��� ��������� ���������� �����
	{
		a[i] = rand() % 15;//���������� ������� ��������� ������
		cout << a[i] << " ";//�����
	}
	cout << endl;//����� �������
	int b, c;//���������� ����������
	cout << "������� ������ ��������: ";//�����
	cin >> b;//����
	cout << "������� ������ ��������: ";//�����
	cin >> c;//����
	if (b > c) swap(b, c);//��������� ���������� 
	int k = 0;//���� ��� ����� �����
	for (int i = 0; i < N; i++)//���� ��� �������
		if (a[i] % 4 == 0 && (a[i] >= b && a[i] <= c)) //�������� �� ������
		{
			k++;//��������� ���� �� �������� ���������� ��� �������
			cout << i <<" ";//�����
			
					}
	if (k == 0)//������� ����
		cout << "����� ����� ���!" << endl;//�����
	else//������� ����� 
	cout << endl;//�����
	

	system("pause");//�������� �������
	return 0;//�������� 2
}