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
 *@cname: name of the command
 *@f: the function that executes the command
 */

typedef struct map
{
char *ccname;
void (*ff)(char **command);
} func;
extern char **envi;
extern char *lk;
extern char **cmds;
extern char *sns;
extern int ss;
char *_sstrtok(char *ch, char *d, char **sp);
int _aatois(char *s);
void *_rrllc(void *p, unsigned int sizep, unsigned int nsize);
void cctrlhandler(int snum);
int ccmp(char *s1, char *s2);
char *ccat(char *s1, char *s2);
int _sstr(char *s1, char *s2);
int sstrcs(char *s1, char *s2);
char *sstrc(char *s1, char c);
char **_ttokenizer(char *s1, char *s2);
void _pprint(char *s1, int s2);
void rr_line(char *s1);
void _sstrcpy(char *s1, char *dst);
int _llen(char *s1);
void eenv(char **tkc __attribute__((unused)));
void eexite(char **tkc);
void sstart(char **c, int tc);
void hhandle_mode(void);
int pp_command(char *cm);
void eexecute(char **tkn_cmd, int tcmd);
char *ccheck_p(char *cm);
void (*_ggetfunc(char *cm))(char **);
void _ccpy(char *s1, char *dst);
char *get_env(char *n);
void rr_comment(char *ipt);
#endif
