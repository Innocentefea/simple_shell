#include "shell.h"

/**
 * main - prints line using get line
 * Return: 0
 */
int main(void)
{
	char *line = NULL;

	line = _getline(stdin, line);

	printf("%s\n", line);

	free(line);

	return (0);
}