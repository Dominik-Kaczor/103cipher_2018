/*
** EPITECH PROJECT, 2018
** 103cipher
** File description:
** 103cipher
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct matrix matrix;
struct matrix
{
    int **m;
    int row;
    int col;
    float **n;
};

void size_one(char *, char *);
int my_strlen(char const *);
int mult(matrix a, int **b, int i, int j);
int mult_decr(matrix a, int **b, int i, int j);
int **mult_matrix(matrix, matrix);
int **mult_matrix_decr(matrix, matrix);
void create_matrix(char *str, matrix *);
void create_matrix_rev(char *str, matrix *matrix);
matrix ex1(char *str, matrix);
matrix ex2(char *str, matrix);
matrix ex3(char *str, matrix);
matrix ex4(char *str, matrix);
int invert_1(char *str, matrix *matrix, int **sav);
int invert_2(char *str, matrix *matrix, int **sav);
int invert_3(char *str, matrix *matrix, int **sav);
int *get_int(char *);
int getnbr(char *, int *);
void head(matrix a, matrix b, int **c);
