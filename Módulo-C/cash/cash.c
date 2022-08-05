#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void){
    float dollar;
    //Recebe a informação do usuário
    do {
      dollar = get_float("Qual o valor do troco? "); 
    } while(dollar <= 0);
    
    //arredonda o valor 
    int cents = round(dollar * 100);
    int coins = 0;
    
    //Faz loops de comparação para subtrair até chegar ao resultado
    while (cents >= 25){
        cents -= 25;
        coins ++; //armazena a informação necessária
    }
    
    while (cents >= 10){
        cents -= 10;
        coins ++;
    }
    
    while (cents >= 5){
        cents -= 5;
        coins ++;
    }
    
    while (cents >= 1){
        cents -= 1;
        coins ++;
    }
    //informa o número de moedas
    printf("Você precisará de %i moedas" , coins);
    
}
