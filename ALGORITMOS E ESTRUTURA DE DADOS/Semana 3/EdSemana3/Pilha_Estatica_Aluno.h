#pragma once

#include <iostream>

using namespace std;

class Pilha_Estatica_Aluno
{
public:
	unsigned topo_Pilha;
	Aluno alunos[TOTAL_MAX_ALUNOS];

	Pilha_Estatica_Aluno()
	{
		topo_Pilha = 0;
	}
	~Pilha_Estatica_Aluno() {}

	void imprime_Pilha()
	{
		for (unsigned contador = 0; contador < topo_Pilha; contador++)
		{
			cout << "[" << contador << "] - ";
			alunos[contador].imprime_Aluno();
		}
		cout << endl;
	}
	bool vazia_Pilha() const
	{
		return topo_Pilha == 0;
	}
	void push_Pilha(const Aluno& aluno_Parametro)
	{
		alunos[topo_Pilha] = aluno_Parametro;
		topo_Pilha++;
	}
	Aluno pop_Pilha()
	{
		topo_Pilha--;
		return alunos[topo_Pilha];
	}
};

