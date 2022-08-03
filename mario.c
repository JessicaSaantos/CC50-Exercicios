#include <stdio.h>
#include <cs50.h>

int main (void) {
    int height, row, column, space;
    do {
      height = get_int ("Insira a altura da pirâmide: ");  
    } while(height < 1 || height > 8);
    
    for (row = 0 ; row < height ; row ++){
        
        for (space = 0; space < height - row - 1; space ++){
            printf(" ");
        }
        
        for(column = 0 ; column <= row ; column ++){
            printf("#");
        }
        printf("\n");
    }
    
}
