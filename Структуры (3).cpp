//������� ��������� Hotel, ���������� ��������� ������: ��� �������, ���� �������� � ���� �������. ���������� ������� ���� ������ ������ �������� � �����. ���������� �������� �� ������������ ����� ���.



#include <iostream>//���������� ��� ������ ����� -������
#include <string>//���������� ��� ������ �� ��������

using namespace std;//���������

struct Hotel//�������� ���������
{ 
	string fio;//���������� ����������
	int day1;//���� ������
	int month1;//����� ������
	int year1;//��� ������
	int day2;//���� ������
	int month2;//����� ������
	int year2;//��� ������
};

Hotel STR1_Hotel(string str1, string str2, string fio)//�������� 1
{
	Hotel hot;

	//��� ������
	string str = str1.substr(0, 2); //��������� �� ������ � ��� 
	const char *sd = str.c_str();//��������� �� ������ � ����������� ����� ( ������ ����� C)
	int dd = atoi(sd);//������������
	hot.day1 = dd;//����
	str = str1.substr(3, 2); //��������� �� ������ � ���
	sd = str.c_str();//���������� 
	dd = atoi(sd);//������������
	hot.month1 = dd;//�����
	str = str1.substr(6, 4); //��������� �� ������ � ��� 
	sd = str.c_str();//����������
	dd = atoi(sd);//������������
	hot.year1 = dd;//���

	//��� ������
	str = str2.substr(0, 2); //��������� �� ������ � ��� 
	sd = str.c_str();//����������
	dd = atoi(sd);//������������
	hot.day2 = dd;//����
	str = str2.substr(3, 2); //��������� �� ������ � ��� 
	sd = str.c_str();//����������
	dd = atoi(sd);//������������
	hot.month2 = dd;//�����
	str = str2.substr(6, 4); //��������� �� ������ � ��� 
	sd = str.c_str();//����������
	dd = atoi(sd);//������������
	hot.year2 = dd;//���

	hot.fio = fio; //��������

	return hot;//�������� 2
}

bool vis(int y) //�������� �� ���������� ���
{ 
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);//���� ��������
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

int correct(string str1, string str2, string fio) //�������� ������������ ������
{ 
	if (str1.length() != 10) //������� ����
		return -1;//�������� 5
	for (string::size_type i = 0; i < str1.length(); i++)//����
		if (i != 2 && i != 5) //������� ����
		{
			if (!isdigit(str1[i]))//������� ����
				return -1;//�������� 6
		}
	Hotel data = STR1_Hotel(str1, str2, fio);//��������� (����� ����� ���)
	if (data.day1 <= 0 || data.day1 > EndOfMonth(data.month1, data.year1))//������� ����
		return -2;//�������� 7
	if (data.month1 <= 0 || data.month1 > 12)//�����
		return -3;//�������� 8
	if (data.year1 == 0)//���
		return -4;//�������� 9
	if (str2.length() != 10)//�����
		return -1;//�������� 10
	for (string::size_type i = 0; i < str2.length(); i++)//����
		if (i != 2 && i != 5)
		{
			if (!isdigit(str2[i]))
				return -1;//�������� 11
		}
	if (data.day2 <= 0 || data.day2 > EndOfMonth(data.month2, data.year2))//������� ����
		return -2;//�������� 12 
	if (data.month2 <= 0 || data.month2 > 12)//�����
		return -3;//�������� 14
	if (data.year2 == 0)//���
		return -4;//�������� 15
	return 1;//�������� 16
}

Hotel search(Hotel x)//�������� 17
{
	setlocale(LC_ALL, "RUS"); //������������� ������� ����������
	Hotel y = x;
	int k = 0;//���������� 
	while (y.day1 != y.day2 || y.month1 != y.month2 || y.year1 != y.year2) //����
	{
		if (y.day1 < EndOfMonth(y.month1, y.year1)) //������� ����
		{ 
			//�� ����� ������
			y.day1++;
			k++;
		}
		else if (y.month1 < 12) //������� �����
			
		{ 
			//����� ������, �� �� ����� ����
			y.day1 = 1;
			y.month1++;
			k++;
		}
		else //������� �����
		{ 
			//����� ����
			y.day1 = 1;
			y.month1 = 1;
			y.year1++;
			k++;
		}
	}
	cout << y.fio << " ����� � ����� " << k << " ����" << '\n';//�����
	return y;//�������� 18
}


int main()//�������� 19
{
	int c;//��������� ����������
	do//��������
	{	
		
			setlocale(LC_ALL, "RUS"); //������������� ������� ����������
			string str1, str2, fio;//������ 
			cout << "������� ��� �������\n";//�����
			getline(cin, fio);//���� ������ ���
			cout << "������� ���� ������ � ������� xx.yy.zzzz\n";//�����
			getline(cin, str1);//���� ������ �� ������ ������
			cout << "������� ���� ������� � ������� xx.yy.zzzz\n";//�����
			getline(cin, str2);//���� ������ �� ������ ������
			int fl = correct(str1, str2, fio);
			if (fl == -1)//������� ����
				cout << "������������ ���� ����\n";//�����
			else if (fl == -2)//������� ����
				cout << "������������ ����\n";//�����
			else if (fl == -3)//������� ����
				cout << "������������ �����\n";//�����
			else if (fl == -4)//������� ����
				cout << "������������ ���\n";//�����
			else//������� ����
			{
				Hotel Otvet = STR1_Hotel(str1, str2, fio);//���������
				Hotel Days = search(Otvet);//���������
			}
			
		
			std::cout << "������ ������������� ���������?" << endl;//�����
		std::cout << "���� ��, ������� 1" << endl;//�����
		std::cout << "���� ���, ������� 2" << endl;//�����
		cin >> c;//����

		
	}
	while (c != 2);//����
	system("pause");//�������� �������
	return 0;//�������� 20
}
		
	
	

