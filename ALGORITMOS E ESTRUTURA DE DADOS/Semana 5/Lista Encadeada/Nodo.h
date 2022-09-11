#pragma once

#include <iostream>
#include "Aluno.h"

using namespace std;

class Nodo
{
public:
	Nodo* prox;  // Ponteiro para o próximo elemento
	Aluno aluno; // Destinado para guardar informações

	Nodo();
	Nodo(const Aluno& aluno);
	~Nodo();
};

