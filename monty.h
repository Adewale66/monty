#ifndef __MONTY__
#define __MONTY__

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#ifdef DEFINE_GLOBAL
#define EXTERN
#define INIT(A) = (A)
#else
#define EXTERN extern
#define INIT(A)
#endif

/* global variable */
EXTERN int new_node_n INIT(-1);

/* Function Prototypes */
void parse(FILE *file);
char **tokenize(char *line);
void get_opcode(stack_t **head, unsigned int line_num, char *line, FILE *file);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
int check_number(char *number);
void free_stack(stack_t **head);
int execute(char **tokens, stack_t **head, unsigned int line_num, char *line);

#endif /* __MONTY__ */
