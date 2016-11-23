#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int value;
  pthread_mutex_t mutex;
} secure_int;


const unsigned long MAX = 100 * 1000;

void *for_en_parallele(void *p)
{
  secure_int *data = p;
  pthread_mutex_lock(&(data->mutex));
  for(unsigned long i=0; i < MAX; i++)
    data->value++;
  pthread_mutex_unlock(&(data->mutex));


  return NULL;
}

int 
main(int argc, char *argv[])
{

  int n = atoi(argv[1]);
  pthread_t tids[n];

  secure_int data;
  pthread_mutex_init(&data.mutex, NULL);
  data.value = 0;
 
  for(int i = 0; i <n ; i++)
    pthread_create(tids + i, NULL, for_en_parallele, &data);

  for(int i = 0; i <n ; i++)
    pthread_join(tids[i],NULL);

  printf("%d\n",data.value);

  pthread_mutex_destroy(&data.mutex);

  return EXIT_SUCCESS;
}
