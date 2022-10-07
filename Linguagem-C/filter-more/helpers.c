#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //percorrer cada linha
    for (int i = 0; i < height; i ++)
    {
        //percorrer cada coluna
        for (int j = 0; j < width; j ++)
        {
            //converter pixels para float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;
            
            
            //encontre o valor médio
            int media = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].
                                  rgbtBlue = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // percorrer a linha 
    for (int i = 0; i < height; i ++)
    {
        // percorrer a coluna
        for (int j = 0; j < width / 2; j ++)
        {
            // logica para inverter a img
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // criar copia da img
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    // percorrer a linha
    for (int i = 0; i < height; i ++)
    {
        // percorrer a coluna
        for (int j = 0; j < width; j ++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;
            
            //obter pixels vizinhos
            for (int x = -1; x < 2; x ++)
            {
                for (int y = -1; y < 2; y ++)
                {
                    int currentX = i + x;
                    int currentY = j + y;
                    
                    // verifique se o píxel vizinho é valido
                    if (currentX < 0 || currentX > (height - 1) || 
                        currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    
                    // obter valor valido da img
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    
                    counter++;
                }
                
                // calcular a média de pixels vizinhos
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }
    
    // copiar novos pixels na imagem original
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // criando copia temporaria da img
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    // iniciando array 2d
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
     
    // percorrer cada linha e coluna
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            // inicialização
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;
            
            // loop através de cada pixel para pixels vizinhos
            for (int x = 0; x < 3; x ++)
            {
                for (int y = 0; y < 3; y ++)
                {
                    // verifique se há pixels válidos
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 || j 
                        - 1 + y < 0 || j - 1 + y > width - 1)
                    {
                        continue;
                    }
                       
                    // Calcular Gx para cada cor
                    redX = redX + (image[i - 1 + x][j - 1 + y].rgbtRed *
                                   Gx[x][y]);
                    greenX = greenX + (image[i - 1 + x][j - 1 + y].rgbtGreen *
                                       Gx[x][y]);
                    blueX = blueX + (image[i - 1 + x][j - 1 + y].rgbtBlue *
                                     Gx[x][y]);
                    
                    // Calcular Gy para cada cor
                    redY = redY + (image[i - 1 + x][j - 1 + y].rgbtRed *
                                   Gy[x][y]);
                    greenY = greenY + (image[i - 1 + x][j - 1 + y].rgbtGreen *
                                       Gy[x][y]);
                    blueY = blueY + (image[i - 1 + x][j - 1 + y].rgbtBlue *
                                     Gy[x][y]);
                }
            }
            
            // Calcular a raiz quadrada de Gx2 e Gy2
            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));
            
            //valor do limite em 255 se exceder
            if (red > 255)
            {
                red = 255;
            }
            
            if (green > 255)
            {
                green = 255;
            }
            
            if (blue > 255)
            {
                blue = 255;
            }
            
            // copiar valores em imagem temporária
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }
    
    // copie novos pixels na imagem original
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
