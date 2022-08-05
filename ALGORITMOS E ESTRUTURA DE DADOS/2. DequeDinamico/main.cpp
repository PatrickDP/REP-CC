/*
[ INSTITUTO FEDERAL DO NORTE DE MINAS GERAIS / CAMPUS MONTES CLAROS - TURMA 2019 DE CIÊNCIA DA COMPUTAÇÃO ]
                                    ALUNO: PATRICK DUARTE PIMENTA | Ano: 2020
*/
#include <iostream>

#include "Deque.h"

using namespace std;

int main()
{
    Deque d;

    Cliente c1(1,"a");
    Cliente c2(2,"b");
    Cliente c3(3,"c");
    Cliente c4(4,"d");
    Cliente c5(5,"e");
    Cliente c6(6,"f");
    Cliente c7(7,"g");
    Cliente c8(8,"h");
    Cliente c9(9,"i");
    Cliente c10(10,"j");
    /*
    cout << "<< ADICIONANDO E IMPRIMINDO ELEMENTOS>> \n\n";

    d.insereFim(c1);
    d.insereFim(c3);
    d.insereInicio(c4);
    d.insereFim(c8);
    d.insereInicio(c7);

    d.imprime();

    cout << endl << "<< REMOVENDO ELEMENTOS NO INICIO >> \n\n";

    d.pegaInicio().imprimeCliente();
    d.pegaInicio().imprimeCliente();
    d.pegaInicio().imprimeCliente();

    cout << "\n\n<< IMPRIMINDO ELEMENTOS >> \n\n";

    d.imprime();

    cout << endl << "<< REMOVENDO ELEMENTOS NO INICIO E IMPRIMINDO >> \n\n";

    d.pegaInicio().imprimeCliente();
    d.pegaInicio().imprimeCliente();
    d.pegaInicio().imprimeCliente();

    cout << "\n\n<< ADICIONANDO E IMPRIMINDO ELEMENTOS>> \n\n";

    d.insereInicio(c2);
    d.insereInicio(c6);
    d.insereInicio(c9);
    d.insereFim(c3);
    d.insereFim(c7);

    d.imprime();

    cout << endl << "<< REMOVENDO ELEMENTOS NO FIM >> \n\n";

    d.pegaFim().imprimeCliente();
    d.pegaFim().imprimeCliente();
    d.pegaFim().imprimeCliente();

    cout << "\n\n<< IMPRIMINDO ELEMENTOS >> \n\n";

    d.imprime();

    cout << endl << "<< REMOVENDO ELEMENTOS NO FIM >> \n\n";

    d.pegaFim().imprimeCliente();
    d.pegaFim().imprimeCliente();
    d.pegaFim().imprimeCliente();

    cout << "\n\n<< IMPRIMINDO ELEMENTOS >> \n\n";

    d.imprime();
    */

    d.insereFim(c1);
    d.insereFim(c2);
    d.insereFim(c3);
    d.insereFim(c4);
    d.insereFim(c5);

    d.imprime();
    d.~Deque();
    d.imprime();

    return 0;
}
