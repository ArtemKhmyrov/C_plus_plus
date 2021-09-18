#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

//реализация базового класса "Транспорт"
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

//геттеры
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

//сеттеры
void Transport::ChangeMileage(int way) { //меняем пробег
	if (way >= 0) {
		mileage += way;
	}
	else
		cout << "Путь не может быть отрицательным!\n";
}
void Transport::ChangeMaxspeed(int speed) { //меняем макс.скорость
	if (speed >= 0) {
		maxspeed += speed;
	}
	else
		cout << "Скорость не может быть отрицательной!\n";
}

//методы
void Transport::print() {
	cout << "Модель: " << model << "\n";
	cout << "Серийный номер: " << snumber << "\n";
	cout << "Максимальная скорость: " << maxspeed << "\n";
	cout << "Год выпуска: " << year << "\n";
	cout << "Пробег: " << mileage << "\n";
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

//реализация базового класса "Тип"
Type::Type()
{
};

Type::~Type()
{
};
//геттеры

//реализация класса "Автомобиль"
Car::Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->equipment = equipment;
}
Car::~Car()
{
}
//геттеры
string Car::getEquipment()
{
	return equipment;
}

//методы
void Car::print(void) {
	Transport::print();
	cout << "Комплектация: " << equipment << "\n";
}
void Car::GoCar() {
	cout << "Автомобиль едет на заказ\n";
}

//реализация класса "Поезд"
Train::Train(string model, string snumber, int maxspeed, int year, int mileage, int carriage) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->carriage = carriage;
}
Train::~Train()
{
}
//геттеры
int Train::getCarriage()
{
	return carriage;
}

//методы
void Train::print(void) {
	Transport::print();
	cout << "Количество вагонов: " << carriage << "\n";
}
void Train::GoTrain() {
	cout << "Поезд едет\n";
}


//реализация класса "Самолёт"
Plane::Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass) : Transport(model, snumber, maxspeed, year, mileage)
{
	this->planeclass = planeclass;
}
Plane::~Plane()
{
}

//геттеры
string Plane::getPlaneclass()
{
	return planeclass;
}

//методы
void Plane::print(void) {
	Transport::print();
	cout << "Класс самолёта: " << planeclass << "\n";
}
void Plane::GoPlane() {
	cout << "Самолёт летит\n";
}

//реализация класса "Грузовой"
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
	cout << "Тоннаж: " << tonnage << "\n";
}

void Freight::broke(void) {

}

void Freight::mil(void) {

}

void Freight::tuning(void) {

}

//реализация класса "Пассажирский"
Passenger::Passenger(int passengerseats) : Type()
{
	this->passengerseats = passengerseats;
	//	TType = "Пассажирский";
}
Passenger::~Passenger()
{
}

void Passenger::transportation(int psngr) {

}

void Passenger::print(void) {
	cout << "Пассажирские места: " << passengerseats << "\n";
}

void Passenger::broke(void) {

}

void Passenger::mil(void) {

}

void Passenger::tuning(void) {

}

//реализация класса "Грузовой автомобиль"
Freight_Car::Freight_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int tonnage) : Car(model, snumber, maxspeed, year, mileage, equipment), Freight(tonnage)
{
	TType = "Грузовой автомобиль";
}
Freight_Car::~Freight_Car()
{
}

void Freight_Car::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "Грузовой автомобиль с серийным номером " << snumber << " перевозит груз весом " << tng << "тонн\n";
	else
		cout << "Груз не может быть меньше нуля или больше, чем тоннаж транспорта\n";
}
void Freight_Car::transportation(int psngr) {
	cout << "Грузовой автомобиль не предназначен для перевозки пассажиров!\n";
}
void Freight_Car::print(void) {
	cout << "Тип: " << TType << "\n";
	Car::print();
	Freight::print();
}

void Freight_Car::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}

void Freight_Car::mil(void) {
	int way;
	cout << "Введите путь, пройденный автомобилем: "; cin >> way; cout << "\n";
	cout << "Пробег автомобиля с серийным номером " << snumber << " изменился с " << Freight_Car::getMileage();
	ChangeMileage(way);
	cout << " на " << Freight_Car::getMileage() << "\n";
}

