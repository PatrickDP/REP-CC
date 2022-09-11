#include "Nodo.h"

// Inicializa *prox com NULL
Nodo::Nodo()
{
	prox = NULL;
}
// Inicializa o aluno
Nodo::Nodo(const Aluno& novo_Aluno)
{
	prox = NULL;
	aluno = novo_Aluno;
}
Nodo::~Nodo() {};
