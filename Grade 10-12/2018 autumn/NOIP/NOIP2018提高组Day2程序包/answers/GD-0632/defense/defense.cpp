#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[100010];
int head[N],next[N<<2],to[N<<2],tot;
int pay[N];long long ans;
int p[N];bool used[N];
int n,m;
inline void add(int x,int y)
{
	next[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void lightup(int x)
{
	a[x]=1;
	for(register int i=head[x];i;i=next[i])
	{
		int y=to[i];
		a[y]=1;
	}
}
bool check()
{
    memset(a,0,sizeof(a));
    for(register int i=1;i<=tot;i++)
    {
    	lightup(p[i]);
    }
    for(register int i=1;i<=n;i++)
    if(a[i]==0)return 0;
    
    
	return 1;
}
void dfs(int x,long long sum)
{
	if(check()){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans){return;}
	for(register int i=1;i<=n;i++)
	{
		if(used[i])continue;
		used[i]=1;
		p[++tot]=i;
		dfs(i,sum+pay[i]);
		used[i]=0;
		p[tot]=0;
		tot--;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	char s1;int s2;cin>>s1>>s2;
	for(register int i=1;i<=n;i++)cin>>pay[i];
	for(register int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	int a1,x1,b1,y1;
	for(register int i=1;i<=m;i++){
		for(register int j=1;j<=n;j++)a[i]=0;
		ans=0xfffffff;
		memset(p,0,sizeof(p));
		memset(used,0,sizeof(used));
		cin>>a1>>x1>>b1>>y1;
		long long sum=0;tot=0;
		if(x1)sum+=pay[a1],p[++tot]=a1;
		used[a1]=1;
		if(y1)sum+=pay[b1],p[++tot]=b1;
		used[b1]=1;
		dfs(0,sum);
		if(ans!=0xfffffff)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
