
#include <stdio.h>

#define MAX 100

void backwardDifference(float x[], float y[], float diff[][MAX], int n) {
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
}

float backwardInterpolation(float x[], float y[], float value, int n) {
    float diff[MAX][MAX];
    backwardDifference(x, y, diff, n);
    float h = x[1] - x[0];
    float p = (value - x[n - 1]) / h;
    float result = diff[n - 1][0];
    for (int i = 1; i < n; i++) {
        float term = 1;
        for (int j = 0; j < i; j++) {
            term *= (p + j) / (j + 1);
        }
        result += term * diff[n - 1 - i][i];
    }
    return result;
}
int main() {
    float x[MAX], y[MAX];
    int n;
    float value;

    printf("Enter the number of argument: ");
    scanf("%d", &n);
    printf("Enter the data points (x and y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);
    float result = backwardInterpolation(x, y, value, n);
    printf("The interpolated value at x = %.2f is %.2f\n", value, result);

    return 0;
}
