#include <stdio.h>
#include <stdlib.h>

/*
// funcao que verifica se tem zeros na diagonal principal
int temZeroNaDiagonal(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linha;
    for (linha = 0; linha < numLinhas; linha++)
    {
        if (matriz[linha][linha] == 0)
            return 1; // retorna 1, indicando que EXISTE zero na diagonal principal
    }

    return 0; // retorna 0, indicando que NÃO existe zeros na diagonal principal
}
*/

// troca a coluna a pela coluna b na matriz de floats passada como parâmetro
void trocarColunas(int a, int b, int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// funcao para tirar os zeros da diagonal principal
void tirarZeros(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// retorna o determinante da matriz passada como parâmetro
float determinante(int ordem, float matriz[ordem][ordem]);

// determina o cofator do elemento matriz[linElem][colElem], colocando ele dentro de cofatores
void cofator(int ordem, float matriz[ordem][ordem], float cofator[ordem][ordem], int linElem, int colElem);

// POR ENQUANTO não tá retornando nada, mas vai retornar o valor das incognitas
void resultado(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// funcao que printa a matriz
void printarMatriz(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

int main()
{
    int linha, coluna;
    const int numLinhas = 4, numColunas = 4; // numero de linhas e de colunas
    float matriz[numLinhas][numColunas]; // matriz teste

    matriz[0][0] = 1.0;
    matriz[0][1] = 2.0;
    matriz[0][2] = 3.0;
    matriz[0][3] = -1.0;
    matriz[1][0] = -1.0;
    matriz[1][1] = 3.0;
    matriz[1][2] = 0.0;
    matriz[1][3] = 2.0;
    matriz[2][0] = 0.0;
    matriz[2][1] = 0.0;
    matriz[2][2] = 0.0;
    matriz[2][3] = 2.0;
    matriz[3][0] = 4.0;
    matriz[3][1] = 1.0;
    matriz[3][2] = -2.0;
    matriz[3][3] = 3.0;

    /*
    // preenchendo a matriz teste
    // primeira linha
    matriz[0][0] = 0.0;
    matriz[0][1] = 0.0;
    matriz[0][2] = 3.0;
    matriz[0][3] = 2.0;
    matriz[0][4] = 3.0;
    matriz[0][5] = 5.0;
    // segunda linha
    matriz[1][0] = 4.0;
    matriz[1][1] = 2.0;
    matriz[1][2] = 5.0;
    matriz[1][3] = 6.0;
    matriz[1][4] = 2.0;
    matriz[1][5] = 5.0;
    // terceira linha
    matriz[2][0] = 0.0;
    matriz[2][1] = 0.0;
    matriz[2][2] = 1.0;
    matriz[2][3] = 3.0;
    matriz[2][4] = 0.0;
    matriz[2][5] = 5.0;
    // quarta linha
    matriz[3][0] = 8.0;
    matriz[3][1] = 7.0;
    matriz[3][2] = 0.0;
    matriz[3][3] = 0.0;
    matriz[3][4] = 1.0;
    matriz[3][5] = 5.0;
    // quinta linha
    matriz[4][0] =  0.0;
    matriz[4][1] = 12.0;
    matriz[4][2] = 11.0;
    matriz[4][3] = 10.0;
    matriz[4][4] =  0.0;
    matriz[4][5] =  5.0;
    */
    printarMatriz(numLinhas, numColunas, matriz);

    float det = determinante(numLinhas, matriz);

    printf("\nDeterminante da matriz: %.0f", det);

    // printf("Calculadora de sistemas lineares determinados")
    /*
    if (resultado() != NULL)
    {

    }
    else
        printf("Não foi possível resolver esse sistema! Ele é impossível ou possível e indeterminado.");
    */


    return 0;
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

float determinante(int ordem, float matriz[ordem][ordem])
{
    int sinal, j;
    float det, cofatorTemp[ordem][ordem];
    // se a matriz for 1x1, o determinante é o único elemento da matriz
    if (ordem == 1)
        det = matriz[0][0];
    else
    {
        sinal = 1; // sinal positivo

        // percorrendo colunas
        for (j = 0; j < ordem; j++)
        {
            // vamos usar a linha 1 para achar o determinante pelo método de laplace
            // para isso, vamos pegar o cofator do elemento da matriz que está na
            // linha escolhida (0) e na coluna j
            cofator(ordem, matriz, cofatorTemp, 0, j);
            det += sinal * matriz[0][j] * determinante(ordem - 1, cofatorTemp);


            sinal = -sinal;
        }
    }

    return det;
}
void cofator(int ordem, float matriz[ordem][ordem], float cofatorTemp[ordem][ordem], int linElem, int colElem)
{
     int i = 0, j = 0, linha, coluna;

    // percorrendo toda a matriz
    for (linha = 0; linha < ordem; linha++)
    {
        for (coluna = 0; coluna < ordem; coluna++)
        {
            // passando para a matriz cofator todos os elementos
            // que NÃO estão na linha e na coluna do elemento
            // do qual estamos fazendo o cofator, ou seja,
            // todos os elementos que não estão na linha linElem
            // e na coluna colElem
            if (linha != linElem && coluna != colElem)
            {
                cofatorTemp[i][j] = matriz[linha][coluna];
                j++;

                // preenchemos uma linha, então aumentamos o
                // indice de linha e resetamos o indice de coluna
                if (j == ordem - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void tirarZeros(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linha, coluna;
    for (linha = 0; linha < numLinhas; linha++)
    {
        if (matriz[linha][linha] == 0)
        {
            for (coluna = 0; coluna < numColunas - 1; coluna++)
            {
                // vamos trocar a coluna do elemento da diagonal principal (que tem o mesmo indice
                // da linha atual) pela coluna do primeiro elemento diferente de zero, na mesma linha
                if (matriz[linha][coluna] != 0)
                    trocarColunas(linha, coluna, numLinhas, numColunas, matriz);
            }
        } // se não existir zeros na diagonal, não fazemos nada
    }
}

void trocarColunas(int a, int b, int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linha;
    float aux;
    for (linha = 0; linha < numLinhas; linha++) // percorremos cada linha das colunas
    {
        aux = matriz[linha][a]; // aux recebe o elemento da coluna A na linha atual
        matriz[linha][a] = matriz[linha][b]; // trocamos os elementos correspondentes das colunas A e B
        matriz[linha][b] = aux; // colocamos o elemento guardado em aux na posição correspondente em B
    }
}
