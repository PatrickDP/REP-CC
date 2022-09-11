#pragma once

#include <iostream>

using namespace std;

class Pilha_Estatica
{
public:
	Pessoa pessoas[TOTAL];
	unsigned topo_Pilha;

	Pilha_Estatica()
	{
		topo_Pilha = 0;
	}
	// Fala se a pilha esta vazia
	bool vazia() const
	{
		return topo_Pilha == 0;
	}
	// Insere
	void push(const Pessoa& pessoa)
	{
		if (topo_Pilha == TOTAL)
		{
			cout << "ERRO: Pilha cheia! \n\n";
			return;
		}
		pessoas[topo_Pilha] = pessoa;
		topo_Pilha++;
	}
	// Remove
	Pessoa pop()
	{
		topo_Pilha--;
		if (vazia() == 1)
		{
			cout << "Pilha vazia!" << endl;
		}
		return pessoas[topo_Pilha];
	}
	void imprime_Pilha()
	{
		for (int posicao = topo_Pilha-1; posicao >= 0; posicao--)
		//for (int posicao = 0; posicao < topo_Pilha; posicao++)
		{
			pessoas[posicao].imprime_Pessoa();
			cout << endl;
		}
		cout << endl;
	}
	~Pilha_Estatica() {}
};

