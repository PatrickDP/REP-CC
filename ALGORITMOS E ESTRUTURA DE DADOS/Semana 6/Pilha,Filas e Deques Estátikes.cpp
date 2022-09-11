#include <iostream>

#include "Pessoa.h"
#include "Pilha_Estatica.h"
#include "Fila_Estatica.h"
#include "Deque_Estatico.h"

using namespace std;

int main()
{
	Pessoa p1{ 1,"Maria" };
	Pessoa p2{ 2,"Joao" };
	Pessoa p3{ 3,"Reinaldo" };
	Pessoa p4{ 4,"Cibelly" };
	Pessoa p5{ 5,"David" };
	Pessoa p42{ 42,"Inconveniente" };

	/*
	p1.imprime_Pessoa();
	p2.imprime_Pessoa();
	p3.imprime_Pessoa();
	p4.imprime_Pessoa();
	p5.imprime_Pessoa();
	*/

	cout << "\t< PILHA > \n\n";
	cout << "ADICIONANDO ELEMENTOS NA PILHA: \n\n";

	Pilha_Estatica pe;

	pe.push(p1);
	pe.imprime_Pilha();
	pe.push(p2);
	pe.imprime_Pilha();
	pe.push(p3);
	pe.imprime_Pilha();
	pe.push(p4);
	pe.imprime_Pilha();
	pe.push(p5);
	pe.imprime_Pilha();
	pe.push(p42);

	cout << "REMOVENDO ELEMENTOS NA PILHA: \n\n";

	pe.imprime_Pilha();
	
	pe.pop();
	pe.imprime_Pilha();
	pe.pop();
	pe.imprime_Pilha();
	pe.pop();
	pe.imprime_Pilha();
	pe.pop();
	pe.imprime_Pilha();
	pe.pop();

	cout << "\n\t< FILA > \n\n";
	cout << "ADICIONANDO ELEMENTOS NA FILA: \n\n";

	Fila_Estatica fe;

	fe.insere(p1);
	fe.imprime_Fila();
	fe.insere(p2);
	fe.imprime_Fila();
	fe.insere(p3);
	fe.imprime_Fila();
	fe.insere(p4);
	fe.imprime_Fila();
	fe.insere(p5);
	fe.imprime_Fila();
	fe.insere(p42);

	cout << "REMOVENDO ELEMENTOS NA FILA: \n\n";

	fe.imprime_Fila();
	
	fe.remove();
	fe.imprime_Fila();
	fe.remove();
	fe.imprime_Fila();
	fe.remove();
	fe.imprime_Fila();
	fe.remove();
	fe.imprime_Fila();
	fe.remove();
	fe.remove();
	
	cout << "\n\t< DEQUE > \n\n";
	cout << "ADICIONANDO ELEMENTOS NA FILA: \n\n";

	Deque_Estatico de;

	de.insere_Inicio(p2);
	de.imprime_Deque();
	de.insere_Inicio(p1);
	de.imprime_Deque();
	de.insere_Fim(p3);
	de.imprime_Deque();
	de.insere_Fim(p4);
	de.imprime_Deque();
	de.insere_Fim(p5);
	de.imprime_Deque();
	de.insere_Inicio(p42);

	cout << "REMOVENDO ELEMENTOS NO DEQUE: \n\n";

	de.imprime_Deque();
	
	de.remove_Inicio();
	de.imprime_Deque();
	de.remove_Fim();
	de.imprime_Deque();
	de.remove_Inicio();
	de.imprime_Deque();
	de.remove_Fim();
	de.imprime_Deque();
	de.remove_Inicio();
	de.imprime_Deque();
	de.remove_Inicio();

	return 0;
}
