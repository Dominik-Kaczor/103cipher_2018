/*
** EPITECH PROJECT, 2018
** decrypted
** File description:
** decrypted message
*/

#include "../include/103cipher.h"

int mult_decr(matrix a, int **b, int i, int j)
{
    int nb = 0;
    int z;

    for (z = 0; z < a.col; z++)
        nb = nb + a.m[i][z] * b[z][j];
    return (nb);
}

int **mult_matrix_decr(matrix a, matrix b)
{
    int i, j;
    int **c = malloc(sizeof(int) * (a.col * a.row));

    for (int k = 0; k < a.row; k++)
        c[k] = malloc(sizeof(int) * a.col);
    for (i = 0, j = 0; i < a.row; j++) {
        c[i][j] = mult(a, b.m, i, j);
        if (j == a.col - 1) {
            j = -1;
            i++;
        }
    }
    head(a, b, c);
}

matrix ex4(char *str, matrix second)
{
    second.row = my_strlen(str) / second.col;
    if (second.row * second.col < my_strlen(str))
        second.row++;
    int *array = get_int(str);
    printf("%d %d %d", array[0], array[1], array[2], array[3]);
    return (second);
}

void invertible(char *str, matrix *matrix)
{
    int **sav = malloc(sizeof(int) * (matrix->row * matrix->col));

    for (int i = 0; i < matrix->row; i++)
        sav[i] = malloc(sizeof(int) * matrix->col);
    for (int a = 0; a != matrix->row; a++) {
        for (int b = 0; b != matrix->col; b++)
            sav[a][b] = matrix->n[a][b];
    }
    if (my_strlen(str) == 1) {
        invert_1(str, matrix, sav);
    } else if (my_strlen(str) <= 4) {
        invert_2(str, matrix, sav);
    } else
        invert_3(str, matrix, sav);
}

matrix ex3(char *str, matrix first)
{
    first.row = sqrt(my_strlen(str));
    if (first.row * first.row < my_strlen(str))
        first.row++;
    first.col = first.row;
    create_matrix_rev(str, &first);
    printf("Key matrix:\n");
    invertible(str, &first);
    for (int i = 0; i < first.row; i++) {
        for (int j = 0; j < first.col; j++)
            if (j + 1 == first.col)
                printf("%.3f", first.n[i][j]);
            else
                printf("%.3f\t", first.n[i][j]);
        printf("\n");
    }
    return (first);
}
