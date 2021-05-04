#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll big=1000000007;
int convert(char ch)
{
    return ch-'a'+1;
}
int main()
{
    /*ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    string l,s;
    int i,n,m,j,c=0;
    cin>>s>>l;
    ll rh=0,h=0,t=1;
    n=s.size();
    m=l.size();
    for(i=0;i<m;i++)
    {
        h=(27*h+convert(l[i]))%big;
        rh=(27*rh+convert(s[i]))%big;;
    }
    for(i=1;i<m;i++)
        t=27*t%big;
    if(h==rh)
        c++;
    for(i=m;i<n;i++)
    {
        rh=(rh-convert(s[i-m])*t%big+big)%big;
        rh=(27*rh+convert(s[i]))%big;
        if(rh==h)
            c++;
    }
    cout<<c;
    cout<<"\nAre you satisfied??";
    cin>>s;
    return 0;
}
