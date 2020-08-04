#include<stdio.h>

int n,page[20],f,fr[20],i;
void display()
{
 for(i=0;i<f;i++)
 {
  printf("%8d",fr[i]);
 }
 printf("\n");
}
void request()
{
 printf("Number of pages:");
 scanf("%d",&n);
 printf("Number of frames:");
 scanf("%d",&f);
 printf("Reference string");
 for(i=0;i<n;i++)
 {
  scanf("%d",&page[i]);
 }
 for(i=0;i<n;i++)
 {
  fr[i]=-1;
 }
}
void replace()
{
 int j,flag=0,pf=0;
 int max,lp[10],index,m;
 for(j=0;j<f;j++)
 {
  fr[j]=page[j];
  flag=1;
  pf++;
  display();
 }
 for(j=f;j<n;j++)
 {
  flag=0;
  for(i=0;i<f;i++)
  {
   if(fr[i]==page[j])
   {
    flag=1;
    break;
   }
  }
  if(flag==0)
  {
   for(i=0;i<f;i++)
   lp[i]=0;
   for(i=0;i<f;i++)
   {
    for(m=j+1;m<n;m++)
    {
     if(fr[i]==page[m])
     {
      lp[i]=m-j;
      break;
     }
    }
   }
   max=lp[0];
   index=0;
   for(i=0;i<f;i++)
   {
    if(lp[i]==0)
    {
     index=i;
     break;
    }
    else
    {
     if(max<lp[i])
     {
      max=lp[i];
      index=i;
     }
    }
   }
   fr[index]=page[j];
   pf++;
   display();
  }
 }
 printf("page faults:%d",pf);
}
void main()
{

 request();
 replace();
}
