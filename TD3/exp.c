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

    char c = 'a';

    int ct = 0;
    int size = write(fd[1], &c, sizeof(char));
    ct += size;
    while(size > 0)
    {
        size = write(fd[1], &c, sizeof(char));
        ct += size;
        printf("Buffer pipe: %d octets\n", ct);
        
    }
    printf("End\n");
    close(fd[1]);
    close(fd[0]);

}