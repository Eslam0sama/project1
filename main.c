#include "simpleshell.h"

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

		if (arguments[0] != NULL && compare_strings(arguments[0], "\n") != 0 && compare_strings(arguments[0], "env") != 0)
		{
			prompt_count += 1;
			directories = get_path_directories(env); /* Find PATH in the environment variable */
			status = check_file_status(arguments, directories);
			execute_child_process(arguments[0], arguments, env, status, prompt_count);
		}
		else
		{
			free(arguments);
		}
		free(input_line);
	}

	return EXIT_SUCCESS;
}
