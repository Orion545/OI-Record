#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5000+5;
int n,m;

struct node{
	int x,y;
}e[maxn<<1];
bool cmp(node u,node v)
{
	return u.y>v.y;

}struct f{
	int t,tx;
}a[maxn<<1];
int en=1;
int head[maxn],an=0,vis[maxn],c1[maxn],c2[maxn],s[maxn],n1=1,n2=1,jud=1,f=0,c=0;
inline void addline (int u,int v)
{
	a[an].t=v;a[an].tx=head[u];head[u]=an++;
	return;
}
inline void dfs(int now,int cnt)
{

	//cout<<now<<" "<<cnt<<endl;
	if(c==1)return;
	if(!vis[now])
	{
		vis[now]=1;
		if(jud==1)c2[cnt]=now;
		if(jud==2)c1[cnt]=now;
	}
	if(cnt==n)
	{
		
		if(f==0)
		{
			jud=2;f=1;
			/*if(jud==1)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",c1[i]);
		printf("\n");
	}
	if(jud==2)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",c2[i]);
		printf("\n");
	}*/
		}
		else
		{
			int j=1;
			while(c1[j]==c2[j])j++;
			jud=2;
			if(c1[j]<c2[j]&&c1[j]!=0)jud=1;
			if(!c)
			{
				c=1;return;
			}
				
		}
	}
	else
	{
		int p=0;
		for(int i=head[now];~i;i=a[i].tx)
		{
			
			if(!vis[a[i].t])
			{p=1;
				if((!f)||(jud==1&&a[i].t<=c1[cnt+1])||(jud==2&&a[i].t<=c2[cnt+1]))
				{
					s[a[i].t]=now;
					dfs(a[i].t,cnt+1);
				}
			}
		}
		if(p==1)cnt++;
		if(s[now]!=-1)
		dfs(s[now],cnt);
	}
	vis[now]=0;
	return ;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	int s1=1;
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		if(x==0||y==0)s1=0;
		e[en].x=x;e[en].y=y;en++;
		e[en].x=y;e[en].y=x;en++;
		
	}
	sort(e+1,e+en,cmp);
	for(int i=1;i<en;i++)
	{
		addline(e[i].x,e[i].y);
	}
	
	s[s1]=-1;
	dfs(s1,1);
	if(jud==1)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",c1[i]);
		printf("\n");
	}
	if(jud==2)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",c2[i]);
		printf("\n");
	}
	return 0;
}
