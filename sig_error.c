#include "SimpleShell.h"

/**
 * display_interrupt_message - Displays a new line and prompt when CTRL + C is pressed
 * @signal: The name of the signal
 */
void display_interrupt_message(int signal)
{
	char *interrupt_message = {"\n[INTERRUPT] "};
	(void) signal;

	write(STDOUT_FILENO, interrupt_message, _strlen(interrupt_message));
	fflush(stdout);
}

/**
 * log_command_error - Logs an error message to the standard error output
 * @program_name: Name of the program
 * @prompt_sequence: Number of the prompt
 * @failing_command: Command to be included in the error message
 * Return: 0 on success
 */
int log_command_error(char *program_name, int prompt_sequence, char *failing_command)
{
	char *sequence_str;

	sequence_str = _itoa(prompt_sequence, 10);

	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, sequence_str, _strlen(sequence_str));
	write(2, ": ", 2);
	write(2, failing_command, _strlen(failing_command));
	perror(" ");

	return 0;
}

/**
 * find_executable_file - Locates the executable file and checks its status
 * @commands: Array with commands
 * @directories: Locations of each directory
 * Return: 1 on success
 **/
int find_executable_file(char **commands, char **directories)
{
	char *concatenated_directory = NULL, *new_concatenation = NULL;
	int count;

	struct stat file_status;

	if (directories == NULL)
	{
		free(directories);
		free(commands);
		return 0;
	}

	for (count = 0; directories[count] != NULL ; count++)
	{
		concatenated_directory = str_concat(directories[count], "/");
		new_concatenation = str_concat(concatenated_directory, commands[0]);
		if (stat(new_concatenation, &file_status) == 0 && (file_status.st_mode & S_IXUSR))
		{
			commands[0] = new_concatenation;
			free(concatenated_directory);
			free(directories[0]);
			free(directories);
			return 1;
		}
		free(concatenated_directory);
		free(new_concatenation);
	}
	free(directories[0]);
	free(directories);
	return 0;
}
