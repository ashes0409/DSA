#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[26][26];
int inf=INT_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,t,ans;
    cin>>s>>t;
    int n,i,c,j,k,sum=0;
    char a,b;
    cin>>n;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
            g[i][j]=inf;
    }
    for(i=0;i<26;i++)
        g[i][i]=0;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        g[a-'a'][b-'a']=min(g[a-'a'][b-'a'],c);
    }
    if(s.size()!=t.size())
    {
        cout<<-1;
        return 0;
    }
    for(k=0;k<26;k++)
    {
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                if(g[i][k]!=inf && g[k][j]!=inf && g[i][k]+g[k][j]<g[i][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
    for(i=0;i<s.size();i++)
    {
        int pos,temp=inf;
        for(j=0;j<26;j++)
        {
            if(g[s[i]-'a'][j]!=inf && g[t[i]-'a'][j]!=inf)
            {
                if(temp>g[s[i]-'a'][j]+g[t[i]-'a'][j])
                {
                    temp=g[s[i]-'a'][j]+g[t[i]-'a'][j];
                    pos=j;
                }
            }
        }
        if(temp==inf)
        {
            cout<<-1;
            return 0;
        }
        sum+=temp;
        ans.push_back('a'+pos);
    }
    cout<<sum<<"\n"<<ans;
    return 0;
}
