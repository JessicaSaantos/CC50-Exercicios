#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string nome = get_string("Qual seu nome? ");
    printf("olá, %s", nome);
}