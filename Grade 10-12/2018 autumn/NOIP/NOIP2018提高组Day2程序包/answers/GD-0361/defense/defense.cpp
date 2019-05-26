#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int n,m,a[100005],x[100005],y[100005],f[100005],u,s,t,v;
long long ans;
string st;
void work(int k,long long sum)
{
	if (k>n) 
	{ 
	 bool p=true;
	 for (int i=1;i<n;i++) 
	   if (f[x[i]]==1||f[y[i]]==1) p=true; else {p=false; break; }
	   if (p) ans=min(ans,sum); 
	   return;
	}
	if (k==u&&s==1||k==v&&t==1) { f[k]=1; work(k+1,sum+a[k]); f[k]=0; }
	else
	if (k==u&&s==0||k==v&&t==0) work(k+1,sum); 
	else
	 {
	 	f[k]=1;
	 	work(k+1,sum+a[k]);
	 	f[k]=0;
	 	work(k+1,sum);
	 }
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	 {
	 	scanf("%d%d",&x[i],&y[i]);
	 }
	for (int i=1;i<=m;i++)
	 {
	  scanf("%d%d%d%d",&u,&s,&v,&t);
	  ans=999999999;
	  work(1,0);
	  if (ans!=999999999) cout<<ans<<endl; else cout<<-1<<endl;
}
}
