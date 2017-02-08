#include <string>
#include <iostream>

using namespace std;

class Base{

public:

	virtual Base* operator=(const Base *&other) = 0;

	virtual ~Base()
	{

	}

	virtual void who() = 0;

	string statement;

};

class Derived1 : public Base{

public:

	Derived1();

	Base* operator=(const Base *&other);
	~Derived1() {}

	void who();

};

class Derived2 : public Base{

public:

	Derived2();

	Base* operator=(const Base *&other);
	~Derived2() {}

	void who();

};

Derived1::Derived1()
{
	statement = "I am a Derived1";
}

Derived2::Derived2()
{
	statement = "I am a Derived2";
}

Base* Derived1::operator=(const Base *&other)
{
	if(this != other)
	{
		statement = (*other).statement;
	}

	return this;
}

Base* Derived2::operator=(const Base *&other)
{
	if(this != other)
	{
		statement = (*other).statement;
	}

	return this;
}

void Derived1::who()
{
	cout << statement << endl; 
}

void Derived2::who()
{
	cout << statement << endl;
}

int main()
{
	Base *a = new Derived1;
	(*a).who();

	Base *b = new Derived2;
	(*b).who();

	delete a;	// apparently it makes the b to a assignment
		// no matter how I overload the operator because
		// after the assignment, a has b's address

	a = b;	// it might be easier just to overload objects
		// instead of the pointers
	(*a).who();

	delete a;

	return 0;
}