void Freight_Car::tuning(void) {
	cout << "Ваша тачка прокачана! Йоу!\n";
	cout << "Максимальная скорость увеличилась на 30!\n";
	Freight_Car::ChangeMaxspeed(30);
	cout << "И теперь она равняется " << Freight_Car::getMaxspeed() << "\n";
}

//реализация класса "Грузовой поезд"
Freight_Train::Freight_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int tonnage) : Train(model, snumber, maxspeed, year, mileage, carriege), Freight(tonnage)
{
	TType = "Грузовой поезд";
}
Freight_Train::~Freight_Train()
{
}

void Freight_Train::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "Грузовой поезд с серийным номером " << snumber << " перевозит груз весом " << tng << "тонн\n";
	else
		cout << "Груз не может быть меньше нуля или больше, чем тоннаж транспорта\n";
}
void Freight_Train::transportation(int psngr) {
	cout << "Грузовой поезд не предназначен для перевозки пассажиров!\n";
}
void Freight_Train::print(void) {
	cout << "Тип: " << TType << "\n";
	Train::print();
	Freight::print();
}

void Freight_Train::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}

void Freight_Train::mil(void) {
	int way;
	cout << "Введите путь, пройденный поездом: "; cin >> way; cout << "\n";
	cout << "Пробег поезда с серийным номером " << snumber << " изменился с " << Freight_Train::getMileage();
	ChangeMileage(way);
	cout << " на " << Freight_Train::getMileage() << "\n";
}

void Freight_Train::tuning(void) {
	cout << "Ваш поезд прокачан. Йоу!\n";
	cout << "Максимальная скорость увеличилась на 80! ";
	Freight_Train::ChangeMaxspeed(80);
	cout << "И теперь она равняется " << Freight_Train::getMaxspeed() << "\n";
}

//реализация класса "Грузовой самолёт"
Freight_Plane::Freight_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int tonnage) : Plane(model, snumber, maxspeed, year, mileage, planeclass), Freight(tonnage)
{
	TType = "Грузовой самолёт";
}
Freight_Plane::~Freight_Plane()
{
}

void Freight_Plane::shipping(int tng) {
	if (tng >= 0 && tng <= tonnage)
		cout << "Грузовой самолёт с серийным номером " << snumber << " перевозит груз весом " << tng << "тонн\n";
	else
		cout << "Груз не может быть меньше нуля или больше, чем тоннаж транспорта\n";
}
void Freight_Plane::transportation(int psngr) {
	cout << "Грузовой самолёт не предназначен для перевозки пассажиров!\n";
}
void Freight_Plane::print(void) {
	cout << "Тип: " << TType << "\n";
	Plane::print();
	Freight::print();
}

void Freight_Plane::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}

void Freight_Plane::mil(void) {
	int way;
	cout << "Введите путь, пройденный самолётом: "; cin >> way; cout << "\n";
	cout << "Пролёт самолёта с серийным номером " << snumber << " изменился с " << Freight_Plane::getMileage();
	ChangeMileage(way);
	cout << " на " << Freight_Plane::getMileage() << "\n";
}

void Freight_Plane::tuning(void) {
	cout << "Ваш самолёт улучшен.\n";
	cout << "Максимальная скорость увеличилась на 150. ";
	Freight_Plane::ChangeMaxspeed(150);
	cout << "И теперь она равняется " << Freight_Plane::getMaxspeed() << "\n";
}

//реализация класса "Пассажирский автомобиль"
Passenger_Car::Passenger_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int passengerseats) : Car(model, snumber, maxspeed, year, mileage, equipment), Passenger(passengerseats)
{
	TType = "Пассажирский автомобиль";
}
Passenger_Car::~Passenger_Car()
{
}

void Passenger_Car::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "Автомобиль с серийным номером " << snumber << " перевозит пассажиров в количестве " << psngr << " человек\n";
	else
		cout << "Количество пассажиров не может быть меньше нуля или больше, чем количество мест\n";
}
void Passenger_Car::shipping(int tng) {
	cout << "Пассажирский автомобиль не предназначен для перевозки грузов!\n";
}
void Passenger_Car::print(void) {
	cout << "Тип: " << TType << "\n";
	Car::print();
	Passenger::print();
}

