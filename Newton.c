#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função a ser resolvida
float funcao(int x)
{
    float func;
    func = pow(x, 2) - 1;
    return func;
}

//função derivada
float derivada(int x)
{
    float func_derivada;
    func_derivada = 2 * x;
    return func_derivada;
}

//aplicando o método de newton
void newton(int x_in, double erro_desejado, int max_it)
{
    int it = 0;
    double erro = 1;
    double x_at = 0;
    while ((erro > erro_desejado) || (it >= max_it))
    { //enquanto o erro for maior que o desejado ou as interações chegar ao limite o programa roda

        x_at = x_in - (funcao(x_in) / derivada(x_in)); // formula aplicada ao metodo de Newton

        erro = (abs(x_at - x_in)) / x_at; // calculo do erro
        it = it + 1;                      //contando o numero de interações
        x_in = x_at;                      //o X inicial agora recebe o X atual, para refazer os calculos
        printf("Erro relativo: %.5f\n", erro);
        printf("Numero de interacoes: %d\n", it);
        printf("Raiz da equacao: %.2f\n", x_at);
        printf("*********************************\n\n");
    }
}

int main()
{
    int valor;
    double precisao = 0.0001; //precisão ja definada
    int interacoes = 100;     // interações ja definida

    printf("Informe o chute inicial(x0): "); //pede para inserir o valor de chute
    scanf("%d", &valor);
    newton(valor, precisao, interacoes); // chama a função newton
    return 0;
}