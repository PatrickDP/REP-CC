/*
[ INSTITUTO FEDERAL DO NORTE DE MINAS GERAIS / CAMPUS MONTES CLAROS - TURMA 2019 DE CIÊNCIA DA COMPUTAÇÃO ]
                                    ALUNO: PATRICK DUARTE PIMENTA | Ano: 2020
*/
#include <windows.h>
#include <iostream>
#include <locale>
#include "lista_ordenada_estatica.h"
#include "cliente.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista_Ordenada_Estatica loe_1;

    Cliente c1(1,"a");
    Cliente c2(2,"b");
    Cliente c3(3,"c");
    Cliente c4(4,"d");
    Cliente c5(5,"e");
    Cliente c6(6,"f");
    Cliente c7(7,"g");
    Cliente c8(8,"h");
    Cliente c9(9,"i");

    loe_1.insere_Clientes(c2);
    loe_1.imprime_Clientes();

    loe_1.insere_Clientes(c5);
    loe_1.imprime_Clientes();

    loe_1.insere_Clientes(c9);
    loe_1.imprime_Clientes();

    loe_1.insere_Clientes(c7);
    loe_1.imprime_Clientes();

    loe_1.insere_Clientes(c6);
    loe_1.imprime_Clientes();

    cout << endl << "XXXXXX \n\n";

    loe_1.busca_Clientes(2).imprime_Cliente();
    loe_1.busca_Clientes(9).imprime_Cliente();
    loe_1.busca_Clientes(5).imprime_Cliente();
    loe_1.busca_Clientes(1).imprime_Cliente();
    loe_1.busca_Clientes(8).imprime_Cliente();
    loe_1.busca_Clientes(4).imprime_Cliente();

    cout << endl << "XXXXXX \n\n";

    Lista_Ordenada_Estatica loe_2;

    loe_2.insere_Clientes(c1);
    loe_2.insere_Clientes(c3);
    loe_2.insere_Clientes(c8);
    loe_2.insere_Clientes(c4);

    loe_2.imprime_Clientes();

    cout << endl << "XXXXXX \n\n";

    loe_1.junta_Listas(loe_2);
    loe_1.imprime_Clientes();

    cout << endl << "XXXXXX \n\n";

    loe_2.imprime_Clientes();

    cout << endl;
    system("pause");
    return 0;
}
