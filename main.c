#include "shell.h"
/**
 * main - simple shell program
 *
 * Return: Success 0
 */
int main(void)
{
	char **argv, *command_in;
	int argc, getl_out, i = 0;
	size_t n;

	while (1)
	{
	printf("(sudoshell) $ ");
	getl_out = getline(&command_in, &n, stdin);
	if (getl_out == -1)
	{
		printf("\n\n[Disconnected...]\n");
		return (-1);
	}
	for (argc = 1; command_in[i + 1] != '\0'; i++)
	{
		if (command_in[i] != ' ' && command_in[i - 1] == ' ')
			argc++;
	}
	argv = malloc(sizeof(char) * argc);
	argv = _tokenization(command_in, ' ', argc);
	fun(argv);
	}
	ptr_free(argv, argc);
	free(command_in);
	return (0);
}
