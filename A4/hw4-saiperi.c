#include <stdio.h>
#include <stdio.h>
#include <pthread.h>

int value;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *inputThread(void * args) {
  FILE *input = fopen("hw4.in", "r");
  while(!feof(input)) {
    //printf("Thread locked.\n");
    fscanf(input, "%d\n", &value);
    pthread_mutex_lock(&mutex);
    printf("value: %d\n", value);
    //printf("Thread unlocked.\n");
    pthread_mutex_unlock(&mutex);
  }
  fclose(input);
  pthread_exit(NULL);
}

void *counting(void *args) {
  printf("Value: %d\n", value);
  pthread_exit(NULL);
}

int main() {

  //Creating thread1
  pthread_t pt1;
  pthread_create(&pt1, NULL, inputThread, NULL);

  //Creating thread2
  pthread_t pt2;
  pthread_create(&pt2, NULL, counting, NULL);

  //Joining thread1
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
}
