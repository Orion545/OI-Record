#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k=0;
int d[50010],dis[50010],head[50010],fa[50010][23],lcc[5000][5000];
int sum[50010][3];
long long l=0,r=0,ans=0;
struct node
{
	int to,next,data;
}t[50100*2];
void add(int a,int b,int c)
	{t[++k].to=b;
	t[k].next=head[a];
	t[k].data=c;
	head[a]=k;
	}
inline int read()
	{int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
	}
void dfs(int x,int f,int lon)
	{d[x]=d[f]+1;
	dis[x]=dis[f]+lon;
	fa[x][0]=f;
	for(int i=head[x];i;i=t[i].next)
		{int v=t[i].to;
			if(v!=f)
			{dfs(v,x,t[i].data);
			}
		}
	}
int lca(int a,int b)
{if(d[a]<d[b])swap(a,b);
	for(int i=21;i>=0;i--)
	{if(d[fa[a][i]]>=d[b])a=fa[a][i];
	}
	if(a==b)return a;
	for(int i=21;i>=0;i--)
	{if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	}	
	return fa[a][0];
}
bool check(long long mid)
{int num=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{int f1=lcc[i][j];
			if((dis[i]+dis[j]-2*dis[f1])<mid)continue;
			bool flag=1;
			for(int l=1;l<=num;l++)
				{int a1=sum[l][1],b1=sum[l][2];
				int f2=lcc[a1][b1],f3=lcc[i][a1],f4=lcc[j][b1],f5=lcc[i][b1],f6=lcc[j][a1];
				if(d[f1]>d[f2])
					{if(d[f3]>d[f1]){flag=0;break ;}
					if(d[f4]>d[f1]){flag=0;break ;}
					if(d[f5]>d[f1]){flag=0;break ;}
					if(d[f6]>d[f1]){flag=0;break ;}
					}
				if(d[f1]==d[f2]){if(f1==f2){flag=0;break ;}}
				if(d[f1]<d[f2])
					{
						{if(d[f3]>d[f2]){flag=0;break ;}
						if(d[f4]>d[f2]){flag=0;break ;}
						if(d[f5]>d[f2]){flag=0;break ;}
						if(d[f6]>d[f2]){flag=0;break ;}
						}
					}
				}
			if(flag)
				{sum[++num][1]=i;
				sum[num][2]=j;
				if(num==m)return 1;
				}
			}
	return 0;
	
}
int main()
{freopen("track.in","r",stdin);
freopen("track.out","w",stdout);
n=read();m=read();
	for(int i=1;i<n;i++)
	{int a=read(),b=read(),c=read();r+=c;
	add(a,b,c);
	add(b,a,c);
	}
	d[1]=0;
	dfs(1,0,0);
	for(int j=1;j<=22;j++)
		for(int i=1;i<=n;i++)
			{fa[i][j]=fa[fa[i][j-1]][j-1];
			}
			lca(4,7);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{lcc[i][j]=lca(i,j);
			lcc[j][i]=lcc[i][j];
			}
	while(l<=r)
	{long long mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
