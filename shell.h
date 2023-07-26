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
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define min(x, y) (((x) < (y)) ? (x) : (y))
extern char **cmd;
extern char *l;
extern char *sn;
extern int s;
extern char **environ;
/**
 * struct map - ...
 * @cname: ...
 * @f: ....
 */
typedef struct map
{
	char *cname;
	void (*f)(char **command);
} f_map;
void execute_command(char **arguments);
int tokenize_command(char *command, char **arguments);
int _exite(int arg, char* argv[]);
char *_strtok(char *ch, char *d, char **sp);
int _atois(char *s);
void *_rllc(void *p, unsigned int sizep, unsigned int nsize);
void ctrlhandler(int snum);
void r_comment(char *ipt);
int p_command(char *cm);
void execute(char **tkn_cmd, int tcmd);
char *check_p(char *cm);
void (*_getfunc(char *cm))(char **);
char *get_env(char *n);
int cmp(char *s1, char *s2);
char *cat(char *s1, char *s2);
int _str_s(char *s1, char *s2);
int strcs(char *s1, char *s2);
char *strc(char *s1, char c);
char **_tokenizer(char *s1, char *s2);
void _print(char *s1, int s2);
void r_line(char *s1);
void _cpy(char *s1, char *dst);
int _len(char *s1);
void handle_mode(void);
void start(char **c, int tc);
void exite(char **tkc);
void env(char **tkc __attribute__((unused)));
#endif

