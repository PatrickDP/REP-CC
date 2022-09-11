#include <iostream>
#include <iomanip> // Fornece manipuladores paramétricos
#include "classe.h"

using namespace std;

int main()
{
	ALUNO_IF a1;
	a1.nome_A = "Tadeu";
	a1.notas_A[0] = 60;
	a1.notas_A[1] = 40;
	a1.notas_A[2] = 85;
	ALUNO_IF a2;
	a2.nome_A = "Alberto";
	a2.notas_A[0] = 45;
	a2.notas_A[1] = 40;
	a2.notas_A[2] = 28;
	cout << "A nota da primeira prova de " << a1.nome_A << " eh: " << a1.notas_A[0] << endl;
	cout << "A media de suas notas sao: " << setprecision(5) << a1.calcula_MEDIA() << endl;
	cout << "Situacao: ";
	if (a1.status_ALUNO() == true)
	{
		cout << "APROVADO";
	}
	else
		cout << "REPROVADO";
	cout << "\n\n";
	cout << "A nota da primeira prova de " << a2.nome_A << " eh: " << a2.notas_A[0] << endl;
	cout << "A media de suas notas sao: " << setprecision(5) << a2.calcula_MEDIA() << endl;
	cout << "Situacao: ";
	if (a2.status_ALUNO() == true)
	{
		cout << "APROVADO";
	}
	else
		cout << "REPROVADO";
	cout << "\n\n";

	system("pause");
	
	return 0;
}