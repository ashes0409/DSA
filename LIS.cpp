#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,c=1,m=0;
    vector<int>lis;
    cin>>n;
    pair<int,int> a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=-1;
    }
    int dp[n];
    for(i=0;i<n;i++)
    {
        dp[i]=0;
        for(j=0;j<i;j++)
        {
            if(a[i].first>a[j].first)
            {
                if(dp[i]<dp[j])
                {
                    a[i].second=j;
                    dp[i]=dp[j];
                }
            }
        }
        dp[i]++;
        if(c<dp[i])
        {
            m=i;
            c=dp[i];
        }
    }
    cout<<c<<endl;
    while(m!=-1)
    {
        lis.push_back(a[m].first);
        m=a[m].second;
    }
    for(i=c-1;i>=0;i--)
        cout<<lis[i]<<" ";
    return 0;
}
