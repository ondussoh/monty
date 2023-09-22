#include "monty.h"
/**
  * _add - adds the top two elements of the stack
  * @head: head of the stack
  * @line_number: no of lines
  *
  * Return: nothing
  */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int len = 0, a;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(book.file);
		free(book.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	a = (temp->n + temp->next->n);
	temp->next->n = a;
	*head = temp->next;
	free(temp);
}
