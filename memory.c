#include "memory.h"
#include <stdio.h>

static Block memory[TOTAL_BLOCKS];
static Strategy current_strategy;
static size_t last_position = 0; // Para Next Fit

void init_memory(Strategy strategy) {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        memory[i].pid = -1;
        memory[i].size = 0;
    }
    current_strategy = strategy;
    last_position = 0;
}

static int next_fit(int pid, size_t need) {
    size_t count = 0;

    do {
        size_t free_blocks = 0;
        while (memory[last_position].pid == -1 && free_blocks < need && last_position < TOTAL_BLOCKS) {
            free_blocks++;
            last_position++;
        }

        if (free_blocks == need) {
            size_t pos = last_position - free_blocks;
            for (size_t i = 0; i < need; i++) {
                memory[pos + i].pid = pid;
                memory[pos + i].size = need;
            }
            return 1;
        }

        if (last_position >= TOTAL_BLOCKS) {
            last_position = 0;
        } else {
            last_position++;
        }

        count++;
    } while (count < TOTAL_BLOCKS);

    return 0;
}

static int best_fit(int pid, size_t need) {
    int best_index = -1;
    size_t best_size = TOTAL_BLOCKS + 1;
    size_t i = 0;

    while (i < TOTAL_BLOCKS) {
        if (memory[i].pid == -1) {
            size_t start = i;
            size_t free_blocks = 0;

            while (i < TOTAL_BLOCKS && memory[i].pid == -1) {
                free_blocks++;
                i++;
            }

            if (free_blocks >= need && free_blocks < best_size) {
                best_size = free_blocks;
                best_index = start;
            }
        } else {
            i++;
        }
    }

    if (best_index != -1) {
        for (size_t j = 0; j < need; j++) {
            memory[best_index + j].pid = pid;
            memory[best_index + j].size = need;
        }
        return 1;
    }
    return 0;
}

static int worst_fit(int pid, size_t need) {
    int worst_index = -1;
    size_t worst_size = 0;
    size_t i = 0;

    while (i < TOTAL_BLOCKS) {
        if (memory[i].pid == -1) {
            size_t start = i;
            size_t free_blocks = 0;

            while (i < TOTAL_BLOCKS && memory[i].pid == -1) {
                free_blocks++;
                i++;
            }

            if (free_blocks >= need && free_blocks > worst_size) {
                worst_size = free_blocks;
                worst_index = start;
            }
        } else {
            i++;
        }
    }

    if (worst_index != -1) {
        for (size_t j = 0; j < need; j++) {
            memory[worst_index + j].pid = pid;
            memory[worst_index + j].size = need;
        }
        return 1;
    }
    return 0;
}

int allocate_memory(int pid, size_t size) {
    size_t need = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        need++;
    }

    int success = 0;
    switch (current_strategy) {
        case NEXT_FIT:
            success = next_fit(pid, need);
            break;
        case BEST_FIT:
            success = best_fit(pid, need);
            break;
        case WORST_FIT:
            success = worst_fit(pid, need);
            break;
    }

    return success;
}

void free_memory(int pid) {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        if (memory[i].pid == pid) {
            memory[i].pid = -1;
            memory[i].size = 0;
        }
    }
}

void show_memory(void) {
    printf("\nEstado da Memória:\n\n");
    for (int i = 0; i < TOTAL_BLOCKS; i += 8) {
        // Linha dos índices
        printf("Blocos → ");
        for (int j = 0; j < 8 && (i + j) < TOTAL_BLOCKS; j++) {
            printf("%3d ", i + j);
        }
        printf("\n");

        // Linha dos PIDs
        printf("PID    → ");
        for (int j = 0; j < 8 && (i + j) < TOTAL_BLOCKS; j++) {
            if (memory[i + j].pid == -1)
                printf("  - ");
            else
                printf("%3d ", memory[i + j].pid);
        }
        printf("\n\n");
    }
}
