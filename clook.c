#include <bits/stdc++.h>
using namespace std;

void Ok()
{
    long int a[1013],b[1013],c,d,e,f,g,h,t,i,j,k,l,m,n,Min,Max;
    long int ans_1,ans_2,ans_3,cnt_1,cnt_2,cnt_3,flag_1,flag_2,flag_3,temp,sum;
    double aa,bb,cc,dd,ee,ff,gg;
    char aaa,bbb,ccc,ddd;
    string spc,in,store;

    cin>>c;
    cin>>n;
    a[1] = 0;
    for(i=2;i<=(n+1);i++)
    {
        cin>>a[i];
    }
    a[n+2] = c;
    a[n+3] = 199;
    sort(a+1,a+n+4);
    for(i=1;i<=(n+2);i++)
    {
        if(a[i]==c)
        {
            d = i;
            break;
        }
    }
    sum = 0;
    j = 0;
    for(i=d;i<=(n+2);i++)
    {
        j++;
        b[j] = a[i];
    }
    for(i=d;i<(n+2);i++)
        sum += abs(a[i] - a[i+1]);

    sum += abs(a[n+2] - a[2]);
    for(i=2;i<d;i++)
    {
        j++;
        b[j] = a[i];
    }
    for(i=1;i<(d-1);i++)
        sum += abs(a[i] - a[i+1]);

    for(i=1;i<=j;i++)
        cout<<b[i]<<" ";

    cout<<endl;
    cout<<sum<<endl;

    return;
}

int main()
{
    Ok();

    return 0;
}