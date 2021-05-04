#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s,t;
int n,m;
int sub(int dp[100][100],int i,int j)
{
    if(s[i]=='\0' && t[j]=='\0') return 0;
    else if(s[i]=='\0') return (m-j);
    else if(t[j]=='\0') return (n-i);
    else if(s[i]==t[j]) dp[i][j]=sub(dp,i+1,j+1);
    else dp[i][j]=min(sub(dp,i+1,j+1),min(sub(dp,i,j+1),sub(dp,i+1,j)))+1;
    return dp[i][j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    int dp[100][100];
    cout<<sub(dp,0,0);
    return 0;
}
