/*
** EPITECH PROJECT, 2018
** encrypted
** File description:
** encrypted
*/

#include "../include/103cipher.h"

void size_one(char *message, char *key)
{
    int i;

    printf("Key matrix:\n%d\n\n", key[0]);
    printf("Encrypted message:\n");
    for (i = 0; message[i + 1]; i++) {
        printf("%d ", message[i] * key[0]);
    }
    printf("%d\n", message[i] * key[0]);
}

int mult(matrix a, int **b, int i, int j)
{
    int nb = 0;
    int z;

    for (z = 0; z < a.col; z++)
        nb = nb + a.m[i][z] * b[z][j];
    return (nb);
}

int **mult_matrix(matrix a, matrix b)
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
    printf("Encrypted message:\n");
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            if (j + 1 == a.col && i + 1 == a.row)
                printf("%d", c[i][j]);
            else
                printf("%d ", c[i][j]);
        }
    }
    printf("\n");
}

matrix ex2(char *str, matrix second)
{
    second.row = my_strlen(str) / second.col;
    if (second.row * second.col < my_strlen(str))
        second.row++;
    create_matrix(str, &second);
    return (second);
}

matrix ex1(char *str, matrix first)
{
    first.row = sqrt(my_strlen(str));
    if (first.row * first.row < my_strlen(str))
        first.row++;
    first.col = first.row;
    create_matrix(str, &first);
    printf("Key matrix:\n");
    for (int i = 0; i < first.row; i++) {
        for (int j = 0; j < first.col; j++)
            if (j + 1 == first.col)
                printf("%d", first.m[i][j]);
            else
                printf("%d\t", first.m[i][j]);
        printf("\n");
    }
    return (first);
}
