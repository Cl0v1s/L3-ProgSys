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
    // On va écrire ce qui se trouve dans ce tube à la fois dans la sortie standard et dans le fichier
    int file = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    
    char data;
    while(read(fd[0], &data, sizeof(char)) > 0)
    {
        write(file, &data, sizeof(char));
        write(1, &data , sizeof(char));
    }
    close(fd[0]);
    close(file);
    wait(NULL);
    




}