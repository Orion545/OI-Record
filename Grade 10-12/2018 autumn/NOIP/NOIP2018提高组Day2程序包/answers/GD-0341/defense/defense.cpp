#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<cctype>
#define go(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N=2003,inf=0x3f3f3f3f;
inline int read (int& x) {
	bool f=0;char c;
	for(;!isdigit(c=getchar());f|=(c=='-'));
	for(x=0;isdigit(c);c=getchar())x=x*10+(c^48);
	return x=(f?-x:x);
}
int n,m,p[N],tot=0,h[N],map[N][N];string type;
struct edge{int ed,nxt;}e[N<<1];
void add(int u,int v) {e[++tot].ed=v;e[tot].nxt=h[u];h[u]=tot;}
void lian() {
	int a,b,x,y;ll cost_ji=0,cost_ou=0;
	for(int i=1;i<=n;i+=2) cost_ji+=p[i];
	for(int i=2;i<=n;i+=2) cost_ou+=p[i];
	static bool army[100003]={0};
	go(i,1,m) {
		read(a);read(x);read(b);read(y);
		if(!x && !y && abs(a-b)==1) puts("-1");
		else if((a&1) && (b&1) && x==y && x==1) cout<<cost_ji<<"\n";
		else if(!(a&1) && !(b&1) && x==y && x==1) cout<<cost_ou<<"\n";
		else if((a&1) && (b&1) && x==y && x==0) cout<<cost_ou<<"\n";
		else if(!(a&1) && !(b&1) && x==y && x==0) cout<<cost_ji<<"\n";
		else {
			ll cost=p[a]*x+p[b]*y;
			army[a]=x;army[b]=y;
			go(i,1,n) {
				if(army[i-1] || army[i+1] || i==a || i==b) continue;
				cost+=p[i];
			}
			cout<<cost<<"\n";
		}
	}
}
ll f[103][2];
void dp() {
	go(i,1,n)
		go(j,1,i)
		f[j][0]=max(f[i][1],f[i][1]),f[j][1]=max(f[i][0],f[i][0]);
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;int u,v,a,x,b,y;
	memset(map,0x3f,sizeof(map));
	go(i,1,n) read(p[i]);
	go(i,1,n-1) {
		read(u);read(v);
		add(u,v);add(v,u);
		map[u][v]=map[v][u]=1;
	}
	if(type[0]=='A') {lian();return 0;}
	go(i,1,m) {
		read(a);read(x);read(b);read(y);
		if(!x && !y && map[a][b]!=inf) {puts("-1");continue;}
		dp();
		cout<<max(f[1][0],f[1][1]);
	}
	return 0;
}

