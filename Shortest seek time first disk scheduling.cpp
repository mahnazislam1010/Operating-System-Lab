#include <bits/stdc++.h>
using namespace std;

int main()

{

int n,head,i,j,Total_distance=0,diff=0,Position_value=0,position=0,sec_min=0;

printf("Size of queue : ");
scanf("%d",&n);

int queue[n];

printf("Elements of queue :");
for(i=0;i<n;i++){
scanf("%d",&queue[i]);
}

printf("Head: ");
scanf("%d",&head);

/* printf("Enter the lower_bound of queue:");
        scanf("%d",&lower_bound);*/

printf("Path : ");
printf("%d ",head);

for(i=0;i<n;i++){
  int min=111111,diff=0;
   for(j=0;j<n;j++){
       diff = abs(queue[j]-head);
        if(diff<min && diff!=0 && diff!=head ){
            min=diff;
            Position_value=queue[j];
            position=j;

        }
      }
    printf("%d ",Position_value);
    queue[position]=NULL;

    head=Position_value;

    Total_distance+=min;

}
printf("\nTotal distance : %d\n",Total_distance);
return 0;
}