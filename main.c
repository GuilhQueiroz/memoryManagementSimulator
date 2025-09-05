#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "memory.h"

void print_separator() {
    printf("\033[1;34m==============================\033[0m\n");
}

// Função para simulação automática
void automatic_simulation() {
    int strategy;
    printf("\nSelect allocation strategy:\n");
    printf("1 - Next Fit\n");
    printf("2 - Best Fit\n");
    printf("3 - Worst Fit\n");
    printf("Opção: ");
    scanf("%d", &strategy);

    // Ajusta o valor para corresponder ao enum
    init_memory(strategy - 1);

    printf("\n--- Automatic Simulation ---\n");

    printf("Allocating P1 (10 KB)... ");
    if (allocate_memory(1, 10))
        printf("Success!\n");
    else
        printf("Failed!\n");
    print_separator();
    sleep(2);

    printf("Allocating P2 (8 KB)... ");
    if (allocate_memory(2, 8))
        printf("Success!\n");
    else
        printf("Failed!\n");
    print_separator();
    sleep(2);

    printf("Allocating P3 (14 KB)... ");
    if (allocate_memory(3, 14))
        printf("Success!\n");
    else
        printf("Failed!\n");
    print_separator();
    sleep(2);

    printf("Freeing P2... Done!\n");
    free_memory(2);
    print_separator();
    sleep(2);

    printf("Allocating P4 (6 KB)... ");
    if (allocate_memory(4, 6))
        printf("Success!\n");
    else
        printf("Failed!\n");
    print_separator();
    sleep(2);

    printf("Allocating P5 (50 KB)... ");
    if (allocate_memory(5, 50))
        printf("Success!\n");
    else
        printf("Failed!\n");
    print_separator();
    sleep(2);

    printf("\n--- Final Memory State ---\n");
    show_memory();

}

// Função para modo interativo
void interactive_mode() {
    int option, strategy;
    printf("\nSelect allocation strategy:\n");
    printf("1 - Next Fit\n");
    printf("2 - Best Fit\n");
    printf("3 - Worst Fit\n");
    printf("Opção: ");
    scanf("%d", &strategy);

    // Ajusta o valor para corresponder ao enum
    init_memory(strategy - 1);

    do {
        printf("\nMenu:\n");
        printf("1 - Alocar memória\n");
        printf("2 - Liberar memória\n");
        printf("3 - Mostrar memória\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &option);

        if (option == 1) {
            int pid;
            size_t size;
            printf("Enter PID: ");
            scanf("%d", &pid);
            printf("Enter size (KB): ");
            scanf("%zu", &size);
            if (allocate_memory(pid, size)) {
                printf("Memory allocated successfully.\n");
            } else {
                printf("Allocation failed.\n");
            }
        } else if (option == 2) {
            int pid;
            printf("Enter PID: ");
            scanf("%d", &pid);
            free_memory(pid);
            printf("Memory freed.\n");
        } else if (option == 3) {
            show_memory();
        }

    } while (option != 0);
}

int main() {
    int mode;
    printf("Select mode:\n");
    printf("1 - Modo interativo\n");
    printf("2 - Simulação automática\n");
    printf("Opção: ");
    scanf("%d", &mode);

    if (mode == 1) {
        interactive_mode();
    } else if (mode == 2) {
        automatic_simulation();
    } else {
        printf("Invalid option!\n");
    }

    return 0;
}
