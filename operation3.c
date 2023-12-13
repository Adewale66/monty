#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	current->next->n %= current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	new_node_n = 0;
}
