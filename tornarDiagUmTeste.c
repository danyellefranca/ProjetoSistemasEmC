#include <stdio.h>


int main()
{
    int matriz[3][4];
   
    /*
        sistema
        a +  b +  c = 1
       6a -  b - 4c = 1
      -4a + 6b -  c = 0
   
    */
   
    const int numLinhas =  3;
    const int numColunas = 4;
   
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
   
   
   // tornando a diagonal principal igual a 1 // 
   int linhaAtual[numColunas]; // linha atual vai guardar a linha do elemento que acabamos de tornar igual a 1
   for (int i = 0; i < numLinhas; i++)
   {
       int itemDaDiagonal = matriz[i][i];
       for (int j = 0; j < numColunas; j++)
       {
           linhaAtual[j] = (matriz[i][j] / itemDaDiagonal);
       }
   }
   
   
   
    return 0;
}
