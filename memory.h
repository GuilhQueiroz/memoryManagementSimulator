#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

#define MEMORY_SIZE 128   // Memória total em KB
#define BLOCK_SIZE 2      // Tamanho de cada bloco em KB
#define TOTAL_BLOCKS (MEMORY_SIZE / BLOCK_SIZE)

typedef struct {
    int pid;
    size_t size;
} Block;

typedef enum {
    NEXT_FIT,
    BEST_FIT,
    WORST_FIT
} Strategy;

void init_memory(Strategy strategy);
int allocate_memory(int pid, size_t size);
void free_memory(int pid);
void show_memory(void);

#endif
