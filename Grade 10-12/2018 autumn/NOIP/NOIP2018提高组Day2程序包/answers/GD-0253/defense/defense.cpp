#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#define N 100005
#define mo 1
using namespace std;
int n,m,head[N],nxt[N*2],to[N*2],num,p[N],sign[N],ff[N];
bool vis[N];
long long f[N][2];
string s;
void read(int &x){
	x=0;
	char c;
	int w=1;
	for (c=getchar();c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
	x*=w;
}
void add(int u,int v){
	num++;
	ff[num]=u;
	nxt[num]=head[u];
	head[u]=num;
	to[num]=v;
	num++;
	ff[num]=v;
	nxt[num]=head[v];
	head[v]=num;
	to[num]=u;
}
void DP(int x){
	vis[x]=true;
	for (int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if (!vis[v]){
			DP(v);
			if (sign[x]==1){
				f[x][0]+=f[v][1];
				f[x][1]+=(2147483647);
			}
			else if (sign[x]==2){
				f[x][0]+=(2147483647);
				f[x][1]+=(long long)min(f[v][0],f[v][1]);
			}
			else{
				f[x][0]+=f[v][1];
				f[x][1]+=(long long)min(f[v][0],f[v][1]);
			}
		}
	}
	if (sign[x]==2) f[x][0]=(2147483647);
	else if (sign[x]==1) f[x][1]=(2147483647);
	f[x][1]+=(long long)p[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);
	read(m);
	num=0;
	cin>>s;
	for (int i=1;i<=n;++i)
		read(p[i]);
	for (int u,v,i=1;i<n;++i){
		read(u);read(v);
		add(u,v);
	}
	for (int u,v,x,y,i=1;i<=m;++i){
		bool qwq=true;
		memset(f,0,sizeof(f));
		memset(sign,0,sizeof(sign));
		memset(vis,false,sizeof(vis));
		read(u);read(x);
		sign[u]=x+1;
		read(v);read(x);
		sign[v]=x+1;
		DP(1);
		for (int i=1;i<=num;++i)
		{
			if (sign[ff[i]]==1&&sign[to[i]]==1) {printf("-1\n");qwq=false;break;}
		}
		sign[u]=sign[v]=0;
		if (qwq)
		if (sign[1]==1) printf("%lld\n",f[x][0]);
		else if (sign[1]==2) printf("%lld\n",f[x][1]);
		else printf("%lld\n",(f[1][0]>f[1][1]?f[1][1]:f[1][0]));
	}
	return 0;
}
