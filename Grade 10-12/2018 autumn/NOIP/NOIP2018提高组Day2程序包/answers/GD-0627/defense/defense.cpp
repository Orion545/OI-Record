#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string c;int n,m;
struct node
{
	int pi,last,next;
}t[500000];
bool vis[500000];
bool cmp(node e,node f)
{
	return e.pi<f.pi;
}
int find(int ans)
{
	for(int i=1;i<=n;i++)
    {
    	if(vis[t[i].next]||vis[t[i].last]) {vis[i]=1;continue;}
    	else 
    	{
    		ans+=t[i].pi;
    		vis[i]=1;
    		vis[t[i].next]=1;vis[t[i].last]=1;
    	}
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i]) return -1;
    }
    return ans;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int a,b,x,y;
	scanf("%d%d",&n,&m);
	cin>>c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",t[i].pi);
	}
	t[1].next=2;
	for(int i=2;i<=n-1;i++)
	{
		t[i].last=i-1;
		t[i].next=i+1;
	}
	t[n].last=n-1;
	if(c[0]=='A'&&c[1]=='3')
	{
		for(int i=1;i<=m;i++)
		{
			int ans=0;
			memset(vis,0,sizeof(vis));
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(a==1) {vis[x]=1;ans+=t[x].pi;}
			if(a==0) {vis[x]=1;}
			if(b==0) {vis[y]=1;}
			if(b==1) {vis[y]=1;ans+=t[x].pi;}
			printf("%d\n",find(ans));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
