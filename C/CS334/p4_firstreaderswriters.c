/* Implement the first Readers - Writers problem */

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define NO_OF_READERS 3
#define NO_OF_WRITERS 2

static sem_t write_lock; // Semaphore for updating and signalling
static pthread_mutex_t n_reader_lock; // Mutex for editing number of readers
static int n_reader = 0; // Number of readers at a certain instance of time
static int data = 100; // Data to be read

void *reader_start_routine(void *tid) {
  int thread_id = *((int *) tid);

  printf("[Reader%d]: Waiting to acquire lock for incrementing n_reader\n", thread_id);
  pthread_mutex_lock(&n_reader_lock);

  printf("[Reader%d]: Updating n_reader\n", thread_id);
  ++n_reader;
  if(n_reader == 1) {
    printf("[Reader%d]: First reader. Acquiring write lock\n", thread_id);
    sem_wait(&write_lock);
  }

  printf("[Reader%d]: Unlocking n_reader lock\n", thread_id);
  pthread_mutex_unlock(&n_reader_lock);

  printf("[Reader%d]: Read value: %d\n", thread_id, data);

  printf("[Reader%d]: Waiting to acquire lock for decrementing n_reader\n", thread_id);
  pthread_mutex_lock(&n_reader_lock);

  printf("[Reader%d]: Updating n_reader\n", thread_id);
  --n_reader;
  if(n_reader == 0) {
    printf("[Reader%d]: No readers left. Unlocking write lock\n", thread_id);
    sem_post(&write_lock);
  }

  printf("[Reader%d]: Unlocking n_reader lock\n", thread_id);
  pthread_mutex_unlock(&n_reader_lock);
}

void *writer_start_routine(void *tid) {
  int thread_id = *((int *) tid);

  printf("[Writer%d]: Waiting for write lock\n", thread_id);
  sem_wait(&write_lock);

  printf("[Writer%d]: Write lock acquired. Incrementing value\n", thread_id);
  ++data;

  printf("[Writer%d]: Unlocking write lock\n", thread_id);
  sem_post(&write_lock);
}

int main() {
  pthread_t readers[NO_OF_READERS], writers[NO_OF_WRITERS];
  int reader_ids[NO_OF_READERS], writer_ids[NO_OF_WRITERS];
  
  sem_init(&write_lock, 0, 1);

  // Generating unique identifiers for threads
  for(int i = 0; i < NO_OF_READERS; reader_ids[i++] = i); 
  for(int i = 0; i < NO_OF_WRITERS; writer_ids[i++] = i); 
  
  for(int i = 0; i < NO_OF_READERS; i++) pthread_create(
    &readers[i], NULL, reader_start_routine, (void *)&reader_ids[i]
  );
  
  for(int i = 0; i < NO_OF_WRITERS; i++) pthread_create(
    &writers[i], NULL, writer_start_routine, (void *)&writer_ids[i]
  );

  for(int i = 0; i < NO_OF_READERS; i++) 
    pthread_join(readers[i], NULL);

  for(int i = 0; i < NO_OF_WRITERS; i++)
    pthread_join(writers[i], NULL);

  return 0;
}


