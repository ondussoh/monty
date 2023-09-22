#include "monty.h"
/**
  * _push - add node to stack
  * @head: head of stack
  * @ln: line number
  * Return: no return
  */
void _push(stack_t **head, unsigned int ln)
{
	int n, j = 0, flag = 0;

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
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			fclose(book.file);
			free(book.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
			fclose(book.file);
			free(book.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
	}
	n = atoi(book.arg);
	if (book.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
