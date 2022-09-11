#include <iostream>
#include "Aluno.h"
#include "Nodo.h"
#include "Lista_Encadeada.h"

using namespace std;

int main()
{
	Lista_Encadeada le;

	Aluno aluno_1{ 1,"Patrick" };
	le.insere_Lista(0, aluno_1);
	le.imprime_Lista();

	Aluno aluno_errado{ 2,"David" };
	le.insere_Lista(3, aluno_errado);

	Aluno aluno_2{ 2,"Davi" };
	le.insere_Lista(1, aluno_2);
	le.imprime_Lista();
	
	cout << le.busca_Lista(1) << endl;
	cout << le.busca_Lista(2) << endl;
	cout << le.busca_Lista(3) << endl;

	le.remove_Lista(2);
	le.imprime_Lista();

	le.~Lista_Encadeada();
	le.imprime_Lista();

	system("pause");
	return 0;
}