/*
** EPITECH PROJECT, 2024
** library
** File description:
** library
*/
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#ifndef MY_H
    #define MY_H
static char *atk1;
static char *atk2;
typedef struct pos {
    int *size;
    int *x;
    int *y;
    int *x_fin;
    int *y_fin;
    char *i_char;
    char *f_char;
}pos_t;
typedef struct my_sigaction {
    struct sigaction sig;
    struct sigaction sig2;
    struct sigaction sig3;
    struct sigaction sig4;
    struct sigaction sig5;
    struct sigaction sig6;
    struct sigaction sig8;
    struct sigaction attaqq;
    struct sigaction atk_ennemy;
    struct sigaction ennemy;
}my_sigaction_t;
typedef struct pos2 {
    int *size;
    int *x;
    int *y;
    int *x_fin;
    int *y_fin;
    char *i_char;
    char *f_char;
}pos2_t;

typedef struct info {
    char **map;
    int *check;
    char **position;
    int *rem;
}info_t;

typedef struct info2 {
    char **map;
    int *check;
    char **position;
    int *rem;
}info2_t;

static char **map_player1;
static char **map_player2;
static char **map_ennemi1;
static char **map_ennemi2;
static pid_t usr1;    
char **my_str_to_word_array(char *str);
char **my_str_to_word_array2(char *str);
int my_for1(char **map, int nb_line, int nb_cols);
int my_putstr(char const *str);
void my_putchar(char c);
char *my_get_line(int fd);
int my_strcomp(char *str1, char *str2);
char *my_get_line(int fd);
int case_of_errors(int ac, char **av);
int case_of_errors1(pos_t *pos, info_t *infos, int x, int a);
int case_of_errors2(pos_t *pos, info_t *infos, int x, int a);
int case_of_errors3(pos_t *pos, info_t *infos, int x, int a);
int my_strlen(char *str);
int my_count_boat(char **map);
void player_win(int a, siginfo_t *b, void *c);
int my_count_x(char **map);
int my_get_attack2(char *att2, char **map);
int my_get_player_attack(char *att, char **map);
int my_strcomp(char *str1, char *str2);
void my_sig(int a, siginfo_t *b, void *c);
int my_strlen(char *str);
char *my_read_file(char *filepath);
int my_count_char(char *buffer, char c);
void display(int sig);
int my_getnbr(char *p);
int my_get_player_attack2(char *att2, char **map, char **map_player1, char **map_ennemi2);
int my_display1(char **map_ennemi1, char **map_player2);
void my_display3(char **map_player1, char **map_ennemi2);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
void load(char *c, char *d);
int verif(char *d, siginfo_t *b);
int load2(char *c, char *d);
void my_attaq(int a, siginfo_t *b, void *c);
void atk_ennemy(int a, siginfo_t *b, void *c);
int attack_ennemi(char **av, siginfo_t *b);
int my_convert(char c);
int file_size(char const *filepath);
int my_check(char c1, char c2);
int my_strlen(char *str);
void my_player_atk(int a, siginfo_t *b, void *c);
char *my_get_line(int fd);
int my_display2(void);
void my_read_attack(void);
int my_filling2(pos_t *pos, int j, int *rem, char **map);
int my_filling1(pos_t *pos, int j, int *rem, char **map);
int my_putnbr(int nb);
int all_number(char *str);
void sig_declarations(my_sigaction_t *my_sigactions);
void usage(void);
void my_sig(int a, siginfo_t *b, void *c);
int login_player1(int ac, char **av);
void my_ennemi_atk(int a, siginfo_t *b, void *c);
void ennemy(int a, siginfo_t *b, void *c);
void my_sig2(int a, siginfo_t *b, void *c);
int login_player2(int ac, char **av);
char *attack2(char **av, siginfo_t *b);
char **parsing(char **av, int ac);
char **parsing2(char **av);
void my_remplace_att2(int a, siginfo_t *b, void *c);
void my_remplace_att(int a, siginfo_t *b, void *c);
int attack(siginfo_t *b);
void ennemy_connected(int sig);
int my_get_attack(char *att, char **map);
#endif
