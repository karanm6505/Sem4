#include <stdio.h>
#include <string.h>

int main()
{
    char pn[10][10], t[10];
    int arr[10], bur[10],star[10],finish[10],tat[10],wt[10],i,j,n;
    int totwt = 0, tottat = 0;

    printf("Enter the number of processes to schedule:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the Process name, arrival time and burst times of the processes: \n");
        scanf("%s %d %d", pn[i],&arr[i],&bur[i]);
    }

    // Bubble sort based on arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                // Swap arrival times
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Swap burst times
                temp = bur[j];
                bur[j] = bur[j+1];
                bur[j+1] = temp;
                
                // Swap process names
                strcpy(t,pn[j]);
                strcpy(pn[j],pn[j+1]);
                strcpy(pn[j+1],t);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(i==0)
            star[i] = arr[i];
        else
            star[i] = finish[i-1];

        wt[i] = star[i] - arr[i];
        finish[i] = star[i] + bur[i];
        tat[i] = finish[i] - bur[i];
    }
    
    printf("\nProcess Name\tArrival Time\tBurst Time \tWait Time \tStart\tTurnaround Time\tFinish:\n");
    printf("\n-------\t-------\t-------\t-------\t-------\t-------\t-------\t-------\t-------\t-------\t");

    for(i = 0; i<n; i++)
    {
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d", pn[i],arr[i],bur[i],wt[i],star[i],tat[i],finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    } 

    printf("\nAverage Waiting Time: %f", (float)(totwt/n));
    printf("\nAverage Turnaround Time: %f", (float)(tottat/n));
}
