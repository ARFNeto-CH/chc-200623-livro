#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char** argv)
{
	char arq[80], delim[4];
	int  n = 0;
	FILE* ent = fopen("rpn.txt", "r");

	printf("Entre operador [+-*/]: ");
	n = fscanf(ent, "%[+-/*]%c", arq, delim);
	if (n != 2)
	{
		printf("Nao conseguiu ler operador\n");
		return -1;
	};
	printf("Operador lido: '%c'\n", arq[0]);
	int oper = 0;
	int total = 0;
	printf("Lendo operandos: ");
	while ( (n = fscanf(ent, "%d%c", &oper, delim)) == 2)
	{
		printf(" %d", oper);
		total += 1;
	};
	printf("\nLidos %d operandos\n", total);
	return 0;
	//if( n > 0)

	//while ((n = fscanf(ent, "%[^.]%[^,\n]%c", arq, ext, delim)) == 3)
	//	printf("'%s'\t\tExtensao: '%s' (delim: %d)\n", arq, ext, delim[0]);
};