#include <iostream>//���������� ��� ������ �����-������ 
#include <vector>//���������� �������� 
#include <queue>//���������� ��� ������� 

using namespace std;//��������� 


void bfs(vector<vector<int>> &Gr, vector<int> &used, int x)// ����� � �������
{ 
	used[x] = 1; // ��������, ��� ������� ��������
	queue<int>b;//��������� ���������� 
	b.push(x);//������� 
	while (!b.empty())//���� ���� 
	{
		int y = b.front();//��������������� ���������� 
		b.pop();//����
		for (int i = 0; i < Gr[y].size(); i++) //����
		{ 
			if (!used[Gr[y][i]]) //������� ���� 
			{
				b.push(Gr[y][i]);// �������� �������
				used[Gr[y][i]] = 1;//�������� ������� 
			}
		}
	}
}

int main() //�������� ��� ����
{
	setlocale(LC_ALL, "RUS");//������������� ������� ���������� 
	int n, m, x;//���������� 
	cout << "���������� ������ �����: ";//�����
	cin >> n;//����
	cout << "���������� ����� �����: ";//�����
	cin >> m;//����
	vector <vector<int>> Gr(n);//������ 
	vector<int>used(n);//������ 
	vector<int>check(n);//������
	cout << "������� ���� �������� ������  ";//�����
	int a, b;//���������� 
	for (int i = 0; i < m; i++)//����
	{ 
		cin >> a >> b;//����
		Gr[a].push_back(b);//������� ������ ���������
	}
	cout << "������� ������� � ������� ���������� ����: ";//�����
	cin >> x;//����
	for (int k = 0; k < n; k++) //���� 
	{
		if (k != x)//������� ���� 
		{
			bfs(Gr, used, k);//�������� �������
			if (used[x] == 1) cout << k << " ";//��������� ���������� ���� ��� ���
		}
		used.clear();//�������� 
		used.resize(n);//��������� �������
	}
	system("pause");//�������� ������� 
	return 0;//���������� 
}