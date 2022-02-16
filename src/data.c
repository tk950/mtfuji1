#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/data.h"

//標高と気温で配列にして返す
Data *load_data(const char *filename, int *data_num)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int size = 0;
    int buf_max = 1000;
    char buf[buf_max];
    const int data_type = 2;
    char *data[data_type];
    while (fgets(buf, buf_max, fp) != NULL)
    { //まず行数を数える。
        size++;
    }
    *data_num = size;
    fseek(fp, 0L, SEEK_SET);
    Data *dat_array = (Data *)malloc(size * sizeof(Data));
    for (int i = 0; i < size; ++i)
    {
        fgets(buf, buf_max, fp);
        strcpy(dat_array[i].name, strtok(buf, ","));
        for (int i = 0; i < data_type; ++i)
        {
            data[i] = strtok(NULL, ",");
        }
        double height = strtod(data[0], NULL);
        double temp = strtod(data[1], NULL);
        dat_array[i].height = height;
        dat_array[i].temp = temp;
    }
    return dat_array;
}

void free_data(Data *data_array)
{
    free(data_array);
}