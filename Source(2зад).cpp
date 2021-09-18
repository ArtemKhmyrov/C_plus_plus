#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

//���������� �������� ������ "���������"
Transport::Transport(string model, string snumber, int maxspeed, int year, int mileage) {
	this->model = model;
	this->snumber = snumber;
	this->maxspeed = maxspeed;
	this->year = year;
	this->mileage = mileage;
}

Transport::~Transport()
{
}

//�������
string Transport::getModel() {
	return model;
}
string Transport::getSnumber() {
	return snumber;
}
int Transport::getMaxspeed() {
	return maxspeed;
}
int Transport::getYear() {
	return year;
}
int	Transport::getMileage() {
	return mileage;
}

//�������
void Transport::ChangeMileage(int way) { //������ ������
	if (way >= 0) {
		mileage += way;
	}
	else
		cout << "���� �� ����� ���� �������������!\n";
}
void Transport::ChangeMaxspeed(int speed) { //������ ����.��������
	if (speed >= 0) {
		maxspeed += speed;
	}
	else
		cout << "�������� �� ����� ���� �������������!\n";
}

//������
void Transport::print() {
	cout << "������: " << model << "\n";
	cout << "�������� �����: " << snumber << "\n";
	cout << "������������ ��������: " << maxspeed << "\n";
	cout << "��� �������: " << year << "\n";
	cout << "������: " << mileage << "\n";
}

void Transport::transportation(int psngr)
{

}

void Transport::shipping(int tng)
{

}

void Transport::broke()
{

}

void Transport::mil()
{

}

void Transport::tuning()
{

}

//���������� �������� ������ "���"
Type::Type()
{
};

Type::~Type()
{
};
//�������

//���������� ������ "����������"
Car::Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->equipment = equipment;
}
Car::~Car()
{
}
//�������
string Car::getEquipment()
{
	return equipment;
}

//������
void Car::print(void) {
	Transport::print();
	cout << "������������: " << equipment << "\n";
}
void Car::GoCar() {
	cout << "���������� ���� �� �����\n";
}

//���������� ������ "�����"
Train::Train(string model, string snumber, int maxspeed, int year, int mileage, int carriage) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->carriage = carriage;
}
Train::~Train()
{
}
//�������
int Train::getCarriage()
{
	return carriage;
}

//������
void Train::print(void) {
	Transport::print();
	cout << "���������� �������: " << carriage << "\n";
}
void Train::GoTrain() {
	cout << "����� ����\n";
}


//���������� ������ "������"
Plane::Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->planeclass = planeclass;
}
Plane::~Plane()
{
}

//�������
string Plane::getPlaneclass()
{
	return planeclass;
}

//������
void Plane::print(void) {
	Transport::print();
	cout << "����� �������: " << planeclass << "\n";
}
void Plane::GoPlane() {
	cout << "������ �����\n";
}

//���������� ������ "��������"
Freight::Freight(int tonnage) : Type()
{
	this->tonnage = tonnage;
}
Freight::~Freight()
{
}

void Freight::shipping(int tng) {

}

void Freight::print(void) {
	cout << "������: " << tonnage << "\n";
}

void Freight::broke(void) {

}

void Freight::mil(void) {

}

void Freight::tuning(void) {

}

//���������� ������ "������������"
Passenger::Passenger(int passengerseats) : Type()
{
	this->passengerseats = passengerseats;
	//	TType = "������������";
}
Passenger::~Passenger()
{
}

void Passenger::transportation(int psngr) {

}

void Passenger::print(void) {
	cout << "������������ �����: " << passengerseats << "\n";
}

void Passenger::broke(void) {

}

void Passenger::mil(void) {

}

void Passenger::tuning(void) {

}

//���������� ������ "�������� ����������"
Freight_Car::Freight_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int tonnage) : Car(model, snumber, maxspeed, year, mileage, equipment), Freight(tonnage)
{
	TType = "�������� ����������";
}
Freight_Car::~Freight_Car()
{
}

void Freight_Car::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "�������� ���������� � �������� ������� " << snumber << " ��������� ���� ����� " << tng << "����\n";
	else
		cout << "���� �� ����� ���� ������ ���� ��� ������, ��� ������ ����������\n";
}
void Freight_Car::transportation(int psngr) {
	cout << "�������� ���������� �� ������������ ��� ��������� ����������!\n";
}
void Freight_Car::print(void) {
	cout << "���: " << TType << "\n";
	Car::print();
	Freight::print();
}

