#include <stdio.h>
#include <math.h>

float x[] = { 2, 4, 6, 8 };
float y[] = { 81, 93, 91, 97 };

float aver(float arr[])
{
    float sum, average;
    for (int i = 0; i < (sizeof(arr) / sizeof(float)); i++)
    {
        sum += arr[i];
    }
    average = sum / (sizeof(arr) / sizeof(float));

    return average;
}

float fx1(float a[], float b[], float aa, float ab)
{
    float sum1, sum2, sum_x, sum_y;
    float x1, y1;
    for (int i = 0; i < (sizeof(a) / sizeof(float)); i++)
    {
        x1 = a[i] - aa;
        y1 = b[i] - ab;

        sum1 += x1 * y1;

        sum2 += x1 * x1;
    }

    return sum1 / sum2;
}

float fx2(float a, float b, float c)
{
    return b - (a * c);
}

int main()
{
    float average_x = aver(x);
    float average_y = aver(y);

    float incline = fx1(x, y, average_x, average_y);
    float y_intercept = fx2(average_x, average_y, incline);

    printf("y = %fx + %f", incline, y_intercept);

    return 0;
}
