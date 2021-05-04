#include<bits/stdc++.h>
using namespace std;
struct d
{
    int node=0;
    int update=0;
};
int bsegt (int i,int k,d segt[])
{
    if(i<k)
    {
        segt[i].node=bsegt(2*i,k,segt)+bsegt(2*i+1,k,segt);
    }
    return segt[i].node;
}
void usegt (int a,int b,int s,int e,int i,int &x,d segt[])
{
    if(a==s && b==e)
    {
        segt[i].update+=x;
    }
    else
    {
        segt[i].node+=((b-a+1)*x);
        int mid=(s+e)/2;
        if(a<=mid)
        usegt(a,min(b,mid),s,mid,2*i,x,segt);
        if(b>mid)
        usegt(max(a,mid+1),b,mid+1,e,2*i+1,x,segt);
    }
}
int gsegt(int a,int b,int s,int e,int i,d segt[])
{
    int sum=0;
    if(segt[i].update!=0)
    {
        segt[i].node+=((e-s+1)*segt[i].update);
        segt[2*i].update+=segt[i].update;
        segt[2*i+1].update+=segt[i].update;
        segt[i].update=0;
    }
    if(a==s && b==e)
    {
        return segt[i].node;
    }
    else
    {
        int mid=(s+e)/2;
        if(a<=mid)
        sum+=gsegt(a,min(b,mid),s,mid,2*i,segt);
        if(b>mid)
        sum+=gsegt(max(a,mid+1),b,mid+1,e,2*i+1,segt);
    }
    return sum;
}
int main()
{
    int n,i,q;
    cin>>n>>q;
    int k = ceil(log2(n));
    k=pow(2,k);
    d segt[2*k];
    for(i=k;i<k+n;i++)
    {
        cin>>segt[i].node;
    }
    int ts=bsegt(1,k,segt);
    /*for(i=1;i<2*k;i++)
    {
        cout<<segt[i].node<<" ";
    }*/
    for(i=0;i<q;i++)
    {
        int a,b,t,x;
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>x;
            usegt(min(a,b),max(a,b),1,k,1,x,segt);
        }
        if(t==2)
        {
            int a,b,sum;
            cin>>a>>b;
            sum=gsegt(min(a,b),max(a,b),1,k,1,segt);
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
