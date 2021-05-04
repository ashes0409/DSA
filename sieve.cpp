#include<bits/stdc++.h>
using namespace std;
void sieve( vector<int> &primes)
{
    int i,j;
    bool p[100010]={0};
    p[0]=1,p[1]=1;
    for(i=2;i<100010;i++)
    {
        if(p[i]==0)
        {
            primes.pb(i);
            for(j=i;j<100010;j+=i)
            {
                p[j]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int i,j,k,n,m;
    cin>>n;
    m=n/2;
    bool sieve[m]={0};
    for(i=1;i<m;i++)
    {
        if(sieve[i]==0)
        {
            j=3*(2*i+1);
            k=2*(2*i+1);
            //m=2*n+11;
            for(;j<n;j+=k)
            {
                sieve[(j-1)/2]=1;
            }
        }
    }
    for(i=m-1;i>=0;i--)
    {
        if(sieve[i]==0)
        {
            cout<<2*i+1<<" ";
            break;
        }
    }
    return 0;
}
