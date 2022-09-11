/*
Antes de realizar a PESQUISA BINÁRIA, é importante que o vetor esteja ORDENADO
*/

#include <iostream>

#define TAM_MAX 10

using namespace std;

int busca_Binaria(int vetor[], int elemento) 
{
    int limite_Inferior = 0;
    int limite_Superior = TAM_MAX - 1;
    int meio;
    while (limite_Inferior <= limite_Superior)
    {
        meio = (limite_Inferior + limite_Superior) / 2;
        cout << "meio: [" << meio << "] - " << vetor[meio] << endl;
        if (elemento == vetor[meio]) // ENCONTROU O ELEMENTO NA POSICAO DO MEIO
            return meio;
        if (elemento < vetor[meio]) // CASO O ELEMENTO VIER ANTES DO MEIO
        {
            limite_Superior = meio - 1;
            cout << "limite superior: [" << limite_Superior << "] - " << vetor[limite_Superior] << endl;
        }
        else // CASO O ELEMENT VIER DEPOIS DO MEIO
        {
            limite_Inferior = meio + 1;
            cout << "limite inferior: [" << limite_Inferior << "] - " << vetor[limite_Inferior] << endl;
        }
    }
    return -1; // NAO ENCONTROU O ELEMENTO
}

int main()
{
    int vetor[] = { 1,2,3,4,5,6,7,8,9,10 };
    int elemento;
    int resultado;
    /*
    for (int i = 0; i < TAM_MAX; i++)
    {
        cout << vetor[i] << " ";
    }
    */
    cin >> elemento;
    resultado = busca_Binaria(vetor, elemento);
    cout << "[" << resultado << "]: " << elemento << " - " ;
    if (resultado == -1)
    {
        cout << "ELEMENTO NAO ENCONTRADO";
    }
    else
        cout << "ELEMENTO ENCONTRADO!";

    cout << endl;
    system("pause");
    return 0;
}