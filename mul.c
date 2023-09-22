#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, xt;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(book.file);
		free(book.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	xt = temp->next->n * temp->n;
	temp->next->n = xt;
	*head = temp->next;
	free(temp);
}
