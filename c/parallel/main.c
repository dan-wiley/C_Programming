#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Hello from pthread! Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    printf("=== Fork example ===\n");
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Hello from forked child! PID: %d\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Hello from parent! PID: %d, Child PID: %d\n", getpid(), pid);
    }

    sleep(1); // wait a bit for child to finish

    printf("\n=== Pthread example ===\n");
    pthread_t tid;
    if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
        perror("pthread_create failed");
        exit(1);
    }

    // Wait for thread to finish
    pthread_join(tid, NULL);
    printf("Back in main thread\n");

    return 0;
}
 
