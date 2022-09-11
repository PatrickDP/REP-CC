#include <iostream>
#include <locale>
#include "aluno.h"
#include "ListaEstaticaAluno.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Portuguese");
	
	ListaEstaticaAluno lista;
	
	Aluno a1{ 20, "Patrick" };
	lista.insere_Lista(0, a1);
	
	Aluno a2{ 17, "David" };
	lista.insere_Lista(1, a2);

	Aluno a3{ 37, "Alexsander" };
	lista.insere_Lista(2, a3);

	Aluno a4{ 30, "Stephanie" };
	lista.insere_Lista(2, a4);

	lista.imprime_Alunos_Lista();
	cout << endl;
	if (lista.busca_Lista(20) == -1)
	{
		cout << "Chave não encontrada!" << endl;
	}
	else
	{
		cout << "A chave \"" << lista.alunos->chave << "\" encontra-se na lista!" << endl;
	}
	cout << endl;
	lista.remove_Lista(30);

	return 0;
}
