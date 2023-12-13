#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	if (new_node_n == INVALID_OPCODE)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		free_stack(head);
		return;
	}
	new_node->n = new_node_n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * pall - prints all the values on the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
	new_node_n = 0;
}
