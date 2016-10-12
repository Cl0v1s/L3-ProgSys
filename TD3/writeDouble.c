#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char* filename = argv[1];
    int k = atoi(argv[2]);

    int file = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    double data = 0;
    for(int i = 0; i!= k; i++)
    {
        write(file, &data, sizeof(double));
        data++;
    }

    close(file);

}