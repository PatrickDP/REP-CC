#pragma once

#include <iostream>

using namespace std;

class Deque_Estatico
{
public:
	Pessoa pessoas[TOTAL];
	unsigned tamanho_Deque;
	unsigned topo_Deque;
	unsigned base_Deque;

	Deque_Estatico()
	{
		tamanho_Deque = 0;
		topo_Deque = 0;
		base_Deque = TOTAL - 1;
	}
	bool vazio() const
	{
		return tamanho_Deque == 0;
	}
	void insere_Inicio(const Pessoa& pessoa)  
	{
		if (tamanho_Deque == TOTAL)
		{
			cout << endl << "ERRO: Deque cheio! \n\n";
			return;
		}
		for (int posicao = tamanho_Deque; posicao > topo_Deque; posicao--)
		{
			pessoas[posicao] = pessoas[posicao - 1];
		}
		pessoas[topo_Deque] = pessoa;
		tamanho_Deque++;
	}
	void insere_Fim(const Pessoa& pessoa) 
	{
		if (tamanho_Deque == TOTAL)
		{
			cout << endl << "ERRO: Deque cheio! \n\n";
			return;
		}
		pessoas[tamanho_Deque] = pessoa;
		tamanho_Deque++;
	}
	void remove_Inicio() 
	{
		if (vazio() == 1)
		{
			cout << endl << "ERRO: Deque vazio! \n";
			return;
		}
		pessoas[topo_Deque] = Pessoa();
		tamanho_Deque--;
		topo_Deque++;
	}
	void remove_Fim() 
	{
		if (vazio() == 1)
		{
			cout << endl << "ERRO: Deque vazio! \n";
			return;
		}
		pessoas[base_Deque] = Pessoa();
		tamanho_Deque--;
		base_Deque--;
	}
	void imprime_Deque() 
	{
		for (int posicao = 0; posicao < TOTAL; posicao++)
		{
			pessoas[posicao].imprime_Pessoa();
			cout << " ; ";
		}
		cout << endl;
	}
};


