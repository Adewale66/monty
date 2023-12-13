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

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(head);
		new_node_n = INVALID_OPCODE;
		return;
	}
	printf("%c\n", current->n);
	new_node_n = 0;
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *c = *head;

	(void)line_number;
	while (c != NULL && c->n != 0 && c->n >= 0 && c->n <= 127)
	{
		printf("%c", c->n);
		c = c->next;
	}
	printf("\n");
	new_node_n = 0;
}

/**
 * rot1 - rotates the stack to the top.
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void rot1(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int tmp;

	(void)line_number;
	if (current == NULL || current->next == NULL)
		return;
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
	new_node_n = 0;
}

/**
 * rotr - rotates the stack to the bottom.
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int tmp;

	(void)line_number;
	if (current == NULL || current->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	tmp = current->n;
	current->n = current->prev->n;
	current->prev->n = tmp;
	new_node_n = 0;
}
