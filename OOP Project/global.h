#include"Header2.h"

using namespace std;

class Manager
{
protected:
public:
	string name;
	int id;
};
class User
{
protected:
public:
	string name;
	int id;
};


void global()
{
	cout << "global";
}

template<typename T>
T tempaMethod(T a, T b)
{
	MyClass temp = static_cast<MyClass>(a);
	MyClass temp2= static_cast<MyClass>(b);
	MyClass result;
	result.name = temp.name;
	result.id = temp2.id;
	return result;
}

