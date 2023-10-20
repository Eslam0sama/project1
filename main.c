#include "SimpleShell.h"

/**
 * main - Creates a prompt that reads input, parses it, executes, and waits
 * for another command unless told to exit.
 * @ac: Number of arguments
 * @av: Array of arguments
 * @env: Environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *input_line;
	char **arguments, **directories;
	int prompt_count = 0, status = 0;
	(void)av;
	signal(SIGINT, handle_signal);

	while (1)
	{
		print_prompt();

		/* Read input and return a string */
		input_line = read_input();

		/* Separate the string to get the command and arguments */
		arguments = tokenize_input(input_line, env);

		if (compare_strings(arguments[0], "\n") != 0 && compare_strings(arguments[0], "env") != 0)
		{
			prompt_count += 1;
			directories = get_path_directories(env); /* Find PATH in the environment variable */
			status = check_file_status(arguments, directories);
			execute_child_process(av, arguments, env, status, prompt_count);
		}
		else
		{
			free(arguments);
		}
		free(input_line);
	}

	return EXIT_SUCCESS;
}
