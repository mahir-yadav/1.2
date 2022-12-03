#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct timespec start;
    struct timespec end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    pid_t id1 = fork();
    if (id1 == 0)
    {
        execl("./bash1.sh", "./bash1.sh", (char *)NULL);
        clock_gettime(CLOCK_THREAD_CPUTIME_ID, &end);
        printf("%lu sec, %lf nanoseconds start\n", start.tv_sec, start.tv_sec + (double)(start.tv_nsec) / 1000000000);
        printf("%lu sec, %lf nanoseconds end\n", end.tv_sec, end.tv_sec + (double)(end.tv_nsec) / 1000000000);
        printf("%lu sec, %lf nanoseconds elapsed\n ", end.tv_sec - start.tv_sec, end.tv_sec - start.tv_sec + (double)(end.tv_nsec - start.tv_nsec) / (double)1000000000);
    }
    else
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        pid_t id2 = fork();
        if (id2 == 0)
        {
            execl("./bash2.sh", "./bash2.sh", (char *)NULL);
            clock_gettime(CLOCK_THREAD_CPUTIME_ID, &end);
            printf("%lu sec, %lf nanoseconds start\n", start.tv_sec, start.tv_sec + (double)(start.tv_nsec) / 1000000000);
            printf("%lu sec, %lf nanoseconds end\n", end.tv_sec, end.tv_sec + (double)(end.tv_nsec) / 1000000000);
            printf("%lu sec, %lf nanoseconds elapsed\n ", end.tv_sec - start.tv_sec, end.tv_sec - start.tv_sec + (double)(end.tv_nsec - start.tv_nsec) / (double)1000000000);
        }
        else
        {
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
            pid_t id3 = fork();
            if (id3 == 0)
            {
                execl("./bash3.sh", "./bash3.sh", (char *)NULL);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
                printf("%lu sec, %lf nanoseconds start\n", start.tv_sec, start.tv_sec + (double)(start.tv_nsec) / 1000000000);
                printf("%lu sec, %lf nanoseconds end\n", end.tv_sec, end.tv_sec + (double)(end.tv_nsec) / 1000000000);
                printf("%lu sec, %lf nanoseconds elapsed\n ", end.tv_sec - start.tv_sec, end.tv_sec - start.tv_sec + (double)(end.tv_nsec - start.tv_nsec) / (double)1000000000);
            }
            else
            {
                wait(NULL);
            }
        }
    }

    return 0;
}
