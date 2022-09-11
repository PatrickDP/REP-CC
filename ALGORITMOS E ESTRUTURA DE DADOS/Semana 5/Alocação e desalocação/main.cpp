#include <iostream>
#include "aluno.h"

using namespace std;

int main()
{
    // Aluno* alunoMainPTR = NULL;
    // alunoMainPTR = alunoMainPTR->foo_Din();

    // ALOCACAO DINÂMICA DO ALUNO
    Aluno* aluno_1 = NULL;
    aluno_1 = new Aluno{ 1,"Jose" };
    // BOA PRÁTICA DE PROGRAMAÇÃO
    if (!aluno_1)
    {
        cout << "ERRO: Falta memoria!" << endl;
    }
    Aluno* aluno_2 = NULL;
    aluno_2 = new Aluno{ 2,"Maria" };
    if (!aluno_2)
    {
        cout << "ERRO: Falta memoria!" << endl;
    }
    aluno_2->imprime_Alunos();
    // DELETA O ALUNO
    delete aluno_2;
    // aluno_2->imprime_Alunos(); : vai dar erro porque deletei o aluno.
    aluno_1->imprime_Alunos();
    return 0;
}

