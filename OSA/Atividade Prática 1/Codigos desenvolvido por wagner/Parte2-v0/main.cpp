// implementação rápida, baixissima modularização
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

#define TAM_NOME	50
#define NUM_REGS	1000

int main()
{
	// abrir o arquivo de entrada
	fstream arquivo("Arquivo_Nomes.txt", ios::in);
	if ( !arquivo.is_open() )
	{
		cout<<"\nERRO AO ABRIR ARQUIVO!!! Fechando o programa...\n";
		exit(1);
	}


	// variaveis auxiliares e de armazenamento
	char linha[TAM_NOME+1];
	char dados[NUM_REGS][TAM_NOME+1];
	int cont=0;
	// leitura do arquivo
	while( !arquivo.eof() )
	{
		arquivo.getline(linha, TAM_NOME);
		if ( strlen(linha)>0 )
			strcpy( dados[cont++], linha );
	}
	arquivo.close();

	/// exibir os dados lidos...
	for(int i=0; i<NUM_REGS; i++)
		cout<<setw(4)<<setfill('0')<<i+1<<"-"<<dados[i]<<"\n";
	

	fstream saida("saida.txt", ios::out);
	for(int i=0; i<NUM_REGS; i++)
		saida<<dados[i]<<"\n";
	
	saida.close();
	
	return 0;
}