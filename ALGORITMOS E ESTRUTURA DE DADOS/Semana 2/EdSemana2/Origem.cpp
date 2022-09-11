#include <iostream>

using namespace std;

int passarRef(int& a)
{
	return a = 10;
}

int main()
{
	int a;


	a = 5;
	cout << a;
	cout << endl << passarRef(a);
	return 0;
}