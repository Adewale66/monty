#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	current->next->n += current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	new_node_n = 0;
}

/**
 * nop - does nothing
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	new_node_n = 0;
}
