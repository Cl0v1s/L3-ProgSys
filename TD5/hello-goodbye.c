#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *HelloGoodbye(void *p)
{
  printf("%lu: bonjour\n", pthread_self()); 
  sleep(1);
  printf("%lu: a bientot\n", pthread_self()); 

  return NULL;
}

int 
main(int argc, char *argv[])
{
  int nb = atoi(argv[1]);

  pthread_t* threads;
  threads = malloc(sizeof(pthread_t)*nb);

  for(int i = 0; i != nb; i++)
  {
    printf("Création thread %d...\n", i);
    pthread_create(&threads[i], NULL, HelloGoodbye, NULL);    
  }

  for(int i = 0; i!= nb; i++)
  {
    pthread_join(threads[i], NULL);
  }

  return EXIT_SUCCESS;
}
