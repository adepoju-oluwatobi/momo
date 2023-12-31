#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <str.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

/**
 * struct stack_element - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_element
{
	int n;
	struct stack_element *prev;
	struct stack_element *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruct_t;


/**
 * struct glob_variable - golbal variableiables
 * @file: file name
 * @buff: Getline buffer
 * @temp: Getline counter
 * @dictionary: instruction dictionaryionary
 * @head: pointer to list
 * @line_num: Stores file current line
 * @MODE: Program configuration stack or queue
 */
typedef struct glob_variable
{
	FILE *file;
	char *buff;
	size_t temp;
	instruct_t *dictionary;
	stack_t *head;
	unsigned int line_num;
	int MODE;
} variables;


extern variables variable;

/* ================================================================= */
/* man_file.c */
/* ================================================================= */
int start_variables(variables *variable);
instruct_t *create_instru();
int call_function(variables *variable, char *opcode);
void free_all(void);
int _isdigit(char *str);

/* ================================================================= */
/* op_funct.c */
/* ================================================================= */
void pall(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);

/* ================================================================= */
/* op_funct_2.c */
/* ================================================================= */
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void divi(stack_t **stack, unsigned int line_num);

/* ================================================================= */
/* op_funct_3.c */
/* ================================================================= */
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);

/* ================================================================= */
/* op_funct_4.c */
/* ================================================================= */
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
void stack(stack_t **stack, unsigned int line_num);
void queue(stack_t **stack, unsigned int line_num);


#endif
