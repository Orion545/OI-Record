#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100010;
int p[maxn],cnt=0,head[maxn],vis[maxn];

struct node{
	int to;
	int next;
}edge[maxn];

void add(int a,int b)
{
	edge[++cnt].next=head[a];
	edge[cnt].to=b;
	head[a]=cnt;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,u,v,a,x,b,y;
	string type;
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	cin>>type;
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(type[0]=='A')
	{
		for(int j=1;j<=m;j++)
		{
		    scanf("%d%d%d%d",&a,&x,&b,&y);
		    vis[a]=x;
		    vis[b]=y;
		    if(((a-b)%2==0||(b-a)%2==0)&&x!=y)
		    {
	            printf("-1\n");
	            continue;
		    }
		    if(((a-b)%2==1||(b-a)%2==1)&&x==y)
		    {
		    	printf("-1\n");
		    	continue;
		    }
		    	for(int i=a+1;i<=n;i++)
		       {
		    	   if(vis[i-1])
		    		   vis[i]=0;
		    	   else
		    	   vis[i]=1;
		       }
		       for(int i=a-1;i>=1;i--)
		       {
		       	if(vis[i+1])
		       	vis[i]=0;
		       	else
		       	vis[i]=1;
		       }
			   int  tot=0;
		       for(int i=1;i<=n;i++)
		       {
		       	if(vis[i])
		       	tot+=p[i];
		       }
		    printf("%d\n",tot);
		}
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	

