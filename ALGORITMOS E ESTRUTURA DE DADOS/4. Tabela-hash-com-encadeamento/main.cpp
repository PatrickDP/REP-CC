  
/*
[ INSTITUTO FEDERAL DO NORTE DE MINAS GERAIS / CAMPUS MONTES CLAROS - TURMA 2019 DE CIÊNCIA DA COMPUTAÇÃO ]
                                    ALUNO: PATRICK DUARTE PIMENTA | Ano: 2020
*/
#include <iostream>
#include "hash.hpp"

using namespace std;

int main()
{
                           // MÓDULO:
    Cliente a1(1,"a1");    // 1
    Cliente a2(20,"a2");   // 0
    Cliente a3(17,"a3");   // 2
    Cliente a4(13,"a4");   // 3
    Cliente a5(10,"a5");   // 0
    Cliente a6(18,"a6");   // 3
    Cliente a7(7,"a7");    // 2
    Cliente a8(9,"a8");    // 4
    Cliente a9(16,"a9");   // 1
    Cliente a10(2,"a10");  // 2
    Cliente a11(5,"a11");  // 0
    Cliente a12(11,"a12"); // 1
    Cliente a13(3,"a13");  // 3

    Hash tabHash;

    unsigned leitura = 0; // Armazena
    unsigned escrita = 0; // Exibe

    tabHash.insereHash(a1,leitura);
    tabHash.insereHash(a2,leitura);
    tabHash.insereHash(a3,leitura);
    tabHash.insereHash(a4,leitura);
    tabHash.insereHash(a5,leitura);  // Colisão com a2
    tabHash.insereHash(a6,leitura);  // Colisão com a4
    tabHash.insereHash(a7,leitura);  // Colisão com a3
    tabHash.insereHash(a8,leitura);
    tabHash.insereHash(a9,leitura);  // Colisão com a1
    tabHash.insereHash(a10,leitura); // Colisão com a3
    tabHash.insereHash(a11,leitura); // Colisão com a2
    tabHash.insereHash(a12,leitura); // Colisão com a11
    tabHash.insereHash(a13,leitura); // Colisão com a4

    tabHash.imprimeHash(escrita);

    cout << "Quanta(s) vezes leu: " << leitura << endl;
    cout << "Quanta(s) vezes escreveu: " << escrita << endl;

    escrita = 0;
    leitura = 0;

    tabHash.buscaHash(1,leitura,escrita);
    tabHash.buscaHash(20,leitura,escrita);
    tabHash.buscaHash(17,leitura,escrita);
    tabHash.buscaHash(13,leitura,escrita);
    tabHash.buscaHash(10,leitura,escrita);
    tabHash.buscaHash(18,leitura,escrita);
    tabHash.buscaHash(7,leitura,escrita);
    tabHash.buscaHash(9,leitura,escrita);
    tabHash.buscaHash(16,leitura,escrita);
    tabHash.buscaHash(2,leitura,escrita);
    tabHash.buscaHash(5,leitura,escrita);
    tabHash.buscaHash(11,leitura,escrita);
    tabHash.buscaHash(3,leitura,escrita);

    tabHash.buscaHash(404,leitura,escrita); // mod: 4 (ia colidir com 9)

    cout << endl << "Quanta(s) vezes escreveu: " << escrita << endl;

    return 0;
}
