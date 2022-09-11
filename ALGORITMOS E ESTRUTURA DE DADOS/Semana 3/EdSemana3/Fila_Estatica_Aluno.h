#pragma once

#include <iostream>

using namespace std;

class Fila_Estatica_Aluno
{
public:
	Aluno alunos[TOTAL_MAX_ALUNOS];
	unsigned topo_Fila;
	unsigned base_Fila;
	unsigned tamanho_Fila;

	// Inicializa
	Fila_Estatica_Aluno()
	{
		topo_Fila = TOTAL_MAX_ALUNOS - 1;
		base_Fila = TOTAL_MAX_ALUNOS - 1;
		tamanho_Fila = 0;
	}
	void imprime_Fila() const
	{
		cout << "topo: " << topo_Fila << " ; base: " << base_Fila << "; tamanho: " << tamanho_Fila << endl;
		for (unsigned p = 0; p < tamanho_Fila; p++)
		{
			alunos[p].imprime_Aluno();
		}
	}
	// Só fala que a pilha tá vazia!
	bool vazia_Fila() const
	{
		return tamanho_Fila == 0;
	}
	void insere_Fila(const Aluno& aluno)
	{
		// Fila cheia!
		if (tamanho_Fila == TOTAL_MAX_ALUNOS)
		{
			cout << "Erro: Fila esta cheia!" << endl;
			return;
		}
		
		tamanho_Fila++;

		topo_Fila++; // Incrementa o topo
		topo_Fila = topo_Fila % TOTAL_MAX_ALUNOS; // Caso o array esgotou, volta para o inicio;

		alunos[topo_Fila] = aluno;
	}
	Aluno remove_Fila()
	{
		if (vazia_Fila())
		{
			cout << "Erro: fila esta vazia!" << endl;
			return Aluno();
		}

		tamanho_Fila--;

		base_Fila++; // Incrementa a base
		base_Fila = base_Fila % TOTAL_MAX_ALUNOS; // Caso array esgotou, volta para o inicio;

		return alunos[base_Fila];
	}
};

