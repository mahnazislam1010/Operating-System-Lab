#include<stdio.h>
struct times
{
       int p,bt,wt,rnt;
};

int main()
{
       int i,j,n,time,remain,flag=0,ts;
       struct times a[100];
       float avgwt=0;
       printf("Enter No Of process: ");
       scanf("%d",&n);
       remain=n;
       for(i=0;i<n;i++)
       {
              printf("P%d : ",i);
              scanf("%d",&a[i].bt);
              a[i].p = i;
              a[i].rnt = a[i].bt;
       }
       printf("Enter Quantum No: ");
       scanf("%d",&ts);
       printf("\nGantt Chart:\n0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf("--P%d--%d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf("--P%d--%d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     a[i].wt = time-a[i].bt;
                     avgwt = avgwt + time-a[i].bt;

                     flag=0;
              }
              if(i==n-1)
                     i=0;
              else if(a[i+1].bt <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n");
       avgwt = avgwt/n;
       printf("\nAverage Waiting Time: %.2f\n",avgwt);
       return 0;
}

