#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

void handle_signal(int signal);
int _error(char *program_name, int prompt_count, char *failing_command);

int exit_function(char **args);
void print_environment(char **env);

char **find_executable_path(char *found_path);
char *get_environment_variable(char *name, char **env);
char *find_executable_command(char **directories, char *command);
int execute_child_process(char **program_name, char **arguments, char **environ, int status, int prompt_count);
int access_file(char *filename);

char *concatenate_strings(char *destination, char *source);
char *copy_string(char *destination, char *source);
int measure_string_length(const char *string);
int compare_strings(char *string1, char *string2);
char *duplicate_string(char *source);
char *integer_to_string(int number, int base);

char *read_input(void);
char **tokenize_input(char *line, char **env);
int execute_command(char **arguments, char **argv, int prompt_count, char *input_line, char **env);
void print_prompt(void);

void *reallocate_memory(void *pointer, unsigned int new_size);
int count_periods(char *buffer);

void *allocate_memory(unsigned int num_elements, unsigned int element_size);
char **get_path_directories(char **environ);
int check_file_status(char **commands, char **directories);
char *string_concatenate(char *s1, char *s2);
void display_string(char *str);
int print_character(char c);

#endif
