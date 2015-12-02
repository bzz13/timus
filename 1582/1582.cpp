#include <stdio.h>
#include <math.h>

double k1, k2, k3;

int main() {
    scanf("%lf%lf%lf", &k1, &k2, &k3);
    printf("%.0lf", 1000/(k2/k3+k2/k1+1)*k2);
    return 0;
}