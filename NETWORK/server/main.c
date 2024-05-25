/*
 * WRITING A SIMPLE SERVER
 * */

#include <pthread.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>

void *thread_function(void *args)
{
    printf("Got data %d\n", (int)(size_t)args);
    return NULL;
}

int main()
{
    pthread_t thread;

    printf("Creating thread.\n");
    int temp = 10;

    int ret = pthread_create(&thread, NULL, thread_function, (void *)(size_t)temp);
    if (ret != 0)
    {
        printf("Error creating thread.\n");
        return 1;
    }
    printf("Creating a Thread with id (%lu)\n", thread);

    pthread_join(thread, NULL);
    return 0;
}
