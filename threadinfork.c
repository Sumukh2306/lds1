#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h> // Include for the wait function

// Function for threads to print the 6-table
void* printTable(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d: Printing table of 6 up to 6 x 5\n", thread_num);
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d: 6 x %d = %d\n", thread_num, i, 6 * i);
    }
    free(arg); // Free allocated memory for thread argument
    pthread_exit(NULL);
}

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("In Child Process: PID = %d\n", getpid());

        pthread_t threads[5];
        for (int i = 0; i < 5; i++) {
            int* thread_num = malloc(sizeof(int));
            if (thread_num == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            *thread_num = i + 1; // Thread number (1 to 5)
            if (pthread_create(&threads[i], NULL, printTable, thread_num) != 0) {
                perror("Failed to create thread");
                exit(EXIT_FAILURE);
            }
        }

        // Wait for all threads to complete
        for (int i = 0; i < 5; i++) {
            pthread_join(threads[i], NULL);
        }

        printf("Child Process: All threads completed.\n");
    } else {
        // Parent process
        printf("In Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL); // Wait for the child process to complete
        printf("Parent Process: Child process completed.\n");
    }

    return 0;
}
