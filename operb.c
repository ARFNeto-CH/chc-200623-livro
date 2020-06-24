#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv)
{
	char operador[80];
	char delimitador[4];
	int n = scanf("%[+-/*]%c", operador, delimitador);
	if (n != 2)	return -1;
	int operando = 0, total = 0, res = 0;
	while ( (n = scanf("%d%c", &operando, delimitador)) == 2)
	{	// le e opera
		switch (operador[0])
		{
		case '+':
			res = res + operando;
			break;
		case '-':
			if (total==0)
				res = operando;
			else
				res = res - operando;
			break;
		case '*':
			if (total == 0)
				res = operando;
			else
				res = res * operando;
			break;
		case '/':
			if (total == 0)
				res = operando;
			else
				res = res / operando;
			break;
		};	// switch()
		total += 1;
		if (delimitador[0] == '\n') break;
	};
	if (total > 0)	printf(	"%d\n", res);
	return 0;
};
// fim