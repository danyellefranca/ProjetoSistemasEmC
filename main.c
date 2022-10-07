#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    printf("---RESOLUCAO DE SISTEMAS LINEARES---\n");

    //declara o ponteiro que vai apontar para o arquivo a ser lido
    //define o maximo de caracteres a ser digitado como caminho do arquivo
    char fname[100];
    FILE* fp;
    memset(fname, 0, 100);

    //pede pro usuário digitar o nome do arquivo
    printf("Digite o arquivo que deseja abrir: ");
    gets(fname);

    //abre o arquivo
    fp = fopen(fname, "r");

    //declaramos variaveis que vamos precisar
    int quantLinhas = 0;
    char sistema[80];
    char incognitas[50];
    char numeros[50];
    char resultado[50];
    char matriz;

    //se o arquivo for nulo manda mensagem de erro
    if (fp == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        fclose(fp);
    }
    else
    {

    }


 return 0;
}
