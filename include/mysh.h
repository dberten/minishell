/*
** EPITECH PROJECT, 2019
** bsq.h
** File description:
** bsq.h
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>

typedef struct pipe
{
    int nb_pipe;
    int new_tab[2];
    int old_tab[2];
    char **parse_pipe;
}pipe_t;

typedef struct redirection
{
    char **parse_str;
    char **tab_file;
    int *redirect;
}redirection_t;


typedef struct semicolon
{
    int err;
    char **function;
}semicolon_t;

typedef struct modif
{
    char *home;
    char **tab;
    char **env_tab;
    int return_value;
} modif_t;


typedef struct main_struct
{
    pipe_t *pipe;
    redirection_t *redirection;
    semicolon_t *semicolon;
    modif_t *modif;
}main_struct_t;


int check_after_pipe(char *str);

void error_exec(char **tab);

void close_tab_fd(main_struct_t *main_struct, int rep, int status, int check);

void close_fd(int tmp1, int tmp2);

int check_before_pipe(char *str);

void stock_home(modif_t *modif);

int condition_cd(modif_t *modif, char **tab);

int manage_all_redirection(char *str, int size, main_struct_t *main_struct);

int manage_pipe(char *str, main_struct_t *main_struct);

int cd_mult(modif_t *modif, char **tab);

int parse_cd(modif_t *modif, char **tab);

int check_pipe(char *str);

int error_setenv(char **tab, int size);

int condition_error_simple_cd(modif_t *modif, char *home);

int redirect_index(char *str);

int check_space(char *str);

int get_space(char *str);

void char_remove(int i, char *str);

void fill_tab_int(main_struct_t *main_struct, char *str);

int my_right_redirection(int i, main_struct_t *main_struct);

int my_left_redirection(int i, main_struct_t *main_struct);

int my_double_right_redirect(int i, main_struct_t *main_struct);

int mult_redirection(main_struct_t *main_struct, char *str, int size);

char *parse_str(char *str, main_struct_t *main_struct, char c);

int my_semicolon(main_struct_t *main_struct, char *str, int size);

char *cut_str(char *str);

char *good_str(char *str);

void stock_path(modif_t *modif);

int check_space_chevron(char *str, int i);

void decall_string(char *str, int i);

int manage_error(int tmp, char **tab);

int my_fork(char *str, main_struct_t *main_struct, char **tab);

char *get_redirect(char *str, main_struct_t *main_struct, char c);

int check_redirection(char *str);

char *my_strcat(char *dest, char const *src);

char **mult_arg(modif_t  *modif, char **tab, int size);

char *remove_redirect(char *str, main_struct_t *main_struct);

int check_good_str(char *str);

int check_char(char *str);

void fill_tab_redirect(main_struct_t *main_struct, char *str);

int env_tab(modif_t *modif, char **envp);

int my_strncmp(char const *s1, char const *s2, int n);

int exec_function(main_struct_t *main_struct, char **tab);

int all_function(main_struct_t *main_struct, char **tab, int size);

char *get_files(char *str);

int exit_programm(char **tab);

int manage_input(char *str, main_struct_t *main_struct, int size);

int exec_path(main_struct_t *main_struct, char **tab);

char *clean_str(char *str);

int condition_exec(modif_t *modif, int size);

int get_return(int status);

int my_strlen(char const *str);

char *nice_string(char *str);

int check_chevron(char *str);

char *check_space_before(char *str);

char *my_strcpy(char *dest, char const *src);

int my_strcmp ( char const *s1, char const *s2);

int my_exec(main_struct_t *main_struct, char **tab);

int my_strlen(char const *str);

void set_setenv(modif_t *modif, char **envp);

char *my_strcat (char *dest, char const *src);

int manage_all_case(modif_t *modif, char **tab);

void print_tab(char **tab);

int coord_chevron(char *str, int i);

int my_printf(char *s, ...);

void fill_tab_file(main_struct_t *main_struct, char *str);

int loop(main_struct_t *main_struct, char **envp);

int is_semicolon(char *str);

char **my_str_to_word_array(char *str, char c);

int my_simple_cd(modif_t *modif);

int my_mult_cd(modif_t *modif, char **tab);

int my_dash_cd(modif_t *modif);

void read_file(DIR *rep, modif_t *modif);

int error_cd(DIR *rep, modif_t *modif);

int all_function_2(main_struct_t *main_struct, char **tab);

int get_nb_action(modif_t *modif);

char **my_get_path(char *path);

int my_getnbr(char const *str);

int size_env(char **envp);

int error_env(char **tab);

char *find_oldpwd(modif_t *modif);

int find_variable(char *str, modif_t *modif);

int is_alpha(char c);

int len_tab(char **tab);

char *find_var(char *str, modif_t *modif);

int my_unsetenv(modif_t *modif, char **tab);

char *my_strdup(char *str);

int error_alpha_setenv(char **tab);

int condition_error_cd(char *str, char *str1, char **tab);

#endif /* MYSH_H_ */
