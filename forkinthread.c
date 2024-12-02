#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function for the thread to create 5 child processes
void* createForks(void* arg) {
    printf("Thread started: Creating 5 child processes\n");

    for (int i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Child %d: PID = %d, printing table of 5\n", i + 1, getpid());
            for (int j = 1; j <= 5; j++) {
                printf("Child %d: 5 x %d = %d\n", i + 1, j, 5 * j);
            }
            exit(0); // Exit child process after printing
        }
    }

    // Parent process waits for all child processes to complete
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    printf("Thread: All child processes completed.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    // Create the thread
    if (pthread_create(&thread, NULL, createForks, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    printf("Main process: Thread completed.\n");
    return 0;
}
