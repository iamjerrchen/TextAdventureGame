#include <string>
#include <iostream>

using namespace std;

class Base{

protected:

	struct creation{

		string som;

		creation() {
			som = "I created something";
		}

		string getsom()
		{
			return som;
		}

	};

public:

	virtual ~Base() {}

	virtual void who() = 0;

public:

	string statement;

};

class Derived1 : public Base{

public:

	Derived1();

	Base& operator=(const Base &other);
	~Derived1() { delete thing;
		cout << "Deleted it" << endl;}

	void who();

private:

	creation *thing;

};


Derived1::Derived1()
{
	statement = "I am a Derived1";

	thing = new creation;

	cout << thing->getsom() << endl;;
}


Base& Derived1::operator=(const Base &other)
{
	cout << "I used the derives operator" << endl;
	if(this != &other)
	{
		statement = other.statement;
	}

	return *this;
}


void Derived1::who()
{
	cout << statement << endl; 
}


int main()
{
	Base *a = new Derived1;
	Derived1 b;

	b = *a;

	return 0;
}