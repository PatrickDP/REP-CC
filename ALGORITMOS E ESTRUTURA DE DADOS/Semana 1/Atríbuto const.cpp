#define euler = 2.71 // Macro tamb�m � constante!

#include <iostream>

using namespace std;

int main()
{
	const float pi = 3.14;
	/* pi = 3.21 : Atribui��o incorreta pois, uma vez que uma vari�vel possui o atr�buto
	"const", ela n�o pode ser modificada! */
	cout << pi << endl;
	return 0;
}