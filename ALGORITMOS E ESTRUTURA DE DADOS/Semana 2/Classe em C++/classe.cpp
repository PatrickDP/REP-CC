#include "classe.h"

double ALUNO_IF::calcula_MEDIA()
{
	int somatorio = 0;
	double media = 0;

	for (unsigned i = 0; i < TOTAL_NOTAS; i++)
	{
		somatorio += notas_A[i];
	}
	media = somatorio / (double)TOTAL_NOTAS;
	return media;
}
bool ALUNO_IF::status_ALUNO()
{
	if (calcula_MEDIA() >= 60)
	{
		return true;
	}
	else
		return false;
}

// 12: caso as variaveis tenham tipo e submetidas a operacao de divisao. é importante fazer "casting"