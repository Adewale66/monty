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
		if (line_empty(line) == 1)
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
	char **tokens = NULL;

	tokens = tokenize(line);
	if (tokens == NULL)
	{
		free_stack(head);
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	res = execute(tokens, head, line_num, line, file);
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
 * @ts: array of tokens
 * @head: head of the stack
 * @ln: line number
 * @line: parsed line
 * @file: file to close
 * Return: 0 on success, 1 on failure
 */

int execute(char **ts, stack_t **head, unsigned int ln, char *line, FILE *file)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(ts[0], opcodes[i].opcode) == 0)
		{
			new_node_n = check_number(ts[1]);
			opcodes[i].f(head, ln);
			if (new_node_n == INVALID_OPCODE)
			{
				free(ts);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			free(ts);
			return (0);
		}
		i++;
	}
	return (1);
}
