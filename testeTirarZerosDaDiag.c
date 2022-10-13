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
float determinante (int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// determina o cofator da matriz passada como parâmetro
void cofator();

// POR ENQUANTO não tá retornando nada, mas vai retornar o valor das incognitas
void resultado(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// funcao que printa a matriz
void printarMatriz(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

int main()
{
    int linha, coluna;
    const int numLinhas = 3, numColunas = 4; // numero de linhas e de colunas
    float matriz[numLinhas][numColunas];     // matriz teste

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
    printarMatriz(numLinhas, numColunas, matriz);

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

void resultado(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linhas, colunas;

    if (determinante(numLinhas, numColunas, matriz) != 0)
    {

    }
    else
        return NULL;
}

float determinante(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    float determinante;
    // se a matriz for 1x1, o determinante é o único elemento da matriz
    if (numLinhas == 1 && numColunas == 1)
        determinante = matriz[0][0];
    else
    // parei aqui que delicia que sabor que vontadezinha de morre me mata hmmm

}

void cofator(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{

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
