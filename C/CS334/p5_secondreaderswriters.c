/* Implement the second Readers - Writers problem */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NO_OF_READERS 5
#define NO_OF_WRITERS 3

// Semaphore to avoid updation while readers are active
static sem_t write_lock;

// Number of active readers and writers
static int n_reader = 0, n_writer = 0;

// Mutex lock to lock other threads from editing n_reader
// or n_writer
static pthread_mutex_t n_reader_lock, n_writer_lock, try_read;

static int data = 1000;

// Reader function
void *reader_start_routine(void *tid) {
  int thread_id = *((int *)tid);

  printf("[Reader%d]: Waiting to acquire lock for incrementing n_reader\n",
         thread_id);
  pthread_mutex_lock(&try_read);
  pthread_mutex_lock(&n_reader_lock);

  printf("[Reader%d]: Updating n_reader\n", thread_id);
  ++n_reader;
  if (n_reader == 1) {
    printf("[Reader%d]: First reader. Acquiring write lock\n", thread_id);
    sem_wait(&write_lock);
  }

  printf("[Reader%d]: Unlocking n_reader lock\n", thread_id);
  pthread_mutex_unlock(&n_reader_lock);
  pthread_mutex_unlock(&try_read);

  printf("[Reader%d]: Read value: %d\n", thread_id, data);

  printf("[Reader%d]: Waiting to acquire lock for decrementing n_reader\n",
         thread_id);
  pthread_mutex_lock(&n_reader_lock);

  printf("[Reader%d]: Updating n_reader\n", thread_id);
  --n_reader;
  if (n_reader == 0) {
    printf("[Reader%d]: No readers left. Unlocking write lock\n", thread_id);
    sem_post(&write_lock);
  }

  printf("[Reader%d]: Unlocking n_reader lock\n", thread_id);
  pthread_mutex_unlock(&n_reader_lock);
}

// Writer function
void *writer_start_routine(void *tid) {
  int thread_id = *((int *)tid);

  printf("[Writer%d]: Waiting to acquire lock for incrementing n_writer\n",
         thread_id);
  pthread_mutex_lock(&n_writer_lock);

  printf("[Writer%d]: Updating n_writer\n", thread_id);
  ++n_writer;
  if (n_writer == 1) {
    printf("[Writer%d]: First reader. Acquiring n_reader lock\n", thread_id);
    pthread_mutex_lock(&try_read);
  }

  printf("[Writer%d]: Unlocking n_writer lock\n", thread_id);
  pthread_mutex_unlock(&n_writer_lock);

  printf("[Writer%d]: Waiting for write lock\n", thread_id);
  sem_wait(&write_lock);

  printf("[Writer%d]: Write lock acquired. Incrementing value\n", thread_id);
  ++data;

  printf("[Writer%d]: Unlocking write lock\n", thread_id);
  sem_post(&write_lock);

  printf("[Writer%d]: Waiting to acquire lock for decrementing n_writer\n",
         thread_id);
  pthread_mutex_lock(&n_writer_lock);

  printf("[Writer%d]: Updating n_reader\n", thread_id);
  --n_writer;
  if (n_writer == 0) {
    printf("[Writer%d]: No writer left. Unlocking n_reader lock\n", thread_id);
    pthread_mutex_unlock(&try_read);
  }

  printf("[Writer%d]: Unlocking n_writer lock\n", thread_id);
  pthread_mutex_unlock(&n_writer_lock);
}

int main() {
  pthread_t readers[NO_OF_READERS], writers[NO_OF_WRITERS];
  int reader_ids[NO_OF_READERS], writer_ids[NO_OF_WRITERS];

  sem_init(&write_lock, 0, 1); // Initializing the semaphore
  pthread_mutex_init(&n_reader_lock, 0);
  pthread_mutex_init(&n_writer_lock, 0);

  for (int i = 0; i < NO_OF_READERS; reader_ids[i++] = i);
  for (int i = 0; i < NO_OF_WRITERS; writer_ids[i++] = i);

  for (int i = 0; i < NO_OF_READERS; i++) pthread_create(
    &readers[i], 
    NULL, 
    reader_start_routine,
    (void *)&reader_ids[i]
  );

  for (int i = 0; i < NO_OF_WRITERS; i++) pthread_create(
    &writers[i], 
    NULL, 
    writer_start_routine,
    (void *)&writer_ids[i]
  );

  for (int i = 0; i < NO_OF_READERS; i++)
    pthread_join(readers[i], NULL);
  for (int i = 0; i < NO_OF_WRITERS; i++)
    pthread_join(writers[i], NULL);

  return 0;
}