#pragma once
#include <string>

using namespace std;

class Kitchenware
{
protected:
	int number;
public:
	Kitchenware(int number);

	int GetNumber();	
	void virtual Print(); // ������ ���� ������ ����������� ����� �� ����� ������ ����� PrintType() ����� �������� �� ��, ��� �����
	void PrintType();

	virtual ~Kitchenware();
};

class Stove: virtual public Kitchenware
{	
protected:
	string color;
public:
	Stove(int number, string color);

	string GetColor();
	void Print();	
};

class GasStove : virtual public Stove
{
protected:
	int GasSpend;
public:
	GasStove(int number, string color, int GasSpend);

	int GetGasSpend();
	void Print();
};

class ElectricStove: virtual public Stove
{
protected:
	int power;
public:
	ElectricStove(int number, string color, int power);

	int GetPower();
	void Print();
};

class Pot: virtual public Kitchenware
{
protected:
	int volume;
public:
	Pot(int number, int volume);

	int GetVolume();
	void Print();
	void Print(bool = true);
};

class SlowCooker: public ElectricStove, public Pot 
{
protected:
	bool _isPressureCooker;
public:
	SlowCooker(int number, string color, int power, int volume, bool _isPC);

	bool IsPressureCooker();
	void Print();
};


