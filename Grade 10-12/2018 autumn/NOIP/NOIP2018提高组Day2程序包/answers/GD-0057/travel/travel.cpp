#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int a[5010],ans[5010],head[5010],k=0,num=0,n,m,f[5010],b[5010],out[5010],out1[5010];
bool vis[5010];
struct node
{
	int to,next;
}t[5010*4];
inline int read()
{int w=1,s=0;
char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
return w*s;	
}
void add(int a,int b)
{t[++k].to=b;
t[k].next=head[a];
head[a]=k;
}
bool check(int x)
{bool flag=0;
for(int i=1;i<=x;i++)
	{if(ans[i]>b[i]){flag=1;break ;}
	if(ans[i]<b[i]){flag=0;break ;}
	if(ans[i]==b[i])flag=1;
	}
if(x==n)
	{if(flag)
		{for(int i=1;i<=x;i++)
			{ans[i]=b[i];
			}
		}
	}
else{if(flag)return 1;else return 0;}
}
int find(int x)
{
if(out1[x]<out[x]||x==0)return x;
	else return find(f[x]);
}
void dfs(int x,int fa,int num)
{bool flag1=0,flag2=0;
if((num-1)!=0&&!check(num-1))return ;
if(f[x]==0)f[x]=fa,flag1=1;if(!vis[x])out1[x]++,b[num]=x,flag2=1,out1[fa]++,vis[x]=1;
if(num==n){if(flag1)f[x]=0;if(flag2)out1[x]--,out1[fa]--,vis[x]=0;check(num);return ;}
int minn=0x7fffffff;
	for(int i=head[x];i;i=t[i].next)
	{int v=t[i].to;
		if(!vis[v])
		minn=min(v,minn);
	}
if(minn!=0x7fffffff)
dfs(minn,x,num+1);
int lon=find(f[x]);
if(lon!=0)
dfs(lon,f[lon],num);
if(flag1)f[x]=0;if(flag2)out1[x]--,out1[fa]--,vis[x]=0;
}
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
n=read();m=read();
memset(ans,127,sizeof(ans));
	for(int i=1;i<=m;i++)
	{int a=read(),b=read();
		add(a,b);
		add(b,a);
		out[a]++;
		out[b]++;
	}
	out[0]=-1;
	out1[1]=-1;
	dfs(1,0,1);
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
}
