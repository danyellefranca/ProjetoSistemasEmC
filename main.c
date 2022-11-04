#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// indice auxiliar para o método permuta, guarda o indice da última posição do vetor de permutações
int indicePermutacoes = 0;

void troca(int vetor[], int i, int j);

// coloca dentro do vetor perms todas as combinações possíveis dos elementos dentro do vetor
void permuta(int qtasPerms, int qtosElementos, int vetor[], int inf, int sup, int perms[qtasPerms][qtosElementos]);

/*
void permuta (int qtasPermutacoes, int qtosElementos, int linha[qtosElementos], int perm[qtosElementos], perms[qtasPermutacoes][qtosElementos])
{
    int permutacao = 0;
    if (linha == [])
    {
        perms[i][0];
        i++;
    }
    else
    {
        for (int c = 0; c < qtosElementos; c++)
        {

        }
    }
}

// qtasPermutacoes vai ser o fatorial de qtosElementos
int[qtasPermutacoes][qtosElementos] permutacoes (int qtasPermutacoes, int qtosElementos, int linha[qtosElementos])
{
    int perms[][];
    permuta(linha, [], perms);
    return perms;
}


void getRange(int A[], int L,int R, int array[R-L]) {
   for (int i = L; i <= R; i++) {
      array[i-L] = A[i];
   }
}
void getRange(int A[], int L,int R, int array[R-L]) {
   for (int i = L; i <= R; i++) {
      array[i-L] = A[i];
   }
}
int main() {
   int A[] = { 1, 2, 3, 4, 5, 6 };
   int L = 1, R = 5;
   int newArray[R-L];
   getRange(A, L, R, newArray);
   for(int j = 0; j< R - L; j++)
   {
       printf("%d \n", newArray[j]);
   }
   return 0;
}
*/

// retorna o fatorial do numero passado por parametro
int fatorial (int numero);

// verifica se tem equações equivalentes na matriz
int temEquacoesEquivalentes(int ordem, float matriz[ordem][ordem]);

// troca a coluna a pela coluna b na matriz de floats passada como parâmetro
void trocarColunas(int a, int b, int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

// funcao para tirar os zeros da diagonal principal
void tirarZeros(int numLinhas, int numColunas, float matriz[numLinhas][numColunas]);

int main(int argc, char *argv[])
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
            printf("\nA primeira linha do arquivo tem que ser numerica\n");
            exit(1);
        }

        int ilinha  = ordem;     // quantas linhas tem
        int jcoluna = ordem + 1; // quantas colunas tem

        // matriz com o sistema completo (incluindo a coluna de resultados)
        float matriz[ilinha][jcoluna];

        for (int x = 0; x < ilinha; x++)
        {
            for(int y = 0; y < jcoluna; y++)
            {
                fscanf(arq, "%f ", &matriz[x][y]);
                printf("%f ", matriz[x][y]);
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

        if (temEquacoesEquivalentes(ilinha, matriz_coef)) // 5
        {
            printf("\nO sistema possui equações equivalentes!\n");
            printf("Não é possível resolver esse sitema.\n");
        }
        else
        {
            // 6
            tirarZeros(ilinha, jcoluna, matriz);

            // 7 e 8 - loop para o resultado
            float linhaAtual[jcoluna];
            float numeroQueQueroTornarZero, opostoDoNumeroQueQueroTornarZero;
            int itemDaDiagonal;

            // nesse for, vamos ver cada elemento que está na diagonal principal //
            // -  vamos tornar 1 os itens da diagonal                            //
            // -  tornar 0 todos os outros itens da matriz, exceto os resultados //
           for (int i = 0; i < ilinha; i++) // percorre a matriz, linha a linha
           {
               // tornando 1 os itens da diagonal principal //
               // pegamos o elemento cujo num. da linha é igual ao num. da coluna, ou seja,
               // pegamos o item da diagonal principal da matriz
               itemDaDiagonal = matriz[i][i];

               for (int j = 0; j < jcoluna; j++) // percorre a matriz, coluna a coluna
               {
                   // pegamos cada elemento da linha atual e dividimos pelo número da diagonal principal,
                   // para que no final o item da diagonal principal seja igual a 1
                   matriz[i][j] = (matriz[i][j] / itemDaDiagonal);
                   // guardamos isso no vetor linha atual, que vamos usar mais tarde para
                   // tornar os itens da coluna do item da diagonal principal igual a 0
                   linhaAtual[j] = matriz[i][j];
               } // depois que esse for acabar, o item da diagonal principal vai ser igual a 1

               // TEMOS QUE VERIFICAR SE NENHUM ITEM DA DIAGONAL PRINCIPAL FICOU IGUAL A 0
               // CADA VEZ QUE MEXERMOS NAS COLUNAS

               // tornando o resto dos elementos igual a 0 //
               for (int l = 0; l < ilinha; l++) // percorre a matriz, linha por linha
               {
                   if (l != i) // não vamos fazer isso com o elemento da diagonal principal, pois acabamos de tornar ele 1
                   {
                       // o número que quero tornar zero, é o número da coluna do número que acabei de tornar um, ou seja,
                       // da coluna i e da linha l
                       numeroQueQueroTornarZero = matriz[l][i];
                       if (numeroQueQueroTornarZero != 0) // se o número já é igual a 0, não tenho que fazer nada
                       {
                           opostoDoNumeroQueQueroTornarZero = -(numeroQueQueroTornarZero);
                           for (int c = 0; c < jcoluna; c++)
                           {
                              // if (c != l) {
                                    // multiplicamos a linha atual (linha do elemento que tornamos 1 copiada em um vetor) e
                                    // multiplicamos cada elemento dela pelo oposto do numero que queremos tornar 0
                                    // somamos o resultado pelo elemento correspondente na linha que queremos tornar o elemento igual a 0
                                    matriz[l][c] = matriz[l][c] + (linhaAtual[c] * opostoDoNumeroQueQueroTornarZero);
                             //  }

                           }
                       }
                   }

               }

           }

           // para cada incognita do sistema
           for (int i = 0; i < ilinha; i++)
           {
               printf("Incognita x%d = %f\n", i+1, matriz[i][jcoluna-1]);
           }

        }

    }
    fclose(arq);

 return 0;
}

