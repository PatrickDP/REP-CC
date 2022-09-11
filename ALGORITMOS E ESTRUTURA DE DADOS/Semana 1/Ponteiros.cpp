#include <iostream>

using namespace std;

int main()
{
	bool achou = true;
	bool* achou_Pointer = &achou;

	cout << achou_Pointer << endl;  // Endereço de memória para qual o ponteiro aponta.
	cout << &achou_Pointer << endl; // Endereço de memória do próprio ponteiro.
	cout << *achou_Pointer << endl; // Valor da variável para qual o ponteiro aponta.
	cout << &achou << endl;         // Endereço de memória da variável.
	cout << achou << endl;
	return 0;
}