#include "monty.h"

/**
 * check_number - checks if a string is a number
 * @number: string to check
 * Return: number or INVALID_OPCODE if not a number
 */
int check_number(char *number)
{
	int i = 0;

	if (number == NULL)
		return (INVALID_OPCODE);
	if (number[0] == '-')
		i = 1;
	while (number[i] != '\0')
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
			return (INVALID_OPCODE);
		i++;
	}
	return (atoi(number));
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
		if (i == 2)
			break;
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * line_empty - checks if a line is empty
 * @line: line to check
 * Return: 1 if empty, 0 if not
 */

int line_empty(char *line)
{
	int i = 0;

	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			if (line[i] == '#')
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}
