#include "monty.h"
/**
  * _pint - prints element top of the stack
  * @stack: stack
  * @counter: line counter
  *
  * Return: Nothing
  */
void _pint(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", counter);
		fclose(book.file);
		free(book.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
