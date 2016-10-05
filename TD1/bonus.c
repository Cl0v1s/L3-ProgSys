#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	if(argc < 5)
	{
		printf("Too few arguments\n");
		return 0;
	}

	// Déclaration des variables
	int input1; 
	int input2;
	int output;
	int total_size = 0;
	int size = 0;
	unsigned int position =  atoi(argv[4]);
	char buffer;

	// ouverture des fichiers
	input1 = open(argv[1], O_RDONLY);
	input2 = open(argv[2], O_RDONLY);
	output = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC);

	// Ecriture de la première partie 
	size = read(input1, &buffer, sizeof(char));
	total_size += size;
	while(total_size < position && size >0)
	{
		write(output, &buffer, sizeof(char));
		size = read(input1, &buffer, sizeof(char));
		total_size += size;
	}

	// Insertion du deuxième fichier 
	size = read(input2, &buffer, sizeof(char));
	while(size > 0)
	{
		write(output, &buffer, sizeof(char));
		size = read(input2, &buffer, sizeof(char));
	}

	// Ecriture de la fin du premier fichier 
	size = read(input1, &buffer, sizeof(char));
	while(size > 0)
	{
		write(output, &buffer, sizeof(char));
		size = read(input1, &buffer, sizeof(char));
	}

	// Fermeture des fichiers
	close(input1);
	close(input2);
	close(output);



}