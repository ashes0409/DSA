#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j;
    cin>>n>>m;
    ll a[n][m];
    ll dp[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>a[i][j];
    }
    dp[n-1][m-1]=a[n-1][m-1];
    for(j=m-2;j>=0;j--)
        dp[n-1][j]=dp[n-1][j+1]+a[n-1][j];
    for(i=n-2;i>=0;i--)
        dp[i][m-1]=dp[i+1][m-1]+a[i][m-1];
    for(i=n-2;i>=0;i--)
    {
        for(j=m-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]))+a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
