#include "monty.h"
/**
  * _pall - prints all elements
  * @head: head of stack
  * @counter: line number
  * Return: Nothing
  */
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;
	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
