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

void btsort(int i, int ict) {
    for (int a = i + 1; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            if (p[a].at <= ict && p[b].at <= ict && p[a].bt > p[b].bt) {
                temp = p[a];
                p[a] = p[b];
                p[b] = temp;
            }
        }
    }
}

void sjf() {
    float sum1 = 0, sum2 = 0;
    asort();
    
    int ict = p[0].at;
    
    for (int i = 0; i < n; i++) {
        if (ict < p[i].at) {
            ict = p[i].at;
        }
        p[i].ct = ict + p[i].bt;
        ict = p[i].ct;
        
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        
        sum1 += p[i].tat;
        sum2 += p[i].wt;
        
        btsort(i, ict);
    }

    printf("SJF:\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
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
    sjf();
    return 0;
}

