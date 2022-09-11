#include "aluno.h"

Aluno::Aluno()
{
	chave = 0;
	nome = "Dummy";
}
Aluno::Aluno(unsigned chave, const string& nome)
{
	this->chave = chave;
	this->nome = nome;
}
// ALOCAÇÃO DINÂMICA DO ALUNO
/*
Aluno* Aluno::foo_Din()
{
	Aluno* alunoDinPtr = NULL;
	alunoDinPtr = new Aluno(7, "Lucio");
	return alunoDinPtr;
}
*/
void Aluno::imprime_Alunos()
{
	cout << "<" << chave << "," << nome << "> ";
	cout << endl;
}
Aluno::~Aluno() {}