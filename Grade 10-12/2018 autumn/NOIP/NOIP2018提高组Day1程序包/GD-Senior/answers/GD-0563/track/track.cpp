#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
#define Maxn 50010
int Ans=0,to=0;
int head[Maxn],v[Maxn<<1],w[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e,int t){
	tot++;v[tot]=e;w[tot]=t;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;w[tot]=t;nxt[tot]=head[e];head[e]=tot;
}
//dark fen lei
//case1:
int dis[Maxn];
void dfs1(int u,int f){
	if(dis[u]>dis[to])to=u;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]^f){
		dis[v[i]]=dis[u]+w[i];
		dfs1(v[i],u);
	}
}
void dfs2(int u,int f,int d){
	Ans=max(Ans,d);
	for(int i=head[u];i;i=nxt[i])
	if(v[i]^f)dfs2(v[i],u,d+w[i]);
}
//case2:
int line[Maxn];
inline bool Judge(int mid){
	int ans=0,at=1;
	while(at<n){
		int tmp=0;
		while(tmp<mid&&at<n){
			tmp+=line[at];
			at++;
		}
		if(tmp>=mid)ans++;
	}
	return ans>=m;
}
//case3:
int len[Maxn],cnt=0;
inline bool Check(int mid){
	int ans=0,at=0;
	for(int i=cnt;i>=1;--i)
	if(len[i]>=mid)ans++;
	else{at=i;break;}
	int hehe=1;
	for(int i=at;i>=1;--i){
		while(hehe<i&&len[hehe]+len[i]<mid)hehe++;
		if(hehe>=i)break;
		ans++;
		hehe++;
	}
	return ans>=m;
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	rd(n);rd(m);
	int s,e,t,maxv=0;
	bool flag=true,C=true;
	for(register int i=1;i<n;++i){
		rd(s);rd(e);rd(t);
		add_edge(s,e,t);
		maxv=max(maxv,t);
		if(e!=s+1)flag=false;
		if(s!=1)C=false;
	}
	if(m==1){
		dfs1(1,0);
		dfs2(to,0,0);
		printf("%d\n",Ans);
		return 0;
	}
	if(flag){
		for(register int i=1;i<n;++i)
		for(int j=head[i];j;j=nxt[j])
		if(v[j]==i+1)line[i]=w[j];
		int l=1,r=500000000;
		while(l<r){
			if(r==l+1){
				if(!Judge(r))r=l;
				break;
			}
			int mid=(l+r)>>1;
			if(Judge(mid))l=mid;
			else r=mid-1;
		}
		printf("%d\n",r);
		return 0;
	}
	if(C){
		for(int j=head[1];j;j=nxt[j])
		len[++cnt]=w[j];
		sort(len+1,len+cnt+1);
		int l=1,r=500000000;
		while(l<r){
			if(r==l+1){
				if(!Check(r))r=l;
				break;
			}
			int mid=(l+r)>>1;
			if(Check(mid))l=mid;
			else r=mid-1;
		}
		printf("%d\n",r);
		return 0;
	}
	printf("%d\n",maxv);
	return 0;
}
