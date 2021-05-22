#pragma once

class Person {
private:
    int h;
public:    
    Person(int x);
    Person();
};

class Faculty : virtual public Person {
public:
    Faculty(int x);
};

class Student : virtual public Person {
public:
    Student(int x);
};

class TA : public Faculty, public Student {
public:
    TA(int x);
};
