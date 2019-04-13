/*
** EPITECH PROJECT, 2019
** tools
** File description:
** tools
*/

#include "../include/103cipher.h"

void head(matrix a, matrix b, int **c)
{
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
