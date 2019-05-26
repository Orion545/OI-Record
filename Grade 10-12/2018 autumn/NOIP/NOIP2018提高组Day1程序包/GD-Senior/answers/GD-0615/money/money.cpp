#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,s,a[105],m,z[105];
bool ok(int q)
{
	for (int i=1;i<=n;i++)
	  {
	  	bool qw=false;
	  	for (int j=1;j<q;j++)
	  	  {
	  	  	if (a[i]%z[j]==0) qw=true;
	  	  	if (qw) break;
	  	    for (int k=j+1;k<=q;k++)
	  	      {
	  	      	if (a[i]%z[k]==0) qw=true;
	  	      	if (qw) break;
	  	    	int tl=z[j]+z[k];
	  	    	for (int r=1;r<=a[i]/tl;r++)
	  	    	  {
	  	    	  	int x=a[i]-r*tl;
	  	    	  	if (x%z[j]==0||x%z[k]==0) {qw=true;break;}
	  	          }
	  	      }
	      }
	    if (!qw) return false;
	  }
	return true;
}
void hs(int i)
{
	if (i==n+1) 
	  {
	  	if (m==0||m==n) return;
	  	if (ok(m)) s=min(s,m);
	  	return;
	  }
	m++;
	z[m]=a[i];
	hs(i+1);
	z[m]=0;
	m--;
	hs(i+1);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	  {
	  	cin>>n;s=n;
	  	if (n==2)
	  	  {
	  	  	cin>>a[1]>>a[2];
	  	  	if (a[1]%a[2]==0||a[2]%a[1]==0) cout<<1<<endl;
	  	  	  else cout<<2<<endl;
	  	  	continue;
	  	  }
	  	for (int j=1;j<=n;j++) cin>>a[j];
	  	hs(1);
	  	cout<<s<<endl;
	  }
	return 0;
}
