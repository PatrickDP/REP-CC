##############################################################################
# Makefile para a Parte 2 da 1a prática de OSA
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
#                       Arquivos auxiliares do projeto
##############################################################################
# Registro.cpp: depende de Registro.h (definição dos protótipos das funções 
#            auxiliares utilizadas no arquivo Registro.cpp)
# Auxiliar.cpp: depende de Auxiliar.h e Registro.h
##############################################################################

# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := $(MAIN).o Registro.o Auxiliar.o
# (para C, pode-se usar o padrão ISO 2011 (c11) ou 2018 (c18), dependendo do seu compilador...
# usar -std=c98 no lugar do c++11, c++17, c++20, etc.. 

FLAGS 	:= -Wall -Wextra -std=c++17 -pedantic-errors

# habilitar a depuração
DEBUG :=  -g

# necessário apenas quando se incluir  a biblioteca <math.h> em algum arquivo fonte no projeto
MATH 	:= -lm

# definição do compilador: para C usar o gcc, por exemplo
CC		:= g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
RM	:= del /q /f
else
OUTPUTMAIN := $(MAIN).out
RM	:= rm -f
endif

# ponto de compilação principal
all: main.exe
	@echo Compiling 'all' completed!

# gerando o arquivo executavel
main.exe: $(OBJECTS)  
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)
	
# gerando o arquivo objeto da função principal... adicionar as dependencias (se houverem)
main.o: $(MAIN).cpp Registro.h Auxiliar.h
	$(CC) $(FLAGS) -c $(MAIN).cpp
	
# gerando o arquivo objeto da minha biblioteca 1 (Registro.o)
Registro.o: Registro.cpp Registro.h
	$(CC) $(FLAGS) -c Registro.cpp

# gerando o arquivo objeto da minha biblioteca 2 (Auxiliar.o)
Auxiliar.o: Auxiliar.cpp Auxiliar.h Registro.h
	$(CC) $(FLAGS) -c Auxiliar.cpp

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OUTPUTMAIN)
	@echo Cleanup completed!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' completed!!!