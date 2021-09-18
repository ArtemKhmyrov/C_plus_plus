#include <iostream>//���������� ��� ������ ����� ������
#include <fstream>//���������� ��� �����
#include <string>//��� ����� 
#include <vector>//��� �������� 
#include <iomanip>//��������
#include <algorithm>//����������

// �������� � �������� �����������, ��������������� � ����� ������� �� ����

using namespace std;//��������� 

ifstream in("input.txt");//������� ����
ofstream out("output.txt");//�������� ����

struct date //��������� �������
{
	int dd, mm, yy;//���������� ��� ���� 
};

struct people//��������� ��� �������� 
{ 
	string Surname;//���������� 
	string Position;
	date Birthday;//���������� 
	int Experience;//���������� 
	int Salary;
};

date Str_to_Date(string str) //������� �� ������ � �����
{
	date x;//���������� 
	string t = str.substr(0, 2);//������� 
	x.dd = atoi(t.c_str());//������ \�������
	t = str.substr(3, 2);
	x.mm = atoi(t.c_str());
	t = str.substr(6, 4);
	x.yy = atoi(t.c_str());
	return x;//���������� 
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

void print(people x) 
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

void create(vector<int> &hesh, vector<people> x, int m) //�������� ���-�������
{
	int k, counter = 0, f;
	for (int i = 0; i < x.size(); i++)
	{
		int tmp = x[i].Birthday.yy;
		k = tmp % m;
		counter = 0;
		for (int i1 = k; i1 < hesh.size(); i1++)
		{
			f = k + counter;
			if (hesh[f] == NULL)
			{
				hesh[f] = tmp;
				break;
			}
			else
				counter++;
		}
	}
}

void print(vector<int> hesh) //����� ���-�������
{
	cout << "������� : " << endl;
	for (int i = 0; i < hesh.size(); i++)
		cout << hesh[i] << endl;
}

void search(vector<int> hesh, vector<people> a, int X, int m) // ����� ������������ �������� � ��� �����
{
	bool flag = false;
	for (int i = 0; i < hesh.size(); i++)
	{
		if (hesh[i] == X)
		{
			cout << "������ ���������� � output" << endl;
			for (int j = 0; j < a.size(); j++)
				if (a[j].Birthday.yy == X)
				{
					print(a[j]);
				}
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "����� ������� �� ��� ������" << endl;
}

int main() //�������� ��� ���� 
{
	setlocale(LC_ALL, "RUS");
	vector<people> x;
	x = inFile();
	cout << "������� ������ ������� :" << endl;
	int m;
	cin >> m;
	vector<int> hesh(m, NULL);
	create(hesh, x, m);
	print(hesh);
	cout << "������� ������� �������: " << endl;
	int X;
	cin >> X;
	search(hesh, x, X, m);
	system("pause");
	return 0;
}

//����������� ����� �� ������, ������ �� ���� 