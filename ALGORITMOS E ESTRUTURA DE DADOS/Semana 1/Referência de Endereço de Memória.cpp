#include <iostream>

using namespace std;

int main()
{
	int i;
	int& ref = i;

	cout << &i << endl;
	cout << &ref << endl;
	return 0;
}