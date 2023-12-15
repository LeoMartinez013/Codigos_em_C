#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int reiniciar(){
    int reinicio;
    do{
        printf("\nDeseja reiniciar o programa? \n 1 = Sim \n 2 = Nao \n > ");
        scanf("%d", &reinicio);
    }while(reinicio!=1 && reinicio!=2);

    switch(reinicio){
    case 1:
        return main();
        break;
    case 2:
        return 0;
        break;
    }
}
int funcRecebValor(){
    int valor;

    printf("\nMenor multiplo de ");
    scanf("%d", &valor);

    return valor;
}
int funcRecebLimite(int valor){
    int limite;

    printf("\nMenor multiplo de %d maior que ", valor);
    scanf("%d", &limite);

    return limite;
}
void funcCalculo(int valor, int limite){
    int resultado, aux=valor;

    for(aux; aux<=(limite+valor); aux+=valor){
        resultado = aux;
    }
    printf("\nMenor multiplo de %d maior que %d: %d", valor, limite, resultado);
}
void main(void){
    setlocale(LC_ALL, "");
    int valor, limite;

    valor = funcRecebValor();
    limite = funcRecebLimite(valor);
    funcCalculo(valor, limite);

    reiniciar();
    return 0;
}