#include<bits/stdc++.h>
#define ll long long int

using namespace std;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,k,p,m=1000000009,inv,res1,res2=0,i;
    string s;
    cin>>n>>a>>b>>k;
    cin>>s;
    res1=(me(b,k,m)-me(a,k,m)+m)%m;
    inv=me(res1,m-2,m);
    res1=(me(b,n+1,m)-me(a,n+1,m)+m)%m;
    res1=(res1*inv)%m;
    inv=me(a,m-2,m);
    p=me(a,k-1,m);
    for(i=0;i<k;i++)
    {
        if(s[i]=='+')
            res2=(res2+p)%m;
        else
            res2=(res2-p)%m;
        p=((((p*b)%m)*inv)%m);
    }
    if(res2<0)
        res2+=m;
    res1=(res1*res2)%m;
    cout<<res1;
    return 0;
}
