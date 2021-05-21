#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, it = 0, quant, iteracoes;
    float precisao, erro;
    printf("Informe a quantidade de sistemas: "); // pede para o usuario inserir o numero de equacoes, cada equacao equivale a uma variavel
    scanf("%d", &quant);
    printf("\n");
    float chute[quant], var[quant], igualdade[quant]; //vetores
    float matriz[quant][quant];                       //matriz
    float num, den;
    int n_x;

    for (i = 0; i < quant; i++)
    {
        n_x = 0;
        for (j = 0; j < quant; j++)
        {
            n_x++;
            printf("Informe o valor do coeficiente de X%d na linha %d: ", n_x, i + 1); //aqui o usuario preenche a matriz com os coeficientes
            scanf("%f", &matriz[i][j]);
            if (j == quant - 1)
            {
                printf("Informe o valor da iguadade do sistema na linha %d: ", i + 1); // insere o resultado de cada equação, ou seja o valor depois da igualdade
                scanf("%d", &igualdade[i]);
                printf("\n");
            }
        }
    }
    for (i = 0; i < quant; i++)
    {
        printf("Informe o valor do chute inicial para X%d: ", i + 1); //o usuario insere um chute para cada variavel
        scanf("%d", &chute[i]);
    }
    printf("\nInforme o valor da precisao desejada: "); //o usuario decide o quão precisa deve ser as respostas
    scanf("%f", &precisao);
    printf("\nInforme o numero maximo de iteracoes: ");
    scanf("%d", &iteracoes);

    //**************************************************************************************************************
    do //loop até a precisao desejada ser atingida ou a quantidade maxima de iterações
    {
        it++;
        num = 0;
        den = 0;
        for (i = 0; i < quant; i++)
        {
            var[i] = 0;
            for (j = 0; j < quant; j++)
            {
                if (i != j) //cond para não pegar a diagonal principal
                {
                    var[i] = var[i] + (matriz[i][j] * chute[j]); // soma vai receber o valor soma acumulado(começa com 0) e a multiplicação do valor que esta na posição com o chute
                }
            }
            var[i] = (1 / matriz[i][i]) * (igualdade[i] - var[i]); //atualiza o valor do "chute" a cada iterat
            if (num < abs(var[i] - chute[i]))
            {
                num = abs(var[i] - chute[i]); //atualiza o valor do numerador
            }
            if (den < abs(var[i]))
            {
                den = abs(var[i]); //atualiza o valor do denominador
            }
            chute[i] = var[i]; //O vetor das constantes anteriores � atualizado
        }
    } while (((abs(num / den)) < precisao) || (it <= precisao)); //cond de parada do loop
    printf("Foram utilizadas %d iteracoes.", it);
    for (i = 0; i < quant; i++)
    {
        printf("\nValor de X%d: %f", i + 1, chute[i]); //printa na tela o valor final das variaveis
    }
    return 0;
}
