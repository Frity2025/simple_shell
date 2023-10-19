#include "shell.h"
/**
 * fun - helps to pass arg from shell
 * @argv: arguments 
 *
 * Return: nothing
 */
void fun(char **argv)
{
	int count = fork();
        switch (count)
	{
		case '-1':
			perror("(Input is wrong) ");
		case '0':
			{
				if (argv != NULL)
				{
					if (execve(loc_search(argv[0]), argv, NULL) == -1)
						exit(1);
				}
			}
		default:
			{
				wait(&i);
			}
	}
}
/**
 * loc_search - full path of command is searched
 * @command: command to be searched
 *
 * Return: the command path
 */
char *loc_search(char *command)
{
	int a, num;
	char **buf, *newbuf, *new_file;
	struct stat statbuf;

	if (stat(cmnd, &statbuf) == 0)
		return (cmnd);
	newbuf = getenv("buf");
	if (newbuf != NULL)
	{
		for (i = 0, num = 1; newbuf[i] != '\0'; i++)
			if (newbuf[i] == ':')
				num ++;
		buf = _tokenization(newbuf, ':', num);
		for (i = 0; buf[i] != NULL; i++)
		{
			new_file = malloc(strlen(command) + strlen(buf[i]) + 2);
			strcpy(new_file, buf[i]);
			strcat(new_file, "/");
			strcat(new_file, command);
			strcat(new_file, "\0");
			if (stat(new_file, &statbuf) == 0)
			{
				return (new_file);
			}
			free(new_file);
		}
		return ("NULL");
	}
	return (NULL);
}
/**
 * _tokenization - it splits the string based on the delimiter
 * @str: string to be inputed
 * @delimiter: the string dividing criteria
 * @len: length of str
 *
 * Return: tokens
 */
char **_tokenization(char *str, char delimiter, int length)
{
	int i, j, count;
	char **buf, *s;

	buf_new = malloc(sizeof(char *) * length);
	i = 0;
	count = 0;
	
	while (str[i + 1] != '\0')
	{
		if (str[i] == delimiter)
			continue;
		s = malloc(sizeof(char *));
		for (j = 0; !(str[i + 1] == '\0' || str[i] == delimiter); j++, i++)
			s[j] = str[i];
		buf_new[count] = malloc(sizeof(char) * strlen(s));
		strcpy(buf_new[count], s);
		i++;
		count++;
		free(s);
	}
	buf_new[count] = NULL;
	return (buf_new);
}
