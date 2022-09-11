#pragma once

#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista_Encadeada
{
public:
	Nodo* inicio; // Ponteiro que dar� in�cio a lista

	Lista_Encadeada();
	void imprime_Lista() const;
	void insere_Lista(int posicao, const Aluno& aluno);
	void* busca_Lista(unsigned chave) const;
	void remove_Lista(unsigned chave);
	~Lista_Encadeada();
};

