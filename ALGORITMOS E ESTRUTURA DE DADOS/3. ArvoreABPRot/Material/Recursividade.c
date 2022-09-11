void preOrdem()
{
    aluno.imprime(); // 8
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 5
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 5
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 3
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 3
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 2
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 2
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 1
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 1
    if(ptrEsquerdo != NULL) // FALSO
        ptrEsquerdo->preOrdem(); // 1
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}

// DESEMPILHA 1, 2

void preOrdem()
{
    aluno.imprime(); // 8
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 5
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 5
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 3
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
void preOrdem()
{
    aluno.imprime(); // 3
    if(ptrEsquerdo != NULL) // OK
        ptrEsquerdo->preOrdem(); // 2
    if(ptrDireito != NULL)
        ptrDireito->preOrdem();
}
