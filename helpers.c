#include "monty.h"

/**
 * check_number - checks if a string is a number
 * @number: string to check
 * Return: 0 if number, 1 if not
 */
int check_number(char *number)
{
	int i = 0;

	if (number == NULL)
		return (1);
	if (number[0] == '-')
		i = 1;
	while (number[i] != '\0')
	{
		if (isdigit(number[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_stack - frees a stack
 * @head: pointer to the head of the stack
 * Return: void
 */

void free_stack(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * tokenize - tokenizes a line
 * @line: line to tokenize
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	char *token = NULL;
	char **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
