#include <bits/stdc++.h>
using namespace std;
int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    string t;
    cin>>s>>t;
    int i,n=s.size();
    int j,m=t.size();
    int L[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                L[i][j]=0;
            else if(s[i-1]==t[j-1])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i][j-1],L[i-1][j]);
            cout<<L[i][j]<<" ";
        }
        cout<<"\n";
    }
    int ls=L[n][m];
    i=n;j=m;
    cout<<L[n][m]<<"\n";
    string sub;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            sub.push_back(s[i-1]);
            ls--;i--;j--;
        }
        else
        {
            if(L[i-1][j]>L[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(sub.begin(),sub.end());
    cout<<sub;
    return 0;
}
