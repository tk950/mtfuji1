#include <stdio.h>
#include <stdlib.h>
#include "../include/func.h"

void gradient(Data *data_array, const int data_num, const double var[VAR_NUM], double *grad)
{
    double grad_a = 0;
    double grad_b = 0;
    double a = var[0];
    double b = var[1];
    for (int i = 0; i < data_num; ++i)
    {
        double x = data_array[i].height;
        double y = data_array[i].temp;
        grad_a += 2 * (y - (a * x + b)) * (-x);
        grad_b += 2 * (y - (a * x + b)) * (-1);
    }
    grad[0] = grad_a;
    grad[1] = grad_b;
}

double func(Data *data_array, int data_num, double a, double b) //二乗誤差を返す
{
    double ans = 0;
    for (int i = 0; i < data_num; ++i)
    {
        double sa = data_array[i].temp - (a * data_array[i].height + b);
        ans += sa * sa;
    }
    return ans;
}
