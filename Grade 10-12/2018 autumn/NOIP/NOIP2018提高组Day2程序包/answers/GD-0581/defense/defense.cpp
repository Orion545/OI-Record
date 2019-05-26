#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge{int ot,nex;}e[200100];
int f[100010][2],n,m,p[100010],head[100100],num;
char ca[2];
int read()
{
	int f=1,k=0;char c=getchar();
	while(c<'0'||c>'9') c=='-'&&(f=-1),c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
void add(int u,int v)
{
	e[++num].ot=v;
	e[num].nex=head[u];
	head[u]=num;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int x,a,y,b;
	n=read(); m=read(); scanf("%s",ca);
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++){x=read(); y=read(); add(x,y); add(y,x);}
	if (ca[0]=='A')
	{
		while(m--)
		{
			x=read(); a=read(); y=read(); b=read();
			memset(f,0x3f,sizeof(f)); f[0][0]=f[0][1]=0;
			for(int i=1;i<=n;i++)
			{
				if (i!=x&&i!=y){f[i][0]=f[i-1][1]; f[i][1]=min(f[i-1][0],f[i-1][1])+p[i]; continue;}
				if (i==x)
				{
					if (a==0) {f[i][0]=f[i-1][1]; f[i][1]=0x3f3f3f3f;}
					else {f[i][0]=0x3f3f3f3f; f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];}
					continue;
				}
				if (b==0) {f[i][0]=f[i-1][1]; f[i][1]=0x3f3f3f3f;}
				else {f[i][0]=0x3f3f3f3f; f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];}
			}
			int ans=min(f[n][0],f[n][1]);
			if (ans==0x3f3f3f3f) printf("-1\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
