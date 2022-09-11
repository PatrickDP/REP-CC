#include <stdio.h>

int main()
{
    int c,b,t; /*c = consumo, b = bandeira, t = tipo.)*/
    float conta,iluminacao,impostos,total;
    scanf("%d%d%d",&c,&b,&t);
    switch(t)
    {
    case 1:
        switch(b)
        {
        case 1:
            if(c >= 30)
            {
                conta = 0.19712 * c;
            }
            if(c >= 31 && c <= 100)
            {
                conta = (((c - 31) * 0.33793) + (31 * 0.19712)) - 0.03;
            }
            if(c >= 101 && c <= 220)
            {
                conta = 0.50689 * c;
            }
            if(c > 220)
            {
                conta = 0.56321 * c;
            }
            iluminacao = 0.34559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 2:
            if(c >= 30)
            {
                conta = 0.20237 * c;
            }
            if(c >= 31 && c <= 100)
            {
                conta = 0.34693 * c;
            }
            if(c >= 101 && c <= 220)
            {
                conta = 0.52039 * c;
            }
            if(c > 220)
            {
                /*conta = 0.57821 * c;*/
                conta = (c * 0.57821);
            }
            iluminacao = 0.36059 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 3:
            if(c >= 30)
            {
                conta = 0.21112 * c;
            }
            if(c >= 31 && c <= 100)
            {
                conta = 0.36193 * c;
            }
            if(c >= 101 && c <= 220)
            {
                conta = (((c - 31) * 0.36193) + (31 * 0.36193)) - 0.18;
            }
            if(c > 220)
            {
                /*conta = 0.60321 * c;*/
                conta =
            }
            iluminacao = 0.38559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 4:
            if(c >= 30)
            {
                conta = 0.21812 * c;
            }
            if(c >= 31 && c <= 100)
            {
                conta = 0.37393 * c;
            }
            if(c >= 101 && c <= 220)
            {
                conta = 0.56089 * c;
            }
            if(c > 220)
            {
                conta = 0.40559 * c;
            }
            iluminacao = 0.34559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        }
        break;
    case 2:
        switch(b)
        {
        case 1:
            conta = 0.62833 * c;
            iluminacao = 0.34559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 2:
            conta = 0.64333 * c;
            iluminacao = 0.36059 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 3:
            conta = 0.66833 * c;
            iluminacao = 0.38559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        case 4:
            conta = 0.68833 * c;
            iluminacao = 0.40559 * c;
            impostos = 0.37 * (conta + iluminacao);
            total = conta + iluminacao + impostos;
            printf("Valor da conta: %.2f\n",conta);
            printf("Iluminacao: %.2f\n",iluminacao);
            printf("Valor dos impostos: %.2f\n",impostos);
            printf("Valor total da conta: %.2f\n",total);
            break;
        }
        break;
    }
    return 0;
}
