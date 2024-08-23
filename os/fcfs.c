#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, at, wt, tat, bt, ct;
} p[20], temp;

int n;

void asort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void fcfs() {
    float sum1 = 0, sum2 = 0;
    asort();
    p[0].ct = p[0].at + p[0].bt;
    for (int i = 0; i < n - 1; i++) {
        p[i + 1].ct = p[i].ct + p[i + 1].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sum1 += p[i].tat;
        sum2 += p[i].wt;
    }
    p[n - 1].tat = p[n - 1].ct - p[n - 1].at;
    p[n - 1].wt = p[n - 1].tat - p[n - 1].bt;
    sum1 += p[n - 1].tat;
    sum2 += p[n - 1].wt;

    printf("FCFS:\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average TAT: %.2f\n", sum1 / n);
    printf("Average Waiting Time: %.2f\n", sum2 / n);
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the PID of process %d: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt);
    }
    fcfs();
    return 0;
}
