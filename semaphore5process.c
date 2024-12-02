#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MULTIPLES 10

// Mutex to control access to the critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to print multiples of 5
void* print_multiples_of_5(void* arg) {
    int thread_id = *((int*)arg);
    int i;

    // Loop to print multiples of 5
    for(i = 1; i <= MULTIPLES; i++) {
        int multiple = 5 * i;

        // Enter critical section
        pthread_mutex_lock(&mutex);
        
        // Print the multiple of 5
        printf("Thread %d: %d\n", thread_id, multiple);

        // Leave critical section
        pthread_mutex_unlock(&mutex);

        // Sleep for a short time to simulate some work being done
        usleep(500000);  // Sleep for 0.5 seconds
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create 5 threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, print_multiples_of_5, &thread_ids[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex after use
    pthread_mutex_destroy(&mutex);

    return 0;
}
