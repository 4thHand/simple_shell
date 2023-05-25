#ifndef _SHELL_H_
#define _SHELL_H_

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

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **emission;
/**
 * struct liststng - singly linked list
 * @numb: the number field
 * @stng: a string
 * @next: points to the next node
 */
typedef struct liststng
{
	int numb;
	char *str;
	struct liststng *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *argu;
	char **argv;
	char *way;
	int argc;
	unsigned int er_count;
	int er_numb;
	int ercount_put;
	char *filename;
	list_t *emi;
	list_t *history;
	list_t *alias;
	char **emission;
	int emi_ch;
	int stat;

	char **cmd_buffer; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buffer_type; /* CMD_type ||, &&, ; */
	int rdfd;
	int listcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct makein - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct makein
{
	char *type;
	int (*func)(info_t *);
} makein_table;


/* toem_shloop.c */
int hxh(info_t *, char **);
int find_makein(info_t *);
void find_cmd(info_t *);
void frk_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_cha(char *, int, int);
char *find_way(info_t *, char *, char *);

/* loophsh.c */
int loophxh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strnglen(char *);
int _strngcmp(char *, char *);
char *starts_plus(const char *, const char *);
char *_strngcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdupp(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strngcpy(char *, char *, int);
char *_strngcat(char *, char *, int);
char *_strngchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_mmsett(char *, char, unsigned int);
void frfre(char **);
void *_pureloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfre(void **);

/* toem_atoi.c */
int interact(info_t *);
int is_del(char, char *);
int _isalp(int);
int _atoinie(char *);

/* toem_errors1.c */
int _erratoinie(char *);
void display_err(info_t *, char *);
int display_d(int, int);
char *conv_numb(long int, int, int);
void remv_comt(char *);

/* toem_builtin.c */
int _miex(info_t *);
int _micd(info_t *);
int _mihelp(info_t *);

/* toem_builtin1.c */
int _mihistory(info_t *);
int _mialias(info_t *);

/*toem_getline.c */
ssize_t get_inp(info_t *);
int _getlin(info_t *, char **, size_t *);
void sigintContr(int);

/* toem_getinfo.c */
void clean_inf(info_t *);
void place_inf(info_t *, char **);
void free_inf(info_t *, int);

/* toem_environ.c */
char *_getemi(info_t *, const char *);
int _miemi(info_t *);
int _misetemi(info_t *);
int _miunsetemi(info_t *);
int populate_emi_list(info_t *);

/* toem_getenv.c */
char **get_emiron(info_t *);
int _unsetemi(info_t *, char *);
int _setemi(info_t *, char *, char *);

/* toem_history.c */
char *get_his_file(info_t *info);
int enter_history(info_t *info);
int take_history(info_t *info);
int make_history_list(info_t *info, char *buf, int linecount);
int newnumber_history(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_last(list_t **, const char *, int);
size_t display_list_string(const list_t *);
int del_node_at_inx(list_t **, unsigned int);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_lenht(const list_t *);
char **list_to_strng(list_t *);
size_t display_list(const list_t *);
list_t *node_str_as(list_t *, char *, char);
ssize_t get_node_inx(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void see_chain(info_t *, char *, size_t *, size_t, size_t);
int sub_alias(info_t *);
int sub_vars(info_t *);
int sub_string(char **, char *);

#endif
