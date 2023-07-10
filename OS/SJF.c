#include <stdio.h>

int main() {
    int n, i, j, temp, total = 0;
    float avg_wt, avg_tat;
    int bt[100], at[100], wt[100], tat[100], p[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Taking input of burst time and arrival time
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of process %d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        p[i] = i + 1;
    }

    // Sorting processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculation of waiting time
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    // Calculation of turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }

    avg_tat = (float)total / n;
    avg_wt = (float)total / n - (float)(total - at[n - 1]) / n;

    printf("\nProcess   Arrival Time   Burst Time   Waiting Time   Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("  P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %0.2f\n", avg_wt);
    printf("Average turnaround time: %0.2f\n", avg_tat);

    return 0;
}
