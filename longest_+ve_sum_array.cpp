#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int LPA(int arr[],int n)
{
    int i,j,m=-1;
    int LMin[n],RMax[n];
    LMin[0]=arr[0];
    for(i=1;i<n;i++)
        LMin[i] = min(arr[i],LMin[i-1]);
    RMax[n-1]=arr[n-1];
    for(j=n-2;j>=0;j--)
        RMax[j] = max(arr[j],RMax[j+1]);
    i=0,j=0;
    while(j<n && i<n)
    {
        if(LMin[i] <= RMax[j])
        {
            m=max(m,j-i);
            j=j+1;
        }
        else
            i=i+1;
    }
    return m;
}
void solve()
{
    string s;
    cin>>s;
    int i,a,n=s.size();
    int pre[n+1];
    pre[0]=0;
    for(i=0;i<n;i++)
    {
        cin>>a;
            pre[i+1]=pre[i]+a;
    }
    int ans=LPA(pre,n+1);
    cout<<ans;
    return ;
}
int main()
 {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
