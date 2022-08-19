#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Abre um arquivo TXT
    ifstream Openfile("helloWorld.txt");

    // Declarando um array do tipo char
    char ch;

    // Enquanto não chegar no fim do arquivo, faça...
    // eof() retorna um valor != 0 quando chega no final do arquivo
    while(!Openfile.eof()) {
        // Função get extrai o unico caractere do arquivo e o retorna.
        // Ela recebe ocmo parametro uma variavel do tipo char e insere nela
        Openfile.get(ch);
        cout << ch;
    }
    // Fecha o arquivo;
    Openfile.close();
    return 0;
}