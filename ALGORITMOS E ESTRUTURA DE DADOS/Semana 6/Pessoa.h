#pragma once

#include <iostream>

#define TOTAL 5

using namespace std;

class Pessoa
{
public:
	unsigned chave;
	string nome;

	Pessoa()
	{
		chave = 0;
		nome = "Dummy";
	}
	Pessoa(unsigned chave, const string& nome)
	{
		this->chave = chave;
		this->nome = nome;
	}
	void imprime_Pessoa()
	{
		cout << "[" << chave << "] - " << nome;
	}
	~Pessoa() {}
};

