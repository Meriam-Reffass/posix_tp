#ifndef STRUCTS_H_INLUDED
#define STRUCTS_H_INLUDED
#include "config.h"
#include <semaphore.h>
struct argument {
    int startRow;
    int nRows;
    long partialSum;
} threadArgs[MAX_THREADS];
/* Matrix pointer: it will be dynamically allocated */
long *bigMatrix;


//ADD A MUTEX
sem_t mutex;

// Variable to store the result
static long totalSum = 0;

#endif
