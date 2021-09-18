#include<iostream>//���������� ��� ������ �����-������ 
#include<cstdlib>//���������� ���
#include <algorithm>//���������� ��� ���������� 
#include<vector>//���������� ��������

using namespace std;//��������� 

void dfs(vector<vector<int>> &Gr, vector<int> &used, int x)//����������� ����� � �������
{
	used[x] = 1;//���������� 
	for (int i = 0; i < Gr[x].size(); i++) //����
	{
		if (!used[Gr[x][i]]) //������� ���� 
		{
			dfs(Gr, used, Gr[x][i]);//������� ���� 
		}
	}
}

int main()//�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 
	cout << "������� ���������� ������: ";//������ ���������� ������
	int n; //���������� 
	cin >> n;//����
	vector<vector<int> > Gr(n);//������� ��������� ������������ 
	vector <int> used(n);//������� �������������� ������ 
	cout << "������� ���������� �����: ";//������ ���������� �����
	int m; //���������� 
	cin >> m; //����

	cout << "������� ���� ������� ������:" << endl;//�����

	for (int i = 0; i < m; i++)//���� 
	{
		int perv, vtor;//���������� 
		cin >> perv >> vtor;//����

		Gr[perv].push_back(vtor);//�������� ������ ���������
		Gr[vtor].push_back(perv);//c������� ������ ���������
	}
	dfs(Gr, used, 0);//�������� ������� 
	if (find(used.begin(), used.end(), 0) == used.end()) //�������� �������� ���� ��������� ���� ���
		cout << "���� ���������" << endl;//�����
	else cout << "���� �� ���������" << endl;//������� ����� 
	system("pause");//�������� ������� 
	return 0;//���������� 
}