#include "monty.h"
/**
  * sub - subtracts the top element
  * from second top element of stack
  * @head: head of the stack
  * @line_number: no. of line
  *
  * Return: Nothing
  */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int res = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	if (res < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_stack(*head);
		free(book.content);
		fclose(book.file);
		exit(EXIT_FAILURE);
	}
	temp = (*head);
	res = (temp->next->n - temp->n);
	(*head) = temp->next;
	(*head)->n = res;
	free(temp);
}
