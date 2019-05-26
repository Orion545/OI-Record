#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int last[50010],to[50000*2+10],cost[50000*2+10],next[50000*2+10],num;
int f[50010],g[50010],a[50010];
bool b[50010];
int n,m;
int ans,d;
void add(int x,int y,int z){
	next[++num]=last[x];
	last[x]=num;
	to[num]=y;
	cost[num]=z;
}
void dfs(int x,int fa,int dis){
	if(dis>ans){
		ans=dis;
		d=x;
	}
	for(int j=last[x];j;j=next[j])
		if(to[j]!=fa)
			dfs(to[j],x,dis+cost[j]);
}
bool pd1(int mid){
	int w=1;
	int s=0;
	int z=0;
	for(int i=1;i<n;i++){
		if(s>=mid){
			s=0;
			z++;
		}
		w=last[i];
		while(to[w]!=i+1)
			w=next[w];
		s+=cost[w];
	}
	if(s>=mid){
		s=0;
		z++;
	}
	if(z>=m)
		return true;
	return false;
}
bool qwe(int a,int b){return a>b;}
void dfs(int x,int fa,int t,int mid){
	int h=t+1;
	g[x]=0;
	f[x]=0;
	int w;
	for(int j=last[x];j;j=next[j]){
		if(fa!=to[j]){
			dfs(to[j],x,t,mid);
			a[++t]=g[to[j]];
			b[t]=true;
			f[x]+=f[to[j]];
		}
		else
			w=cost[j];
	}
	if(t>=h){
		sort(a+h,a+t+1,qwe);
		int i=h,j=t;
		for(;i<=j&&a[i]>=mid;i++)
		{
			b[i]=false;
			f[x]++;
		}
		for(;i<j;i++){
			for(;i<j;j--){
				if(a[i]+a[j]>=mid){
					b[i]=b[j]=false;
					f[x]++;
					break;
				}
				else
					g[x]=max(g[x],a[j]);
			}
		}
		for(int i=h;i<=t;i++)
			if(b[i])
				g[x]=max(a[i],g[x]);
	}
	g[x]+=w;
}
bool pd2(int mid){	
	dfs(1,0,0,mid);
	if(f[1]>=m)
		return true;
	return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,z;
	scanf("%d%d",&n,&m);
	bool bk1=1;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(y!=x+1)
			bk1=0;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==1){
		ans=0;
		dfs(1,0,0);
		ans=0;
		dfs(d,0,0);
		printf("%d",ans);
	}
	else if(bk1){
		int l=0,r=500000000+1;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			if(pd1(mid)){
				l=mid+1;
				ans=max(mid,ans);
			}
			else r=mid-1;
		}
		printf("%d",ans);
	}
	else{
		int l=0,r=500000000+1;
		int mid;
		while(l<r){
			mid=(l+r)/2;
			if(pd2(mid)){
				l=mid+1;
				ans=max(mid,ans);
			}
			else r=mid;
		}
		printf("%d",ans);
	}
	return 0;
}

