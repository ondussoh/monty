#include "monty.h"
/**
  * _pop - removes node at top of stack
  * @head: pointer to head of stack
  * @counter: number of lines
  *
  * Return: Nothing
  */
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(book.file);
		free(book.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = (*head);
	(*head) = h->next;
	free(h);
}
