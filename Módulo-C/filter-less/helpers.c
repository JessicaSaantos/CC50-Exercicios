#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // percorra através de cada linha
    for (int i = 0; i < height; i ++)
    {
        // percorra através de cada coluna
        for (int j = 0; j < width; j ++)
        {
            // Converter pixels para float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // encontre o valor médio
            int media = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].
                                  rgbtBlue = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // percorrendo a linha
    for (int i = 0; i < height; i ++)
    {
        // percorrendo a coluna
        for (int j = 0; j < width; j ++)
        {
            // Converter pixels para float
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            // encontre o valor de pixel atualizado
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen +
                                 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen +
                                   0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen +
                                  0.131 * originalBlue);

            // atualize o valor do pixel se sepiaRed, sepiaGreen ou
            // sepiaBlue exceder 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // atualizar os valores finais de pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // percorrer linha
    for (int i = 0; i < height; i ++)
    {
        // percorrer coluna
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
    // criar uma cópia da img
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //percorrendo a linha
    for (int i = 0; i < height; i ++)
    {
        //percorrendo a coluna
        for (int j = 0; j < width; j ++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // obter pixels vizinhos
            for (int x = -1; x < 2; x ++)
            {
                for (int y = -1; y < 2; y ++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // verifique se o pixel vizinho é válido
                    if (currentX < 0 || currentX > (height - 1) ||
                        currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // obter valor da imagem
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
