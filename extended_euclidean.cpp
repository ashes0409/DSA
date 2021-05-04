#include <bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
    int x,y;
    int a,b;
    cin>>a>>b;
    int g = gcdExtended(a, b, &x, &y);
    cout<<a<<"*"<<x<<" + "<<b<<"*"<<y<<"="<<g<<"\n";
    cout<<"The gcd is "<<g;
    return 0;
}
