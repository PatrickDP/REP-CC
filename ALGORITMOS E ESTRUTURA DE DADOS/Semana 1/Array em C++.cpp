#include <iostream>

using namespace std;

int main()
{
    string Alunos[] = {"Patrick" , "Peutrick" , "Petrix"}; // Outra declaração
    int i = 1;

    for (unsigned count = 0; count < 1; count++)
    {
        cout << Alunos[count] << endl;
    }
    while (i < 3)
    {
        cout << Alunos[i] << endl;
        i++;
    }
    return 0;
}

/*
string Alunos[2];
Alunos[0] = "Patrick";
Alunos[1] = "Peutrick";
*/
