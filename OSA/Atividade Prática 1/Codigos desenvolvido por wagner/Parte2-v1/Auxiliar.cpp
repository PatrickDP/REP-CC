#include "Auxiliar.h"
#include <string.h>
#include <iostream>
#include <iomanip>

void AbrirArquivo(fstream &arquivo, const string &nome_arquivo)
{
	arquivo.open(nome_arquivo, ios::in);
	if ( !arquivo.is_open() )
	{
		cerr<<"Erro ao abrir arquivo "<<nome_arquivo<<"! Fechando o programa...\n";
		exit(1);
	}
}

Registro* LerArquivo(fstream &arquivo)
{
	Registro* d = new Registro[NUM_REGS];
	char aux[TAM_NOME+1];
	int cont=0;
	while( !arquivo.eof() )
	{
		arquivo.getline( aux, TAM_NOME );
		if ( strlen(aux)>0 )
			d[cont++].SetNome(aux);
	}
	return d;
}

void GerarArquivo(Registro *dados, string nome_arquivo)
{
	fstream out(nome_arquivo, ios::out);
	for(int i=0; i<NUM_REGS; i++)
		out<<dados[i]<<'\n';
	out.close();
}

void ExibirDados(Registro *dados)
{
	cout<<"Dados Lidos...\n";
	for(int i=0; i<NUM_REGS; i++)
		cout<<setfill('0')<<setw(4)<<i+1<<"-"<<dados[i]<<"\n";
		//dados[i].Print();
		//cout<<endl;
	
}