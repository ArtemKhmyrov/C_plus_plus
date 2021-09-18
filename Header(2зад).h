#include <iostream>
#include <string>

using namespace std;

class Transport
{ 
protected:
	Transport(string model, string snumber, int maxspeed, int year, int mileage); 
	~Transport();
	string model;
	string snumber;
	int maxspeed;
	int year;
	int mileage;
	void ChangeMileage(int way);
	void ChangeMaxspeed(int speed);
public:
	string getModel();
	string getSnumber();
	int getMaxspeed();
	int getYear();
	int	getMileage();
	virtual void print(); //вывод всего в консоль
	virtual void transportation(int psngr); //перевозка грузов
	virtual void shipping(int tng); //перевозка пассажиров
	virtual void broke(); //транспорт ломается
	virtual void mil(); //смена пробега
	virtual void tuning(); //тюнинг
};

class Type
{
protected:
	Type();
	~Type();
	string TType;
public:
};

class Car : public Transport
{
protected:
	Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment);
	~Car();
public:
	string getEquipment();
	void print(void);
	void GoCar();
private:
	string equipment;
};

class Train : public Transport
{
protected:
	Train(string model, string snumber, int maxspeed, int year, int mileage, int carriage);
	~Train();
public:
	int getCarriage();
	void print(void);
	void GoTrain();
protected:
	int carriage; 
};

class Plane : public Transport
{
protected:
	Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass);
	~Plane();
public:
	string getPlaneclass();
	void print(void);
	void GoPlane();
protected:
	string planeclass;
};

class Freight : public Type 
{
protected:
	Freight(int tonnage);
	~Freight();
	int tonnage;
public:
	void print(void);
	void shipping(int tng);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Passenger : public Type
{
protected:
	Passenger(int passengerseats);
	~Passenger();
	int passengerseats;
public:
	void print(void);
	void transportation(int psngr);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Freight_Car : public Car, public Freight
{
public:
	Freight_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int tonnage);
	~Freight_Car();
	void print(void);
	void shipping(int tng);
	void transportation(int psngr);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Freight_Train : public Train, public Freight
{
public:
	Freight_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int tonnage);
	~Freight_Train();
	void print(void);
	void shipping(int tng);
	void transportation(int psngr);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Freight_Plane : public Plane, public Freight 
{
public:
	Freight_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int tonnage);
	~Freight_Plane();
	void print(void);
	void shipping(int tng);
	void transportation(int psngr);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Passenger_Car : public Car, public Passenger 
{
public:
	Passenger_Car(string model, string snumber, int maxspeed, int year, int mileage, string equipment, int passengerseats);
	~Passenger_Car();
	void print(void);
	void transportation(int psngr);
	void shipping(int tng);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Passenger_Train : public Train, public Passenger 
{
public:
	Passenger_Train(string model, string snumber, int maxspeed, int year, int mileage, int carriege, int passengerseats);
	~Passenger_Train();
	void print(void);
	void transportation(int psngr);
	void shipping(int tng);
	void broke(void);
	void mil(void);
	void tuning(void);
};

class Passenger_Plane : public Plane, public Passenger
{
public:
	Passenger_Plane(string model, string snumber, int maxspeed, int year, int mileage, string planeclass, int passengerseats);
	~Passenger_Plane();
	void print(void);
	void transportation(int psngr);
	void shipping(int tng);
	void broke(void);
	void mil(void);
	void tuning(void);
};