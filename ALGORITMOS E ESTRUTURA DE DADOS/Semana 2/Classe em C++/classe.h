#pragma once

#include <iostream>

#define TOTAL_NOTAS 3

using namespace std;

class ALUNO_IF
{
public:
	string nome_A;
	unsigned notas_A[TOTAL_NOTAS];
public:
	double calcula_MEDIA();
	bool status_ALUNO();
};

