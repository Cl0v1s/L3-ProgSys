#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define FILENAME "temp"

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Too few args\n");
        exit(1);
    }

    int fk = fork();
    // Lancement de la première commande
    if(fk == 0)
    {
        int temp = open(FILENAME, O_CREAT | O_TRUNC | O_WRONLY, 0666);
        dup2(temp, 1); // On remplace la sortie standard par le fichier ouvert 
        execlp(argv[1], argv[1], NULL);
    }
    // On continue le code du père qui attends la fin de la première commande pour lancer la deuxième
    wait(NULL);
    fk = fork();
    // Lancement de la seconde commande
    if(fk == 0)
    {
        int temp = open(FILENAME, O_RDONLY);
        dup2(temp, 0);
        execvp(argv[2], argv+2);
    }
    wait(NULL);
    
}