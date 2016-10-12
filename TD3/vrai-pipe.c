#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int desc[2];
    pipe(desc);

    int fk = fork();
    if(fk == 0)
    {
        close(desc[0]);
        dup2(desc[1], 1);
        execlp(argv[1], argv[1], NULL);
    }
    fk = fork();
    if(fk == 0)
    {
        close(desc[1]);
        dup2(desc[0], 0);
        execvp(argv[2], argv+2);
        
    }
    // Fermeture du pipe pour le père
    close(desc[0]);
    close(desc[1]);
    wait(NULL);
    wait(NULL);
    

}