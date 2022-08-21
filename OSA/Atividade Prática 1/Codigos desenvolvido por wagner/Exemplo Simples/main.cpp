/*********************************************************************
 * PROGRAMA 2: INTRODUÇÃO A LINGUAGEM C++
 * *******************************************************************
 * DESCRICAO: programa para exibir a soma de dois numeros inteiros
 * PROGRAMADOR: Wagner F. Barros
 * DATA: 06/10/2021
 * MODIFICACAO: 09/08/2022
 * *******************************************************************/

// inclusão de bibliotecas
#include "funcoes.h"
#include "funcoes.cpp"
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    a = 123;
    b = Soma(a, a);
    cout<< "Soma de A+B = "<< Soma(a, b) << endl;
    return 0;
}