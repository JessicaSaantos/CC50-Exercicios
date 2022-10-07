#include <cs50.h>
#include <stdio.h>

int main(void)
{
      // Solicita o valor inicial ao usuário
    int inicial, final;
    do
    {
        inicial = get_int("Valor inicial da população: ");
    }
    while (inicial < 9);

     // Solicita o valor final ao usuário
    do
    {
        final = get_int("Valor final da população: ");
    }
    while (final < inicial);

     // Calcule o número de anos até o limite
     int anos = 0;
     while (inicial < final)
     {

        inicial = inicial + (inicial / 3) - (inicial / 4);
        anos++;

     }

     // Imprime o número de anos

     printf("Tempo necessário: %i anos\n", anos);

}
