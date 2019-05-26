#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int readq(){
	int j=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		j=(j<<3)+(j<<1)+(c^48);
		c=getchar();
	}
	return j;
}
void writeq(ll x){
	if (x>9) writeq(x/10);
	putchar(x%10+48);
}
#define N 100100
int n,m,a[N];
ll ans,f[N][3];//no ; his son;himsely
char type[10];
int last[N*2],wh[N],v[N*2],Z;
inline void add(int a,int b){last[++Z]=wh[a];wh[a]=Z;v[Z]=b;}
int p[N];
bool c[N],c2[N];
void dfs(int x){
	c[x]=1;
	f[x][0]=0;
	f[x][1]=1ll<<40;
	f[x][2]=a[x];
	ll sum=0;
	bool flag=1;
	for (int i=wh[x];i;i=last[i])
		if (!c[v[i]]){
			dfs(v[i]);
			flag=0;
			f[x][0]+=min(f[v[i]][1],f[v[i]][2]);
			f[x][2]+=min(f[v[i]][0],min(f[v[i]][1],f[v[i]][2]));
			sum+=min(f[v[i]][1],f[v[i]][2]);
		}
	for (int i=wh[x];i;i=last[i])
		if (c2[v[i]])
			f[x][1]=min(f[x][1],sum-min(f[v[i]][1],f[v[i]][2])+f[v[i]][2]);
	c2[x]=1;
	if (p[x]==1){
		f[x][2]=1ll<<40;
	}
	if (p[x]==2){
		f[x][0]=f[x][1]=1ll<<40;
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type);
	for (int i=1;i<=n;i++) a[i]=readq();
	for (int i=1,x,y;i<n;i++){
		x=readq();y=readq();
		add(x,y);
	}
	while (m--){
		memset(p,0,sizeof(p));
		int x=readq(),x1=readq(),y=readq(),y1=readq();
		p[x]=x1+1;
		p[y]=y1+1;
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(c2,0,sizeof(c2));
		dfs(1);
		if (min(f[1][2],f[1][1])==(1ll<<40))puts("-1"); else{
			writeq(min(f[1][2],f[1][1]));
			putchar('\n');
		}
	}
	return 0;
}
