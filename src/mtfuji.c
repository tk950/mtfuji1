#include <stdio.h>
#include <stdlib.h>
#include "../include/data.h"
#include "../include/optimize.h"
#include "../include/qsort.h"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage : bin/mtfuji data/data.csv\n");
        exit(EXIT_FAILURE);
    }
    double alpha = 0.01;
    Data *data_array;
    int data_num = 0;
    data_array = load_data(argv[1], &data_num);
    sort_height(data_array, data_num);
    double var[VAR_NUM];
    optimize(data_array, data_num, alpha, var);
    double temp = var[0] * 3.776 + var[1];
    printf("Predicted temperature at the top of mtfuji : %7.4f\n", temp);
    free_data(data_array);
    return 0;
}
