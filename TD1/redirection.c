#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


void verifier(int i, char *s)
{
  if (!i) {
    perror (s);
    exit (EXIT_FAILURE);
  }
}

void quelques_prints (void)
{
  printf ("Juste");
  printf (" histoire");
  printf (" de tester...\n");
  printf ("...que la redirection");
  printf (" marche !\n");
}

void rediriger_vers (void (*f)(void), char *file)
{
  int backup = dup(1); // On sauvegarde la sortie standard
  close(1); // fermeture de la sortie standard pour libérer une place dans la liste de sdescripteur 

  int filed = open(file, O_WRONLY | O_TRUNC | O_CREAT);

  f();

  close(filed); // fermeture du fichier 
  dup2(backup, 1); // restauration du descripteur de fichier 

}

int main(int argc, char *argv[])
{
  printf ("*** DEBUT ***\n");

  rediriger_vers (quelques_prints, "sortie.txt");

  printf ("*** FIN ***\n");

  return EXIT_SUCCESS;
}
  
