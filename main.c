#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    printf("---RESOLUCAO DE SISTEMAS LINEARES---\n");

    //declara o ponteiro que vai apontar para o arquivo a ser lido
    //define o maximo de caracteres a ser digitado como caminho do arquivo
    char fname[100];
    FILE* arq;
    memset(fname, 0, 100);

    //pede pro usuário digitar o nome do arquivo
    printf("Digite o arquivo que deseja abrir: ");
    gets(fname);

    //abre o arquivo
    arq = fopen(fname, "r");

    //se o arquivo for nulo manda mensagem de erro
    if (arq == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        fclose(arq);
    }
    else
    {
        char sistema[200];
        char incognitas[30];
        char coeficientes[300];
        char resultado[50];
        // para ler uma linha
        int ordem;
        fscanf(arq,"%d",&ordem);

        int quantasLinhas = ordem;

        int i = quantasLinhas;
        int j = quantasLinhas + 1;

        char matriz[i][j];


        // agora ler linha por linha e guardar sistemas em um vetor
        // depois de ler uma linha (acho que while)
        // pegar o que tá nesse vetor sistemas e dividir em outros dois vetores:
        // coeficientes e incoignitas


            // quantasLinhas++ pra mudar de linha
            // fazer um for pra montar a matriz
    }

 return 0;
}
