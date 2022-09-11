#include "Aluno.h"

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
Aluno::~Aluno() {}