/*Considere um arquivo com o seguinte formato:
Maria    020       RJ
Joao     101       SP
Jose     006       MG
Os nomes, idades e estados aparecem sempre, respectivamente, nas posições 0, 10 e 20 de cada linha. As idades possuem exatamente 3 caracteres. Os estados possuem exatamente 2 caracteres.
Escreva um programa que leia o número de uma linha e mostre, separadamente, a idade e o estado correspondente. Por exemplo, para o arquivo acima, a leitura 2 deve exibir a idade 101 e o estado SP. Caso a linha não exista, o programa deverá exibir registro nao encontrado.
Teste o programa com linhas inválidas (por exemplo, -1, 0, 1000, etc).*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[50];  
    int numero_linha;
    int contador = 0;
  
    arquivo = fopen("dados.txt", "r");  //abrir o arquivo para leitura
    if (arquivo == NULL) {              //Se o arquivo não existir, o programa mostra erro e termina
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    printf("Digite o numero da linha: ");
    scanf("%d", &numero_linha);

    if (numero_linha <= 0) {
        printf("Registro nao encontrado\n");
        fclose(arquivo);
        return 0;
    }
  
    while (fgets(linha, sizeof(linha), arquivo) != NULL) { //fgets lê uma linha inteira do arquivo, linha vai guardar a linha inteira como string, lê linha por linha
        contador++;

        
        if (contador == numero_linha) {         // quando chegar na linha desejada
            char idade[4];   // 3 caracteres + '\0'
            char estado[3];  // 2 caracteres + '\0'

          
            strncpy(idade, linha + 10, 3);   // copiar idade da linha(posição 10 a 12)
            idade[3] = '\0';  //garantir o final da string

            strncpy(estado, linha + 20, 2);  // Copiar estado da linha (posição 20 a 21)
            estado[2] = '\0'; // garantir o final da string

            printf("Idade: %s\n", idade);
            printf("Estado: %s\n", estado);

            fclose(arquivo);
            return 0;
        }
    }

    printf("Registro nao encontrado\n"); //se chegou aqui a linha não existe
    fclose(arquivo);
    return 0;
}











