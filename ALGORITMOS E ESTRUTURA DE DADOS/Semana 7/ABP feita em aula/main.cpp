#include <iostream>

#include "Aluno.hpp"
#include "Nodo.hpp"
#include "Arvore.hpp"

using namespace std;

int main()
{
    Aluno a1(1,"a1");
    Aluno a2(2,"a2");
    Aluno a3(3,"a3");
    Aluno a4(4,"a4");
    Aluno a5(5,"a5");
    Aluno a6(6,"a6");
    Aluno a7(7,"a7");
    Aluno a8(8,"a8");
    Aluno a9(9,"a9");
    Aluno a10(10,"a10");
    Aluno a11(11,"a11");
    Aluno a12(12,"a12");

    ABP abp;
    /*
    abp.insere(a5);
    abp.insere(a9);
    abp.insere(a7);
    abp.insere(a11);
    abp.insere(a6);
    abp.insere(a10);
    abp.insere(a12);
    abp.insere(a1);
    abp.insere(a3);
    abp.insere(a2);

    abp.preOrdem();
    //abp.ordemSimetrica(); não mostra em aula
    abp.posOrdem();

    abp.busca(0).imprime();
    abp.busca(1).imprime();
    abp.busca(2).imprime();
    abp.busca(3).imprime();
    abp.busca(4).imprime();
    abp.busca(5).imprime();
    abp.busca(6).imprime();
    abp.busca(7).imprime();
    abp.busca(8).imprime();
    abp.busca(9).imprime();
    abp.busca(10).imprime();
    abp.busca(11).imprime();
    abp.busca(12).imprime();
    abp.busca(13).imprime();

    //abp.~ABP(); // ERRO
    */

    abp.insere(a8);
    abp.insere(a5);
    abp.insere(a3);
    abp.insere(a12);
    abp.insere(a9);
    abp.insere(a4);
    abp.insere(a11);
    abp.insere(a2);
    abp.insere(a6);
    abp.insere(a10);
    abp.insere(a1);
    abp.insere(a7);

    abp.preOrdem();
    return 0;
}
