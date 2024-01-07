     #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isInside_boundry(double x, double y) {
    if (pow(x, 2) + pow(y, 2) - 16 < 0) {
        return 1;
    } else {
        return 0;
    }
}

double approximate_pi(int num_of_drops) {
    int num_inside = 0;
    for (int i = 0; i < num_of_drops; i++) {
        double x = ((double)rand() / RAND_MAX) * 8 - 4;
        double y = ((double)rand() / RAND_MAX) * 8 - 4;
        if (isInside_boundry(x, y) == 1) {
            num_inside++;
        }
    }
    return (4 * num_inside) / (double)num_of_drops;
}

int main() {
    srand(time(NULL));
    int drops;
    printf("Enter the value of drops:");
    scanf("%d", &drops);
    double pi_approximation = approximate_pi(drops);
    printf("The approximate value of PI with %d pin drops is %f\n", drops, pi_approximation);
    return 0;
}

