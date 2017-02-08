#include <iostream>

using namespace std;

class test{

public:

	test();
	test(int want);
	test(const test &other);
	test & operator=(const test &other);
	~test();

	void copy(const test &other, int *&see);
	void clear(int *&work);

	int* getInspect() const;

private:

	int *inspect;

};

test::test()
{
	inspect = NULL;
}

test::test(int want)
{
	inspect = new int(want);
}

test::test(const test &other)
{
	cout << "copy constructor, inspect is: " << inspect << endl;
	copy(other, inspect);
}

test & test::operator=(const test &other)
{
	if(this != &other)
	{
		if(inspect)
			clear(inspect);
	
		copy(other, inspect);
	}

	return *this;
}

test::~test()
{
	if(inspect)	// try not to delete NULLs, such as b
		clear(inspect);
}

// What' I'm trying to test
/*
 *	Should I be passing by reference? and does it make sense to
 *		do that for class members?
 *		What I want to use this information for is to do a recursive
 *		function that builds a tree using a class pointer
 *	Also do I need to return by reference for stuff such as get pointer?
 */

void test::copy(const test &other, int *&see)
{
	cout << "copy function, inspect is: " << inspect << endl;
	cout << "copy function, see is: " << see << endl;
	see = new int(*(other.getInspect()));
	cout << "after copy, inspect is: " << inspect << endl;
	cout << "after copy, see is: " << see << endl;
}

// Conclusion on clear
//	when passed by reference, it passes inspect's address correctly
//	but when you delete and set work to NULL it deletes inspect
//	and resets it's value to 0, but it doesn't set inspect's address to NULL

// When passing by reference, setting delete work and setting it to NULL
// does the same thing to inspect
void test::clear(int *&work)
{
	cout << "clear function, work is: " << work << endl;
	cout << "clear function, inspect is: " << inspect << endl;
	cout << "inspect has: " << *inspect << endl;	
	delete work;
	work = NULL;
	cout << "clear function, post delete work is: " << work << endl;
	cout << "clear function, post delete inspect is: " << inspect << endl;
	//cout << "inspect has: " << *inspect << endl;
}

// I actually dont think I can return by reference for this
int* test::getInspect() const
{
	cout << "class value is: " << inspect << endl;
	return inspect;
}

// What I noticed so far, if you pass by value you'll get the same address
// but that doesn't mean that changes to the copied variable will happen to the
// original one

int main()
{
	test a(5);

	cout << endl;

	test b;	// default, inspect is NULL
	cout << "b's inspect is: " << b.getInspect() << endl;

	b = a;	// test assignment operator
	cout << "b's inspect is now: " << b.getInspect() << endl;
	// return by value if you just dereference, return by reference for idk what
	cout << "the value is: " << *(b.getInspect()) << endl;

	*(b.getInspect()) = 10;	// try changing it
	// it actually changes it
	cout << "the value is: " << *(b.getInspect()) << endl;


	return 0;
}

// Summary, pass by reference for class variables if you want to change the class member value