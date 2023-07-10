#include <stdio.h>

int main() {
    int i, n, sum = 0, count = 0, y, quantum, wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    y = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time");

    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quantum && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= quantum;
            sum += quantum;
        }
        if (temp[i] == 0 && count == 1) {
            y--;
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i];
            tat += sum - at[i];
            count = 0;
        }
        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    avg_wt = (float)wt / n;
    avg_tat = (float)tat / n;

    printf("\n\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);

    return 0;
}
