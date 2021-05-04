#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
typedef long double ld;
stack <int> s;
vector <vector <int> >g;
vector <bool> v;
vector <int> circle;
bool found = 0;
void find_cycle(int e,int p)
{
    if(found==1)
    {
        v[e]=1;
        return ;
    }
    v[e]=1;
    s.push(e);
    for(int i=0;i<g[e].size();i++)
    {
        if(v[g[e][i]]==1 && g[e][i]!=p && circle.empty())
        {
            while(s.top()!=g[e][i])
            {
                circle.pb(s.top());
                s.pop();
            }
            circle.pb(g[e][i]);
            found = 1;
            return ;
        }
        else if(v[g[e][i]]==0)
        {
            find_cycle(g[e][i],e);
        }
    }
    if(found == 0)
    s.pop();
}
int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,a,b,n;
    cin>>n;
    g.resize(n+1);v.resize(n+1,0);
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            find_cycle(i,-1);
        }
    }
    for(i=0;i<circle.size();i++)
    {
        cout<<circle[i]<<" ";
    }
    return 0;
}
