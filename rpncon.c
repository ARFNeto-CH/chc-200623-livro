#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char** argv)
{
	char arq[80]; 
	char delim[4]; // delimitador
	int  n = 0;
	const char* sc_operador = "%[+-/*]%c";
	const char* sc_operandos = "%d%c";

	printf("Entre operador [+-*/]: ");
	n = scanf( sc_operador, arq, delim);
	if (n != 2)
	{	printf("Nao conseguiu ler operador\n");
		return -1;
	};
	printf("Operador lido: '%c'\n", arq[0]);
	int oper = 0; // operador
	int total = 0; 
	printf("Lendo operandos: ");
	n = scanf(sc_operandos, &oper, delim);
	while (n == 2)
	{
		printf("Operando %d: %d\n", 1 + total, oper);
		total += 1;
		if (delim[0] == '\n') break;
		n = scanf(sc_operandos, &oper, delim);
	};
	printf("\nLidos %d operandos\n", total);
	return 0;
};