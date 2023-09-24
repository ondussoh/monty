#include "monty.h"
/**
  * _ext - executes the opcode
  * @stack: head of a linked list
  * @counter: line counter
  * @file: pointer to monty file
  * @content: line content
  * Return: 0 on success, 1 if failed
  */
int _ext(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t fops[] = {
				{"push", _push}, {"div", f_div},
				{"pall", _pall}, {"mul", f_mul},
				{"pint", _pint}, {"mod", mod},
				{"pop", _pop},
				{"nop", _nop},
				{"swap", _swap},
				{"add", _add}, {"sub", sub},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *ops;
	int flag = 0, j = 0;

	ops = strtok(content, " \n\t");
	if (ops && ops[0] == '#')
		return (0);

	book.arg = strtok(NULL, " \n\t");

	if (book.arg)
	{
		if (book.arg[0] == '-')
			j++;
		for (; book.arg[j] != '\0'; j++)
		{
			if (book.arg[j] < 48 || book.arg[j] > 57)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d:unknown instruction %s\n", counter, content);
			fclose(book.file);
			free(book.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	while (fops[a].opcode && ops)
	{
		if (strcmp(ops, fops[a].opcode) == 0)
		{
			fops[a].f(stack, counter);
			return (0);
		}
		a++;
	}
	if (ops && fops[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, ops);
			fclose(file);
			free(content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
	}
	return (1);
}
