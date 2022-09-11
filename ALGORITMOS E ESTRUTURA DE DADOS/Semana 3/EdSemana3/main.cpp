#include <iostream>
#include "Aluno.h"
#include "Lista_Estatica_Aluno.h"
#include "Pilha_Estatica_Aluno.h"
#include "Fila_Estatica_Aluno.h"

using namespace std;

int main()
{
	Lista_Estatica_Aluno lista_Estatica_Aluno;

	Aluno aluno_1{ 20,"Patrick" };
	//lista_Estatica_Aluno.adicionar_Alunos(0, aluno_1);

	Aluno aluno_2{ 17,"David" };
	//lista_Estatica_Aluno.adicionar_Alunos(1, aluno_2);
	
	Aluno aluno_3{ 30,"Stephanie" };
	//lista_Estatica_Aluno.adicionar_Alunos(2, aluno_3);
	
	Aluno aluno_4{ 37,"Alexsander" };
	//lista_Estatica_Aluno.adicionar_Alunos(3, aluno_4);

	/*
	lista_Estatica_Aluno.imprime_Alunos();
	
	cout << "- posicao: " << lista_Estatica_Aluno.buscar_Alunos(20) << endl;
	cout << "- posicao: " << lista_Estatica_Aluno.buscar_Alunos(17) << endl;
	cout << "- posicao: " << lista_Estatica_Aluno.buscar_Alunos(30) << endl;
	cout << "- posicao: " << lista_Estatica_Aluno.buscar_Alunos(37) << endl;
	cout << "- posicao: " << lista_Estatica_Aluno.buscar_Alunos(38) << endl;

	lista_Estatica_Aluno.remover_Alunos(20);

	lista_Estatica_Aluno.imprime_Alunos();
	*/
	
	Pilha_Estatica_Aluno pilha_Estatica_Aluno;

	
	pilha_Estatica_Aluno.push_Pilha(aluno_1);
	pilha_Estatica_Aluno.imprime_Pilha();
	
	pilha_Estatica_Aluno.push_Pilha(aluno_2);
	pilha_Estatica_Aluno.imprime_Pilha();
	
	pilha_Estatica_Aluno.push_Pilha(aluno_3);
	pilha_Estatica_Aluno.imprime_Pilha();
	
	pilha_Estatica_Aluno.push_Pilha(aluno_4);
	pilha_Estatica_Aluno.imprime_Pilha();

	pilha_Estatica_Aluno.pop_Pilha();
	pilha_Estatica_Aluno.imprime_Pilha();
	
	if (pilha_Estatica_Aluno.vazia_Pilha() == 1)
	{
		cout << "VAZIA";
	}
	else
		cout << "NAO VAZIA";
	cout << endl;
	
	cout << endl << "< FILA > \n\n";

	Fila_Estatica_Aluno fila_estatica_aluno;

	fila_estatica_aluno.insere_Fila(aluno_1);
	fila_estatica_aluno.imprime_Fila();

	fila_estatica_aluno.insere_Fila(aluno_2);
	fila_estatica_aluno.imprime_Fila();

	fila_estatica_aluno.insere_Fila(aluno_3);
	fila_estatica_aluno.imprime_Fila();

	fila_estatica_aluno.insere_Fila(aluno_4);
	fila_estatica_aluno.imprime_Fila();

	fila_estatica_aluno.remove_Fila();
	fila_estatica_aluno.imprime_Fila();

	system("pause");
	return 0;
}

/*

- LISTAS ESTÁTICAS
	* CRIAR UMA LISTA VAZIA (OK)
	* ADICIONAR (OK)
	* BUSCAR (OK)
	* REMOVER (OK)
	* IMPRIMIR (OK)
- PILHAS
	* VAZIA (RESPONDE SE A PILHA TÁ VAZIA) (OK)
	* PUSH (EMPILHA/INSERE) (OK)
	* POP (DESEMPILHAR/REMOVE) (OK)
- FILAS
'	* VAZIA
	* INSERE
	* REMOVE

*/