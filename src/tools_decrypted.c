/*
** EPITECH PROJECT, 2018
** tools_decryptage
** File description:
** tools
*/

#include "../include/103cipher.h"

int invert_1(char *str, matrix *matrix, int **sav)
{
    int det = 0;
}

int invert_2(char *str, matrix *matrix, int **sav)
{
    float det = 0;

    det = (1 / (float)((sav[0][0] * sav[1][1])-(sav[0][1] * sav[1][0])));
    if (det == 0)
        exit (84);
    matrix->n[0][0] = det * sav[1][1];
    matrix->n[0][1] = det * -(sav[0][1]);
    matrix->n[1][0] = det * -(sav[1][0]);
    matrix->n[1][1] = det * sav[0][0];
}

int invert_3(char *str, matrix *matrix, int **sav)
{
    float det = 0;

    det = (1 / (float)((sav[0][0] * sav[1][1] * sav[2][2]) +
                       (sav[0][1] * sav[1][2] * sav[2][0]) +
                       (sav[0][2] * sav[1][0] * sav[2][1]) -
                       (sav[0][2] * sav[1][1] * sav[2][0]) -
                       (sav[1][2] * sav[2][1] * sav[0][0]) -
                       (sav[2][2] * sav[0][1] * sav[1][0])));
    if (det == 0)
        exit (84);
    matrix->n[0][0] = det * (sav[1][1] * sav[2][2] - (sav[1][2] * sav[2][1]));
    matrix->n[1][0] = det * (sav[1][2] * sav[2][0] - (sav[1][0] * sav[2][2]));
    matrix->n[2][0] = det * (sav[1][0] * sav[2][1] - (sav[1][1] * sav[2][0]));
    matrix->n[0][1] = det * (sav[0][2] * sav[2][1] - (sav[0][1] * sav[2][2]));
    matrix->n[1][1] = det * (sav[0][0] * sav[2][2] - (sav[0][2] * sav[2][0]));
    matrix->n[2][1] = det * (sav[0][1] * sav[2][0] - (sav[0][0] * sav[2][1]));
    matrix->n[0][2] = det * (sav[0][1] * sav[1][2] - (sav[0][2] * sav[1][1]));
    matrix->n[1][2] = det * (sav[0][2] * sav[1][0] - (sav[0][0] * sav[1][2]));
    matrix->n[2][2] = det * (sav[0][0] * sav[1][1] - (sav[0][1] * sav[1][0]));
}

int getnbr(char *str, int *i)
{
    int j = 1;

    for (*i; str[*i] >= '0' && str[*i] <= '9'; *i++) {
        j = j * 10;
        j = j + (str[*i] - 48);
    }
    return (j);
}

int *get_int(char *str)
{
    int k = 0;
    int *a = malloc(sizeof(int) * my_strlen(str));

    for (int i = 0; str[i]; i++) {
        a[k] = getnbr(str, &i);
        k++;
    }
    return (a);
}
