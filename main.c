#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main() {
    int option, strategy;

    printf("Selecione a estratégia:\n");
    printf("1 - Next Fit\n");
    printf("2 - Best Fit\n");
    printf("3 - Worst Fit\n");
    printf("Opção: ");
    scanf("%d", &strategy);

    init_memory(strategy);

    do {
        printf("\nMenu:\n");
        printf("1 - Alocar memória\n");
        printf("2 - Liberar memória\n");
        printf("3 - Mostrar memória\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        if (option == 1) {
            int pid;
            size_t size;
            printf("Informe o PID: ");
            scanf("%d", &pid);
            printf("Informe o tamanho (KB): ");
            scanf("%zu", &size);
            if (allocate_memory(pid, size)) {
                printf("Memória alocada com sucesso.\n");
            } else {
                printf("Falha na alocação.\n");
            }
        } else if (option == 2) {
            int pid;
            printf("Informe o PID: ");
            scanf("%d", &pid);
            free_memory(pid);
            printf("Memória liberada.\n");
        } else if (option == 3) {
            show_memory();
        }

    } while (option != 0);

    return 0;
}
