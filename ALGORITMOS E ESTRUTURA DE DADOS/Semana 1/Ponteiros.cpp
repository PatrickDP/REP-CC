#include <iostream>

using namespace std;

int main()
{
	bool achou = true;
	bool* achou_Pointer = &achou;

	cout << achou_Pointer << endl;  // Endere�o de mem�ria para qual o ponteiro aponta.
	cout << &achou_Pointer << endl; // Endere�o de mem�ria do pr�prio ponteiro.
	cout << *achou_Pointer << endl; // Valor da vari�vel para qual o ponteiro aponta.
	cout << &achou << endl;         // Endere�o de mem�ria da vari�vel.
	cout << achou << endl;
	return 0;
}