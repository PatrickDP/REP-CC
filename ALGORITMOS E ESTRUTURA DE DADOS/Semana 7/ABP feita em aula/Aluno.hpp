#pragma once

using namespace std;

class Aluno {
public:
    Aluno(unsigned novaChave, const string & novoNome) {
        chave = novaChave;
        nome = novoNome;
    }
    Aluno() {
        chave =0;
        nome="dummy";
    }
    ~Aluno() { }

    void imprime() const {
        cout << "<" << chave << "," << nome << ">  ";
    }

    int chave;
    string nome;
};
