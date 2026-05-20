#include <stdio.h>
#include <math.h>

double f(float x)
{
    return (x * x - 4 * x - 10);
}
int main()
{
    float a = -2, b = -1;
    float root;
    float f0, f1, f2;
    if (f(a) * f(b) > 0)
    {
        printf("wrong guess");
    }

    do
    {
        f1 = f(a);
        f2 = f(b);
        root = (a + b) / 2;
        f0 = f(root);
        printf("\na =%f, b =%f, f1= %f, f2=%f, root=%f f0= %f ", a, b, f1, f2, root, f0);
        if (f1 * f0 < 0)
        {
            b = root;
            f2 = f0;
        }
        else
        {
            a = root;
            f1 = f0;
        }
        printf("\n");

    } while (fabs(f(root)) >= 0.01);

    printf("\nFinal Root = %f", root);
}