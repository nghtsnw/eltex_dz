#include <stdio.h>
#include <stdlib.h>

#define N 6
int matrix[N][N];

void print_matrix()
{
    for (int i = 0; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < N; j++)
        {            printf("%d ", matrix[i][j]);
            if (matrix[i][j] < 10) printf(" ");
        }
    }
    printf("\n");
    printf("\n");
}

void cube_matrix(void)
{
    int index = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = index;
            index++;
        }

    print_matrix();
}

void backout(void)
{
    int array[N];
    int index = 1;
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        array[i] = index;
        index++;
    }
    for (int j = 0; j < N; j++) printf("%d ", array[j]);
    printf("\n");
    for (int j = N-1; j >= 0; j--) printf("%d ", array[j]);
    printf("\n");
    printf("\n");
}

void triangle(void)
{
    int index = N;
    for (int i = 0; i < N; i++)
    {
        index--;
        for (int j = 0; j < N; j++)
        {
            if (j < index) matrix[i][j] = 1;
            else matrix [i][j] = 0;
        }
    }

    print_matrix();
}

void ulitka(void)
{
    const unsigned int square_size = N*N;
    unsigned int index = 1;
    unsigned int i = 0, j = 0;
    unsigned int shift = 0;
    while (index <= square_size)
    {
        for (; (i < N-1 - shift) && (index <= square_size); i++, index++) //прибавляем индекс позиции
            matrix[j][i] = index;

        for (; (j < N-1 - shift) && (index <= square_size); j++, index++) // прибавляем индекс строки
            matrix[j][i] = index;

        for (; (i > (0 + shift)) && (index <= square_size); i--, index++) // отнимаем индекс позиции
            matrix[j][i] = index;

        shift++; // тут появляется сдвиг

        for (; (j > (0 + shift)) && (index <= square_size); j--, index++) // отнимаем индекс строки
            matrix[j][i] = index;
    }

    print_matrix();
}

int main()
{
    cube_matrix();
    backout();
    triangle();
    ulitka();
    return 0;
}
