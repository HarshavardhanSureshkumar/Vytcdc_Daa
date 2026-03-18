//CH.SC.U4CSE24037
//S HARSHAVARDHAN
//Q)Job Sequencing with Deadlines using Greedy Algorithm

#include<stdio.h>

#define N 14

// Structure for a job
struct Job {
    int id;
    int profit;
    int deadline;
};

// Function to sort jobs in descending order of profit
void sortJobs(struct Job jobs[]) {
    int i, j;
    struct Job temp;
    
    for(i = 0; i < N - 1; i++) {
        for(j = 0; j < N - i - 1; j++) {
            if(jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, j, maxDeadline = 0, totalProfit = 0;

    // Given profits and deadlines
    int profits[N] = {22, 19, 29, 28, 30, 21, 27, 25, 24, 26, 14, 27, 19, 11};
    int deadlines[N] = {3, 3, 8, 6, 7, 5, 10, 4, 6, 12, 13, 2, 14, 1};

    struct Job jobs[N];

    // Initialize jobs
    for(i = 0; i < N; i++) {
        jobs[i].id = i + 1;
        jobs[i].profit = profits[i];
        jobs[i].deadline = deadlines[i];

        if(deadlines[i] > maxDeadline)
            maxDeadline = deadlines[i];
    }

    // // Sort jobs by profit (descending)
    // printf("Jobs before sort :\n");
    // for(int k = 0; k < N; k++) {
    //     printf("Job ID: %d, Profit: %d, Deadline: %d\n", jobs[k].id, jobs[k].profit, jobs[k].deadline);
    // }

    sortJobs(jobs);
    // printf("Jobs sorted by profit (descending):\n");
    // for(int k = 0; k < N; k++) {
    //     printf("Job ID: %d, Profit: %d, Deadline: %d\n", jobs[k].id, jobs[k].profit, jobs[k].deadline);
    // }

    // Time slots
    int slot[maxDeadline];
    
    // Initialize all slots to -1 (empty)
    for(i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    // Job sequencing
    for(i = 0; i < N; i++) {
        // Find a free slot for this job (from deadline backwards)
        for(j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                printf("Job %d scheduled at time slot %d with profit %d\n", jobs[i].id, j + 1, jobs[i].profit);
                break;
            }

        }
        printf("Current slot status after scheduling job %d:\n", jobs[i].id);
        for(int k = 0; k < N; k++) {
        printf("Job ID: %d, Profit: %d, Deadline: %d,Slot : %d \n", jobs[k].id, jobs[k].profit, jobs[k].deadline,slot[k]);
    }
    }

    // Print selected jobs
    printf("Selected Jobs (in order of execution):\n");
    for(i = 0; i < maxDeadline; i++) {
        if(slot[i] != -1)
            printf("Job %d ", slot[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}