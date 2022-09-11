#include "Lista_Encadeada.h"

// Inicializa a lista com tamanho 0
Lista_Encadeada::Lista_Encadeada()
{
	inicio = NULL;
}
// Imprime os elementos da lista
void Lista_Encadeada::imprime_Lista() const
{
	Nodo* novo_Nodo = inicio; // Ponteiro auxiliar que pecorrerá a lista
	
	if (!inicio)
	{
		cout << "Lista vazia!" << endl;
	}
	while (novo_Nodo)
	{
		cout << novo_Nodo->aluno.chave << " - " << novo_Nodo->aluno.nome << " , ";
		novo_Nodo = novo_Nodo->prox;
	}
	cout << endl;
}
// Insere os elementos na lista
void Lista_Encadeada::insere_Lista(int posicao, const Aluno& aluno)
{
	// Inserido de forma dinâmica o aluno.
	Nodo* novo_Nodo = new Nodo(aluno);
	Nodo* anterior_Nodo = inicio; // Ponteiro que apontará e disponibilizará endereço do elemento anterior

	// Caso o elemento for inserido na posicao 0
	if (posicao == 0)
	{
		novo_Nodo->prox = inicio;
		inicio = novo_Nodo;
		return;
	}
	// Pecorre a lista até a posição desejada
	for (int p = 0; p < posicao - 1; p++)
	{
		// Caso a posicao fornecida seja maior que o número de nodos
		if (! anterior_Nodo->prox)
		{
			cout << "Posicao invalida!" << endl;
			return;
		}
		anterior_Nodo = anterior_Nodo->prox;
	}
	//cout << "Ponteiro anterior: " << anterior_Nodo->aluno.chave << endl;
	// Ajusta os ponteiros na posicao desejada
	novo_Nodo->prox = anterior_Nodo->prox;
	anterior_Nodo->prox = novo_Nodo;
}
void* Lista_Encadeada::busca_Lista(unsigned chave) const
{
	Nodo* atual_Nodo = inicio; // Pecorre a lista

	while (atual_Nodo)
	{
		if (atual_Nodo->aluno.chave == chave)
		{
			// Encontrou o elemento!
			return& (atual_Nodo->aluno);
		}
		atual_Nodo = atual_Nodo->prox;
	}
	// Não encontrou o elemento!
	return NULL;
}
void Lista_Encadeada::remove_Lista(unsigned chave)
{
	Nodo* atual_Nodo = inicio; // Pecorre a lista
	Nodo* anterior_Nodo = NULL; // Receberá o nodo anterior

	// Pecorre a lista em busca do elemento
	while (atual_Nodo)
	{
		if (atual_Nodo->aluno.chave == chave)
		{
			break;
		}
		// Armazena o nodo anterior
		anterior_Nodo = atual_Nodo;
		atual_Nodo = atual_Nodo->prox;
	}
	// Caso a chave não exista
	if (!atual_Nodo)
	{
		cout << "Chave inválida!" << endl;
	}
	else
	{
		// Caso a chave não estiver no primeiro elemento da lista
		if (anterior_Nodo)
		{
			// Ajusta o nodo anterior, apontado para o elemento posterior do nodo a ser removido
			anterior_Nodo->prox = atual_Nodo->prox;
		}
		// Se estiver no primeiro elemento da lista
		else
			// Ajusta o ponteiro inicio como primeiro nodo
			inicio = atual_Nodo->prox;
		// Remove dinâmicamente o nodo
		delete atual_Nodo;
	}
}
Lista_Encadeada::~Lista_Encadeada() 
{
	Nodo* prox; // Recebe o nodo posterior
	
	// Pecorre todos os nodos, apagando um por um
	while (inicio)
	{
		prox = inicio->prox;
		delete inicio;
		inicio = prox;
	}
}