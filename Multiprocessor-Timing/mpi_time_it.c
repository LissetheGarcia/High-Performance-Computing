// Program using a timer to produce small differences in output to compare serial and parallel output
// using mpi library for C/C++

// Header for access to functions to the POSIX API of the OS, useful for kernel interaction
#include <unistd.h>
#include <stdio.h>
// Header for performing parallel programming in C
#include <mpi.h>

int main(int argc, char *argv[])
{
    int mype;

    // MPI initialization and processor rank spawn
    // This function initiliazes MPI environment, taking addresses from argc and argv command line args.
    MPI_Init(&argc, &argv);
    // Manage communicators for process communicators
    /* this function returns the process ID of the processor that called the function.
     * takes the MPI environment and the memory address of an integer value */
    MPI_Comm_rank(MPI_COMM_WORLD, &mype);

    double t1, t2;

    t1 = MPI_Wtime();
    sleep(10);
    t2 = MPI_Wtime();
    if(mype == 0)
    {
        printf("Elapsed time is %f secs\n", t2-t1);
    }

    // This function cleans up MPI environment & ends MPI communications
    MPI_Finalize();
}
