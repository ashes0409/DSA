#include<bits/stdc++.h>
#define ll long long int
#define ld long double
ll a,b,h,v1,v2;
ld f (ld x1)
{
    return (sqrt(a*a+x1*x1)*1.0/v1)+(sqrt((h-x1)*(h-x1)+b*b)*1.0/v2);
}
ld ts(ld l,ld r)
 {
    ld eps = 1e-12,m1,m2,f1,f2;
    while ((1-l*1.0/r) > eps)
    {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        f1 = f(m1);
        f2 = f(m2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ld t1,xmax;
    cin>>a>>b>>h>>v1>>v2;
    xmax=h*1.0;
    t1=ts(0,xmax);
    cout<<setprecision(11)<<t1;
    return 0;
}
