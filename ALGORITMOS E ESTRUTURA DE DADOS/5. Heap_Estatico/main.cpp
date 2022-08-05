/*
[ INSTITUTO FEDERAL DO NORTE DE MINAS GERAIS / CAMPUS MONTES CLAROS - TURMA 2019 DE CIÊNCIA DA COMPUTAÇÃO ]
                                    ALUNO: PATRICK DUARTE PIMENTA | Ano: 2020
*/
#include <iostream>
#include "Heap.hpp"

using namespace std;

int main()
{
    Cliente c1(20,"c1");
    Cliente c2(80,"c2");
    Cliente c3(40,"c3");
    Cliente c4(50,"c4");
    Cliente c5(10,"c5");
    Cliente c6(25,"c6");
    Cliente c7(35,"c7");
    Cliente c8(60,"c8");
    Cliente c9(45,"c9");

    Heap h;

    cout << "\t\t\t :: INSERE E IMPRIME O HEAP ::\n";

    h.inserir(c1);
    h.imprimir();
    h.inserir(c2);
    h.inserir(c3);
    h.inserir(c4);
    h.inserir(c5);
    h.inserir(c6);
    h.inserir(c7);
    h.inserir(c8);
    h.inserir(c9);
    h.imprimir();

    cout << endl << "\t :: SELECIONA O ELEMENTO DE MAIOR PRIORIDADE E IMPRIME ::\n";

    h.seleciona().imprime();

    cout << "\n\n\t :: REMOVE O ELEMENTO COM MAIOR PRIORIDADE E IMPRIME ::\n";

    h.remover();
    h.imprimir();
    h.remover();
    h.remover();
    h.remover();
    h.imprimir();

    cout << endl << "\t :: SELECIONA O ELEMENTO DE MAIOR PRIORIDADE E IMPRIME ::\n";

    h.seleciona().imprime();

    cout << endl;

    return 0;
}
