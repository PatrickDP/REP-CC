#pragma once

#include <iostream>

using namespace std;

class Fila_Estatica
{
public:
	Pessoa pessoas[TOTAL];
	unsigned topo_Fila;
	unsigned base_Fila;
	unsigned tamanho_Fila;

	Fila_Estatica()
	{
		topo_Fila = TOTAL - 1;
		base_Fila = TOTAL - 1;
		tamanho_Fila = 0;
	}
	bool vazia() const
	{
		return tamanho_Fila == 0;
	}
	void insere(const Pessoa& pessoa)
	{
		if (tamanho_Fila == TOTAL)
		{
			cout << endl << "ERRO: Fila cheia! \n\n";
			return;
		}
		tamanho_Fila++;
		topo_Fila++;
		// Resultado do módulo entre topo_Fila & total
		topo_Fila = topo_Fila % TOTAL; 
		pessoas[topo_Fila] = pessoa;
	}
	Pessoa remove()
	{
		if (vazia() == 1)
		{
			cout << endl << "ERRO: Fila vazia! \n";
			return Pessoa();
		}
		tamanho_Fila--;
		base_Fila++;
		base_Fila = base_Fila % TOTAL;
		pessoas[base_Fila] = Pessoa();
		return pessoas[base_Fila];
	}
	void imprime_Fila()
	{
		cout << " topo: " << topo_Fila << " ; base: " << base_Fila << " ; tamanho : " << tamanho_Fila << endl;
		for (unsigned posicao = 0; posicao < TOTAL; posicao++)
		{
			if (pessoas[posicao].chave != 0)
			{
				pessoas[posicao].imprime_Pessoa();
				cout << " ; ";
			}
		}
		cout << endl;
	}
};

