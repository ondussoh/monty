#include "monty.h"
/**
  * _swap - swaps the top two elements of the stack
  * @head: head of the stack
  * @line_number: the line number
  *
  * Return: Nothing
  */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *curr;
	int len = 0, temp;

	curr = (*head);

	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: cant't swap, stack too short\n", line_number);
		fclose(book.file);
		free(book.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	curr = *head;
	temp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = temp;
}
