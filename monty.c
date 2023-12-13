#define DEFINE_GLOBAL
#include "monty.h"

/**
 * parse - parses a file for monty opcodes
 * @file: file to parse
 * Return: void
 */
void parse(FILE *file)
{
	size_t buffer_size = 0;
	unsigned int line_number = 0;
	stack_t *head = NULL;
	char *line = NULL;

	while (getline(&line, &buffer_size, file) != -1)
	{
		line_number++;
		if (line[0] == '\n')
			continue;
		get_opcode(&head, line_number, line, file);
	}
	free(line);
	free_stack(&head);
}

/**
 * get_opcode - gets the opcode
 * @head: head of the stack
 * @line_num: line number
 * @line: line to parse
 * @file: file to parse
 * Return: void
 */
void get_opcode(stack_t **head, unsigned int line_num, char *line, FILE *file)
{

	int res = 0;
	char **tokens = tokenize(line);

	if (tokens == NULL)
	{
		free_stack(head);
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	res = execute(tokens, head, line_num, line);
	if (res == 0)
		return;

	free_stack(head);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, tokens[0]);
	free(tokens);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * execute - executes the opcode
 * @tokens: array of tokens
 * @head: head of the stack
 * @line_num: line number
 * @line: parsed line
 * Return: 0 on success, 1 on failure
 */

int execute(char **tokens, stack_t **head, unsigned int line_num, char *line)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(tokens[0], opcodes[i].opcode) == 0)
		{
			if (tokens[1] && check_number(tokens[1]) == 0)
				new_node_n = atoi(tokens[1]);
			else
				new_node_n = -1;
			opcodes[i].f(head, line_num);
			if (new_node_n == -1)
			{
				free(tokens);
				free(line);
				exit(EXIT_FAILURE);
			}
			free(tokens);
			return (0);
		}
		i++;
	}
	return (1);
}
