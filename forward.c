#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void calculateDifferenceTable(float x[], float y[][MAX], int n) {
    for (int i = 0; i < n; i++)
        y[i][0] = y[i][0];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
}

float newtonForwardInterpolation(float x[], float y[][MAX], int n, float value) {
    float result = y[0][0];
    float h = x[1] - x[0];
    float u = (value - x[0]) / h;

    for (int i = 1; i < n; i++) {
        float term = y[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u - j);
        }
        term /= factorial(i);
        result += term;
    }

    return result;
}

int main() {
    float x[MAX], y[MAX][MAX];
    int n;
    float value;

    printf("Enter the number of Argument : ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the corresponding values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }
    calculateDifferenceTable(x, y, n);
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);
    float result = newtonForwardInterpolation(x, y, n, value);
    printf("The interpolated value at x = %.2f is: %.2f\n", value, result);

    return 0;
}