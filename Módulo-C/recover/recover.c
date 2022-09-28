#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // verificando se o argumento é diferente de 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // arquivo aberto para leitura
    FILE *input_file = fopen(argv[1], "r");

    // verifique se o input_file é válido
    if (input_file == NULL)
    {
        printf("Não foi possível abrir arquivo");
        return 2;
    }

    // armazenar blocos de 512 bytes em um array
    unsigned char buffer[512];

    // acompanhar o número de imagens geradas
    int count_image = 0;


    // arquivo pointer para imagens recuperadas
    FILE *output_file = NULL;

    // char nome_arquivo[8]
    char *filename = malloc(8 * sizeof(char));

    // leia os blocos de 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // verifique se os bytes indicam o início do JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // escreva os nomes dos arquivos JPEG
            sprintf(filename, "%03i.jpg", count_image);

            // abrir output_file para escrita
            output_file = fopen(filename, "w");

            // contar o número de imagens encontradas
            count_image++;
        }

        // verifique se a saída foi usada para entrada válida
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}