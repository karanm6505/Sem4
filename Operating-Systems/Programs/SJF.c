#include <stdio.h>
#include <string.h>

int main()
{
    int et[20], at[10], n, i, j, temp, st[10], ft[10], wt[10],ta[10];
    int totwt = 0, totta = 0;
    float awt, ata;
    char pn[10][10], t[10];

    printf("Enter the number of processes to schedule:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the Process name, arrival time and execution times of the processes: \n");
        scanf("%s %d %d", pn[i],&at[i],&et[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(et[j]>et[j+1])
            {
                temp=et[j];
                et[j]=et[j+1];
                et[j+1]=temp;

                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                strcpy(t,pn[j]);
                strcpy(pn[j],pn[j+1]);
                strcpy(pn[j+1],t);
            }
        }
    }

    for(i = 0; i<n; i++)
    {
        if(i == 0)
        {
            st[i] = at[i];
        }
        else
        {
            st[i] = ft[i-1];
        }
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + et[i];
        ta[i] = ft[i] - at[i];
        totwt += wt[i];
        totta += ta[i];
    }

    awt = (float)(totwt/n);
    ata = (float)(totta/n);
    
    printf("\nProcess  Arrival  Execution  Waiting  TurnAround\n");
    printf("-------------------------------------------------\n");
    
    for(i=0; i<n; i++)
    {
        printf("%-8s %8d %9d %8d %10d\n", pn[i], at[i], et[i], wt[i], ta[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average TurnAround Time: %.2f\n", ata);
    
    return 0;
}