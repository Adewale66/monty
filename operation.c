#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void push(stack_t **head, unsigned int line_number)
{
	if (global.type == 0)
		push_stack(head, line_number);
	else
		push_queue(head, line_number);
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
	global.n = 0;
}

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	printf("%d\n", current->n);
	fflush(stdout);
	global.n = 0;
}

/**
 * pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	*head = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
	global.n = 0;
}

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int temp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
	global.n = 0;
}
