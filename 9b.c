#include <stdio.h>

int complete_time[3], turnaround_time[3], waiting_time[3];

void completionTime(int p[], int bt[]) {
    for (int i = 0; i < 3; i++) {
        complete_time[i] = 0;
        for (int j = 0; j <= i; j++) {
            complete_time[i] += bt[j];
        }
    }
}

void turnAroundTime(int cp[]) {
    for (int i = 0; i < 3; i++) {
        turnaround_time[i] = cp[i] - 0; //Taking Arrival Time for all processes as 0
    }
}

void waitingTime(int tat[3], int bt[3]) {
    for (int i = 0; i < 3; i++) {
        waiting_time[i] = tat[i] - bt[i];
    }
}

int main() {
    int processes[3] = {1,2,3};
    int burst_time[3] = {5,10,15};

    completionTime(processes, burst_time);
    turnAroundTime(complete_time);
    waitingTime(turnaround_time, burst_time);

    printf("Processes\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\n", processes[i], burst_time[i], complete_time[i], turnaround_time[i], waiting_time[i]);
    }

    return 0;
}