void Freight_Car::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}

void Freight_Car::mil(void) {
	int way;
	cout << "������� ����, ���������� �����������: "; cin >> way; cout << "\n";
	cout << "������ ���������� � �������� ������� " << snumber << " ��������� � " << Freight_Car::getMileage();
	ChangeMileage(way);
	cout << " �� " << Freight_Car::getMileage() << "\n";
}

void Freight_Car::tuning(void) {
	cout << "���� ����� ���������! ���!\n";
	cout << "������������ �������� ����������� �� 30!\n";
	Freight_Car::ChangeMaxspeed(30);
	cout << "� ������ ��� ��������� " << Freight_Car::getMaxspeed() << "\n";
}

//���������� ������ "�������� �����"
Freight_Train::Freight_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int tonnage) : Train(model, snumber, maxspeed, year, mileage, carriege), Freight(tonnage)
{
	TType = "�������� �����";
}
Freight_Train::~Freight_Train()
{
}

void Freight_Train::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "�������� ����� � �������� ������� " << snumber << " ��������� ���� ����� " << tng << "����\n";
	else
		cout << "���� �� ����� ���� ������ ���� ��� ������, ��� ������ ����������\n";
}
void Freight_Train::transportation(int psngr) {
	cout << "�������� ����� �� ������������ ��� ��������� ����������!\n";
}
void Freight_Train::print(void) {
	cout << "���: " << TType << "\n";
	Train::print();
	Freight::print();
}

void Freight_Train::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}

void Freight_Train::mil(void) {
	int way;
	cout << "������� ����, ���������� �������: "; cin >> way; cout << "\n";
	cout << "������ ������ � �������� ������� " << snumber << " ��������� � " << Freight_Train::getMileage();
	ChangeMileage(way);
	cout << " �� " << Freight_Train::getMileage() << "\n";
}

void Freight_Train::tuning(void) {
	cout << "��� ����� ��������. ���!\n";
	cout << "������������ �������� ����������� �� 80! ";
	Freight_Train::ChangeMaxspeed(80);
	cout << "� ������ ��� ��������� " << Freight_Train::getMaxspeed() << "\n";
}

//���������� ������ "�������� ������"
Freight_Plane::Freight_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int tonnage) : Plane(model, snumber, maxspeed, year, mileage, planeclass), Freight(tonnage)
{
	TType = "�������� ������";
}
Freight_Plane::~Freight_Plane()
{
}

void Freight_Plane::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "�������� ������ � �������� ������� " << snumber << " ��������� ���� ����� " << tng << "����\n";
	else
		cout << "���� �� ����� ���� ������ ���� ��� ������, ��� ������ ����������\n";
}
void Freight_Plane::transportation(int psngr) {
	cout << "�������� ������ �� ������������ ��� ��������� ����������!\n";
}
void Freight_Plane::print(void) {
	cout << "���: " << TType << "\n";
	Plane::print();
	Freight::print();
}

void Freight_Plane::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}

void Freight_Plane::mil(void) {
	int way;
	cout << "������� ����, ���������� ��������: "; cin >> way; cout << "\n";
	cout << "����� ������� � �������� ������� " << snumber << " ��������� � " << Freight_Plane::getMileage();
	ChangeMileage(way);
	cout << " �� " << Freight_Plane::getMileage() << "\n";
}

void Freight_Plane::tuning(void) {
	cout << "��� ������ �������.\n";
	cout << "������������ �������� ����������� �� 150. ";
	Freight_Plane::ChangeMaxspeed(150);
	cout << "� ������ ��� ��������� " << Freight_Plane::getMaxspeed() << "\n";
}

//���������� ������ "������������ ����������"
Passenger_Car::Passenger_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int passengerseats) : Car(model, snumber, maxspeed, year, mileage, equipment), Passenger(passengerseats)
{
	TType = "������������ ����������";
}
Passenger_Car::~Passenger_Car()
{
}

