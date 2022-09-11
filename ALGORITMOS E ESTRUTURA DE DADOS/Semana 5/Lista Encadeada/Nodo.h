#pragma once

#include <iostream>
#include "Aluno.h"

using namespace std;

class Nodo
{
public:
	Nodo* prox;  // Ponteiro para o pr�ximo elemento
	Aluno aluno; // Destinado para guardar informa��es

	Nodo();
	Nodo(const Aluno& aluno);
	~Nodo();
};

