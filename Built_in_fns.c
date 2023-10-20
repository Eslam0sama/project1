#include "SimpleShell.h"

/**
 * print_environment - Prints the current environment variables
 * @environment: The environment variable
 */
void print_environment(char **environment)
{
	int index = 0;

	for (; environment[index] ; index++)
	{
		display_string(environment[index]); /* Print the entire environment */
	}
}