void Passenger_Car::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}

void Passenger_Car::mil(void) {
	int way;
	cout << "Введите путь, пройденный автомобилем: "; cin >> way; cout << "\n";
	cout << "Пробег автомобиля с серийным номером " << snumber << " изменился с " << Passenger_Car::getMileage();
	ChangeMileage(way);
	cout << " на " << Passenger_Car::getMileage() << "\n";
}

void Passenger_Car::tuning(void) {
	cout << "Ваша тачка прокачана! Йоу!\n";
	cout << "Максимальная скорость увеличилась на 30!\n";
	Passenger_Car::ChangeMaxspeed(30);
	cout << "И теперь она равняется " << Passenger_Car::getMaxspeed() << "\n";
}

//реализация класса "Пассажирский поезд"
Passenger_Train::Passenger_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int passengerseats) : Train(model, snumber, maxspeed, year, mileage, carriege), Passenger(passengerseats)
{
	TType = "Пассажирский поезд";
}
Passenger_Train::~Passenger_Train()
{
}

void Passenger_Train::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "Поезд с серийным номером " << snumber << " перевозит пассажиров в количестве " << psngr << " человек\n";
	else
		cout << "Количество пассажиров не может быть меньше нуля или больше, чем количество мест\n";
}
void Passenger_Train::shipping(int tng) {
	cout << "Пассажирский поезд не предназначен для перевозки грузов!\n";
}
void Passenger_Train::print(void) {
	cout << "Тип: " << TType << "\n";
	Train::print();
	Passenger::print();
}
void Passenger_Train::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}

void Passenger_Train::mil(void) {
	int way;
	cout << "Введите путь, пройденный поездом: "; cin >> way; cout << "\n";
	cout << "Пробег поезда с серийным номером " << snumber << " изменился с " << Passenger_Train::getMileage();
	ChangeMileage(way);
	cout << " на " << Passenger_Train::getMileage() << "\n";
}

void Passenger_Train::tuning(void) {
	cout << "Ваш поезд прокачан. Йоу!\n";
	cout << "Максимальная скорость увеличилась на 80! ";
	Passenger_Train::ChangeMaxspeed(80);
	cout << "И теперь она равняется " << Passenger_Train::getMaxspeed() << "\n";
}

//реализация "Пассажирский самолёт"
Passenger_Plane::Passenger_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int passengerseats) : Plane(model, snumber, maxspeed, year, mileage, planeclass), Passenger(passengerseats)
{
	TType = "Пассажирский самолёт";
}
Passenger_Plane::~Passenger_Plane()
{
}

void Passenger_Plane::transportation(int psngr) {
	if (psngr >= 0 && psngr <= passengerseats)
		cout << "Самолёт с серийным номером " << snumber << " перевозит пассажиров в количестве " << psngr << " человек\n";
	else
		cout << "Количество пассажиров не может быть меньше нуля или больше, чем количество мест\n";
}
void Passenger_Plane::shipping(int tng) {
	cout << "Пассажирский самолёт не предназначен для перевозки грузов!\n";
}
void Passenger_Plane::print(void) {
	cout << "Тип: " << TType << "\n";
	Plane::print();
	Passenger::print();
}
void Passenger_Plane::broke(void) {
	cout << TType << " с серийным номером " << snumber << " сломался, наши специалисты уже выехали на место происшествия\n";
}
void Passenger_Plane::mil(void) {
	int way;
	cout << "Введите путь, пройденный самолётом: "; cin >> way; cout << "\n";
	cout << "Пролёт самолёта с серийным номером " << snumber << " изменился с " << Passenger_Plane::getMileage();
	ChangeMileage(way);
	cout << " на " << Passenger_Plane::getMileage() << "\n";
}
void Passenger_Plane::tuning(void) {
	cout << "Ваш самолёт улучшен.\n";
	cout << "Максимальная скорость увеличилась на 150. ";
	Passenger_Plane::ChangeMaxspeed(150);
	cout << "И теперь она равняется " << Passenger_Plane::getMaxspeed() << "\n";
}