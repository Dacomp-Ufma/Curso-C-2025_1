#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// função de potência quadrada - versão void
void elevar_ao_quadrado_void(int* var) {
    if (var != NULL) {
        *var = (*var) * (*var);
        printf("Valor de var: %d\n", *var);
    }else {
        printf("Erro ao executar operacao: parametro invalido. \n");
    }
}

// função de potência quadrada - versão booleana
int elevar_ao_quadrado(int* var) {
    if ( var != NULL) {
        *var = (*var) * (*var);
        printf("Valor de var: %d\n", *var);
        return true;
    }else {
        printf("Erro ao executar operacao: parametro invalido. \n");
        return false;
    }
}

// Estrutura do nó da lista simplesmente encadeada ( aplicação de ponteiro e alocação dinâmica )
typedef struct No {
    int valor;
    struct No* next;
}NO;

int main() {

    // Ponteiros
    int var = 25;
    int* ptr = &var;
    printf("O endereco de memoria contido em ptr eh: %p \n", ptr);
    printf(" O valor contido no ponteiro eh: %d \n", *ptr);

    *ptr = 50;
    printf("O valor de var apos ser alterado pelo ponteiro: %d \n", *ptr);

    // Casting de ponteiros

    void *ptr_void = &var;
    int* ptr_int = (int*)ptr_void;

    printf("O valor contido no ponteiro ptr_int eh: %d \n", *ptr_int);

    // acesso de variável por referência
    int parametro = 10;
    printf("O parametro antes de ser referenciado: %d \n", parametro);

    elevar_ao_quadrado_void(&parametro);

    printf("O valor da variavel apos a referencia eh: %d \n", parametro);

    // alocação dinâmica
    // malloc
    int n = 10;
    int* variavel_alocada = (int*)malloc(n * sizeof(int));
    if (variavel_alocada != NULL) {
        printf("Alocacao foi valida! \n");
        for (int i = 0; i < n; i++) {
            variavel_alocada[i] = i + 1;
            printf("%d ", variavel_alocada[i]);
        }
        printf("\n");
    }

    // realloc
    variavel_alocada = (int*)realloc(variavel_alocada, (n+2) * sizeof(int));
    if (variavel_alocada != NULL) {
        variavel_alocada[10] = 42;
        variavel_alocada[11] = 43;
        for (int i = 0; i < n + 2; i++) {
            printf("%d ", variavel_alocada[i]);
        }
        printf("\n");
    }

    free(variavel_alocada);
    variavel_alocada = NULL;

    // Exemplo de aplicação em lista encadeada
    // Aloca nós dinâmicamente
    NO* first = (NO*) malloc(sizeof(NO));
    if (first != NULL) {
        first->valor = 100;
        first->next = NULL;
    }

    NO* second = (NO*) malloc(sizeof(NO));
    if (second != NULL) {
        second->valor = 200;
        second->next = NULL;
        first->next = second;
    }

    // imprime a lista
    NO* aux = first;
    while (aux != NULL) {
        printf("%d -> ", aux->valor); // 100 -> 200 ->
        aux = aux->next;
    }
    printf("NULL \n");

    // libera a memória
    free(first);
    free(second);

    return 0;
}