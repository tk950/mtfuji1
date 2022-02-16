#ifndef DATA_H_
#define DATA_H_
#define VAR_NUM 2
typedef struct data
{
    double temp;
    double height;
    char name[100];
} Data;

Data *load_data(const char *filename, int *data_num);
void free_data(Data *data_array);
#endif