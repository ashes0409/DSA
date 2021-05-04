#include<bits/stdc++.h>
using namespace std;
int bsegt (int i,int k,int segt[])
{
    if(i<k)
    {
        segt[i]=bsegt(2*i,k,segt)+bsegt(2*i+1,k,segt);
    }
    return segt[i];
}
void usegt (int i,int k,int x,int segt[])
{
    i+=(k-1);
    int diff=x-segt[i];
    for(;i>=1;i/=2)
    {
        segt[i]+=diff;
    }
}
int gsegt(int a,int k,int segt[])
{
    a += (k-1);
    int s = 0;
    if(a==2*k-1)
    {
        return segt[1];
    }
    while (a>1)
    {
        if (a%2 == 0) s += segt[a--];
        a/=2;
    }
return s;
}
int main()
{
    int n,i,q;
    cin>>n>>q;
    int k = ceil(log2(n));
    k=pow(2,k);
    int segt[2*k]={0};
    for(i=k;i<k+n;i++)
    {
        cin>>segt[i];
    }
    int ts=bsegt(1,k,segt);
    for(i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,j;
            cin>>j>>x;
            usegt(j,k,x,segt);
        }
        if(t==2)
        {
            int a,b,sum;
            cin>>a>>b;
            sum=gsegt(b,k,segt)-gsegt(a-1,k,segt);
            cout<<sum;
        }
    }
    /*cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<gsegt(i,k,segt)<<" ";
    }*/
    return 0;
}
