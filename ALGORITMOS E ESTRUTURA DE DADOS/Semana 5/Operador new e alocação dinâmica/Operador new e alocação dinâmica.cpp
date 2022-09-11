#include <iostream>

using namespace std;

class Aluno
{
public:
    string nome;
    Aluno()
    {
        nome = "dummy";
    }
};

int main()
{

    float* real = NULL;
    real = new float;
    *real = 3.14;

    int* inteiro = NULL;
    inteiro = new int;
    *inteiro = 3;

    Aluno* aluno = NULL;
    aluno = new Aluno();
    aluno->nome = "Patrick";

    cout << *real << endl;
    cout << *inteiro << endl;
    cout << aluno->nome << endl;
    return 0;
}
