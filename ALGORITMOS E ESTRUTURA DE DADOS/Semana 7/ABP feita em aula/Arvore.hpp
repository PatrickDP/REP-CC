#pragma once

#include "Nodo.hpp"

class ABP {
public:
    ABP() {
        raiz = NULL;
    }
    ~ABP() {
        if(raiz)
            apaga(raiz);
    }

    //pos fixada para não precisar de auxiliar
    void apaga(Nodo * nodePtr) {
        if(nodePtr->filhoEsq)
            apaga(nodePtr->filhoEsq);
        if(nodePtr->filhoDir)
            apaga(nodePtr->filhoDir);
        cout << "\n\t!" << nodePtr->aluno.nome;
        delete nodePtr;
    }

    void preOrdem() const {
        if(raiz)
            raiz->preOrdem();
        cout << endl;
    }

    void ordemSimetrica() const {
        if(raiz)
            raiz->ordemSimetrica();
        cout << endl;
    }

    void posOrdem() const {
        if(raiz)
            raiz->posOrdem();
        cout << endl;
    }

    void insere(const Aluno & aluno) {
        Nodo * novoNodoPtr = new Nodo(aluno);
        Nodo * ptrNodoAtual = raiz;

        if( ! raiz) {
            raiz = novoNodoPtr;
            return;
        }

        while(true) {
            if(ptrNodoAtual->aluno.chave < aluno.chave) {//direita do nodo atual
                if(ptrNodoAtual->filhoDir)//ainda nao chegamos na folha
                    ptrNodoAtual = ptrNodoAtual->filhoDir;
                else {//chegamos na folha
                    ptrNodoAtual->filhoDir = novoNodoPtr;
                    return;
                }
            } else {//esquerda do nodo atual
                if(ptrNodoAtual->filhoEsq)//ainda nao chegamos na folha
                    ptrNodoAtual = ptrNodoAtual->filhoEsq;
                else {//chegamos na folha
                    ptrNodoAtual->filhoEsq = novoNodoPtr;
                    return;
                }
            }
        }
    }


    Aluno busca(int chave) {
        Nodo * ptrNodoAtual = raiz;

        while(ptrNodoAtual) {
            if(ptrNodoAtual->aluno.chave == chave)
                return ptrNodoAtual->aluno;
            else if(ptrNodoAtual->aluno.chave < chave)
                ptrNodoAtual = ptrNodoAtual->filhoDir;
            else
                ptrNodoAtual = ptrNodoAtual->filhoEsq;
        }

        return Aluno();
    }



    Nodo * raiz;
};
