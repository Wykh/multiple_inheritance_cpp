#include "Test.h"
#include <iostream>

using namespace std;

Person::Person(int x)
{
	cout << "Person::Person(int ) called" << endl;
}

Person::Person()
{
	cout << "Person::Person( ) called" << endl;
}

Faculty::Faculty(int x):Person(x)
{
	cout << "Faculty::Faculty(int ) called" << endl;
}

Student::Student(int x):Person(x)
{
	cout << "Student::Student(int ) called" << endl;
}

TA::TA(int x):Student(x), Faculty(x)
{
	cout << "TA::TA(int ) called" << endl;
}
