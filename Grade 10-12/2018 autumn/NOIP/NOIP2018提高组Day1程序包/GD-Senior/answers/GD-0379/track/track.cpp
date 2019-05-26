#include <bits/stdc++.h>
#define N 50010
using namespace std;

long long len1=0,len2=0,p1=0,p2=0,pre[N];
int head[N],cnt=0,kkk[N];
struct ed{
	int v,w,nxt;
}e[N<<1];
inline void read(int &x){
	int y=0;char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(!(c<'0' || c>'9')) y=y*10+c-'0',c=getchar();
	x=y;
}
inline void add(int a,int b,int c){
	e[++cnt]=(ed){b,c,head[a]},head[a]=cnt;
	e[++cnt]=(ed){a,c,head[b]},head[b]=cnt;	
}

void dfs1(int x,int fa,int dep){
	for(int i=head[x];i;i=e[i].nxt){
		int to=e[i].v;
		if(fa!=to) dfs1(to,x,dep+e[i].w);
	}
	if(e[head[x]].v==fa && e[head[x]].nxt==0){
		if(1ll*dep>len1){
			len1=dep;
			kkk[p1]=0,kkk[x]=1;
			p1=x;
		}
	} 
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=e[i].nxt){
		int to=e[i].v;
		if(fa!=to) dfs(to,x);
		if(x!=1) kkk[x]|=kkk[to];
	}
}
void dfs2(int x,int fa,int dep){
	for(int i=head[x];i;i=e[i].nxt){
		int to=e[i].v;
		if(fa!=to && !kkk[to]) dfs2(to,x,dep+e[i].w);
		if(x!=1) kkk[x]|=kkk[to];
	}
	if(e[head[x]].v==fa && e[head[x]].nxt==0){
		if(1ll*dep>len2) len2=dep;
	} 
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,i,a,b,c;
	bool p=1;
	long long sum=0,mn;
	read(n),read(m);
	for(i=1;i<n;++i){
		read(a),read(b),read(c);
		if(a>b) swap(a,b);
		add(a,b,c);
		if(b!=a+1 || a!=b+1) p=0;
		pre[a]=c;
		sum+=c;
	}
	if(m==1){
		dfs1(1,0,0);
		dfs(1,0);
		dfs2(1,0,0);
		printf("%lld",len1+len2);
	}else{
		if(p==1){
			mn=sum;
			sum/=m;
			for(i=1;i<n;){
				long long x=0;
				while(x<sum){
					x+=pre[i];
					i++;
				}
				mn=min(x,mn);
			}
			printf("%lld",mn);
		}
	}
}
