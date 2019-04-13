/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "../include/103cipher.h"

int error(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        printf("USAGE\n    ./103cipher message key flag\n\n");
        printf("DESCRIPTION\n    message    a message");
        printf(", made of ASCII characters");
        printf("\n    key        the encryption key");
        printf(", made of ASCII characters\n");
        printf("    flag       0 for the message to be encrypted,");
        printf(" 1 to be decrypted\n");
        return (1);
    }
    else if (ac != 4)
        return (1);
    else if ((av[3][0] != '0' && av[3][0] != '1') || av[3][1] != '\0')
        return (1);
    if (av[3][0] == '1') {
        if (my_strlen(av[2]) > 9)
            return (1);
    }
    return (0);
}

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

void create_matrix(char *str, matrix *matrix)
{
    int k = 0;
    int j = 0;
    int i = 0;

    matrix->m = malloc(sizeof(int) * (matrix->row * matrix->col));
    for (int i = 0; i < matrix->row; i++)
        matrix->m[i] = malloc(sizeof(int) * matrix->col);
    for (i = 0; i < matrix->row; j++, k++) {
        if (k > my_strlen(str))
            matrix->m[i][j] = 0;
        else
            matrix->m[i][j] = str[k];
        if (j == matrix->col - 1) {
            j = -1;
            i++;
        }
    }
}

void create_matrix_rev(char *str, matrix *matrix)
{
    int k = 0;
    int j = 0;
    int i = 0;

    matrix->n = malloc(sizeof(float) * (matrix->row * matrix->col));
    for (int i = 0; i < matrix->row; i++)
        matrix->n[i] = malloc(sizeof(float) * matrix->col);
    for (i = 0; i < matrix->row; j++, k++) {
        if (k > my_strlen(str))
            matrix->n[i][j] = 0;
        else
            matrix->n[i][j] = str[k];
        if (j == matrix->col - 1) {
            j = -1;
            i++;
        }
    }
}

int main(int ac,char **av)
{
    matrix first;
    matrix second;

    if (error(ac, av))
        return (84);
    if (av[3][0] == '0') {
        if (my_strlen(av[2]) == 1) {
            size_one(av[1], av[2]);
            return (0);
        }
        first = ex1(av[2], first);
        second.col = first.col;
        printf("\n");
        second = ex2(av[1], second);
        mult_matrix(second, first);
    } else if (av[3][0] == '1') {
        first = ex3(av[2], first);
        second.col = first.col;
        printf("\n");
    }
    return (0);
}
