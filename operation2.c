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
		global.n = INVALID_OPCODE;
		return;
	}
	current->next->n += current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	global.n = 0;
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
	global.n = 0;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	current->next->n -= current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	global.n = 0;
}

/**
 * divide - divides the second top element of the stack by the top element
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void divide(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	current->next->n /= current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	global.n = 0;
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	current->next->n *= current->n;
	*head = current->next;
	current->next->prev = NULL;
	free(current);
	global.n = 0;
}
