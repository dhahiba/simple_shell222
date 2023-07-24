#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0

#define B -1
#define W 1024
#define R 1024
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
extern char **environ;

/**
 * struct link_l - ...
 * @n: ...
 * @s:...
 * @next: ..
 */
typedef struct link_l
{
	char *s;
	int n;
	struct link_l* next;
} link_l;

/**
 * struct inf_t - list of argements
 * @path: a string
 * @argv: an array of stings
 * @arg: a string
 * @environ: an array of string
 * @fname: a string
 * @cmd_buf: an arry of strings
 * @linecount_flag: integer
 * @argc: integer
 * @line_count: integer
 * @err_num: integer
 * @readfd: integer
 * @histcount: integer
 * @env_changed: integer
 * @status: integer
 * @cmd_buf_type: integer
 * @env: linked list
 * @alias: linked list
 * @historynked list
 */
typedef struct inf_t
{
	char *path;
	char **argv;
	char *arg;
	char **environ;
	char *fname;
	char **cmd_buf;
	int linecount_flag;
	int argc;
	unsigned int line_count;
	int err_num;
	int readfd;
	int histcount;
	int env_changed;
	int status;
	int cmd_buf_type;
	link_l *history;
	link_l *alias;
	link_l *env;
} inf_t;

#define INF_I \
{NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0,\
	0, 0, 0, 0, NULL, NULL, NULL}
/**
 * struct buil_t - ...
 * @t: ...
 * @f: ....
 */
typedef struct buil_t
{
	char *t;
	int (*f)(inf_t *);
} buil_t;
/* chaine1.c */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
/* chaine2.c */
int _strcmp(char *s1, char *s2);
char *strwith(const char *ch1, const char *ch2);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
/* chaine3.c */
char *_strchr(const char *s, int ch);
int find_b(inf_t *f);
void f_cmd(inf_t *f);
void fork_cmd(inf_t *f);
/* func_list */
link_l *add_node(link_l **head, char *str, int n);
link_l *add_node_end(link_l **head, char *str, int n);
size_t print_list_str(const link_l *h);
int delete_node_at_index(link_l **head, unsigned int index);
void free_list(link_l **head);
/* func_list2.c */
size_t list_len(const link_l *h);
char  **list_to_string(link_l *h);
size_t print_listint(const link_l *h);
link_l *node_starts_with(link_l *node, char *pr, char c);
ssize_t get_node_index(link_l *h, link_l *n);
/* func_mum.c */
void ffree(char **p);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);
int bfree(void **p);
/* functions1.c */
int _isalpha(int c);
int is_delim(char c, char *d);
int _inter(inf_t *f);
void print_error(inf_t *f, char *s);
int read_h(inf_t *f);
/* functions2.c */
int _unsetenv(inf_t *f, char *v);
int _setenv(inf_t *f, char *v, char *vl);
char *get_history_file(inf_t *f);
int renumber_history(inf_t *f);
int b_history(inf_t *f, char *b, int l);
/*functios3.c */
char **get_environ(inf_t *f);
char *_getenv(inf_t *f, const char *n);
int _myenv(inf_t *f);
int _mysetenv(inf_t *f);
int _myunsetenv(inf_t *f);
/* main_shell.c */
int main_shell(inf_t *f, char **s);
void free_inf(inf_t *f, int l);
void clear_info(inf_t *f);
void set_info(inf_t *f, char **a);
/* write_h.c */
int write_h(inf_t *f);
void _sigintHandler(__attribute__((unused))int s);
ssize_t read_buf(inf_t *f, char *b, size_t *n);
int _getline(inf_t *f, char **pr, size_t *l);
int _mycd(inf_t *f);
/* func1.c */
int _eputchar(char c);
int _putfd(char c, int f);
int _putsfd(char *s, int f);
ssize_t input_buf(inf_t *f, char **b, size_t *l);
ssize_t get_input(inf_t *f);
/* func2.c */
int _erratoi(char *s);
int print_d(int n, int f);
char *convert_number(long int n, int b, int f);
void remove_comments(char *b);
void eputs(char *s);
/* func3.c */
int replace_string(char **ch, char *n);
int replace_alias(inf_t *f);
void check_chain(inf_t *f, char *b, size_t *p, size_t i, size_t l);
int replace_vars(inf_t *f);
int _atoi(char *s);
/* func4.c */
char **strtow(char *s, char *d);
char **strtow2(char *s, char d);
int is_chain(inf_t *f, char *b, size_t *p);
/* path1.c */
int set_alias(inf_t *f, char *s);
int unset_alias(inf_t *f, char *s);
int _myhistory(inf_t *f);
int _myhelp(inf_t *f);
int _myexit(inf_t *f);
/* path2.c */
char *find_path(inf_t *f, char *p, char *c);
char *dup_chars(char *p, int s, int t);
int is_cmd(inf_t *f, char *p);
int _myalias(inf_t *f);
int print_alias(link_l *n);
#endif
