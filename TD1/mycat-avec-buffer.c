#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	// Récupération de la taille des données sur l'entrée standard
	unsigned int real_size; 
	unsigned int size = lseek(0, 0, SEEK_END);
	lseek(0,0,SEEK_SET);
	printf("Lecture de %d octets\n", size);
	// Créationdu buffer de tampon 
	char *data = malloc(size+1);
	// lecture des données en entrée standard 
	real_size = fread(data, sizeof(char), size, stdin);
	printf("%d octets lus\n", real_size);
	// Ecriture des données sur la sortie standard 
	real_size = fwrite(data, sizeof(char), size, stdout);
	printf("%d octets écrits\n", real_size);


}