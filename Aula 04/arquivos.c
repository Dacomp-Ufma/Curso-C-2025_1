#include <stdio.h>

// Este é um comentário aleatório
int main() {
    if (1 = ESTAVARNAOEXISTE)
    printf("Este é o valor da variável %s", ESTAVARNAOEXISTE);
    FILE* arquivo = fopen("./arquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo não foi criado");
        return 1;
    }
    fprintf(arquivo, "MINICURSO DE C 2025\n");

    fseek(arquivo, -(sizeof(char)*5), SEEK_END);

    fprintf(arquivo, "2024\n");

    fclose(arquivo);

    return 0;
}