#include "shell.h"
/**
 * ptr_free -free two dimensional array
 * @argv: free two dimensional array.
 * @h: height of array
 *
 * Return: NULL
 */
void ptr_free(char **argv, int h)
{
	int a = 0;

	while (a < h)
	{
		free(argv[a]);
		a++;
	}
	free(argv);
}
