#include <iostream>

using namespace std;

int parametro_Valor(int x);
int parametro_Referencia(int& y);
int parametro_Referencia2(int* y);
int parametro_Referencia3(const int& y);

int main()
{
	int x, y;
	
	x = 1;
	y = 2;

	parametro_Valor(x);
	parametro_Referencia(y);
	cout << "Passagem de parametro por valor: " << x << endl;
	cout << "Passagem de parametro por referencia: " << y << endl;
	parametro_Referencia2(&y);
	cout << "Passagem de parametro por referencia. Valor de y muda novamente! : " << y << endl;
	cout << "Passagem de parametro por referencia com atributo const : " << parametro_Referencia3(y) << endl;

	return 0;
}

int parametro_Valor(int x)
{
	x = 3;
	return x;
}
int parametro_Referencia(int& y)
{
	y = 4;
	return y;
}
int parametro_Referencia2(int *y)
{
	*y = 5;
	return *y;
}
int parametro_Referencia3(const int& y) // O atríbuto const permite que o parâmetro não seja modificado
{
	// y = 6; : erro de compilação! Pois o const não permite a modificação.
	return y-1;
}