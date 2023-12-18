#include <stdio.h>

int main(){
    double x, y;
    double result = 0.0;
    char c;
    scanf("%lf %c %lf", &x, &c, &y);

    switch (c)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            break;
    }
    printf("%.3f\n", result);
    return 0;
}