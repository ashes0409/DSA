#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,i,j,c=0,k;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  {
      cin>>a[i];
  }
  cin>>m;
  sort(a,a+n);
  i=0;j=n-1;
  while(i<j)
  {
      if(a[i]+a[j]==m)
      {
          cout<<a[i]<<"+"<<a[j]<<"="<<m;
          return 0;
      }
      else if(a[i]+a[j]<m)
      i++;
      else if(a[i]+a[j]>m)
      j--;
  }
  cout<<"No pair found";
  return 0;
}