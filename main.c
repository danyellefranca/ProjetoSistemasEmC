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
        # char sistema[200];
        char incognitas[30];
        char coeficientes[300];
        char resultado[50];

        // para ler a primeira linha linha
        int ordem;
        fscanf(arq,"%d",&ordem);

        int quantasLinhas = ordem;

        int i = quantasLinhas;
        int jcoluna = quantasLinhas + 1;

        char matriz[i][j];

        int qualLinha = 0; // contador

        // lê o conteudo da linha e coloca no vetor sistema

        char *sistema[ordem];

        int indiceIndice = 0;


        // eof ==> end of file
        while (!arq.eof())
        {
            fscanf(arq,"%d",&linha);
            sistema[indiceIndice++] = linha;

        }


        // lê linha por linha e guardar sistemas em um vetor
        // pegar o que tá nesse vetor sistemas e divide os coeficientes

        int indiceCoef = 0;

        for (i = 0; i < ordem; i++)
        {
            char *token = strtok(sistema[i], " ");

             while (token != NULL) {
              coeficientes[indiceCoef++] = token;

              printf(" %s\n", token);

              token = strtok(NULL, " ");
           }

           indiceCoef = 0;

        }


            // montar a matriz


            // PRINTAR MATRIZ:
            for ( i=0; i<ordem; i++ )
            {
                for ( k=0; k<jcoluna; k++ )
                {
                    printf ("%d", matriz[ i ][ j ]);
                }
            }
    }
    fclose(arq);

 return 0;
}
