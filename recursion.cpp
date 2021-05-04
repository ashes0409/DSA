#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> p;
int mi=1,ma,x;
void choose (int i,int c)
{
    if(i<p.size()-1)
    {
    choose(i+1,c);
    }
    c*=p[i];
    if(max(c,x/c)<ma)
    {
        mi=min(c,x/c);
        ma=max(c,x/c);
    }
    if(i<p.size()-1)
    {
    choose(i+1,c);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,c=1;
    cin>>x;
    ma=x;
    if(x%2==0)
    {
        while(x%2==0)
        {
            c*=2;
            x/=2;
        }
        p.push_back(c);
        c=1;
    }
    for(i=3;i<=sqrt(x);i+=2)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                c*=i;
                x/=i;
            }
            p.push_back(c);
            c=1;
        }
    }
    if(x>1)
    p.push_back(x);
    x=ma;
    choose(0,1);
    cout<<mi<<" "<<ma;
    return 0;
}
