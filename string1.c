#include "SimpleShell.h"

/**
 * display_string - Prints a string to the standard output
 * @str: The string to be displayed
 */
void display_string(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		print_character(str[index]);
	}
	print_character('\n');
}

/**
 * calculate_string_length - Computes the length of a string
 * @s: The string to measure
 * Return: The length of the string
 */
int calculate_string_length(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return length;
}

/**
 * print_character - Writes the character c to the standard output
 * @c: The character to print
 * Return: On success, it returns 1. On error, it returns -1, and errno is set appropriately.
 */
int print_character(char c)
{
	return write(1, &c, 1);
}

/**
 * concatenate_strings - Combines two strings and returns a dynamically allocated array
 * @s1: The first string
 * @s2: The second string
 * Return: A dynamically allocated array containing the concatenated strings
 */
char *concatenate_strings(char *s1, char *s2)
{
	char *result;
	unsigned int i, j, total_size;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	total_size = (calculate_string_length(s1) + calculate_string_length(s2) + 1);

	result = (char *)malloc(total_size * sizeof(char));

	if (result == 0)
	{
		return NULL;
	}

	for (i = 0; s1[i] != '\0'; i++)
	{
		result[i] = s1[i];
	}

	for (j = 0; s2[j] != '\0'; j++)
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';

	return result;
}

/**
 * compare_strings - Compare two strings
 * @string1: The first string
 * @string2: The second string
 * Return: An integer less than, equal to, or greater than zero if string1 is found, respectively, to be less than, to match, or be greater than string2.
 */
int compare_strings(char *string1, char *string2)
{
	char *pointer1 = string1;
	char *pointer2 = string2;

	while (*pointer1 != '\0' && *pointer2 != '\0' && *pointer1 == *pointer2)
	{
		pointer1++;
		pointer2++;
	}
	return (*pointer1 - *pointer2);
}
