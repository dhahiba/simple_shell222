#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))
/**
 *struct map - a struct that maps a command name to a function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct map
{
        char *cname;
        void (*f)(char **command);
} func;
extern char **ev;
extern char *l;
extern char **cmd;
extern char *sn;
extern int s;
extern char **envi;
char *_strtok(char *string, char *delim, char **sp);
int _atois(char *s);
void *_rllc(void *p, unsigned int sizep, unsigned int nsize);
void ctrlhandler(int snum);
int cmp(char *s1, char *s2);
char *cat(char *s1, char *s2);
int _str_(char *s1, char *s2);
int strcs(char *s1, char *s2);
char *strc(char *s1, char c);
char **_tokenizer(char *s1, char *s2);
void _print(char *s1, int s2);
void r_line(char *s1);
void _strcpy(char *s1, char *dst);
int _len(char *s1);
void env(char **tkc __attribute__((unused)));
void exite(char **tkc);
void start(char **c, int tc);
void handle_mode(void);
int p_command(char *cm);
void execute(char **tkn_cmd, int tcmd);
char *check_p(char *cm);
void (*_getfunc(char *cm))(char **);
void _cpy(char *s1, char *dst);
char *get_env(char *n);
void r_comment(char *ipt);

#endif
