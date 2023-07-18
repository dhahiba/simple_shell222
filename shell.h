#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define B -1
#define W 1024
#define R 1024

/* chaine1.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
/* chaine2.c */
int _strcmp(char *s1, char *s2);
char *strwith(const char *ch1, const char *ch2);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
/* chaine3.c */
char *_strchr(const char *s, int ch);
/* func_list */
list_t *add_node(list_t **head, const char *str, int n);
list_t *add_node_end(list_t **head, const char *str, int n);
size_t print_list_str(const list_t *h);
int delete_node_at_index(listint_t **head, unsigned int index);
void free_list(list_t *head);
/* func_list2.c */
size_t list_len(const list_t *h);
char  *list_to_string(const listint_t *h);
size_t print_listint(const listint_t *h);
list_t *node_starts_with(list_t *node, char *pr, char c);
ssize_t get_node_index(list_t *h, list_t *n);
/* func_mum.c */
void ffree(char **p);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);
int bfree(void *p);
/* functions1.c */
int _isalpha(int c);
int is_delim(char c, char *d);
int _inter(info_t *f);

#endif
