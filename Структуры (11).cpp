#include<iostream>//���������� ��� ������ �����-������
#include<string>//���������� ��� ���������

using namespace std;//���������

struct date//������� ���������
{
	int day;//����
	int month;//�����
	int year;//���
};

date STR_date(string str) //������������ �� ������ � ���
{
	date data;//����������	
	string str1 = str.substr(0, 2);//����
	const char *sd = str1.c_str();//��������
	int dd = atoi(sd);//������������
	data.day = dd;//����
	str1 = str.substr(3, 2);//�����
	sd = str1.c_str();//��������
	dd = atoi(sd);//������������
	data.month = dd;//�����
	str1 = str.substr(6, 4);//���
	sd = str1.c_str();//��������
	dd = atoi(sd);//������������ 
	data.year = dd;//���
	return data;//�������� 2
}

bool vis(int y)//���������� ���
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);//�������� �� ���������� ���
}

int EndOfMonth(int m, int y)//����� ����� ������
{
	switch (m)//�������� 3
	{
		//��� ����������� ������� ���� � ������
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;//�������� ����� 
	case 4: case 6: case 9: case 11: return 30;//������ �����
	case 2://�� ������� (28 ����)
		if //������� ����
			(vis(y))
			return 29;//������� ����
		else //������� �����
			return 28;//�������� 4
	}
}

date Next(date x, int n) //�������� 1
{
	date y = x;
	if (x.day + n > EndOfMonth(x.month, x.year))//������� ����
	{
		x.day += n - EndOfMonth(x.month, x.year);
		while (x.day + n > EndOfMonth(x.month, x.year) - 1) //���� 
		{
			x.day -= EndOfMonth(x.month, x.year);//����
		}
		x.month += n / (EndOfMonth(x.month, x.year)) + 1;//����� ��������� � n
	}
	else//������� �����
		x.day += n;

	if (x.month > 12)//������� ����
	{

		x.month = x.month + n / (EndOfMonth(x.month, x.year)) - 12;//� ������
		x.year += n / 365 + 1;//� ���� ���������� 1
	}
	return x;//��������
}

void print(date x)//�������� ������� ������� ��� �� ����� ��� �������
{
	if (x.day < 10) cout << "0" << x.day << ".";//������� ����
	else cout << x.day << ".";//������� �����
	if (x.month < 10) cout << "0" << x.month << ".";//������� ����
	else cout << x.month << ".";//������� �����
	if (x.year < 10) cout << "000" << x.year;//������� ����
	else if (x.year < 100) cout << "00" << x.year;//������� �����
	else if (x.year < 1000) cout << "0" << x.year;//������� �����
	else//������� �����
		cout << x.year;//�����
	cout << endl;//������
}

int correct(string str) //�������� 1
{//�������� ������������ ������
	if (str.length() != 10) return -1;
	for (string::size_type i = 0; i < str.length(); i++)//����
		if (i != 2 && i != 5) //������� ����
		{
			if (!isdigit(str[i])) return -1;//����
		}
	date data = STR_date(str);
	if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;//������� ���� ����
	if (data.month <= 0 || data.month > 12) return -3;//������� ���� �����
	if (data.year == 0) return -4; //������� ���� ���
	return 1;//�������� 2
}

int main()//�������� 1
{
	setlocale(LC_ALL, "RUS");//������������� ������� ����������
	string str; //���������
	int n;//����������
	cout << "������� ����� � ������� dd.mm.yyyy." << endl;//�����
	getline(cin, str);//����
	cout << "������� �����";//�����
	cin >> n;//����
	int fl = correct(str);
	if (fl == -1) cout << "������" << endl;//�������� ����
	else if (fl == -2) cout << "������������ ����� ������ ���" << endl;//�����
	else if (fl == -3) cout << "������������ ����� ������ ������" << endl;//�����
	else if (fl == -4) cout << "������������ ����� ������ ����" << endl;//�����
	else//������� �����
	{
		date data = STR_date(str);
		date N_date = Next(data, n);//��������� ����
		print(N_date);//�������
	}
	system("pause");//�������� �������
	return 0;//�������� 2
}