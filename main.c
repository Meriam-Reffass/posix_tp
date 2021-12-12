#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>


#include "routine.h"
#include "structs.h"
#include "config.h"




int main (int argc, char *args[]) {
    /* Array of thread identifiers */
    pthread_t threads[MAX_THREADS];
    long totalSum_1;
    int i, j, nThreads, rowsPerThread, lastThreadRows;
    sem_init(&mutex, 0, 1);
    /* Get the number of threads from command parameters */
    if (argc != 2) {
        printf ("Usage: %s <numThreads>\n", args[0]);
        exit (0);
    }				//fin if
    sscanf (args[1], "%d", &nThreads);
    /* Allocate the matrix M */
    bigMatrix = malloc (ROWS * COLS * sizeof (long));
    /* Fill the matrix with some values */
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            bigMatrix[i * COLS + j] = i + COLS * j;

    /* If the number of rows cannot be divided exactly by the number of threads,let the last thread handle also the remaining rows */
    rowsPerThread = ROWS / nThreads;
    if (ROWS % nThreads == 0)
        lastThreadRows = rowsPerThread;
    else
        lastThreadRows = rowsPerThread + ROWS % nThreads;
    /* Prepare arguments for threads */
    for (i = 0; i < nThreads; i++) {
        /* Prepare Thread arguments */
        threadArgs[i].startRow = i * rowsPerThread;
        if (i == nThreads - 1)
            threadArgs[i].nRows = lastThreadRows;
        else
            threadArgs[i].nRows = rowsPerThread;
    }				//fin for
    /* Start the threads using default thread attributes */
    for (i = 0; i < nThreads; i++)
        pthread_create (&threads[i], NULL, thread_routine, &threadArgs[i]);
    /* Display the values of the matrix */
    printf ("Your matrix is as follows:\n");
    for (i = 0; i < ROWS; i++) {
        printf ("[");
        for (j = 0; j < COLS; j++)
            printf ("%ld:", bigMatrix[i * COLS + j]);
        printf ("]\n");
    }				//fin for
    printf ("Please hit enter to continue ...");
    getchar ();
    /* Wait thread termination and use the corresponding sum value for the final summation */
    totalSum_1 = 0;
    for (i = 0; i < nThreads; i++) {
        pthread_join (threads[i], NULL);
        //printf ("Thread %d just terminated with its partial sum %ld\n", i,threadArgs[i].partialSum);
        totalSum_1 += threadArgs[i].partialSum;
    }				//fin for

    /* Display the total sum calculated */
    //printf ("The total sum calculated by all the threads is %ld\n", totalSum_1);
    printf ("The total sum calculated by all the threads using semaphores is %ld\n", totalSum);
    sem_destroy(&mutex);
    pthread_exit (NULL);

}				//fin main
