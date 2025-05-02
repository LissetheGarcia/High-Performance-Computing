// This program shows how to get the thread ID and the number of threads.
// simple attemp fro writing a simple hello world
// To compile with gcc: gcc -fopenmp -o helloOpenMP helloOpenMP.c

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int nthreads, threadId;

    nthreads = omp_get_num_threads();
    threadId = omp_get_thread_num();

    puts("Saying bye to slow serial world and welcoming OpenMP world! :)");
    printf("There are %d threads in this computer.", nthreads);
    puts("");
    printf("My thread ID is: %d", threadId);
    puts("");
}
