#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0, it = 0, it_max = 50;
    double soma = 0, precisao = 0, precisao_atual = 1;
    printf("Insira o numero de equacoes: "); // pede para o usuario inserir o numero de equacoes, cada equacao equivale a uma variavel
    scanf("%d", &n);
    double matriz[n][n], chute[n], cont[n], cont1[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("mat[%d][%d]: ", i + 1, j + 1); //aqui o usuario preenche a matriz com os coeficientes
            scanf("%f", &matriz[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("Insira o resultado de cada equacao: ", i + 1); // insere o resultado de cada equação, ou seja o valor depois da igualdade
        scanf("%lf", &cont[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Insira o chute inicial para a equacao %d: ", i + 1); //o usuario insere um chute para cada variavel
        scanf("%lf", &chute[i]);
    }
    printf("Insira o nivel de precisao que deseja: "); //o usuario decide o quão precisa deve ser as respostas
    scanf("%d", &precisao);
    while ((precisao_atual > precisao) || (it <= it_max)) //loop até a precisao desejada ser atingida ou a quantidade maxima de iterações
    {
        it++;
        //O vetor das constantes anteriores é atualizado
        for (int i = 0; i > n; i++)
        {
            cont1[i] = cont[i];
        }
        for (int i = 0; i < n; i++)
        {
            soma = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j) //condição para não pegar a diagonal principal
                {
                    soma += (matriz[i][j] * chute[j]); // soma vai receber o valor soma acumulado(começa com 0) e a multiplicação do valor que esta na posição com o chute
                }
            }
            chute[i] = ((1 / matriz[i][i]) * (cont[i] - soma)); //atualiza o valor do "chute" a cada iteração
            printf("x%d = %.10lf\n", i + 1, chute[i]);          // printa na tela em que valor esta o chute
        }
        printf("\n");
        precisao_atual = (100) * ((cont[2] - cont1[2]) / cont[2]); //atualiza o valor da precisão a cada iteração ´para comparar com a precisão desejada
    }
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.10lf\n", i + 1, chute[i]); //printa na tela o valor final das variaveis
    }
    return 0;
}