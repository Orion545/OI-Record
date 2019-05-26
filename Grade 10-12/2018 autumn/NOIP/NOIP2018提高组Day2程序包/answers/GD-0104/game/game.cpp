#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 10;
const int L = 300;
const int mo = 1e9+7;

int n,m;
int f[N*2][L][L];
struct status{
	int r,c,u;
	status(const int r_=0,const int c_=0,const int u_=0){r=r_;c=c_;u=u_;}
	friend bool operator <(status a,status b){
		if (a.r!=b.r)return a.r<b.r;
		if (a.c!=b.c)return a.c<b.c;
		return a.u<b.u;
	}
};
map<status,int>id;
int k;
int tr[505][505];
status que[150];

int dfs(int r,int c,int u){
	if (r>=n&&r<m)r=m;
	status t=status(r,c,u);
	if (id[t])return id[t];
	id[t]=++k;
	que[k]=t;
	int st=k;
	int pl,pr,pv=0;
	if (r==1)pl=pr=pv=1;
	else{
		if (r>m)pl=r-m+1;else pl=1;
		if (r<n)pr=r;else pr=n;
		fo(i,pl,pr)pv|=(1<<(i-1));
	}
	int L,R,now=0;
	if (r+1>m)L=(r+1)-m+1;else L=1;
	if (r+1<n)R=r+1;else R=n;
	fo(i,L,R)now|=(1<<(i-1));
	int u1=u|(u<<1);
	fo(i,max(2,L),R)
	if (i<=pr&&i-1>=pl&&((c&(1<<(i-1)))>0)==((c&(1<<(i-2)))>0))u1|=(1<<(i-1));
	u1=u1&now;
	fo(p,L-1,R){
		int c1=0;
		fo(i,p+1,R)c1|=(1<<(i-1));
		bool can=1;
		fo(i,pl,pr)
		if ((u&(1<<(i-1)))>0&&i>=L&&i+1<=R&&((c1&(1<<(i-1)))>0)!=((c1&(1<<i))>0))can=0;
		if (can){
			int to=dfs(r+1,c1,u1);
			tr[st][to]++;
		}
	}
	if (r>=n&&r==m){
		L=pl,R=pr,now=pv;
		int u1=u|(u<<1);
		fo(i,max(2,L),R)
		if (i<=pr&&i-1>=pl&&((c&(1<<(i-1)))>0)==((c&(1<<(i-2)))>0))u1|=(1<<(i-1));
		u1=u1&now;
		fo(p,L-1,R){
			int c1=0;
			fo(i,p+1,R)c1|=(1<<(i-1));
			bool can=1;
			fo(i,pl,pr)
			if ((u&(1<<(i-1)))>0&&i>=L&&i+1<=R&&((c1&(1<<(i-1)))>0)!=((c1&(1<<i))>0))can=0;
			if (can){
				int to=dfs(r,c1,u1);
				tr[st][to]++;
			}
		}
	}
	return st;
}

struct matrix{
	LL a[150][150];
	LL* operator [](int x){return a[x];}
	void init(){
		fo(i,1,k)fo(j,1,k)a[i][j]=0;
	}
};
matrix operator *(matrix a,matrix b){
	matrix c;
	fo(i,1,k)fo(j,1,k)c[i][j]=0;
	fo(i,1,k)
		fo(j,1,k)
		if (a[i][j])
			fo(x,1,k)
			c[i][x]=(c[i][x]+a[i][j]*b[j][x])%mo;
	return c;
}

LL tmp[150];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=get();m=get();
	dfs(1,0,0);
	int tim=m>=n?m-n:0;
	matrix ans;
	fo(i,1,k)fo(j,1,k)ans[i][j]=0;
	ans[1][id[status(1,0,0)]]=1;
	fo(i,1,n-1){
		matrix t;
		t.init();
		fo(x,1,k)tmp[x]=0;
		fo(x,1,k)
		if (que[x].r==i+1||(i==n-1&&m>=n&&que[x].r==m))fo(y,1,k)t[y][x]=tr[y][x];
		fo(x,1,k)
			fo(y,1,k)
			tmp[y]=(tmp[y]+ans[1][x]*t[x][y])%mo;
		fo(x,1,k)ans[1][x]=tmp[x];
	}
	if (tim){
		matrix t;
		t.init();
		fo(x,1,k)
			fo(y,1,k)
			if (que[x].r==m&&que[y].r==m)t[x][y]=tr[x][y];
		for(;tim;tim/=2,t=t*t)
		if (tim&1){
			fo(x,1,k)tmp[x]=0;
			fo(x,1,k)fo(y,1,k)tmp[y]=(tmp[y]+ans[1][x]*t[x][y])%mo;
			fo(x,1,k)ans[1][x]=tmp[x];
		}
	}
	fo(i,max(n,m),n+m-2){
		matrix t;
		t.init();
		fo(x,1,k)tmp[x]=0;
		fo(x,1,k)
		if (que[x].r==i+1)fo(y,1,k)t[y][x]=tr[y][x];
		fo(x,1,k)
			fo(y,1,k)
			tmp[y]=(tmp[y]+ans[1][x]*t[x][y])%mo;
		fo(x,1,k)ans[1][x]=tmp[x];
	}
	LL ANS=0;
	fo(x,1,k)ANS=(ANS+ans[1][x])%mo;
	ANS=(ANS*2)%mo;
	cout<<ANS<<endl;
	return 0;
}
