#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
int LB(int a[], int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (a[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<LB(a,0,n,k);
    return 0;
}
