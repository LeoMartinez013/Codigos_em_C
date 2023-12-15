#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
//#include <string.h>

/*

1 a Pesquise as funcoes de biblioteca abaixo que manipulam arquivos.
 	fopen();
  	fclose();
	fwrite();    cuidado com esta funcao
	fread();    cuidado com esta fun��o
    exit(0);

2 - Escreva um programa que tem 3 vetores unidimensionais livro[20] e 3 vetores  unidimensionais autor[20] declarados como vari�veis globais.
Na fun��o main()  fa�a um menu com as seguintes op��es:
1 � Entrada de dados.
    O usu�rio insere os dados necess�rios pros 6 vetores
2 � Lista todos os dados na tela.
    Exibe todos os dados inseridos
3 � Pesquisa um livro com o nome completo e mostra na tela
    O usu�rio procura um livro inserindo seu nome completo
4 � Pesquisa autor pela 1. letra e mostra todos na tela.
    O usu�rio procura por livros do autor
5 � Altera dados. Pesquisa pelo livro completo.
    Alterar os dados de um livro
6 � Exclui dados. Pesquisa pelo livro completo.
    Exclui os dados de um livro
7 - Sa�da
    Sai do programa

 - Os 6 vetores devem ser escritos e lidos em um arquivo.
 - Cada uma das op��es do menu � uma fun��o no programa.
 - N�o pode usar nenhuma fun��o de biblioteca a n�o ser as 6 da apostila e as fun��es de manipula��o de arquivos pesquisadas.
*/

char livro1[20], livro2[20], livro3[20];
char autor1[30], autor2[30], autor3[30];

