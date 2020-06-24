#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char**argv)
{	char arq[80], ext[80], delim[4];
	int  n = 0;
	FILE* ent = fopen("listagem.txt", "r");
	while ((n = fscanf(ent, "%[^.]%[^,\n]%c", arq, ext, delim)) == 3)
		printf("'%s'\t\tExtensao: '%s' (delim: %d)\n", arq, ext, delim[0]);
};