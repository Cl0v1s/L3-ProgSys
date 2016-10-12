#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
   // printf("%s\n", argv[1]);
    int file = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    char data;
    while(read(0, &data, sizeof(char)) > 0)
    {
        write(file, &data, sizeof(char));
        write(1, &data , sizeof(char));
    }
    close(file);
}