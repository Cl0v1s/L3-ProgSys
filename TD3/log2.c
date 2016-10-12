#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int fd[2];
    pipe(fd);

    int fk = fork();
    // On lance le programme en écrivant sa sortie dans un tube
    if(fk == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        execvp(argv[2], argv+2);
    }
    close(fd[1]);
    fk = fork();
    if(fk == 0)
    {
        dup2(fd[0], 0);
        execlp("./tee.c.bin", "tee", argv[1], NULL);
    }
    close(fd[0]);
    wait(NULL);
    wait(NULL);
}