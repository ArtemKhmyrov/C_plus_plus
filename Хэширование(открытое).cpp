#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

//����� ������� �� ���� ��������

using namespace std;//���������

ifstream in("input.txt");//������� ����
ofstream out("output.txt");//�������� ����

struct date //��������� �������
{
	int dd, mm, yy;//���������� 
};

struct people//��������� �������� 
{ 
	string Surname;
	string Position;
	date Birthday;
	int Experience;
	int Salary;
};

date Str_to_Date(string str) //������� �� ������ � �����
{
	date x;
	string t = str.substr(0, 2);
	x.dd = atoi(t.c_str());
	t = str.substr(3, 2);
	x.mm = atoi(t.c_str());
	t = str.substr(6, 4);
	x.yy = atoi(t.c_str());
	return x;
}

vector<people> inFile() //�������� ������� �����
{ 
	vector <people> x;
	people t;
	while (in.peek() != EOF)
	{
		in >> t.Surname;
		in >> t.Position;
		string tmp;
		in >> tmp;
		t.Birthday = Str_to_Date(tmp);
		in >> t.Experience;
		in >> t.Salary;
		x.push_back(t);
	}
	return x;
}

void print(people x) //����� � ���� 
{
	out << setw(10) << left << x.Surname << " ";
	out << left << setw(15) << x.Position << " ";
	if (x.Birthday.dd < 10)
		out << '0' << x.Birthday.dd << '.';
	else
		out << left << x.Birthday.dd << '.';
	if (x.Birthday.mm < 10)
		out << '0' << x.Birthday.mm << '.';
	else
		out << x.Birthday.mm << '.';
	out << left << setw(6) << x.Birthday.yy << " ";
	out << left << setw(2) << x.Experience << " ";
	out << left << setw(10) << x.Salary << endl;
}

void create(vector<people> x, vector<vector<int>> &hesh, int m) //�������� ���-�������
{
	for (int i = 0; i < x.size(); i++)
	{
		int k = x[i].Birthday.yy;
		k = k % m;
		hesh[k].push_back(x[i].Birthday.yy);
	}
}

void print(vector<vector<int>> &hesh) //����� ���-�������
{
	cout << "���-������� : " << endl;
	for (int i = 0; i < hesh.size(); i++, cout << endl)
		for (int j = 0; j < hesh[i].size(); j++)
			cout << hesh[i][j] << " ";
	cout << endl;
}

void dElite(vector<vector<int>> &hesh, int X, int m) //�������� ������������ ��������
{
	int k = X % m;
	for (int i = 0; i < hesh[k].size(); i++)
		if (hesh[k][i] == X)
		{
			hesh[k].erase(hesh[k].begin() + i);
			i--;
		}
}

void search(vector<vector<int>> hesh, vector<people> a, int X, int m) //����� ������������ ��������
{
	int k = X % m;
	for (int i = 0; i < hesh[k].size(); i++)
	{
		if (hesh[k][i] == X)
		{
			for (int j = 0; j < a.size(); j++)
				if (a[j].Birthday.yy == X)
					print(a[j]);
			break;
		}
	}
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	vector<people> x;
	x = inFile();
	int n;
	cout << "������� ������ ���-�������" << endl;
	int m;
    cin >> m;
	cout << m;
	vector<vector<int>> hesh(m);
	create(x, hesh, m);
	print(hesh);
	cout << "������� ��� �������� �������� ��� ������, ����� � output" << endl;
	int Y;
	cin >> Y;
	search(hesh, x, Y, m);
	cout << "������� ��� �������� ��������, �������� ����� �������" << endl;
	int X;
	cin >> X;
	dElite(hesh, X, m);
	print(hesh);
	system("pause");
	return 0;
}