
#include <stdio.h>

int main() {
    int n;
    int burst[10], remaining[10];
    int waiting[10], turnaround[10];
    int time = 0, completed = 0;
    float avgBurst = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        waiting[i] = 0;
        avgBurst += burst[i];
    }

    avgBurst = avgBurst / n;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {

                int timeQuantum;
                if (burst[i] <= avgBurst)
                    timeQuantum = 4;
                else
                    timeQuantum = 6;

                if (remaining[i] > timeQuantum) {
                    time += timeQuantum;
                    remaining[i] -= timeQuantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                    completed++;
                }
            }
        }
    }

    float avgWT = 0, avgTAT = 0;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        avgWT += waiting[i];
        avgTAT += turnaround[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