void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int qtasPerms, int qtosElementos, int vetor[], int inf, int sup, int perms[qtasPerms][qtosElementos])
{
	if(inf == sup)
	{
        for (int c = 0; c < qtosElementos; c++)
            printf("%d ", vetor[c]);
        printf("\n");

        for (int c = 0; c < qtosElementos;c++)
        {
            perms[indicePermutacoes][c] = vetor[c];
        }
		// perms[indicePermutacoes][0] = vetor;
		indicePermutacoes++;
	}
	else
	{
		for(int i = inf; i < sup; i++)
		{
			troca(vetor, inf, i);
			permuta(qtasPerms, qtosElementos, vetor, inf + 1, sup, perms);
			troca(vetor, inf, i); // backtracking
		}
	}
}

int fatorial (int numero)
{
    int fatorial = 0;

    for (fatorial = 1; numero > 1; numero--)
    {
        fatorial = fatorial * numero;
    }

    return fatorial;
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

/*
void tirarZeros(int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int linha, coluna, temZero = 0;
    for (linha = 0; linha < numLinhas; linha++)
    {
        if (matriz[linha][linha] == 0) // se o elemento da diagonal na linha atual é igual a zero
        {
            for (coluna = 0; coluna < numColunas - 1; coluna++) // numColunas - 1 porque tem resultado
            {
                // vamos trocar a coluna do elemento da diagonal principal (que tem o mesmo indice
                // da linha atual) pela coluna do primeiro elemento diferente de zero, na mesma linha
                if (matriz[linha][coluna] != 0)
                    trocarColunas(linha, coluna, numLinhas, numColunas, matriz);

            }
        } // se não existir zeros na diagonal, não fazemos nada
    }
}
*/

void tirarZeros (int numLinhas, int numColunas, float matriz[numLinhas][numColunas])
{
    int indices[numColunas]; // formamos um vetor com os indices da matriz
    for (int i = 0; i < numColunas; i++)
    {
        indices[i] = i;
    }

    int qtasCombinacoes = fatorial(numColunas);
    int permutacoes[qtasCombinacoes][numColunas];

    permuta(qtasCombinacoes, numColunas, 0, numColunas, permutacoes);

    float matrizTeste[numLinhas][numColunas];
    for (int i = 0; i < numLinhas; i++)
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
