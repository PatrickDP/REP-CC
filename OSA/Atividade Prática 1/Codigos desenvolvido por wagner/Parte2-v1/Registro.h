#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
using namespace std;

#define TAM_NOME    100
class Registro
{
private:
    char nome[TAM_NOME+1];
public:
    Registro();
    Registro(const char *n);
    Registro(const Registro&);

    void SetNome(const char *n);
    const char* GetNome() const;

    void Print() const;
    
    Registro& operator=(const Registro&);
    bool operator==(const Registro&) const;

    friend ostream& operator<<(ostream&, const Registro&);
    friend istream& operator>>(istream&, Registro&);
};

#endif