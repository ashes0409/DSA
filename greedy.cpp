#include<bits/stdc++.h>
#define ll          long long
#define all(a)      (a).begin(),(a).end()
#define pb          push_back
#define INF         10000000000000000
using namespace std;
void solve()
{
    ll n,k,m,hx,hy,tx,ty,i,c=0,mh,mv,s,e,j,ma;
    cin>>n>>k>>m;
    vector< pair<ll,ll> >h;
    vector< pair<ll,ll> >v;
    s=((n-k)/2+1);
    e=((n+k)/2);
    for(i=0;i<m;i++)
    {
        cin>>hx>>hy>>tx>>ty;
        if(hx==tx)
        {
            if((max(hy,ty)<s)|| (min(hy,ty)>e))
            {
                if(hx>s && hx<e)
                   {
                       h.push_back(make_pair(hx,hx));
                   }
            }
            else
            {
                v.push_back(make_pair(min(hy,ty),max(hy,ty)));
            }
        }
        if(hy==ty)
        {
            if((max(hx,tx)<s)|| (min(hx,tx)>e))
            {
                if(hy>s && hy<e)
                   {
                       v.push_back(make_pair(hy,hy));
                   }
            }
            else
            {
                h.push_back(make_pair(min(hx,tx),max(hx,tx)));
            }
        }
    }
    sort(h.begin(),h.end());
    sort(v.begin(),v.end());
    mh=h.size();
    mv=v.size();
    /*cout<<"Horizontal\n";
    for(i=0;i<mh;i++)
    {
        cout<<h[i].first<<" "<<h[i].second<<"\n";
    }
    cout<<"Vertical\n";
    for(i=0;i<mv;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }*/
    i=0;j=s;ma=0;
    while(j<=e && i<mh)
    {
        if(h[i].first<=j)
        {
            ma=max(ma,h[i].second);
            i++;
        }
        else
        {
            j=ma+1;
            c++;
        }
    }
    if(j<=e)
    {
        j=ma+1;
        c++;
    }
    if(j<=e)
    {
        cout<<-1<<"\n";
        return;
    }
    i=0;j=s;ma=0;
    while(j<=e && i<mv)
    {
        if(v[i].first<=j)
        {
            ma=max(ma,v[i].second);
            i++;
        }
        else
        {
            j=ma+1;
            c++;
        }
    }
    if(j<=e)
    {
        j=ma+1;
        c++;
    }
    if(j<=e)
    {
        cout<<-1<<"\n";
        return;
    }
    cout<<c<<"\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
