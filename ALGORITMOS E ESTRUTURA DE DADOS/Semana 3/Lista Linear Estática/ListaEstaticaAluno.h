#pragma once

#include <iostream>
#include "aluno.h"

#define MAX_ALUNOS 100

using namespace std;

class ListaEstaticaAluno
{
public:
	unsigned tamanho;
	Aluno alunos[MAX_ALUNOS];
public:
	ListaEstaticaAluno()
	{
		tamanho = 0;
	}
	~ListaEstaticaAluno() {}
	
	void imprime_Alunos_Lista()
	{
		for (unsigned i = 0; i < tamanho; i++)
		{
			alunos[i].imprime_Aluno();
		}
	}
	void insere_Lista(unsigned posicao_Lista, const Aluno& aluno) 
	{
		// CASO A POSICAO INSERIDA ESTIVER FORA DO LIMITE DA LSITA
		if (posicao_Lista > tamanho)
		{
			cout << "Posição inválida!" << endl;
			return;
		}
		// LISTA CHEIA
		if (MAX_ALUNOS == tamanho)
		{
			cout << "Lista cheia!" << endl;
			return;
		}
		// DESLOCANDO TODOS OS ALUNOS DE POSICAO EM DIANTE (A DIREITA)
		for (unsigned i = tamanho; i > posicao_Lista; i--)
		{
			alunos[i] = alunos[i - 1];
		}
		// ESCREVE NOVO ALUNO
		alunos[posicao_Lista] = aluno;
		tamanho++;
	}
	int busca_Lista(unsigned chave_Busca) 
	{
		int indice = -1;

		// PROCURA O ALUNO
		for (unsigned posicao = 0; posicao < tamanho; posicao++)
		{
			// ENCONTROU O ALUNO
			if (alunos[posicao].chave == chave_Busca)
			{
				indice = posicao;
				posicao = tamanho;
			}
		}
		// ALUNO NÃO ENCONTRADO
		return indice; 
	}
	void remove_Lista(unsigned chave_Busca)
	{
		unsigned posicao;

		posicao = busca_Lista(chave_Busca);

		if (posicao >= 0)
		{
			tamanho--;
			for (unsigned i = posicao; i < tamanho; i++)
			{
				alunos[i] = alunos[i + 1];
			}
		}
		imprime_Alunos_Lista();
	}
};

/*

TAD (da a classe ListaEstaticaAluno)

- atríbutos
  > tamanho: Tamanho da lista:
  > Aluno alunos[MAX_ALUNOS]: Tipo para Aluno para alunos e o seu tamanho total.
    O macro serve para definir o tamanho máximo que
	a lista deve ter.
- Métodos
  > Construtor da linha 16: Inicializa a lista de tamanho 0.
  > void imprime_Alunos_Lista(): Imprime os dados dos alunos.
  > void insere_Lista:
    * posição
	* dados dos alunos.

*/