#pragma once

#include <iostream>

#define TOTAL_MAX_ALUNOS 4

using namespace std;

class Aluno
{
public:
	unsigned chave_Aluno{}; // {} Inicializa a variável
	string nome_Aluno;

	Aluno() {}
	Aluno(unsigned chave_Aluno, const string& nome_Aluno) 
	{
		this->chave_Aluno = chave_Aluno;
		this->nome_Aluno = nome_Aluno;
	}

	~Aluno() {}
	
	void imprime_Aluno() const 
	{
		// const NÃO MEXE NA ESTRUTURA DE DADOS

		cout << "\t > Chave: " << chave_Aluno << " - Nome: " << nome_Aluno << endl;
	}
};

