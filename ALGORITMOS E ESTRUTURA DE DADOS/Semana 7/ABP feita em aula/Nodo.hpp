#pragma once

#include "Aluno.hpp"

using namespace std;

class Nodo {
public:
    Nodo() {
        filhoEsq = NULL;
        filhoDir = NULL;
    }
    Nodo(const Aluno & novoAluno) {
        filhoEsq = NULL;
        filhoDir = NULL;
        aluno = novoAluno;
    }
    ~Nodo() { }

    void preOrdem() const {
        aluno.imprime();
        if(filhoEsq)
            filhoEsq->preOrdem();
        if(filhoDir)
            filhoDir->preOrdem();
    }

    void ordemSimetrica() const {
        if(filhoEsq)
            filhoEsq->ordemSimetrica();
        aluno.imprime();
        if(filhoDir)
            filhoDir->ordemSimetrica();
    }

    void posOrdem() const {
        if(filhoEsq)
            filhoEsq->posOrdem();
        if(filhoDir)
            filhoDir->posOrdem();
        aluno.imprime();
    }

    Nodo * filhoEsq;
    Nodo * filhoDir;
    Aluno aluno;
};
