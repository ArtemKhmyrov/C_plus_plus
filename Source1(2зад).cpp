#include <iostream>
#include <string>
#include <windows.h>
#include <list>
#include "Header.h"

using namespace std;

void enter(string& s1, string& s2, int& in1, int& in2, int& in3)
{
	cout << "Введите модель: ";
	cin >> s1;
	cout << "Введите гос номер: ";
	cin >> s2;
	cout << "Введите максимальную скорость: ";
	cin >> in1;
	cout << "Введите год выпуска: ";
	cin >> in2;
	cout << "Введите пробег: ";
	cin >> in3;
}
bool check(list <Transport*> a, string snumber) {
	Transport* b;
	for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++) 
	{
		b = *it;
		if (b->getSnumber() == snumber) {
			cout << "Такой объект уже создан!\n";
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
		cout << "\n1. Создать новый транспорт\n2. Действие с транспортом\n3. Вывод информации о транспорте\n4. Вывод информации о всём транспорте\n5. Продать транспорт\n6. Продать весь транспорт\n";
		cin >> temp;
		if (temp == 1) 
		{
			cout << "\n1. Грузовой транспорт\n2. Пассажирский транспорт\n Другая клавиша — выход из программы\n";
			cin >> temp;
			if (temp == 1)
			{
				cout << "Выберите ваш транспорт!\n1. Автомобиль\n2. Поезд\n3. Самолёт\n";
				cin >> temp;
				if (temp == 1)
				{
					enter(s1, s2, in1, in2, in3);
					cout << "Введите комплектацию ";
					cin >> s3;
					cout << "Введите тоннаж ";
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
					cout << "Введите количество вагонов ";
					cin >> in4;
					cout << "Введите тоннаж ";
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
					cout << "Введите класс самолёта ";
					cin >> s3;
					cout << "Введите тоннаж ";
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
					cout << "Некорректный ввод\n";
					break;
				}
			}
			else if (temp == 2) 
			{
				cout << "Выберите ваш транспорт!\n1. Автомобиль\n2. Поезд\n3. Самолёт\n";
				cin >> temp;
				if (temp == 1) 
				{
					enter(s1, s2, in1, in2, in3);
					cout << "Введите комплектацию ";
					cin >> s3;
					cout << "Введите количество пассажирских мест: ";
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
					cout << "Введите количество вагонов ";
					cin >> in4;
					cout << "Введите количество пассажирских мест: ";
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
					cout << "Введите класс самолёта ";
					cin >> s3;
					cout << "Введите количество пассажирских мест: ";
					cin >> in4;
					if (check(a, s2)) 
					{
						Passenger_Plane* transport;
						transport = new Passenger_Plane(s1, s2, in1, in2, in3, s3, in4);
						a.push_back(transport);
					}
				}
				else {
					cout << "Некорректный ввод\n";
					break;
				}
			}
		}
		else if (temp == 2) {
			//тут что-то с действиями
			cout << "Введите серийный номер: "; cin >> strtemp;
			cout << "Введите действие.\n1. Везти груз\n2. Везти пассажиров\n3. Транспорт сломался\n4. Изменился пробег\n5. Улучшить характеристики транспорта\n";
			cin >> temp;
			Transport* b;
			if (temp == 1) 
			{
				cout << "Введите количество груза, который необходимо перевезти\n";
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
				cout << "Введите количество людей, которых необходимо перевезти\n";
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
				cout << "Вы вернулись в меню\n";
				continue;
			}
		}
		else if (temp == 3) 
{
			//тут с выводом информации о транспорте
			cout << "Введите серийный номер: "; cin >> strtemp;
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
				cout << k << ". " << "Модель: " << b->getModel() << ". Серийный номер: " << b->getSnumber() << ".\n";
				k++;
			}
		}
		else if (temp == 5)
 {
			cout << "Введите серийный номер транспорта, который хотите продать: ";
			cin >> strtemp;
			Transport* b;
			for (list<Transport*>::iterator it = a.begin(); it != a.end(); it++)
			{
				b = *it;
				if (b->getSnumber() == strtemp)
				{
					cout << "Вот Ваш транспорт с серийным номером " << b->getSnumber() << endl;
					a.remove(b);
				}
			}
		}
		else if (temp == 6)
 {
			cout << "Весь транспорт продан!\n";
			a.clear();
		}
		else
 {
			return 0;
		}
	}
}