#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temEquacoesEquivalentes(int ordem, float matriz[ordem][ordem]);
void printarMatriz(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

int main(int argc,char *argv[])
{
    printf("---RESOLUCAO DE SISTEMAS LINEARES---\n");

    //declara o ponteiro que vai apontar para o arquivo a ser lido
    //define o maximo de caracteres a ser digitado como caminho do arquivo
    char fname[100];
    FILE *arq;
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
        char coeficientes[300];

        // para ler a primeira linha linha
        int ordem;
        fscanf(arq,"%d",&ordem);
        if (isdigit(ordem)){
            printf("A primeira linha do arquivo tem que ser numerica");
            exit(1);
        }

        int ilinha  = ordem;     // quantas linhas tem
        int jcoluna = ordem + 1; // quantas colunas tem

        // matriz com o sistema completo (incluindo a coluna de resultados)
        float matriz[ilinha][jcoluna];

        for (int x = 0; x < ordem; x++)
        {
            for(int y = 0; y<ordem+1; y++)
            {
                fscanf(arq,"%f ",&matriz[ilinha][jcoluna]);
                printf("%f ", matriz[ilinha][jcoluna]);
            }
            printf("\n");
        }


        // lê linha por linha e guardar sistemas em um vetor
        // pegar o que tá nesse vetor sistemas e divide os coeficientes

        /*
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
        }*/

        float matriz_coef[ilinha][ilinha]; // matriz com os coeficientes da equação

        for (int linha = 0; linha < ordem; linha++)
        {
            for (int coluna = 0; coluna < ordem; coluna++)
            {
                matriz_coef[linha][coluna] = matriz[linha][coluna];
            }
        }

        if (temEquacoesEquivalentes(ilinha, matriz_coef))
        {
            printf()
        }
        */

    }
    fclose(arq);



 return 0;
}

int temEquacoesEquivalentes(int ordem, float matriz[ordem][ordem])
{
    float resultadoDaDivisao[ordem];
    float modelo;
    int linha1, linha2, coluna, elemento;
    int saoEquivalentes = 1; // sao equivalentes começa com true

    for (linha1 = 0; linha1 < ordem; linha1++)
    {
        for (linha2 = linha1 + 1; linha2 < ordem; linha2++)
        {
            for (coluna = 0; coluna < ordem; coluna++)
            {
                float num = matriz[linha1][coluna] / matriz[linha2][coluna];
                resultadoDaDivisao[coluna] = num;
            }

            for (elemento = 1; elemento < ordem; elemento++)
            {
                if (resultadoDaDivisao[0] != resultadoDaDivisao[elemento])
                {
                    saoEquivalentes = 0;
                }
            }

            if (saoEquivalentes) return saoEquivalentes;
        }

    }

    return saoEquivalentes;
}

void printarMatriz(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linha, coluna;
    for (linha = 0; linha < numLinhas; linha ++)
    {
        for (coluna = 0; coluna < numColunas; coluna++)
        {
            printf("[%.0f]", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
