# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := main.o NetflixTitles.o Buffer.o Auxiliar.o
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
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
main.exe: $(OBJECTS)  
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)

# gerando o arquivo objeto da função principal... adicionar as dependencias (se houverem)
main.o: $(MAIN).cpp library.hpp
	$(CC) $(FLAGS) -c $(MAIN).cpp

NetflixTitles.o: NetflixTitles.cpp NetflixTitles.hpp
	$(CC) $(FLAGS) -c NetflixTitles.cpp
	
Buffer.o: Buffer.cpp Buffer.hpp
	$(CC) $(FLAGS) -c Buffer.cpp

Auxiliar.o: Auxiliar.cpp Auxiliar.hpp
	$(CC) $(FLAGS) -c Auxiliar.cpp

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OUTPUTMAIN)
	$(RM) *.dat

	@echo Cleanup complete.

run: all
	./$(OUTPUTMAIN)

	@echo Executing 'all' complete.