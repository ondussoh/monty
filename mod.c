#include "monty.h"
/**
  * mod - modulo
  * @head: head of the stack
  * @line_number: number of the line
  *
  * Return: Nothing
  */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *t;
	int len = 0;

	t = *head;
	while (t)
	{
		t = t->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(book.file);
		free_stack(*head);
		free(book.content);
		exit(EXIT_FAILURE);
	}
	t = *head;
	len = (t->next->n % t->n);
	t->next->n = len;
	(*head) = t->next;
	free(t);
}
