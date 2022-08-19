#include "Registro.h"
#include "Auxiliar.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{	
	Registro *dados;
	fstream arq;
	string nome_arquivo("Arquivo_Nomes.txt");

	AbrirArquivo(arq, nome_arquivo);
	dados = LerArquivo(arq);
	ExibirDados(dados);
	GerarArquivo(dados, "saida.txt");

	arq.close();
	return 0;
}


