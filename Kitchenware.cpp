#include <iostream>
#include "Kitchenware.h"

using namespace std;

Kitchenware::Kitchenware(int number)
{
	this->number = number;
}

int Kitchenware::GetNumber()
{
	return number;
}

void Kitchenware::Print()
{
	cout << "number: " << number << endl;
}

void Kitchenware::PrintType()
{
	cout << typeid(*this).name() << endl;
}

Kitchenware::~Kitchenware()
{

}

Stove::Stove(int number, string color): Kitchenware(number)
{
	this->color = color;
}

string Stove::GetColor()
{
	return color;
}

void Stove::Print()
{
	Kitchenware::Print();
	cout << "color: " << color << endl;
}

GasStove::GasStove(int number, string color, int GasSpend) : Stove(number, color), Kitchenware(number)
{
	this->GasSpend = GasSpend;
}

int GasStove::GetGasSpend()
{
	return GasSpend;
}

void GasStove::Print()
{
	Stove::Print();
	cout << "Gas spend: " << GasSpend << endl;
}

ElectricStove::ElectricStove(int number, string color, int power): Stove(number, color), Kitchenware(number)
{
	this->power = power;
}

int ElectricStove::GetPower()
{
	return power;
}

void ElectricStove::Print()
{
	Stove::Print();
	cout << "power: " << power << endl;
}


Pot::Pot(int number, int volume):Kitchenware(number)
{
	this->volume = volume;
}

int Pot::GetVolume()
{
	return volume;
}

void Pot::Print()
{
	Print(true);	
}	

void Pot::Print(bool _printNum)
{
	if (_printNum)
		Kitchenware::Print();
	cout << "volume: " << volume << endl;
}

SlowCooker::SlowCooker(int number, string color, int power, int volume, bool _isPC):ElectricStove(number, color, power), Pot(number, volume), Stove(number, color), Kitchenware(number)
{
	this->_isPressureCooker = _isPC;
}

bool SlowCooker::IsPressureCooker()
{
	return _isPressureCooker;
}

void SlowCooker::Print()
{
	ElectricStove::Print();
	Pot::Print(false);
	//cout << "volume: " << volume << endl;
	cout << "Is it pressure cooker: ";
	if (_isPressureCooker)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
