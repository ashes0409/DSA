#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
pair<int, int> e[N];
map<int, vector<int> > a;
bool used[N];
vector<int> ans;

void dfs(int v)
{
    for (int i : a[v]) if (!used[i]) {
        used[i] = true;
        dfs(e[i].first + e[i].second - v);
    }
    ans.push_back(v);
}
int main()
 {

    int n,i,x,y;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x>>y;
        e[i] = {x, y};
        a[x].push_back(i);
        a[y].push_back(i);
    }
    map<int, vector<int> > :: iterator z;
    for (z=a.begin();z!=a.end();z++)
    {
        if (z->second.size() % 2)
        {
            dfs(z->first);
            break;
        }
    }
    for (i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
