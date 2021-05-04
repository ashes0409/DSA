#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main()
{
    int n;
    cin>>n;
    if(n&(n-1))
        cout<<"NO";
    else
        cout<<"YES";
	return 0;
}
