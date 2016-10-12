#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char* filename = argv[1];
    double data;


    int file = open(filename, O_RDONLY);

    while(read(file, &data, sizeof(double)) > 0)
    {
        printf("%f\n", data);
    }
    close(file);
}