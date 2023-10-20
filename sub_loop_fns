#include "SimpleShell.h"

/**
 * parse_path - Identifies the path of the command (*args) being passed
 * @found_path: The command being passed to it
 * Return: The complete path of the command or NULL on failure
 */
char **parse_path(char *found_path)
{
	int size = TOK_BUFSIZE;
	int i = 0;
	char *copy_path = NULL;
	char *tokens = NULL;
	char *delimiter = ":=";
	char **directories = _calloc(sizeof(char *), size);

	if (found_path == NULL)
	{
		free(found_path);
		return NULL;
	}

	if (directories == NULL)
	{
		free(found_path);
		perror("Error allocating memory");
		return NULL;
	}

	copy_path = _strdup(found_path); /* Copy the string (PATH) */
	tokens = strtok(copy_path, delimiter); /* Split the string by a delimiter */
	while (tokens != NULL)
	{
		directories[i] = tokens;
		i++;
		tokens = strtok(NULL, delimiter);
	}

	return directories;
}

/**
 * execute_child - Executes a command if the path to it is an executable file
 * @av: Name of the program
 * @args: The command to be executed
 * @env: Environment variable
 * @main_status: Status variable
 * @count: Count of prompts
 * Return: 1
 */
int execute_child(char **av, char **args, char **env, int main_status, int count)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return -1;

	pid = fork();
	if (pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], count, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (main_status == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return 1;
}

/**
 * get_exec_paths - Retrieves the path to execute commands
 * @environ: Environment variable
 * Return: exec_paths
 **/
char **get_exec_paths(char **environ)
{
	int position = 0;
	char **exec_paths;

	for (; environ[position] != NULL; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			exec_paths = parse_path(environ[position]);
		}
	}
	return exec_paths;
}
