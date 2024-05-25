/*
 * WRITING A SIMPLE SERVER
 * */

#include <pthread.h>
#include <stdio.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>

void *thread_function(void *args)
{
    sleep(1);
    printf("The thread\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    printf("Creating thread.");
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("Thread id: %lu\n", thread);

    pthread_join(thread, NULL);
    return 0;
}
