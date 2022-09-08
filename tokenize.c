#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * n_toks - get number of token
 *
 * @str: string to tokenize
 *
 * Return: Number of tokens
 *
 */

int no_toks(char *str, char *delim)
{
	int i = 0;
	char *token;

	if (str == NULL)
	{
		return (0);
	}
	token = strtok(str, delim);
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}
	return (i);
}


/**
 * tokenize - tokenize a a line read
 *
 * @line_read: string to tokenize
 *
 * Return: array of tokens got
 *
 */

char **tokenize(char *str, char *delim)
{
	char *token = NULL;
	char **tokens;
	char *str_cpy = NULL;
	int i = 0;
	int no_token;

	str_cpy = malloc(sizeof(char ) * strlen(str));
	str_cpy = strdup(str);
	no_token = no_toks(str_cpy, delim);
	printf("%d\n", no_token);
	tokens = malloc(sizeof(char ) * no_token);
	token  = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = (char *)malloc(sizeof(char ) * strlen(token));
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(token);
	free(str_cpy);
	tokens[i] = NULL;
	return (tokens);
}


void main ()
{
	char str[30] = "Welcome to 50 School";
	char **token;
	int i = 0;

	
	token = tokenize(str);
	while (token[i] != NULL)
	{
		printf("%s\n", token[i]);
		free(token[i]);
		i++;
	}
	free(token);
	/* NEED TO FREE - TOKEN */
	printf("GET HERE\n");
}