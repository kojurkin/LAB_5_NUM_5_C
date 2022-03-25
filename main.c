#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void max_of_file(double* array, int size, double *max)
{
    *max = DBL_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > *max)
        {
            *max = array[i];
        }
    }
}

int main()
{
    double max = 0;
    FILE *in_file = fopen("input.txt", "r");
    int size;
    fscanf(in_file, "%d", &size);
    double* array = malloc( size * sizeof(double));
    for (int i = 0; i < size; i++)
    {
        if(feof(in_file))
        {
            printf("\nERROR: not enough elements in file"); // если элементов меньше чем (n - 1 + " ")
            return 1;
        }
        fscanf(in_file, "%lf", &array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", array[i]);
    }
    max_of_file(array, size, &max);
    printf("\nMax file of array is %lf", max);
    free(array);
    fclose(in_file);
    return 0;
}