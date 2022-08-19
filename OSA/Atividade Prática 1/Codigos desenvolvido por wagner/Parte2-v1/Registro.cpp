#include "Registro.h"
#include <string.h>

Registro::Registro(){
	strcpy(nome, "");
}
Registro::Registro(const char *n){
	strcpy(nome, n);
}
Registro::Registro(const Registro& reg){
	strcpy(nome, reg.nome);
}

void Registro::SetNome(const char *n){
	strcpy(nome, n);
}
const char* Registro::GetNome() const{
	return nome;
}

void Registro::Print() const{
	cout<<nome;
}

Registro& Registro::operator=(const Registro& reg){
	strcpy(nome, reg.nome);
	return *this;
}
bool Registro::operator==(const Registro& reg) const{
	return strcmp(nome, reg.nome) == 0;
}

ostream& operator<<(ostream& out, const Registro& reg)
{
	out<<reg.nome;
	return out;
}

istream& operator>>(istream& in, Registro& reg)
{
	in.getline(reg.nome, TAM_NOME);
	return in;
}