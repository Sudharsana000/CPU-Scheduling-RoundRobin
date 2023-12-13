#include<stdio.h>
#include<conio.h>

int allDone(int n, int bt[n])
{
    for(int i=0; i<n; i++)
    {
        if(bt[i] != 0)
            return 1;
    }
    return 0;
}

void main()
{
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10], comtime[10], pro[10];
    float avg_wt, avg_tat;
    printf("Total number of process in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for(i=0; i<NOP; i++)
    {
        printf("Enter the Burst time of the Process %d\n", i+1);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        pro[i] = i+1;
    }

    for(i=0; i<NOP; i++)
        temp[i] = bt[i];

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &quant);
    int time = 0;
    int temptime = 0;

    printf("\nProcessing sequence :- \n");
    while(allDone(NOP, bt))
    {
        for(int i=0; i<NOP; i++)
        {
            if(bt[i] != 0)
            {
                temptime = time;
                if(bt[i] <= quant)
                {
                    comtime[i] = time + bt[i];
                    time = comtime[i];
                    bt[i] = 0;
                }
                else
                {
                    bt[i] -= quant;
                    time += quant;
                }
                printf("\tp%d[%d] -> %d - %d\n",i+1, bt[i], temptime, time);
            }
        }
    }

    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for(int i=0; i<NOP; i++)
    {
        printf("\nProcess %d \t\t %d \t\t\t %d \t\t %d ", pro[i], temp[i], comtime[i], comtime[i]-temp[i]);
        avg_wt += comtime[i]-temp[i];
        avg_tat += comtime[i];
    }

    avg_wt *= 1.0/NOP;
    avg_tat *= 1.0/NOP;
    printf("\nAverage Turn Around Time: %.2f", avg_wt);
    printf("\nAverage Waiting Time: %.2f", avg_tat);
    getch();
}
