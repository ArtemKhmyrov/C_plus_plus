#include <iostream>
#include <string>
#include <windows.h>
#include <list>
#include "Header.h"

using namespace std;

void enter(string& s1, string& s2, int& in1, int& in2, int& in3)
{
	cout << "������� ������: ";
	cin >> s1;
	cout << "������� ��� �����: ";
	cin >> s2;
	cout << "������� ������������ ��������: ";
	cin >> in1;
	cout << "������� ��� �������: ";
	cin >> in2;
	cout << "������� ������: ";
	cin >> in3;
}
bool check(list <Transport*> a, string snumber) {
	Transport* b;
	for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++) 
	{
		b = *it;
		if (b->getSnumber() == snumber) {
			cout << "����� ������ ��� ������!\n";
			return false;
		}
	}
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	list <Transport*> a;
	int temp, in1, in2, in3, in4, in5;
	string strtemp, s1, s2, s3, s4;
	while (true) 
	{
		cout << "\n1. ������� ����� ���������\n2. �������� � �����������\n3. ����� ���������� � ����������\n4. ����� ���������� � ��� ����������\n5. ������� ���������\n6. ������� ���� ���������\n";
		cin >> temp;
		if (temp == 1) 
		{
			cout << "\n1. �������� ���������\n2. ������������ ���������\n ������ ������� � ����� �� ���������\n";
			cin >> temp;
			if (temp == 1)
			{
				cout << "�������� ��� ���������!\n1. ����������\n2. �����\n3. ������\n";
				cin >> temp;
				if (temp == 1)
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ������������ ";
					cin >> s3;
					cout << "������� ������ ";
					cin >> in4;
					if (check(a, s2))
					{
						Freight_Car* transport;
						transport = new Freight_Car(s1, s2, in1, in2, in3, s3, in4);
						a.push_back(transport);
					}
				}
				else if (temp == 2) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ���������� ������� ";
					cin >> in4;
					cout << "������� ������ ";
					cin >> in5;
					if (check(a, s2)) 
					{
						Freight_Train* transport;
						transport = new Freight_Train(s1, s2, in1, in2, in3, in4, in5);
						a.push_back(transport);
					}
				}
				else if (temp == 3) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ����� ������� ";
					cin >> s3;
					cout << "������� ������ ";
					cin >> in4;
					if (check(a, s2)) 
					{
						Freight_Plane* transport;
						transport = new Freight_Plane(s1, s2, in1, in2, in3, s3, in4);
						a.push_back(transport);
					}
				}
				else
				{
					cout << "������������ ����\n";
					break;
				}
			}
			else if (temp == 2) 
			{
				cout << "�������� ��� ���������!\n1. ����������\n2. �����\n3. ������\n";
				cin >> temp;
				if (temp == 1) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ������������ ";
					cin >> s3;
					cout << "������� ���������� ������������ ����: ";
					cin >> in4;
					if (check(a, s2)) 
					{
						Passenger_Car* transport;
						transport = new Passenger_Car(s1, s2, in1, in2, in3, s3, in4);
						a.push_back(transport);
					}
				}
				else if (temp == 2) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ���������� ������� ";
					cin >> in4;
					cout << "������� ���������� ������������ ����: ";
					cin >> in5;
					if (check(a, s2))
					{
						Passenger_Train* transport;
						transport = new Passenger_Train(s1, s2, in1, in2, in3, in4, in5);
						a.push_back(transport);
					}
				}
				else if (temp == 3) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "������� ����� ������� ";
					cin >> s3;
					cout << "������� ���������� ������������ ����: ";
					cin >> in4;
					if (check(a, s2)) 
					{
						Passenger_Plane* transport;
						transport = new Passenger_Plane(s1, s2, in1, in2, in3, s3, in4);
						a.push_back(transport);
					}
				}
				else {
					cout << "������������ ����\n";
					break;
				}
			}
		}
		else if (temp == 2) {
			//��� ���-�� � ����������
			cout << "������� �������� �����: "; cin >> strtemp;
			cout << "������� ��������.\n1. ����� ����\n2. ����� ����������\n3. ��������� ��������\n4. ��������� ������\n5. �������� �������������� ����������\n";
			cin >> temp;
			Transport* b;
			if (temp == 1) 
			{
				cout << "������� ���������� �����, ������� ���������� ���������\n";
				cin >> temp;
				for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++) 
				{
					b = *it;
					if (b->getSnumber() == strtemp)
					{
						b->shipping(temp);
						break;
					}
				}
			}
			else if (temp == 2)
			{
				cout << "������� ���������� �����, ������� ���������� ���������\n";
				cin >> temp;
				for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
				{
					b = *it;
					if (b->getSnumber() == strtemp)
					{
						b->transportation(temp);
						break;
					}
				}
			}
			else if (temp == 3) 
			{
			
				for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
				{
					b = *it;
					if (b->getSnumber() == strtemp) 
					{
						b->broke();
						break;
					}
				}
			}
			else if (temp == 4)
			{
				for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++) 
				{
					b = *it;
					if (b->getSnumber() == strtemp) 
					{
						b->mil();
						break;
					}
				}
			}
			else if (temp == 5) {
				for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
				{
					b = *it;
					if (b->getSnumber() == strtemp)
					{
						b->tuning();
						break;
					}
				}
			}
			else
			{
				cout << "�� ��������� � ����\n";
				continue;
			}
		}
		else if (temp == 3) 
{
			//��� � ������� ���������� � ����������
			cout << "������� �������� �����: "; cin >> strtemp;
			Transport* b;
			for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
			{
				b = *it;
				if (b->getSnumber() == strtemp)
					b->print();
			}
		}
		else if (temp == 4) {
			Transport* b; int k = 1;
			for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++) 
			{
				b = *it;
				cout << k << ". " << "������: " << b->getModel() << ". �������� �����: " << b->getSnumber() << ".\n";
				k++;
			}
		}
		else if (temp == 5)
 {
			cout << "������� �������� ����� ����������, ������� ������ �������: ";
			cin >> strtemp;
			Transport* b;
			for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
			{
				b = *it;
				if (b->getSnumber() == strtemp)
				{
					cout << "��� ��� ��������� � �������� ������� " << b->getSnumber() << endl;
					a.remove(b);
				}
			}
		}
		else if (temp == 6)
 {
			cout << "���� ��������� ������!\n";
			a.clear();
		}
		else
 {
			return 0;
		}
	}
}