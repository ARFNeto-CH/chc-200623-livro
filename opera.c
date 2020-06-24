#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int opera(char, int, int, int); 

int main(int argc, char** argv)
{
	char arq[80];
	char delim[4]; // delimitador
	int  n = 0;
	const char* sc_operador = "%[+-/*]%c";
	const char* sc_operandos = "%d%c";
	
	printf("Entre operador [+-*/]: ");
	n = scanf(sc_operador, arq, delim);
	if (n != 2)
	{
		printf("Nao conseguiu ler operador\n");
		return -1;
	};
	printf("Operador lido: '%c'\n", arq[0]);
	int operando = 0; // operador
	int total = 0;
	int res = 0;
	printf("Lendo operandos: ");
	while ((n = scanf(sc_operandos, &operando, delim))==2)
	{
		res = opera(arq[0], operando, res, total);
		//printf("Operando %d: %d\n", 1 + total, operando);
		total += 1;
		if (delim[0] == '\n') break;
	};
	printf("\nLidos %d operandos\n", total);
	if(total>0)
	    printf(
			"\nOp: [%c] Total acumulado para os %d operandos = %d\n",
		arq[0], total, res);
	return 0;
};

int opera(char op, int A, int B, int ind)
{	// executa a operacao e retorna o total
	switch (op)
	{
	case '+':
		return(A + B);
		break;
	case '-':
		if (!ind) B = A, A = 0;
		return(B - A);
		break;
	case '*':
		if (!ind) B = 1;
		return(A * B);
		break;
	case '/':
		if (!ind) B = A, A = 1;
		return(B / A);
		break;
	};	// switch()
	return 0;
};	// opera()
