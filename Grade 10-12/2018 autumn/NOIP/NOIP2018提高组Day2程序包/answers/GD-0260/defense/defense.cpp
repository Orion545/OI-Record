#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100010;
struct node{
	int y,next;
}a[maxn*2];int len,first[maxn];
int n,m,d[maxn],f[maxn][2];
char ss[10];

void read(int &sum)
{
	char ch=getchar();int f=0;sum=0;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	(ch=='-')&&(f=1,ch=getchar());
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	(f)&&(sum=-sum);
}
void ins(int x,int y) {a[++len]=(node){y,first[x]};first[x]=len;}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);read(m);scanf("%s",ss);
	for(int i=1;i<=n;i++)
		read(d[i]);
	memset(first,len=0,sizeof first);
	for(int i=1;i<n;i++)
	{
		int x,y;
		read(x);read(y);
		ins(x,y);
		ins(y,x);
	}
	memset(f,63,sizeof f);
	if(ss[0]=='A' && ss[1]=='1')
	{
		for(int i=1;i<=m;i++)
		{
			int s,x,t,y;
			read(s);read(x);read(t);read(y);
			if(x==0 && y==0 && abs(s-t)==1)
			{
				printf("-1\n");
				continue;
			}
			long long ans=0;
			f[0][0]=f[0][1]=0;
			if(s>t) swap(s,t);
			if(s!=1)
			{
				f[1][0]=0;f[1][1]=f[2][0]=d[1];f[2][1]=d[2];
				for(int i=3;i<s;i++)
				{
					f[i][0]=f[i-1][1];
					f[i][1]=min(f[i-1][0],f[i-1][1])+d[i];
				}
			}
			if(x==0) ans=f[s-1][1],f[s][0]=f[s][1]=0;
			else ans=min(f[s-1][0],f[s-1][1]),f[s][0]=f[s][1]=d[s];
			printf("a%lld\n",ans);
			for(int i=s+1;i<t;i++)
			{
				if(i!=s+1 || (i==s+1 && x==1)) f[i][0]=f[i-1][1];
				f[i][1]=min(f[i-1][0],f[i-1][1])+d[i];
			}
			if(y==0) ans+=f[t-1][1],f[t][0]=f[t][1]=0;
			else ans+=min(f[t-1][0],f[t-1][1]),f[t][0]=f[t][1]=d[t];
			for(int i=t+1;i<=n;i++)
			{
				if(i!=t+1 || (i==t+1 && x==1)) f[i][0]=f[i-1][1];
				f[i][1]=min(f[i-1][0],f[i-1][1])+d[i];
			}
			ans+=min(f[n][0],f[n][1]);
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int s,x,t,y;
		read(s);read(x);read(t);read(y);
		if(x==0 && y==0)
		{
			bool tf=true;
			for(int i=first[s];i;i=a[i].next)
				if(a[i].y==t)
				{
					tf=false;
					break;
				}
			if(!tf)
			{
				printf("-1\n");
				continue;
			}
		}
	}
	return 0;
}
