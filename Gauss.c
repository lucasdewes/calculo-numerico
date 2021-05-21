#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaração de variaveis
    int n = 0, i, j, k, l;

    //o usuario informa quantos equacoes vão ter o sistema
    printf("Informe quantas equacoes teram o sistema: ");
    scanf("%d", &n);

    //declaração de variaveis
    float termo, m;
    float matriz[n][n + 1], x[n];

    //aqui o usuario vai informar os valores dos coeficientes
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("\nInforme o(s) coeficiente(s) da linha %d: ", i + 1); // pede ao usuario digitar os coeficientes um a um
            scanf("%f", &matriz[i][j]);
        }
    }

    //printando a matriz informada na tela
    printf("\nMatriz informada:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%.0f", matriz[i][j]);
            if (j == n)
            {
                printf("\n");
            }
            else
            {
                printf("\t");
            }
        }
    }

    //implementando o método de gauss
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            //multiplicadores
            m = (-1 * matriz[i][k]) / matriz[k][k]; //faz a fra��o do termo a ser zerado para calcular nas linhas
            for (j = 0; j < n + 1; j++)
            {
                matriz[i][j] = (matriz[k][j] * m) + matriz[i][j]; //devolve o valor ja calculado a linha que foi zerado a(s) variavel(is)
            }
        }
    }

    //printa a matriz transformada na tela
    printf("\nMatriz transformada:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%.0f", matriz[i][j]);
            if (j == n)
            {
                printf("\n");
            }
            else
            {
                printf("\t");
            }
        }
    }
    //resolvendo o sistema
    for (i = 0; i < n; i++)
    {
        termo = 0;
        l = n - i;
        for (j = l; j < n; j++)
        {
            termo = termo + (x[j] * matriz[n - i - 1][j]); // faz a soma termo a termo
        }
        x[n - i - 1] = (matriz[n - 1 - i][n] - termo) / matriz[n - i - 1][n - i - 1]; //calcula o sistema e devolve o valor final da variavel
        printf("\nVariavel%d: %.2f\n", n - i, x[n - i - 1]);                          //printa na tela o valor final da variavei
    }
    return 0;
}