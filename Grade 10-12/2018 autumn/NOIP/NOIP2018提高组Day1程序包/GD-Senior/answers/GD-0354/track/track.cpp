#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#define inf 50005
using namespace std;

int n,m;
struct edge{
	int y,nxt,s;
	edge(){}
	edge(int yy,int nn,int ss){
		y=yy,nxt=nn,s=ss;
	}
}e[inf*2];
int head[inf],ecnt;

void addedge(int x,int y,int s){
	e[++ecnt]=edge(y,head[x],s);
	head[x]=ecnt;
	return;
}

namespace s1{

int ans=0;
int dis[inf],mx[inf];

void dfs(int u,int last){
	mx[u]=dis[u];
	int mx2=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (v!=last){
			dis[v]=dis[u]+e[i].s;
			dfs(v,u);
			if (mx[v]>mx[u]){
				mx2=mx[u];
				mx[u]=mx[v];
			}
			else if (mx[v]>mx2){
				mx2=mx[v];
			}
		}
	}
	ans=max(ans,mx2-dis[u]+mx[u]-dis[u]);
	return;
}

void solve1(void){
	dfs(1,0);
	printf("%d\n",ans);
	return;
}

}

namespace s2{

int len[inf],p[inf];
int t1,t2;

bool check(int k){
	memset(p,0,sizeof(p));
	int pos=0;
	for (int i=1;i<=n;i++){
		if (len[i]>=k){
			if (n-i+1<=t2){
				return 0;
			}
			pos=i-1;
			break;
		}
	}
	for (int i=1;i<=pos;i++){
		if (len[i]+len[pos-i+1]<k){
			return 0;
		}
	}
	return 1;
}

void solve2(){
	t1=(n-1-m)/2;
	t2=n-1-t1;
	int cnt=0;
	int l=0,r=0;
	for (int i=head[1];i;i=e[i].nxt){
		len[++cnt]=e[i].y;
		r+=len[i];
	}
	sort(len+1,len+cnt+1);
	int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return;
}

}

namespace s3{

int len[inf];

bool check(int k){
	int now=0,cnt=0;
	for (int i=1;i<=n;i++){
		if (now<k){
			now+=len[i];
		}
		else{
			cnt++;
			now=len[i];
		}
	}
	return cnt>=m;
}

void solve3(void){
	int l=0,r=0;
	for (int i=1,j=1;i<=n-1;i++,j+=2){
		len[i]=e[j].s;
		r+=len[i];
	}
	int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return;
}

}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	int p1=1,p2=1;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
		if (x!=1){
			p1=0;
		}
		if (y!=x+1){
			p2=0;
		}
	}
	if (m==1){
		s1::solve1();
	}
	else if (p2){
		s3::solve3();
	}
	else if (p1){
		s2::solve2();
	}
	return 0;
}

/*
8 3
1 2 2 
2 3 3
3 4 4 
4 5 2
5 6 5
6 7 7
7 8 1

8 3
1 2 2 2 3 3 3 4 4 4 5 2 5 6 5 6 7 7 7 8 1

5 
*/