void Passenger_Car::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "���������� � �������� ������� " << snumber << " ��������� ���������� � ���������� " << psngr << " �������\n";
	else
		cout << "���������� ���������� �� ����� ���� ������ ���� ��� ������, ��� ���������� ����\n";
}
void Passenger_Car::shipping(int tng) {
	cout << "������������ ���������� �� ������������ ��� ��������� ������!\n";
}
void Passenger_Car::print(void) {
	cout << "���: " << TType << "\n";
	Car::print();
	Passenger::print();
}

void Passenger_Car::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}

void Passenger_Car::mil(void) {
	int way;
	cout << "������� ����, ���������� �����������: "; cin >> way; cout << "\n";
	cout << "������ ���������� � �������� ������� " << snumber << " ��������� � " << Passenger_Car::getMileage();
	ChangeMileage(way);
	cout << " �� " << Passenger_Car::getMileage() << "\n";
}

void Passenger_Car::tuning(void) {
	cout << "���� ����� ���������! ���!\n";
	cout << "������������ �������� ����������� �� 30!\n";
	Passenger_Car::ChangeMaxspeed(30);
	cout << "� ������ ��� ��������� " << Passenger_Car::getMaxspeed() << "\n";
}

//���������� ������ "������������ �����"
Passenger_Train::Passenger_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int passengerseats) : Train(model, snumber, maxspeed, year, mileage, carriege), Passenger(passengerseats)
{
	TType = "������������ �����";
}
Passenger_Train::~Passenger_Train()
{
}

void Passenger_Train::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "����� � �������� ������� " << snumber << " ��������� ���������� � ���������� " << psngr << " �������\n";
	else
		cout << "���������� ���������� �� ����� ���� ������ ���� ��� ������, ��� ���������� ����\n";
}
void Passenger_Train::shipping(int tng) {
	cout << "������������ ����� �� ������������ ��� ��������� ������!\n";
}
void Passenger_Train::print(void) {
	cout << "���: " << TType << "\n";
	Train::print();
	Passenger::print();
}
void Passenger_Train::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}

void Passenger_Train::mil(void) {
	int way;
	cout << "������� ����, ���������� �������: "; cin >> way; cout << "\n";
	cout << "������ ������ � �������� ������� " << snumber << " ��������� � " << Passenger_Train::getMileage();
	ChangeMileage(way);
	cout << " �� " << Passenger_Train::getMileage() << "\n";
}

void Passenger_Train::tuning(void) {
	cout << "��� ����� ��������. ���!\n";
	cout << "������������ �������� ����������� �� 80! ";
	Passenger_Train::ChangeMaxspeed(80);
	cout << "� ������ ��� ��������� " << Passenger_Train::getMaxspeed() << "\n";
}

//���������� "������������ ������"
Passenger_Plane::Passenger_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int passengerseats) : Plane(model, snumber, maxspeed, year, mileage, planeclass), Passenger(passengerseats)
{
	TType = "������������ ������";
}
Passenger_Plane::~Passenger_Plane()
{
}

void Passenger_Plane::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "������ � �������� ������� " << snumber << " ��������� ���������� � ���������� " << psngr << " �������\n";
	else
		cout << "���������� ���������� �� ����� ���� ������ ���� ��� ������, ��� ���������� ����\n";
}
void Passenger_Plane::shipping(int tng) {
	cout << "������������ ������ �� ������������ ��� ��������� ������!\n";
}
void Passenger_Plane::print(void) {
	cout << "���: " << TType << "\n";
	Plane::print();
	Passenger::print();
}
void Passenger_Plane::broke(void) {
	cout << TType << " � �������� ������� " << snumber << " ��������, ���� ����������� ��� ������� �� ����� ������������\n";
}
void Passenger_Plane::mil(void) {
	int way;
	cout << "������� ����, ���������� ��������: "; cin >> way; cout << "\n";
	cout << "����� ������� � �������� ������� " << snumber << " ��������� � " << Passenger_Plane::getMileage();
	ChangeMileage(way);
	cout << " �� " << Passenger_Plane::getMileage() << "\n";
}
void Passenger_Plane::tuning(void) {
	cout << "��� ������ �������.\n";
	cout << "������������ �������� ����������� �� 150. ";
	Passenger_Plane::ChangeMaxspeed(150);
	cout << "� ������ ��� ��������� " << Passenger_Plane::getMaxspeed() << "\n";
}