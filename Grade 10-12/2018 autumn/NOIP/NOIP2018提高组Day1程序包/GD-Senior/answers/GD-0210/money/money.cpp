#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=105,M=25005;
int n,mx,cnt;
int a[N];
bool ban[M];

int read()
{
	int ret=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c^48),c=getchar();
	return ret;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T=read();
	while(T--)
	{
		memset(ban,0,sizeof(ban));mx=0;cnt=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		if(a[1]==1) {puts("1");continue;}
		//for(int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
		ban[0]=1;
		for(int i=1;i<=n;++i)
		{
			if(ban[a[i]]) continue;
			++cnt;
			for(int j=0;j<=mx-a[i];++j) if(ban[j]) ban[j+a[i]]=1;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
