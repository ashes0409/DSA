#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll big=1000000000000000-1;
/*const ll mod=1000000007;
ll f[52][52]={0};
ll a[52][52]={0};
void mul(ll a[52][52], ll f[52][52])
{
    ll i,j,k;
    ll temp[52][52]={0};
    for(i=0;i<52;i++)
    {
        for(j=0;j<52;j++)
        {
            for(k=0;k<52;k++)
            {
                temp[i][j]+=((a[k][j]*f[i][k])%mod);
            }
        }
    }
    for(i=0;i<52;i++)
    {
        for(j=0;j<52;j++)
        {
            a[i][j]=temp[i][j]%mod;
        }
    }
}
void pow(ll n)
{
    while(n>0)
    {
        if(n%2==1)
        {
            mul(a,f);
        }
        mul(f,f);
        n/=2;
    }
}*/
void multiply(ll F[2][2], ll M[2][2])
{
    ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
    F[0][0] = x%17;
    F[0][1] = y%17;
    F[1][0] = z%17;
    F[1][1] = w%17;
}
void power(ll F[2][2], ll n)
{
    if( n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
