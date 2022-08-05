#include <stdio.h>

int main()
{
    char *ptr = "GeeksQuiz";
    printf("%c\n", *ptr); //1° posicao = G;
    printf("%c\n", *(ptr+1)); //2° posicao = e

    printf("%c\n", *ptr+1); //ASCII = G(um numero hexa) + 1 -> H;
    return 0;
}
