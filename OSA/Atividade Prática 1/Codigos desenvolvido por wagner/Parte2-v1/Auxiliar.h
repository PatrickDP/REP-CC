#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "Registro.h"
#include <fstream>
#include <string>
using namespace std;

#define NUM_REGS 1000

void AbrirArquivo(fstream &arquivo, const string &nome_arquivo);
Registro* LerArquivo(fstream &arquivo);
void GerarArquivo(Registro *dados, string nome_arquivo);
void ExibirDados(Registro *dados);

#endif