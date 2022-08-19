// BIBLIOTECA DE ARQUIVOS
#include <fstream> 
#include <iostream>

using namespace std;

int main() {
    // Cria um arquivo txt através do handle "SaveFile". O nome é de sua escolha.
    ofstream SaveFile("helloWorld.txt");
    // Escreve algo no arquivo
    SaveFile << "Hello, world!!! Realmente sinto-me emocionado por está expressando este comunicado em arquivos...";
    // Fecha o arquivo
    SaveFile.close();

    return 0;
}