void funcBaixarDados(){
    FILE *arquivo;

    arquivo = fopen("arq_desafio.txt", "r");
    fread(&livro1, sizeof(livro1), 1, arquivo);
    fread(&autor1, sizeof(autor1), 1, arquivo);
    fread(&livro2, sizeof(livro2), 1, arquivo);
    fread(&autor2, sizeof(autor2), 1, arquivo);
    fread(&livro3, sizeof(livro3), 1, arquivo);
    fread(&autor3, sizeof(autor3), 1, arquivo);

    fclose(arquivo);
}
void funcEnviarDados(){
    FILE *arquivo;

    arquivo = fopen("arq_desafio.txt", "w");
    fwrite(livro1, sizeof(livro1), 1, arquivo);
    fwrite(autor1, sizeof(autor1), 1, arquivo);
    fwrite(livro2, sizeof(livro2), 1, arquivo);
    fwrite(autor2, sizeof(autor2), 1, arquivo);
    fwrite(livro3, sizeof(livro3), 1, arquivo);
    fwrite(autor3, sizeof(autor3), 1, arquivo);
    fclose(arquivo);
}
//   1 � Entrada de dados.
void funcEntradaDados(){
    setlocale(LC_ALL, "");
    int seq, atualizar=0;
    char debbug[10];

    do{
        seq=1;

        gets(debbug); //Criei esse gets() para corrigir um bug de entrada de dados do 1� livro.

        //  ENTRADA DE DADOS DOS LIVROS
        printf("\nA seguir, insira os 3 livros que ser�o arquivados.");
        printf("\n%d� livro: ", seq);
        gets(livro1);
        printf("\nAutor do livro |%s|: ", livro1);
        gets(autor1);
        seq++;
        printf("\n%d� livro: ", seq);
        gets(livro2);
        printf("\nAutor do livro |%s|: ", livro2);
        gets(autor2);
        seq++;
        printf("\n%d� livro: ", seq);
        gets(livro3);
        printf("\nAutor do livro |%s|: ", livro3);
        gets(autor3);

        //  Op��o de reescrever os dados.
        do{
            printf("\nOs dados est�o corretos? \n1 = Sim \n2 = N�o \n>");
            scanf("%d", &atualizar);
        }while(atualizar!=1 && atualizar!=2);

        if(atualizar==1){
            //  Abrindo arquivo para alterar
            funcEnviarDados();
            printf("\nArquivo atualizado.");
        }else{
        }
    }while(atualizar==2);
}
//   2 � Lista todos os dados na tela.
void funcListaDados(){
    funcBaixarDados();      //  Baixando dados do arquivo nos vetores.

    //  Exibi��o dos livros
    printf("\n=====LIVROS===========================================");
    if(livro1[0]!='*'){     //  Verificando se livro1 existe.
        printf("\n1� %s - de %s", livro1, autor1);
    }
    if(livro2[0]!='*'){     //  Verificando se livro2 existe.
        printf("\n2� %s - de %s", livro2, autor2);
    }
    if(livro3[0]!='*'){     //  Verificando se livro3 existe.
        printf("\n3� %s - de %s", livro3, autor3);
    }
    if(livro1[0]=='*' && livro2[0]=='*' && livro3[0]=='*'){
        printf("\nOps...parece que n�o temos livros ainda por aqui.");
    }
    printf("\n======================================================");
}
//   3 � Pesquisa um livro com o nome completo e mostra na tela
void funcPesqLivro(){
    char pesquisa[20]={"_"}, debbug[2];
    int seq=1, aux=0, valid=0;

    puts("\nInsira o nome do livro que voc� deseja: ");
    gets(debbug);
    gets(pesquisa);

    printf("\nProcurando %s...", pesquisa);

    funcBaixarDados();      //  Baixando dados do arquivo nos vetores.

    for(aux=0; pesquisa[aux]!='\0'; aux++){
        if(pesquisa[aux]==livro1[aux]){
            valid = 1;
        }else if(pesquisa[aux]==livro2[aux]){
            valid = 2;
        }else if(pesquisa[aux]==livro3[aux]){
            valid = 3;
        }else{
            valid = 0;
        }
    }

    switch(valid){
    case 1:
        printf("\nLivro encontrado: '%s' de %s.", livro1, autor1);
        break;
    case 2:
        printf("\nLivro encontrado: '%s' de %s.", livro2, autor2);
        break;
    case 3:
        printf("\nLivro encontrado: '%s' de %s.", livro3, autor3);
        break;
    default:
        printf("\n\nLivro n�o encontrado.");
        printf("\nMas temos os livros: ");
        printf("\n\t'%s' de %s.", livro1, autor1);
        printf("\n\t'%s' de %s.", livro2, autor2);
        printf("\n\t'%s' de %s.", livro3, autor3);
        break;
    }
}
//   4 � Pesquisa autor pela 1. letra e mostra todos na tela.
void funcPesqAutor(){
    char pesquisa, debbug[2];
    int aux=0, caso=0, auxPesq;
    int null_1=0, null_2=0, null_3=0;

    funcBaixarDados();

    printf("\nInsira a primeira letra do nome do autor: ");
    gets(debbug);
    scanf("%c", &pesquisa);

    // COMPARAR AUTORES
    /******************
    autor1 == autor2 = caso 1
    autor1 == autor3 = caso 2
    autor1 == autor2 == autor3 = caso 3
    autor != autor2 != autor3 = caso 0
    autor2 == autor3 = caso 4
    *******************/

    if(autor1[0]=='*'){
        null_1=1;
    }
    if(autor2[0]=='*'){
        null_2=1;
    }
    if(autor3[0]=='*'){
        null_3=1;
    }

    if(null_1==0){
        for(aux=0; autor1[aux]!='\0'; aux++){
            if(autor1[aux]==autor2[aux] && autor1[aux]!=autor3[aux]){
            // autor1 == autor2
                caso=1;
            }else if(autor1[aux]==autor3[aux] && autor1[aux]!=autor2[aux]){
            // autor1 == autor3
                caso=2;
            }else if(autor1[aux]==autor2[aux] && autor1[aux]==autor3[aux]){
            // autor1 == autor2 == autor3
                caso=3;
            }else{
                caso=0;
            }
        }
    }
    if(caso==0){
        for(aux=0; autor2[aux]!='\0'; aux++){
            if(autor2[aux]!=autor1[aux] && autor2[aux]==autor3[aux]){
            // autor2 == autor3
                caso=4;
            }else{
                caso=0;
            }
        }
    }
    printf("\n==============================================");
    if(pesquisa==autor1[0] && pesquisa!=autor2[0] && pesquisa!=autor3[0]){
        if(null_1==0){
            printf("\nLivros de %s:", autor1);
            printf("\n- %s.", livro1);
        }
    }else if(pesquisa!=autor1[0] && pesquisa==autor2[0] && pesquisa!=autor3[0]){
        if(null_2==0){
            printf("\nLivros de %s:", autor2);
            printf("\n- %s.", livro2);2;
        }
    }else if(pesquisa!=autor1[0] && pesquisa!=autor2[0] && pesquisa==autor3[0]){
        if(null_3==0){
            printf("\nLivros de %s:", autor3);
            printf("\n- %s.", livro3);
        }
    }else if(pesquisa==autor1[0] && pesquisa==autor2[0] && pesquisa!=autor3[0]){
        if(null_1==0){
            printf("\nLivros de %s:", autor1);
            printf("\n- %s.", livro1);
            if(caso==1){
                printf("\n- %s.", livro2);
            }else if(caso==0){
                printf("\nLivros de %s:", autor2);
                printf("\n- %s.", livro2);
            }else{
            }
        }

    }else if(pesquisa==autor1[0] && pesquisa!=autor2[0] && pesquisa==autor3[0]){
        if(null_1==0){
            printf("\nLivros de %s:", autor1);
            printf("\n- %s.", livro1);
            if(caso==2){
                printf("\n- %s.", livro3);
            }else if(caso==0){
                printf("\nLivros de %s:", autor3);
                printf("\n- %s.", livro3);
            }else{
            }
        }
    }else if(pesquisa!=autor1[0] && pesquisa==autor2[0] && pesquisa==autor3[0]){
        if(null_2){
            printf("\nLivros de %s:", autor2);
            printf("\n- %s.", livro2);
            if(caso==4){
                printf("\n- %s.", livro3);
            }else if(caso==0){
                printf("\nLivros de %s:", autor3);
                printf("\n- %s.", livro3);
            }else{
            }
        }
    }else if(pesquisa==autor1[0] && pesquisa==autor2[0] && pesquisa==autor3[0]){
        if(null_1==0){
            printf("\nLivros de %s:", autor1);
            printf("\n- %s.", livro1);
            if(caso==1){
                printf("\n- %s.", livro2);
                printf("\nLivros de %s:", autor3);
                printf("\n  %s.", livro3);
            }else if(caso==2){
                printf("\n- %s.", livro3);
                printf("\nLivros de %s:", autor2);
                printf("\n%s.", livro2);
            }else if(caso==3){
                printf("\n- %s.", livro2);
                printf("\n- %s.", livro3);
            }else if(caso==4){
                printf("\nLivros de %s:", autor2);
                printf("\n- %s.", livro2);
                printf("\n- %s.", livro3);
            }else if(caso==0){
                printf("\nLivros de %s:", autor2);
                printf("\n- %s.", livro2);
                printf("\nLivros de %s:", autor3);
                printf("\n- %s.", livro3);
            }else{
            }
        }
    }else{
        printf("\nN�o encontrei um autor com esta inicial.");
        printf("\nMas temos estes seguintes livros:");
        printf("\n==============================================");
        switch(caso){
        case 1:
        //  autor1 == autor2 = caso 1
            if(null_1==0){
                printf("\n%s:", autor1);
                printf("\n- %s.", livro1);
                printf("\n- %s.", livro2);
            }
            if(null_3==0){
                printf("\n%s:", autor3);
                printf("\n- %s.", livro3);
            }
            break;
        case 2:
        //  autor1 == autor3 = caso 2
            if(null_1==0){
                printf("\n%s:", autor1);
                printf("\n- %s.", livro1);
                printf("\n- %s.", livro3);
            }
            if(null_2==0){
                printf("\n%s:", autor2);
                printf("\n- %s.", livro2);
            }
            break;
        case 3:
        //  autor1 == autor2 == autor3 = caso 3
            if(null_1==0){
                printf("\n%s:", autor1);
                printf("\n- %s.", livro1);
                printf("\n- %s.", livro2);
                printf("\n- %s.", livro3);
            }
            break;
        case 4:
        //  autor2 == autor3 = caso 4
            if(null_1==0){
                printf("\n%s:", autor1);
                printf("\n- %s.", livro1);
            }
            if(null_2==0){
                printf("\n%s:", autor2);
                printf("\n- %s.", livro2);
                printf("\n- %s.", livro3);
            }
            break;
        default:
        //  autor != autor2 != autor3 = caso 0
            if(null_1==0){
                printf("\n%s:", autor1);
                printf("\n- %s.", livro1);
            }
            if(null_2==0){
                printf("\n%s:", autor2);
                printf("\n- %s.", livro2);
            }
            if(null_3==0){
                printf("\n%s:", autor3);
                printf("\n- %s.", livro3);
            }
            if(null_1==1 && null_2==1 & null_3==1){
                printf("\nOps... n�o temos livros armazenados.");
            }
            break;
        }
    }
    printf("\n==============================================");
}
//   5 � Altera dados. Pesquisa pelo livro completo.
void funcAlterar(){
    char pesquisa[20]={"_"}, debbug[2];
    char novoLivro[20], novoAutor[20];
    int aux=0, valid=0, confirm=0;

    funcBaixarDados();

    printf("\nQual livro voc� deseja ALTERAR? \n> ");
    gets(debbug);
    gets(pesquisa);

    //  PESQUISA PELO LIVRO
    for(aux=0; pesquisa[aux]!='\0'; aux++){
        if(pesquisa[aux]==livro1[aux]){
            valid = 1;
        }else if(pesquisa[aux]==livro2[aux]){
            valid = 2;
        }else if(pesquisa[aux]==livro3[aux]){
            valid = 3;
        }else{
            valid = 0;
        }
    }
    //  LIVRO N�O ENCONTRADO
    if(valid==0){
        printf("\nLivro n�o encontrado, temos os livros: ");
        printf("\n=====================================================");
        if(livro1[0]!='*'){     //  Verificando se livro1 existe.
            printf("\n1� %s - de %s", livro1, autor1);
        }else{
            printf("\n1� [Vazio]");
        }
        if(livro2[0]!='*'){     //  Verificando se livro2 existe.
            printf("\n2� %s - de %s", livro2, autor2);
        }
        else{
            printf("\n2� [Vazio]");
        }
        if(livro3[0]!='*'){     //  Verificando se livro3 existe.
            printf("\n3� %s - de %s", livro3, autor3);
        }
        else{
            printf("\n3� [Vazio]");
        }
        if(livro1[0]=='*' && livro2[0]=='*' && livro3[0]=='*'){
            printf("\nOps...parece que n�o temos livros ainda por aqui.");
        }
        printf("\n======================================================");
        do{
            printf("\nQual dos 3 voc� procura? \n> ");
            scanf("%d", &valid);
            gets(debbug);
        }while(valid!=1 && valid!=2 && valid!=3);
    }else{
    }

    switch(valid){
    case 1:
    //  ALTERANDO O LIVRO 1
        if(livro1[0]!='*'){
            printf("\nAlterando '%s' de %s.", livro1, autor1);
        }
        do{
            printf("\nInsira o novo nome do livro: ");
            gets(novoLivro);
            printf("\nInsira o novo nome do autor: ");
            gets(novoAutor);
            do{
                printf("\nO dados est�o corretos? ['%s' de %s]", novoLivro, novoAutor);
                printf("\nSim = 1 \nN�o = 2 \nN�o alterar = 3 \n>");
                scanf("%d", &confirm);
            }while(confirm!=1 && confirm!=2 && confirm!=3);
        }while(confirm==2);
        break;
    case 2:
    //  ALTERANDO O LIVRO 2
        if(livro2[0]!='*'){
            printf("\nAlterando '%s' de %s.", livro2, autor2);
        }
        do{
            printf("\nInsira o novo nome do livro: ");
            gets(novoLivro);
            printf("\nInsira o novo nome do autor: ");
            gets(novoAutor);
            do{
                printf("\nO dados est�o corretos? ['%s' de %s]", novoLivro, novoAutor);
                printf("\nSim = 1 \nN�o = 2 \nN�o alterar = 3 \n>");
                scanf("%d", &confirm);
            }while(confirm!=1 && confirm!=2 && confirm!=3);
        }while(confirm==2);
        break;
    case 3:
    //  ALTERANDO O LIVRO 3
        if(livro3[0]!='*'){
            printf("\nAlterando '%s' de %s.", livro3, autor3);
        }
        do{
            printf("\nInsira o novo nome do livro: ");
            gets(novoLivro);
            printf("\nInsira o novo nome do autor: ");
            gets(novoAutor);
            do{
                printf("\nO dados est�o corretos? ['%s' de %s]", novoLivro, novoAutor);
                printf("\nSim = 1 \nN�o = 2 \nN�o alterar = 3 \n>");
                scanf("%d", &confirm);
            }while(confirm!=1 && confirm!=2 && confirm!=3);
        }while(confirm==2);
        break;
    default:
        break;
    }
    if(valid==1 && confirm==1){
        for(aux=0; livro1[aux]!='\0'; aux++){
            livro1[aux]=' ';
        }
        for(aux=0; novoLivro[aux]!='\0'; aux++){
            livro1[aux] = novoLivro[aux];
        }
        for(aux=0; autor1[aux]!='\0'; aux++){
            autor1[aux]=' ';
        }
        for(aux=0; novoAutor[aux]!='\0'; aux++){
            autor1[aux] = novoAutor[aux];
        }
    }else if(valid==2 && confirm==1){
        for(aux=0; livro2[aux]!='\0'; aux++){
            livro2[aux]=' ';
        }
        for(aux=0; novoLivro[aux]!='\0'; aux++){
            livro2[aux] = novoLivro[aux];
        }
        for(aux=0; autor2[aux]!='\0'; aux++){
            autor2[aux]=' ';
        }
        for(aux=0; novoAutor[aux]!='\0'; aux++){
            autor2[aux] = novoAutor[aux];
        }
    }else if(valid==3 && confirm==1){
        for(aux=0; livro3[aux]!='\0'; aux++){
            livro3[aux]=' ';
        }
        for(aux=0; novoLivro[aux]!='\0'; aux++){
            livro3[aux] = novoLivro[aux];
        }
        for(aux=0; autor3[aux]!='\0'; aux++){
            autor3[aux]=' ';
        }
        for(aux=0; novoAutor[aux]!='\0'; aux++){
            autor3[aux] = novoAutor[aux];
        }
    }else{
        printf("\nNenhum livro foi alterado.");
    }
    funcEnviarDados();
}
//   6 � Exclui dados. Pesquisa pelo livro completo.
void funcExcluir(){
    char pesquisa[20]={"_"}, debbug[2];
    int aux=0, valid=0, confirm;

    funcBaixarDados();

    printf("\nQual livro voc� deseja EXCLUIR? \n> ");
    gets(debbug);
    gets(pesquisa);
    for(aux=0; pesquisa[aux]!='\0'; aux++){
        if(pesquisa[aux]==livro1[aux]){
            valid = 1;
        }else if(pesquisa[aux]==livro2[aux]){
            valid = 2;
        }else if(pesquisa[aux]==livro3[aux]){
            valid = 3;
        }else{
            valid = 0;
        }
    }

    if(valid==0){
        printf("\nLivro n�o encontrado, temos os livros: ");
        printf("\n (1) '%s' de %s.", livro1, autor1);
        printf("\n (2) '%s' de %s.", livro1, autor1);
        printf("\n (3) '%s' de %s.", livro1, autor1);
        do{
            printf("\nQual dos 3 voc� procura? \n> ");
            scanf("%d", &valid);
        }while(valid!=1 && valid!=2 && valid!=3);
    }

    switch(valid){
    case 1:
        do{
            printf("\n Deseja excluir '%s' de %s? \nSim = 1 \nN�o = 2 \n> ", livro1, autor1);
            scanf("%d", &confirm);
        }while(confirm!=1 && confirm!=2);
        break;
    case 2:
        do{
            printf("\n Deseja excluir '%s' de %s? \nSim = 1 \nN�o = 2 \n> ", livro2, autor2);
            scanf("%d", &confirm);
        }while(confirm!=1 && confirm!=2);
        break;
    case 3:
        do{
            printf("\n Deseja excluir '%s' de %s? \nSim = 1 \nN�o = 2 \n> ", livro3, autor3);
            scanf("%d", &confirm);
        }while(confirm!=1 && confirm!=2);
        break;
    default:
        break;
    }
    if(valid==1 && confirm==1){
        livro1[0] = '*';
        autor1[0] = '*';
        printf("\n%s excluido.", livro1);
    }else if(valid==2 && confirm==1){
        livro2[0] = '*';
        autor2[0] = '*';
        printf("\n%s excluido.", livro2);
    }else if(valid==3 && confirm==1){
        livro3[0] = '*';
        autor3[0] = '*';
        printf("\n%s excluido.", livro3);
    }else{
        printf("\nNenhum livro foi excluido");
    }

    funcEnviarDados();
}
//   7 - Sa�da
void funcSaida(){
    exit(1);
}
void main(){
    setlocale(LC_ALL, "");
    int opcao=0;


    // VERIFICA��O DO ARQUIVO
    FILE *arquivo;
    arquivo = fopen("arq_desafio.txt", "rt");
    if(arquivo==NULL){
        printf("\nErro na abertura do arquivo!");
        printf("\nArquivo n�o encontrado.");
    }else{
        fclose(arquivo);
        printf("Ol�, este programa busca arquivas 3 livros e seus autores. :)");
    }

    //  MENU
    do{
        printf("\nEscolha uma das op��es abaixo do menu: ");
        printf("\n\t=================================================================");
        printf("\n\t= 1 � Entrada de dados.                                         =");
        printf("\n\t= 2 � Lista todos os dados na tela.                             =");
        printf("\n\t= 3 � Pesquisa um livro com o nome completo e mostra na tela    =");
        printf("\n\t= 4 � Pesquisa autor pela 1. letra e mostra todos na tela.      =");
        printf("\n\t= 5 � Altera dados. Pesquisa pelo livro completo.               =");
        printf("\n\t= 6 � Exclui dados. Pesquisa pelo livro completo.               =");
        printf("\n\t= 7 - Sa�da                                                     =");
        printf("\n\t=================================================================");

        //  VERIFICAR ESCOLHA
        do{
            printf("\nSua escolha: ");
            scanf("%d", &opcao);
            if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5 && opcao!=6 && opcao!=7){
                printf("\nEscolha uma das op��es acima!");
            }else{
            }
        }while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5 && opcao!=6 && opcao!=7);

        printf("\n_____________________________________________________________________________");
        switch(opcao){
        case 1:
            funcEntradaDados();
            break;
        case 2:
            funcListaDados();
            break;
        case 3:
            funcPesqLivro();
            break;
        case 4:
            funcPesqAutor();
            break;
        case 5:
            funcAlterar();
            break;
        case 6:
            funcExcluir();
            break;
        case 7:
            funcSaida();
            break;
        default:
            printf("\nErro!");
            break;
        }
        printf("\n_____________________________________________________________________________");
        printf("\n\nRetornando ao menu...\n");

    }while(opcao!=7);
}
