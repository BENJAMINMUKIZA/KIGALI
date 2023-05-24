#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/**
 * struct liststr - Linked list structures of a function inserted
 * @num: Number inputed
 * @str: String inserted
 * @next: Pointer to next node of a shell
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
/**
 * struct passinfo - A program to pass Information structure for shell
 * @arg: Argument of the program
 * @path: Path of the info
 * @argv: Argument vector of the functo
 * @argc: Argument count of the number
 * @err_num: Error number of the progr
 * @line_count: Line count of the program,
 * @linecount_flag: Line count flag used
 * @env: Environment list of gthe command line
 * @fname: File name of the function
 * @alias: Alias list of the command
 * @history: History list of the structured
 * @environ: Environment variables used
 * @status: Status of the pro
 * @env_changed: Environment changed flag inputed
 * @cmd_buf: Command buffer line of pro
 * @cmd_buf_type: Command buffer type of a progar
 * @readfd: Read file descriptor of the function
 * @histcount: History count of the histroy
 */

typedef struct passinfo
{
	char *arg;
	char *path;
	char **argv;
	int argc;
	int err_num;
	unsigned int line_count;
	int linecount_flag;
	list_t *env;
	char *fname;
	list_t *alias;
	list_t *history;
	char **environ;
	int status;
	int env_changed;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

extern char **environ;

int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void _eputs(char *);
int _eputchar(char);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow2(char *, char);
char **strtow(char *, char *);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _myexit(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
void remove_comments(char *str);

#endif
