//LAB 4: FCFS ,RR,Priority Scheduling and SJF

//LAB 5: Bankers Algorithm
#include <stdio.h>
#include<conio.h>
int main(){
    int n, bt[20], wt[20],tat[20], avwt = 0, avtat=0,i,j;
    printf("Enter total number of processess:");
    scanf("%d", &n);
    printf("Enter the burst time for the processess: ");
    for(i=0;i<n;i++){
        printf("\n Process[%d]:", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i=1;i<n;i++){
            wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i]+= bt[j];
    }
    }
    printf("\nProcess BurstTime WaitingTime TurnaroundTime");
    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\n P[%d} \t%d \t\t%d \t\t%d", i+1, bt[i], wt[i], tat[i]);
    }

    avwt /= i;
    avtat /= i;
    printf("\n Average Waiting Time: %d", avwt);
    printf("\n Average Turn Around Time: %d", avtat);
    return 0;

}
