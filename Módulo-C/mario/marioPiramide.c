#include <stdio.h>
#include <cs50.h>

int main (void) {
    int height, row, column, space, gap;
    do {
      height = get_int ("Insira a altura da pirâmide: ");  
    } while(height < 1 || height > 8);
    
    // loop externo imprime linhas 
    for (row = 0 ; row < height ; row ++){
        
        for (space = 0; space < height - row - 1; space ++){
            printf(" ");
        }
        // loop interno imprime colunas
        for(column = 0 ; column <= row ; column ++){
            printf("#");
        }
        
        for (gap = 0; gap <= height -1; gap = height){
            printf("  ");
        }
        for(column = 0 ; column <= row ; column ++){
            printf("#");
        }
        
        printf("\n");
    }
    
}
