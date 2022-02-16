#include <stdlib.h>
#include <stdio.h>
#include "../include/qsort.h"
int cmp_height(const void *x0, const void *x1)
{
    const Data *y0 = (Data *)x0;
    const Data *y1 = (Data *)x1;
    return y0->height < y1->height ? 1 : -1;
}

void sort_height(Data *data_array, const int data_num)
{
    qsort(data_array, data_num, sizeof(Data), cmp_height);
    for (int i = 0; i < data_num; ++i)
    {
        printf("%s height:%7.4f\n", data_array[i].name, data_array[i].height);
    }
}