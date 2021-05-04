#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n,k,x,j,m1=1,m2=1,q,l,r;
    cin>>n>>q;
    k=log2(n);
    vector <int> data[k+1];
    for(i=0;i<n;i++)
    {
        cin>>x;
        data[0].push_back(x);
    }
    for(i=1;i<=k;i++)
    {
        m2*=2;
        for(j=0;j+m2<=n;j++)
            data[i].push_back(min(data[i-1][j],data[i-1][j+m1]));
        m1*=2;
    }
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        l--;
        r--;
        int temp=r-l+1;
        k=log2(temp);
        cout<<min(data[k][l],data[k][r-pow(2,k)+1])<<"\n";
    }
    return 0;
}
