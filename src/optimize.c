#include <stdio.h>
#include <math.h>
#include "../include/optimize.h"

double calc_norm(const double g[VAR_NUM])
{
    double temp = 0;
    for (int i = 0; i < VAR_NUM; ++i)
    {
        temp += g[i] * g[i];
    }
    return sqrt(temp);
}

void optimize(Data *data_array, const int data_num, const double alpha, double var[VAR_NUM])
{
    for (int i = 0; i < VAR_NUM; ++i)
    {
        var[i] = 1;
    }
    const double norm = 0.01;
    int cnt = 0;
    while (++cnt < 100000)
    {
        double grad[VAR_NUM] = {0};
        gradient(data_array, data_num, var, grad);
        for (int i = 0; i < VAR_NUM; ++i)
        {
            var[i] -= alpha * grad[i];
        }
        if (calc_norm(grad) < norm)
        {
            break;
        }
        cnt++;
    }
}
