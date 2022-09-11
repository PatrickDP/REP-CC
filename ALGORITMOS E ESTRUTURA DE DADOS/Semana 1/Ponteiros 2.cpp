#include <iostream>

using namespace std;

int main()
{
	int* ptr;
	int valor = 1;
	ptr = &valor;
	*ptr = 10;

	cout << *ptr << endl;
	cout << ptr << endl;
	cout << &ptr;

	return 0;
}