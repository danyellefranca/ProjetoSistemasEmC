#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char linha;
        char incognitas[30];
        char coeficientes[300];
        char resultado[50];

        // para ler a primeira linha linha
        int ordem;
        fscanf(arq,"%d",&ordem);
        if (isdigit(ordem)){
            printf("A primeira linha do arquivo tem que ser numerica");
            exit(1);
        }

        // int quantasLinhas = ordem;

        int ilinha = ordem;
        int jcoluna = ordem + 1;

        // lê o conteudo da linha e coloca no vetor sistema

        char *sistema[ordem];

        int indiceIndice = 0;

        // eof ==> end of file
        /*
        while (linha =! eof())
        {
            fscanf(arq,"%d",&linha);
            sistema[indiceIndice++] = linha;
        }
        */

        float matriz[ilinha][jcoluna];

        for (int x=0; x < ordem; x++)
        {
            for(int y=0; y<ordem; y++)
            {
                fscanf(arq,"%f ",&matriz[ilinha][jcoluna]);
                printf("%f ", matriz[ilinha][jcoluna]);
            }
            printf("\n");
        }

        // lê linha por linha e guardar sistemas em um vetor
        // pegar o que tá nesse vetor sistemas e divide os coeficientes

        int indiceCoef = 0;

        for (int i = 0; i < ordem; i++)
        {
            char *token = strtok(sistema[i], " ");

             while (token != NULL) {
              coeficientes[indiceCoef++] = token;

              printf(" %s\n", token);

              token = strtok(NULL, " ");
           }
           indiceCoef = 0;

        }

    }
    fclose(arq);

 return 0;
}
