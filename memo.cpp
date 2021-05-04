#include <bits/stdc++.h>
using namespace std;
int term[1000];
int f(int n)
{
    if (term[n-1] != 0)
        return term[n-1];
    else
    {
        term[n-1] = f(n - 1) + f(n - 2) + f(n-3);
        return term[n-1];
    }
}
int main()
{
    int n;
    cin>>n;
    term[0]=1;
    term[1]=2;
    term[2]=4;
    cout<<f(n);
    return 0;
}
