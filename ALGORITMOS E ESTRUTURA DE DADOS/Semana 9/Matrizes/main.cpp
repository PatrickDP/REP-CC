#include <iostream>
#define TAM 10
using namespace std;

int main()
{
    int mat[TAM][TAM];
    int counter = 0;

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
            mat[i][j] = 0;
    }
    for(int i = 0; i < TAM; i++)
    {
        for(int j= 0; j < TAM; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
            if((j == (TAM - (counter + 1))) || (counter == i && counter == j))
                mat[i][j] = 1;
        counter++;
    }
    cout << endl;
    for(int i = 0; i < TAM; i++)
    {
        for(int j= 0; j < TAM; j++)
        {
            if(mat[i][j] == 0)
                cout << "  ";
            else
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
