 #include<bits/stdc++.h>
#define ll long long int

using namespace std;
ll a1,b1,c1,i2,j2,n,m,k=1000000007;
ll me (ll n,ll p,ll m)
{
    ll res=1,x=n;
    while(p>0)
    {
        if(p&1==1)
            res=(res*x)%m;
        p=p>>1;
        x=(x*x)%m;
    }
    return res;
}
ll sol (ll i,ll j,int grid[15][15])
{
    if(i==i2&&j==j2)
        return 1;
    if(i>=n || i<0 || j>=m || j<0 || grid[i][j]==0)
        return 0;
    return (sol(i,j+1,grid)*a1+sol(i+1,j+1,grid)*b1+sol(i-1,j+1,grid)*c1)%k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,p,i1,j1,i,j,res;
    cin>>n>>m>>a>>b>>c>>i1>>j1>>i2>>j2;
    char ch;
    int grid[15][15];
    a1=me(a,k-2,k);
    b1=me(b,k-2,k);
    c1=me(c,k-2,k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ch;
            if(ch=='.')
                grid[i][j]=1;
            else
                grid[i][j]=0;
        }
    }
    res=sol(i1,j1,grid)%k;
    cout<<res;
    return 0;
}
