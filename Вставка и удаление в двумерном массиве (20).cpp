#include <iostream> // ���������� ����������� ��� ������ �����-������

using namespace std;//���������

int main()//�������� 1
{ 
	setlocale(LC_ALL, "RUS"); // ������������� ������� ����������

		int x, y, m, g = 0; // ������ ����������
		cout << "������� ���������� ����� � �������: "; //�����
		cin >> x; //����
		cout << "������� ���������� �������� � �������: "; //�����
		cin >> y; //����
		cout << "������� ����o x: "; //�����
		cin >> m; //����
		int** a = new int *[x]; // �������� ������ ��� ������
		for (int i = 0; i < x; i++) //��� �������
		{
			a[i] = new int[y];//��������� ��� �������
		}

		for (int i = 0; i < x; i++) // ���� ��� �������
		{ 
			for (int j = 0; j < y; j++) // ���� ��� �������
			{
				cout << "������� ������ "; // �����
				cin >> a[i][j]; //����
			}
		}

		cout << endl; //������
		cout << "��������: " << endl; //�����

		for (int i = 0; i < x; i++) //���� ��� �������
		{ 
			for (int j = 0; j < y; j++) //���� ��� �������
			{
				cout << a[i][j] << " ";//�����
			}
			cout << endl;//������
		}

		for (int i = 0; i < y; i++) //���� ��� �������
		{ 
			for (int j = 0; j < x; j++)//���� ��� �������
			{
				if (a[j][i] % 10 == m)//������� ���� 
				{ 
					g++;//+1
				}
			}
			if (g > 0) //������� ���� ����� �������
			{ 
				for (int k = i; k < y - 1; k++)//������� ����
				{
					for (int p = 0; p < x; p++) //���� ��� �������
					{
						a[p][k] = a[p][k + 1];//����������� 
					}
				}
				y--; //�������
				i--; //�������
				g = 0;  //�������� ����
			}
		}

		cout << endl;//������
		cout << "���������: " << endl;//�����
		for (int i = 0; i < x; i++) //���� ��� �������
		{ 
			for (int j = 0; j < y; j++) //���� ��� �������
			{
				cout << a[i][j] << " ";//�����
			}
			cout << endl;//������
		}
		system("pause");//�������� �������
	   return 0;//�������� 2
}