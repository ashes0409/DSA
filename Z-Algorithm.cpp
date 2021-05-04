#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string p,t;
    cin>>p>>t;
    string y=p+"1"+t;
    int n=y.size(),m=p.size();
    int i,c,l,r,z[n];
    z[0]=-1;i=0;r=0;
    for(i=1;i<n;i++)
    {
        if(i>r)
        {
            for(c=0;c<n-i;c++)
            {
                if(y[i+c]!=y[c])
                    break;
            }
            z[i]=c;
            l=i;
            r=i+c-1;
        }
        else
        {
            if(z[i-l]<(r-i+1))
                z[i]=z[i-l];
            else
            {
                l=i;
                for(;r<n;r++)
                {
                    if(y[r]!=y[r-l])
                        break;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<z[i]<<" ";
    }
    cout<<"\n";
    for(i=m;i<n;i++)
        {
            if(z[i]==m)
                cout<<"Found at (start from 1) "<<i-m<<"\n";
        }
    return 0;
}
