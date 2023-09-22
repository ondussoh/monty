#include "monty.h"
#include <stdio.h>

/**
  * main - entry point
  * @argc: argument count
  * @argv: argument vector
  * Return: 0 success, 1 fail
  */
int main(int argc, char *argv[])
{
	bus_t book = {NULL, NULL, NULL, 0};
	FILE *fptr;
	ssize_t chars_rd;
	size_t bytsz;
	char *lineptr;
	unsigned int lc = 0;
	stack_t *stack = NULL;

	chars_rd = 1;
	bytsz = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	book.file = fptr;
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (chars_rd > 0)
	{
		lineptr = NULL;
		chars_rd = getline(&lineptr, &bytsz, fptr);
		book.content = lineptr;/*store the line(opcode in stack)*/
		lc++;
		if (chars_rd > 0)
		{
			_ext(lineptr, &stack, lc, fptr);
		}
		free(lineptr);
	}
	free_stack(stack);
	fclose(fptr);
	return (0);
}
