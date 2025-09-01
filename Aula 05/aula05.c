#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

// Questão 1

int funcao_recursiva(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return funcao_recursiva(n-1) + funcao_recursiva(n-2) + funcao_recursiva(n-3);
}
// execução expandida
// n = 5
// funcao recursiva (4) + funcao recursiva ( 3) + funcao recursiva (2)
//  // 6                    // 3                     // 2
//
// n = 4
//
// funcao recursiva (3) + funcao recursiva ( 2) + funcao recursiva (1)
//  // 3                     // 2                  //1
//
// n = 3
//
// funcao recursiva (2) + funcao recursiva ( 1) + funcao recursiva (0)
//   2                              1                 0


// questão 2
int removeSpecArray (int tamanho, int posicao, int* vetor) {
    // A posição = indice + 1
    if (tamanho > 0 && posicao >= 0 && vetor != NULL) {
        int i = 0;
        for ( i = posicao; i < tamanho - 1; i++) {
            vetor[i-1] = vetor[i];
        }
        vetor[tamanho-1] = '\0';
        return true;
    }else{
        printf("Erro de parâmetro! \n");
        return false;
    }
}

// Questão 3

int somaDigitosRecursivo(int num) {
    if (num == 0) return 0;

    return (num % 10) + somaDigitosRecursivo(num/10);
}
//
// 245
// return 1 + countDigitsRecursivo(245/10);
//            //3
// 24.5
// 24 <- função recebe parametro truncado
// return 1 + countDigitsRecursivo(24/10);
//            //2
// 2.4
// 2
// return 1 + countDigitsRecursivo(2/10);
//             //1
// 0.2
// 0
// return 1 + countDigitsRecursivo(0/10);
//             // 0

// Questão 35

typedef struct carro{
    char placa[20];
    char modelo[50];
} Carro;

char* get_modelo(Carro* carros, int n, char* placa_desejada) {
    for (int i = 0; i < n; i++) {
        if (strcmp(carros[i].placa, placa_desejada) == 0) return carros[i].modelo;
    }
    return NUll;
}

// Questão 38
typedef struct evento {
    float start_period;
    float end_period;
}Evento;

int tem_conflito(Evento e1, Evento e2) {
    return (e1.start_period < e2.end_period && e2.start_period < e1.end_period) ? 1 : 0;
}

// Questão 40
typedef struct {
    char nome[50];
    int idade;
    float* notas;
    int numNotas;
}Estudante;

Estudante* createStudent(char* nome, int idade, int max_notas) {
    Estudante* estudante = malloc(sizeof(Estudante));
    if (estudante != NULL) {
        strcpy(estudante->nome, nome);
        estudante->idade = idade;
        estudante->notas = malloc(max_notas * sizeof(float));
        estudante->numNotas = 0;
        return estudante;
    }
}

int adicionaNota(Estudante* estudante, float nota) {
    estudante->notas = realloc(estudante->notas, (estudante->numNotas + 1) * sizeof(float));
    if (estudante->notas == NULL) {
        estudante->notas[estudante->numNotas++] = nota;
        return 1;
    }else {
        printf("Erro de adicionaNota! \n");
    }
    return 0;
}


int main () {
    int n = 523;
    int soma = somaDigitosRecursivo(n);
    printf("Soma = %d\n", soma);

    return 0;
}
