#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101];
bool f[26000];
int T,n,ans,bestmatch;
bool ns(int a,int b)
{
	return a<b;
}
void clr()
{
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	memset(f,false,sizeof(f));
	sort(a+1,a+n+1,ns);
	bestmatch=a[n];
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;	
	for(T;T>0;T--)
	{
		clr();
		for(int i=1;i<=n;i++)
		{
			int p=a[i];
			if(f[p])continue;
			else {f[p]=true;ans++;}
			for(int j=1;(j+p)<=bestmatch;j++)
			{
				f[j+p]=(f[j]||f[j+p]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
