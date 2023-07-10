#include<stdio.h>

int main() {
    int n, i, j, temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n], arrival_time[n], priority[n], process[n], waiting_time[n], turnaround_time[n];

    for(i=0; i<n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority for process %d: ", i+1);
        scanf("%d%d%d", &arrival_time[i], &burst_time[i], &priority[i]);
        process[i] = i+1;
    }

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(priority[i] < priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = burst_time[i]; burst_time[i] = burst_time[j]; burst_time[j] = temp;
                temp = arrival_time[i]; arrival_time[i] = arrival_time[j]; arrival_time[j] = temp;
                temp = process[i]; process[i] = process[j]; process[j] = temp;
            }
        }
    }

    waiting_time[0] = 0;

    for(i=1; i<n; i++) {
        waiting_time[i] = 0;
        for(j=0; j<i; j++) {
            waiting_time[i] += burst_time[j];
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");

    for(i=0; i<n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", process[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);

        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\n\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
