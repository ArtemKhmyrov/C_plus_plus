#include <iostream>//���������� ��� ������ �����-������
#include <string>//���������� ��� �����
#include <fstream>//���������� ��� �����
#include <vector>//���������� ��� ��������
#include <iomanip>//����������� ���������� ��� ����������

using namespace std;//���������

ifstream in("input.txt");//������
ofstream out("output.txt");//������

struct date//������� ���������
{ 
	int day, month, year;//������ ����������
};

struct workers //������� ��������� ��� ��������
{ 
	string name;//���
	string position;//�����
	date birth;//����
	int experience;//����
	string salary;//��������
};

date str_to_int(string str1)//��������� ��� �������� ����
{ 
	date work; string str; const char *sd; int dd;
	str = str1.substr(0, 2); //��������� �� ������ � ��� ����
	sd = str.c_str();//����������
	dd = atoi(sd);//������
	work.day = dd;//������
	str = str1.substr(3, 2); //��������� �� ������ � ��� �����
	sd = str.c_str();//����������
	dd = atoi(sd);//������
	work.month = dd;//������
	str = str1.substr(6, 4); //��������� �� ������ � ��� ���
	sd = str.c_str();//����������
	dd = atoi(sd);//������ 
	work.year = dd;//������

	return work;//���������
}

void sel_sort(workers *a, int k)//���������� �������
{ 
	for (int i = 0; i < k - 1; i++)//����
	{
		int min = i;//����������
		for (int j = i + 1; j < k; j++)//����
		{
			if (a[j].salary < a[min].salary)//������� ����
				min = j;//�����������
			else if (a[j].salary == a[min].salary)//������� ����
				if (a[j].birth.year < a[min].birth.year)//������� ����
					min = j;//�����������
				else if (a[j].birth.year == a[min].birth.year)//������� ����
					if (a[j].experience < a[min].experience)//������� ����
						min = j;//�����������
		}
		if (min != i) //������� ����
		{
			swap(a[i], a[min]);//�������
			min = i;//�����������
		}
	}
	for (int i = 0; i < 20; i++)//����
	{
		out << setw(15) << left << a[i].name << setw(15) << left << a[i].position;//�����������
		if (a[i].birth.day < 10) out << left << '0' << a[i].birth.day << '.';//
		else out << left << a[i].birth.day << '.';//������� �����
		if (a[i].birth.month < 10) out << '0' << a[i].birth.month << '.';//������� ����
		else out << a[i].birth.month << '.';
		out << left << setw(6) << a[i].birth.year << left << setw(6) << a[i].experience << left << setw(10) << a[i].salary << '\n';//������������
	}
}

int main()//��������
{
	int n = 20; string str;//���������� 
	workers a[20]; //�������� ������� �����������
	for (int i = 0; i < n; i++) 
	{
		in >> a[i].name;//���
		in >> a[i].position;//�������
		in >> str;
		a[i].birth = str_to_int(str);//����
		in >> a[i].experience;//����
		in >> a[i].salary;//��������
	}
	sel_sort(a, 20); //����� ����������
	in.close();//���������
	out.close();//���������
	system("pause");//�������� �������
	return 0;//����������
}