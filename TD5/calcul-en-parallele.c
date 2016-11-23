#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX  10000000

/*typedef struct {
  int start;
  int length; 
} block;*/

double resultat[MAX];
int nb_threads;

/*void *calcul(void *p)
{
  block *args = p;
  printf("start:%d\n", args->start);
  printf("end:%d\n", args->length+args->start);
  for(int i = args->start; i!= args->start + args->length; i++)
    resultat[i] = tan(atan((double)i));
  free(args);
}*/

void *calcul(void *p)
{
  int* index  = p;
  int target = *index % nb_threads;
  //printf("%d: Je calcule %d\n",*index, target);
  for(int i = target; i < MAX; i = i + nb_threads)
  {
    //printf("%d: calcule %d.\n", *index, i);
    resultat[i] = tan(atan((double)i));
    //sleep(1);
  }
  free(p);
}


int 
main(int argc, char *argv[])
{
  nb_threads = atoi(argv[1]);

  pthread_t *threads;
  threads = malloc(sizeof(pthread_t)*nb_threads);


  /* Distribution par thread
  int seq = MAX / nb_threads;
  int start = 0;
  for(int i = 0; i!= nb_threads; i++)
  {
    block *arg = malloc(sizeof(block));
    arg->start = start;
    arg->length = seq;
    if(i == nb_threads - 1) //Gestion des restes de la division
    {
      arg->length += MAX % nb_threads;
    }
    pthread_create(&threads[i], NULL, calcul, arg);
    start += seq;
  }*/

  for(int i = 0; i!= nb_threads; i++)
  {
    //printf("Lancement %d\n", i);
    int* index = malloc(sizeof(int));
    (*index) = i;
    pthread_create(&threads[i], NULL, calcul, index);
  }


  //for(int k=0; k < MAX; k++)
  //  resultat[k] = acos(cos((double)k)); 
 
  //attente des threads
  for(int i = 0; i != nb_threads; i++)
  {
    pthread_join(threads[i], NULL);
  }

  /*for(int i = 0; i!=MAX; i++)
  {
    printf("%d : %f\n", i, resultat[i]);
  }*/

  return EXIT_SUCCESS;
}
