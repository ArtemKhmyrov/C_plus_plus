#include <iostream>//���������� ��� ������ �����-������ 
#include <vector>//���������� �������� 
#include <algorithm>//���������� ���������� 

using namespace std;//��������� 

int main()//�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 

	cout << "������� ���������� ������: ";//�����
	int n; cin >> n;//������ ���������� ������ 
	vector<vector<int> > Gr(n);//�������� ���������� ������������ 

	cout << "������� ���������� �����: ";//�����
	int m; //���������� 
	cin >> m;//����

	cout << "������� ���� ������� ������:" << endl;//�����

	for (int i = 0; i < m; i++)//���� 
	{
		int perv, vtor;//���������� 
		cin >> perv >> vtor;//�������� ������ ���������

		Gr[perv].push_back(vtor);//������ � ������ 
	}

	for (int i = 0; i < n; i++) //���� 
	{
		int k = 0;//���������� 
		for (int j = 0; j < n; j++)//���� 
			if (find(Gr[j].begin(), Gr[j].end(), i) != Gr[j].end())//����� ����������� ������
				k++;//������� � ���������� �������� 
		cout << "����������� ������ �������" << i << ": " << k;//�����
		cout << endl;//������ 

	}

	system("pause");//�������� ������� 
	return 0;//���������� 
}