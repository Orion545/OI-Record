#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<queue>

int n,m;
int head[50005],tot,sum[50005];
bool _case1=true,_case2=true,_case3=true;
int rd[50005],dis[50005];
bool visit[50005];

struct node{
	int x,y,z;
}e2[50005];

struct edge{
	int to,val,next;
}e[100005];

void build(int x,int y,int z) {
	tot++;
	e[tot].to=y;
	e[tot].val=z;
	e[tot].next=head[x];
	head[x]=tot;
}

bool cmp(node a,node b) {
	return a.z<b.z;
}

void spfa(int s) {
	queue <int> q;
	memset(dis,0,(sizeof dis));
	visit[s]=1;
	q.push(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next) {
			int y=e[i].to;
			if(visit[y]) continue;
			if(dis[y]<dis[x]+e[i].val) {
				dis[y]=dis[x]+e[i].val;
				if(!visit[y]) {
					visit[y]=1;
					q.push(y);
				}
			}
		}
	}
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m!=1) _case3=false;
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&e2[i].x,&e2[i].y,&e2[i].z);
		if(e2[i].x!=1) _case1=false;
		if(e2[i].x+1!=e2[i].y) _case2=false;
	}
	if(_case1==true) {
		sort(e2+1,e2+n,cmp);
		int ans;
		if((n-1)-2*m>=0) {
			ans=e2[n-1].z+e2[n-2*m].z;
			for(int i=2;i<=m;i++) 
				ans=min(ans,e2[n-i].z+e2[n-2*m+i-1].z);
		}
		else {
			if((n-1)%2==0) {
				int tmp=2*m-(n-1);
				ans=e2[n-tmp].z;
				for(int i=1;i<=m-tmp;i++)
					ans=min(ans,e2[i].z+e2[n-tmp-i].z);
			}
			else {
				int tmp=2*m-(n-1);
				ans=e2[n-tmp].z;
				for(int i=1;i<=m-tmp;i++) 
					ans=min(ans,e2[i].z+e2[n-tmp-i].z);
			}
		}
		cout<<ans;
	}
	else if(_case2==true) {
		int l=1,r=500000000;
		for(int i=1;i<n;i++) sum[i]=sum[i-1]+e2[i].z;
		while(l<r) {
			int mid=(l+r)/2;
			int now=1,ans=0;
			for(int i=1;i<n;i++) {
				if(sum[i]-sum[now-1]>mid) {
					now=i;
					ans++;
				}
			}
			if(ans<=m) r=mid;
			else l=mid+1;
		}
		cout<<l;
	}
	else {
		for(int i=1;i<n;i++) {
			build(e2[i].x,e2[i].y,e2[i].z);
			build(e2[i].y,e2[i].x,e2[i].z);
			rd[e2[i].x]++;
			rd[e2[i].y]++;
		}
		for(int i=1;i<=n;i++) 
			if(rd[i]==1) {
				spfa(i);
				break;
		}
		int ans=0;
		for(int i=1;i<=n;i++) 
			ans=max(ans,dis[i]);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
