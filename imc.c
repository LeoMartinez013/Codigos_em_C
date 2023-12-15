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
struct estrutura{
    char nome[30];
    float peso;
    float altura;
};

struct estrutura dados[4];

int funcMenu(){
    int auxMenu=0;

    printf("\n=MENU=============================");
    printf("\n1 - Receber todos os dados");
    printf("\n2 - Imprimir todos os dados");
    printf("\n3 - Calcular IMC de todas as pessoas");
    printf("\n4 - Sair");
    do{
        printf("\n> ");
        scanf("%d", &auxMenu);
    }while(auxMenu!=1 && auxMenu!=2 && auxMenu!=3);
    printf("\n==================================");

    return auxMenu;
}
void funcReceberDados(){
    int aux = 0;

    for(aux; aux<4; aux++){
        printf("\n=%do individuo==========================================", aux+1);
        printf("\nInsira o NOME: ");
        scanf("%s", &dados[aux].nome);
        printf("\nInsira o PESO: ");
        scanf("%f", &dados[aux].peso);
        printf("\nInsira a ALTURA com virgula (Exemplo: 1,80): ");
        scanf("%f", &dados[aux].altura);
        printf("\n=======================================================");
    }

}
void funcImprimirDados(int valid){
    int aux=0;

    if(valid==1){
        for(aux; aux<4; aux++){
            printf("\n=%do individuo==========================================", aux+1);
            printf("\nNome: %s", dados[aux].nome);
            printf("\nPeso: %.2f", dados[aux].peso);
            printf("\naltura: %.2f", dados[aux].altura);
            printf("\n=======================================================");
        }
    }else{
        printf("\nAinda nao possuo os dados necessarios.");
    }

}
void funcCalcular(int valid){
    int aux=0;
    float imc=0, auxPeso=0, auxAltura=0;

    if(valid==1){
        for(aux; aux<4; aux++){
            auxPeso = dados[aux].peso;
            auxAltura = dados[aux].altura;
            imc = auxPeso/(auxAltura*auxAltura);

            printf("\n=%do individuo==========================================", aux+1);
            printf("\nNome: %s", dados[aux].nome);
            printf("\nPeso: %.2f", auxPeso);
            printf("\naltura: %.2f", auxAltura);
            printf("\n[ IMC: %.2f ]", imc);
            printf("\n=======================================================");
        }
    }else{
        printf("\nAinda nao possuo os dados necessarios.");
    }
}
void main(){
    int auxMenu=0, valid=0;
    setlocale(LC_ALL, "");

    do{
        auxMenu = funcMenu();

        switch(auxMenu){
        case 1:
            //1 - receber todos os dados
            funcReceberDados();
            valid=1;
            break;
        case 2:
            //2 - imprime todos os dados
            funcImprimirDados(valid);
            break;
        case 3:
            //3 - calcula o IMC de todas as pessoas.
            funcCalcular(valid);
            break;
        default:
            //4 - sair
            break;
        }
    }while(auxMenu!=3);

    funcReiniciar();
}