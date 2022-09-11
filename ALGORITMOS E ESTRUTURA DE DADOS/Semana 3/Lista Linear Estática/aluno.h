#pragma once

#include <iostream>

using namespace std;

class Aluno
{
public:
	unsigned chave{};
	string nome;
public:
	Aluno() {}
	Aluno(unsigned novaChave_a, const string& novoNome_a)
	{
		chave = novaChave_a;
		nome = novoNome_a;
	}
	~Aluno() {}
	
	void imprime_Aluno()
	{
		cout << "chave: " << chave <<  " - " << "nome: " << nome << endl;
	}
};


/*

TAD (TIPO ABSTRATO DE DADOS)

Para classe Aluno:

- Atr�buto & Construtor: Chave ( ou CPF), nome e construtor aluno.
  > const string& novoNome_a: utiliza��o da passagem de
  par�metro por refer�ncia.
- Construtor Aluno: Funcionar� como a fun��o set, ela recebe
  os dados dos alunos, neste caso, a chave e o nome.
- Fun��o "void imprime_Aluno() {...}: Imprime os dados
  do aluno.

*/
