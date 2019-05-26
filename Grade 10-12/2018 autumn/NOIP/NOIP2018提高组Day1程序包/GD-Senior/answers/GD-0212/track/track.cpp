#include<iostream>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxN=50010;
struct bian{
	int po,next,value;
}edge[2*maxN];
int n,m;
int head[maxN],tot;
int dis[maxN],deep[maxN];
int ans[maxN],fa[maxN][30],maxd[2];
bool book[maxN],flag1=true,flag2=true,vis[maxN];

inline void insert(int x,int y,int z)
{
	edge[++tot].po=y;
	edge[tot].next=head[x];
	edge[tot].value=z;
	head[x]=tot;
}

inline void dfs(int x,int father)
{
	int t=head[x];
	bool flag=false;
	while(t!=0){
		int y=edge[t].po;
		if(y!=father){
			deep[y]=deep[x]+1;
			dis[y]=dis[x]+edge[t].value;
			fa[y][0]=x;
			flag=true;
			dfs(y,x);
		}
		t=edge[t].next;
	}
	if(flag==false){
		book[x]=true;
		ans[++ans[0]]=x;
	}
}

void prepare()
{
	for(int i=1;i<=20;++i){
		for(int j=1;j<=n;++j){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
}

int operate(int x,int y)
{
	for(int i=20;i>=0;--i){
		if((y-(1<<i))>=0){
			y-=(1<<i);
			x=fa[x][i];
		}
	}
	return x;
}

int findfa(int x,int y)
{
	if(deep[x]>deep[y])
		x=operate(x,deep[x]-deep[y]);
	if(deep[x]<deep[y])
		y=operate(y,deep[y]-deep[x]);
	if(x==y)
		return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

void work1()
{
	memset(dis,0,sizeof(dis));
	memset(deep,0,sizeof(deep));
	dfs(1,0);
	prepare();
	int nans=0;
	for(int i=1;i<=ans[0];++i){
		for(int j=1;j<=ans[0];++j){
			if(i!=j){
				int lca=findfa(ans[i],ans[j]);
				int no=deep[ans[i]]+deep[ans[j]]-2*deep[lca];
				int d=dis[ans[i]]+dis[ans[j]]-2*dis[lca];
				nans=max(nans,d);
			}
		}
	}
	cout<<nans<<endl;
}

bool check(int x)
{
	int sum=0,num=0;
	for(int i=1;i<=n;++i){
		if(num>=m)
			break;
		sum+=dis[i]-dis[i-1];
		if(sum>=x){
			num++;
			sum=0;
		}
	}
	if(num>=m)
		return true;
	return false;
}

int erfen(int l,int r)
{
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	return l-1;
}

void work2()
{
	memset(dis,0,sizeof(dis));
	memset(deep,0,sizeof(deep));
	dfs(1,0);
	long long ans=erfen(1,dis[n]);
	cout<<ans<<endl;
}

void qsort(int l,int r)
{
	if(l>=r)
		return;
	int i=l,j=r;
	int t=dis[rand()%(r-l+1)+l];
	while(i<=j){
		while(dis[i]>t)i++;
		while(dis[j]<t)j--;
		if(i<=j){
			swap(dis[i],dis[j]);
			i++;
			j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
}

int dich(int l,int r,int target)
{
	while(l<=r){
		int mid=(l+r)/2;
		if(dis[mid]>=target)
			l=mid+1;
		else
			r=mid-1;
	}
	return l-1;
}

bool judge(int x)
{
	int num=0;
	for(int i=1;i<=n;++i){
		if(num>=m)
			break;
		if(vis[i]==false){
			int k=x-dis[i];
			int t=dich(1,n,k);
			for(int j=t;j>=1;++j){
				if(vis[j]==false){
					vis[i]=true;
					vis[j]=true;
					num++;
					break;
				}
			}
		}
	}
	if(num>=m)
		return true;
	return false;
}

int erfen2(int l,int r)
{
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	return l-1;
}

void work3()
{
	memset(dis,0,sizeof(dis));
	memset(deep,0,sizeof(deep));
	dfs(1,0);
	srand(10000000);
	qsort(1,n);
	long long ans=erfen2(1,dis[1]+dis[2]);
	cout<<ans<<endl;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;++i){
		int a,b,v;
		cin>>a>>b>>v;
		if(a!=1)
			flag2=false;
		if(b!=(a+1))
			flag1=false;
		insert(a,b,v);
		insert(b,a,v);
	}
	if(flag1==true)
		work2();
	else if(flag2==true)
		work3();
	else if(m==1)
		work1();
	return 0;
}
