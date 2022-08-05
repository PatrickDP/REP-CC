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

int Soma(int a, int b) /*Atividade: (5)*/
{
    int adicao=0;
    adicao = a + b;
    return adicao;
}
/*.*/
void Troca(int *a, int *b) /*Atividade: (6)*/ /*Argumentos como ponteiros*/
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("Troca: a = \"%d\" & b = \"%d\"",*a,*b);
}
/*.*/
int encontrarMaxElem(int arr1[], int n) /*Atividade: (7)*/
{
    int i,recebe=0;
    for(i=0; i<n; i++)
    {
        if(arr1[i] > recebe)
        {
            recebe = arr1[i];
        }
    }
    return recebe;
}
