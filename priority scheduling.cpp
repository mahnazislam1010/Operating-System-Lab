#include<stdio.h>
#define max 20
int main()
{
    int i,j,n,bt[max],p[max],wt[max],tat[max],pr[max],total=0,pos,temp;
    float avg_wt;
    printf("Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("Burst Time for P[%d]:", i+1);
        scanf("%d",&bt[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){

        printf("Priority for P[%d]:",i+1);
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;
    total=0;

    printf("\nGantt Chart : \n");

    printf("0 ");
    for(i=0;i<n;i++)
    {
        wt[i]=bt[i]+wt[i];
        printf("P%d %d ",p[i],wt[i]);
    }

    printf("\n\nAverage Waiting Time=%f",avg_wt);

	return 0;
}

