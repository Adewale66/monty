#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void queue(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	global.type = 1;
	global.n = 0;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void stack(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
	global.type = 0;
	global.n = 0;
}

/**
 * push_stack - pushes an element to the stack
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void push_stack(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	if (global.n == INVALID_OPCODE)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		free_stack(head);
		return;
	}
	new_node->n = global.n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * push_queue - pushes an element to the queue
 * @head: pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void push_queue(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		global.n = INVALID_OPCODE;
		return;
	}
	if (global.n == INVALID_OPCODE)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		free_stack(head);
		return;
	}
	new_node->n = global.n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}
