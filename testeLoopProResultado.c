#include <stdio.h>

int main()
{
    const int numLinhas =  3;
    const int numColunas = 4;
    float linhaAtual[numColunas];
    float matriz[numLinhas][numColunas];
    float numeroQueQueroTornarZero, opostoDoNumeroQueQueroTornarZero;
    int i, l, j, c; // i ou l = linha; j ou c = coluna
    int itemDaDiagonal; // vai guardar o item da diagonal principal

    // sistema maligno
    // primeira linha
    matriz[0][0] = 4;
    matriz[0][1] = 0;
    matriz[0][2] = 2;
    matriz[0][3] = 24;
    // segunda linha
    matriz[1][0] = 2;
    matriz[1][1] = 3;
    matriz[1][2] = 0;
    matriz[1][3] = 16;
    // terceira linha
    matriz[2][0] = 0;
    matriz[2][1] = 3;
    matriz[2][2] = 2;
    matriz[2][3] = 28;
    /*
    sistema malignon
        4a 0b 2c = 24
        2a 3b 0c = 16
        0a 3b 2c = 28

    sistema para teste
        a +  b +  c = 1
       6a -  b - 4c = 1
      -4a + 6b -  c = 0

    */
    /*
    // sistema teste
    // primeira linha
    matriz[0][0] = 2;
    matriz[0][1] = 2;
    matriz[0][2] = 2;
    matriz[0][3] = 2;
    // segunda linha
    matriz[1][0] =  6;
    matriz[1][1] = -1;
    matriz[1][2] = -4;
    matriz[1][3] =  1;
    // terceira linha
    matriz[2][0] = -4;
    matriz[2][1] =  6;
    matriz[2][2] = -1;
    matriz[2][3] =  0;
    */


   // nesse for, vamos ver cada elemento que está na diagonal principal //
   // -  vamos tornar 1 os itens da diagonal                            //
   // -  tornar 0 todos os outros itens da matriz, exceto os resultados //
   for (i = 0; i < numLinhas; i++) // percorre a matriz, linha a linha
   {
       // tornando 1 os itens da diagonal principal //
       // pegamos o elemento cujo num. da linha é igual ao num. da coluna, ou seja,
       // pegamos o item da diagonal principal da matriz
       itemDaDiagonal = matriz[i][i];

       for (j = 0; j < numColunas; j++) // percorre a matriz, coluna a coluna
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
       for (l = 0; l < numLinhas; l++) // percorre a matriz, linha por linha
       {
           if (l != i) // não vamos fazer isso com o elemento da diagonal principal, pois acabamos de tornar ele 1
           {
               // o número que quero tornar zero, é o número da coluna do número que acabei de tornar um, ou seja,
               // da coluna i e da linha l
               numeroQueQueroTornarZero = matriz[l][i];
               if (numeroQueQueroTornarZero != 0) // se o número já é igual a 0, não tenho que fazer nada
               {
                   opostoDoNumeroQueQueroTornarZero = -(numeroQueQueroTornarZero);
                   for (c = 0; c < numColunas; c++)
                   {
                       // multiplicamos a linha atual (linha do elemento que tornamos 1 copiada em um vetor) e
                       // multiplicamos cada elemento dela pelo oposto do numero que queremos tornar 0
                       // somamos o resultado pelo elemento correspondente na linha que queremos tornar o elemento igual a 0
                       matriz[l][c] = matriz[l][c] + (linhaAtual[c] * opostoDoNumeroQueQueroTornarZero);
                   }
               }
           }

       }

   }


   // isso aqui é pra printar a matriz
   for (i = 0; i < numLinhas; i++)
   {
       for (j = 0; j < numColunas; j++)
       {
           printf("Matriz[%d][%d] = %.0f\n", (i + 1), (j + 1), matriz[i][j]);
       }
   }

   return 0;
}
