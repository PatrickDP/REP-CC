#pragma once

#include <iostream>

using namespace std;

class Lista_Estatica_Aluno
{
public:
	unsigned tamanho_Lista;
	Aluno alunos[TOTAL_MAX_ALUNOS];

	Lista_Estatica_Aluno()
	{
		tamanho_Lista = 0;
	}
	~Lista_Estatica_Aluno() {}

	void imprime_Alunos() const
	{
		for (unsigned posicao = 0; posicao < tamanho_Lista; posicao++)
		{
			alunos[posicao].imprime_Aluno();
		}
	}
	void adicionar_Alunos(unsigned posicao_Fornecida_Aluno, const Aluno& aluno_Parametro) 
	{
		if (posicao_Fornecida_Aluno > tamanho_Lista)
		{
			cout << "POSICAO INVALIDA!";
			return;
		}
		if (tamanho_Lista >= TOTAL_MAX_ALUNOS)
		{
			cout << "LISTA CHEIA!" << endl;
			return;
		}
		// DESLOCANDO A LISTA DA DIREITA PARA A ESQUERDA
		for (unsigned posicao = tamanho_Lista; posicao > posicao_Fornecida_Aluno; posicao--)
		{
			alunos[posicao] = alunos[posicao - 1];
		}
		alunos[posicao_Fornecida_Aluno] = aluno_Parametro;
		tamanho_Lista++;
	}
	int buscar_Alunos(unsigned chave_Aluno)  const
	{
		int indice = -1;
		unsigned posicao = 0;

		while (posicao < tamanho_Lista)
		{
			if (alunos[posicao].chave_Aluno == chave_Aluno)
			{
				indice = posicao;
				posicao = tamanho_Lista; // FORÇA A PARADA!
			}
			posicao++;
		}

		return indice;
	}
	void remover_Alunos(unsigned chave_Aluno) 
	{
		unsigned posicao_Aluno = 0;

		posicao_Aluno = buscar_Alunos(chave_Aluno);

		for (unsigned posicao = posicao_Aluno; posicao < tamanho_Lista; posicao++)
		{
			alunos[posicao] = alunos[posicao + 1];
		}
		tamanho_Lista--;
	}
};

