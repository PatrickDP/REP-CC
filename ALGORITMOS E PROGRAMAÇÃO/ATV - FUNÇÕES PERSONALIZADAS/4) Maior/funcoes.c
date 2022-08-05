int Edivisivel(int a, int b) /*Atividade: (1)(2)(3)*/
{
    if(a%b == 0)
    {
        return 1;
    }
    else
        return 0;
}

int Primo(int a) /*Atividade: (2)(3)*/
{
    int i,primo=0;
    if(a == 1 || a == 0)
    {
        return 0;
    }
    for(i=2; i<a; i++) /*Caso se a for 2, este for não vai rodar*/
    {
        if(Edivisivel(a,i) == 1) /*i passa a ser parametro de Edivisivel*/
        {
            primo++;
        }
    }
    if(primo == 0)
    {
        return 1; /*É primo*/
    }
    else
    {
        return 0; /*Não é primo*/
    }
}

void Nprimo(int a) /*Atividade: (3)*/
{
    int i;
    printf("Numeros primos de %d até N\n",a);
    for(i=2; i<=a; i++)
    {
        if(Primo(i) == 1)
        {
            printf("%d ",i);
        }
    }
}
/*.*/
int Maior(int a, int b) /*Atividade: (4)*/
{
    if(a > b)
    {
        return a;
    }
    else
        return b;
}
