#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>

using namespace std;
int a[1005],mn,ans,n,j,b[1005],t,p[1005],f[25005],s;
int check()
{
	  for (int i=1;i<=b[s];i++) f[i]=0;
	  f[0]=1;mn=s;
	  int r=0;
	  for (int j=1;j<s;j++)
	  {
	  	while (f[b[j]]>0) {r++;j++;}
	  	for (int l=1;l<=b[s];l++)
	  	 for (int z=0;z<=l/b[j];z++)
	  	  if (l-z*b[j]>=0) f[l]+=f[l-z*b[j]];
	  	int o=0;
	  	for (int i=j+1;i<=s;i++)
	  	 if (f[b[i]]==0) o++;
	  	mn=min(j+o-r,mn);
	  }
	  return mn;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while (t--)
	{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
	 scanf("%d",&a[i]);
	 p[i]=0;
	}
	s=0;
	if (n==2)
	{
	 if (a[2]<a[1]) swap(a[1],a[2]);
	 if (a[2]%a[1]==0) cout<<"1"<<endl;else cout<<"2"<<endl;
	 continue;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if (i!=j&&a[i]%a[j]==0) p[i]=1;
	for (int i=1;i<=n;i++)
	 if (p[i]==0) 
	 {s++;b[s]=a[i];}
	if (s==n) 
	{cout<<s<<endl;continue;}
	sort(1+b,1+b+s);
	cout<<check()<<endl;
	}
	return 0;
}
