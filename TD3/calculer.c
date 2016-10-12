#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define N 3

typedef double (*f_pointer)(double);


double f1(double a)
{
    return a+1;
}
double f2(double a)
{
    return a-1;
}
double f3(double a)
{
    return a*2;
}


int main(int argc, char** argv)
{
    // Définition du tableau des fonctions
    f_pointer g[N];
    g[0] = &f1;
    g[1] = &f2;
    g[2] = &f3;

    int fd[2];
    int fk;
    double data;
    char* inputname = argv[1];
    char* outputname = argv[2];

    pipe(fd);    

    // Initialisation de la chaine de valeurs dans le pipe
    printf("INIT\n");
    int input = open(inputname, O_RDONLY);
    while(read(input, &data, sizeof(double)) > 0)
    {
        printf("%f\n", data);
        write(fd[1], &data, sizeof(double));
    }


    // Lancement de la chaine 
    printf("CHAIN\n");
    for(int i = 0; i != N; i++)
    {
        fk = fork();
        if(fk == 0)
        {

            input = dup(fd[0]); // Création nouvelle entrée pour lire 
            close(fd[0]);

            while(read(input, &data, sizeof(double)) > 0)
            {
                printf("b: %f\n", data);
                data = g[i](data);
                printf("a: %f\n", data);
                write(fd[1], &data, sizeof(double));
            }
            close(input);
            close(fd[1]);
        }
        wait(NULL);
    }


}


