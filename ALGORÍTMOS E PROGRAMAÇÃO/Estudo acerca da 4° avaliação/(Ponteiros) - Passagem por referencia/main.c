#include <stdio.h>

void fun(int *ptr){

*ptr = 30;

}
int main(){
int y = 20;
fun(&y);
printf("%d",y); //saida = 30;
return 0;
}
