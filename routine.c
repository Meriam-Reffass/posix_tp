#include "routine.h"
#include "structs.h"
#include "routine.h"
#include "config.h"
#include <stddef.h>
#include <semaphore.h>

/* Thread routine : make the summation of all the elements of the assigned matrix rows */
static void * thread_routine (void *arg) {
    int i, j;
    /* Typeb cast passed pointer to expected structure containing the start row,the number of rows to be summed and the return sum argument */
    struct argument *currArg = (struct argument *) arg;
    long sum = 0;
    for (i = 0; i < currArg->nRows; i++)
        for (j = 0; j < COLS; j++)
            sum += bigMatrix[(currArg->startRow + i) * COLS + j];
    //currArg->partialSum = sum;
    sem_wait(&mutex); // locking the semaphore
    totalSum += sum;
    sem_post(&mutex); //releasing the semaphore

    return NULL;
}				//fin thread_routine()
