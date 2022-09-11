#define euler = 2.71 // Macro também é constante!

#include <iostream>

using namespace std;

int main()
{
	const float pi = 3.14;
	/* pi = 3.21 : Atribuição incorreta pois, uma vez que uma variável possui o atríbuto
	"const", ela não pode ser modificada! */
	cout << pi << endl;
	return 0;
}