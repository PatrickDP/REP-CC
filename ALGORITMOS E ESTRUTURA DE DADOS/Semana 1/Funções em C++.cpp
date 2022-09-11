#include <iostream>

using namespace std; 

int soma_Numeros(int x, int y);

int main()
{
	int a, b;

	a = 1;
	b = 1;
	cout << soma_Numeros(a, b);

	return 0;
}

int soma_Numeros(int x, int y)
{
	return x + y;
}
