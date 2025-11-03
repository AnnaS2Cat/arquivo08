/*Sem usar um loop ( while, for, etc), escreva um programa que adicione o caractere |meio|exatamente no meio de um arquivo dado (mas desconhecido).
Dica: Use o modo r+para ler e escrever no arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char filename[128];
    const char *insert = "|meio|";
    size_t insert_len = strlen(insert);
    printf("Digite o nome do arquivo: ");
    scanf("%127s", filename);  // lê o nome do arquivo

    FILE *f = fopen(filename, "rb+"); // abro pra ler e escrever 
    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fseek(f, 0, SEEK_END);  //descobrir o tamanho do arquivo
    long size = ftell(f);
    if (size == -1L) {
        perror("ftell falhou");
        fclose(f);
        return 1;
    }

    long mid = size / 2; //quanto vale o meio

    fseek(f, mid, SEEK_SET);  // ler depois do meio
    long remaining = size - mid;
    unsigned char *buffer = NULL;
    if (remaining > 0) {
        buffer = malloc((size_t)remaining);
        if (buffer == NULL) {
            fprintf(stderr, "Memória insuficiente.\n");
            fclose(f);
            return 1;
        }
        fread(buffer, 1, (size_t)remaining, f);
    }

    fseek(f, mid, SEEK_SET);
    fwrite(insert, 1, insert_len, f);
    if (remaining > 0)
        fwrite(buffer, 1, (size_t)remaining, f);

    free(buffer);
    fclose(f);
    printf("Inserido \"%s\" no meio do arquivo \"%s\" \n", insert, filename);
}
