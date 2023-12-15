#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/*6 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/

struct estrutura{
    char nome[30];
    char end[40];
    char cidade[20];
    char estado[3];
    char cep[10];
};
struct estrutura dados[4];

int funcMenu(int qtdDados){
    int auxMenu=0;
    printf("\n=MENU=============================");
    printf("\n1 - Inserir dados");
    printf("\n2 - Imprimir dados");
    printf("\n3 - Sair");
    do{
        printf("\n> ");
        scanf("%d", &auxMenu);
    }while(auxMenu!=1 && auxMenu!=2 && auxMenu!=3);
    printf("\n==================================");

    return auxMenu;
}
void funcEntrada(int qtdDados){
    int aux = qtdDados;
    struct estrutura *pDados;
    pDados = &dados[0];

    if(qtdDados!=4){
        printf("\nInsira o NOME: ");
        scanf("%s", pDados[aux].nome);
        printf("\nInsira o ENDERE�O: ");
        scanf("%s", pDados[aux].end);
        printf("\nInsira a CIDADE: ");
        scanf("%s", pDados[aux].cidade);
        printf("\nInsira o DIGITO ESTADUAL: ");
        scanf("%s", pDados[aux].estado);
        printf("\nInsira o CEP: ");
        scanf("%s", pDados[aux].cep);
    }else{
        printf("\nO elementos j� foram preenchidos.");
    }

}
void funcImprimir(int qtdDados){
    int aux = 0;
    struct estrutura *pDados;
    pDados = &dados[0];

    if(qtdDados>0){
        for(aux; aux<qtdDados; aux++){
            printf("\n=Elemento %d==================================================", aux+1);
            printf("\nNome: %s", pDados[aux].nome);
            printf("\nEndere�o: %s", pDados[aux].end);
            printf("\nCidade: %s", pDados[aux].cidade);
            printf("\nEstado: %s", pDados[aux].estado);
            printf("\nCEP: %s", pDados[aux].cep);
            printf("\n=============================================================");
        }
    }else{
        printf("\nOs elementos est�o vazios, favor insira os dados necessarios.");
    }
}
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
void main(){
    int qtdDados=0, auxMenu=0;
    setlocale(LC_ALL, "");

    do{
        printf("\n(%d/4) elementos preenchidos", qtdDados);
        auxMenu = funcMenu(qtdDados);

        switch(auxMenu){
        case 1:
            funcEntrada(qtdDados);
            qtdDados++;
            break;
        case 2:
            funcImprimir(qtdDados);
            break;
        default:
            break;
        }
    }while(auxMenu!=3);

    reiniciar();
}