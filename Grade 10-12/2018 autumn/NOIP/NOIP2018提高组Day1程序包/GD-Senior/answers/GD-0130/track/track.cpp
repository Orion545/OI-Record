#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)

using namespace std;

const int maxn=50007,maxm=maxn*2;

int n,m,fi[maxn],la[maxm],ne[maxm],va[maxm],tot;
void add(int a,int b,int c){
	tot++;
	ne[tot]=fi[a];
	la[tot]=b;
	va[tot]=c;
	fi[a]=tot;
}

int ru[maxn];
bool a1d1=true,chaiN=true,no3=true;
void Init(){
	scanf("%d%d",&n,&m);
	fo(i,1,n-1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		if (z!=1) a1d1=false;
		if (y!=x+1) chaiN=false;
		if (++ru[x]>3) no3=false;
		if (++ru[y]>3) no3=false;
	}
}
int ed,Ed;
int b[maxn],fa[maxn],dis[maxn];
void bfs(int v){
	memset(dis,0,sizeof dis);
	ed=0;
	Ed=-1;
	fa[b[b[0]=1]=v]=0;
	fo(i,1,b[0]){
		int v=b[i];
		if (dis[v]>Ed){
			ed=v;
			Ed=dis[v];
		}
		for(int k=fi[v];k;k=ne[k])
			if (la[k]!=fa[v]){
				fa[la[k]]=v;
				b[++b[0]]=la[k];
				dis[la[k]]=dis[v]+va[k];
			}
	}
}
int Ans=0;
bool check_chaiN(int v){
	int z=0,sum=0;
	for(int i=1;i<=tot;i+=2){
		sum+=va[i];
		if (sum>=v){
			sum=0;
			z++;
		}
	}
	return z>=m;
}
int MN=0;
int f[maxn],c[maxn][2],cnt,de[maxn];
void dfs(int v,int from,int temp=0){
	c[++cnt][0]=v;
	for(int k=fi[v];k;k=ne[k])
		if (la[k]!=from){
			temp+=f[la[k]];
		}
	temp-=f[v];
	c[cnt][1]=temp;
	for(int k=fi[v];k;k=ne[k])
		if (la[k]!=from)
			dfs(la[k],v,temp);
}
int rt;
void dp(int v,int from){
	int temp=0;
	f[v]=0;
	for(int k=fi[v];k;k=ne[k])
		if (la[k]!=from){
			de[la[k]]=de[v]+va[k];
			dp(la[k],v);
			f[v]+=f[la[k]];
		}
	temp=f[v];
	c[cnt=1][0]=v;
	c[1][1]=0;
	for(int k=fi[v];k;k=ne[k])
		if (la[k]!=from){
			int op=cnt;
			dfs(la[k],v);
			fo(i,1,op)
				fo(j,op+1,cnt)
					f[v]=max(f[v],(de[c[i][0]]+de[c[j][0]]-de[v]-de[v]>=MN)+c[i][1]+c[j][1]+temp);
		}
	if (v!=rt) fo(i,1,cnt) f[v]=max(f[v],(de[c[i][0]]-de[from]>=MN)+c[i][1]+temp);
}
bool check(int mn){
	memset(f,0,sizeof f);
	MN=mn;
	dp(rt,0);
	return f[rt]>=m;
}
bool check_a1d1(int mn){
	int z=0,p=0;
	for(int i=tot;i>p;i-=2)
		if (va[i]>=mn){
			z++;
		}else{
			while (i>p && va[p]+va[i]<mn) p+=2;
			if (i>p && va[p]+va[i]>=mn) z++;
			else break;
		}
	return z>=m;
}
void Solve(){
	if (m==1){
		bfs(1);
		bfs(ed);
		Ans=Ed;
	}else if (a1d1){
		sort(va+1,va+tot+1);
		int l=1,r=1e9;
		while (l<r){
			int mid=l+r+1>>1;
			if (check_a1d1(mid)) l=mid;
			else r=mid-1;
		}
		Ans=l;
	}else if (chaiN){
		int l=1,r=1e9;
		while (l<r){
			int mid=l+r+1>>1;
			if (check_chaiN(mid)) l=mid;
			else r=mid-1;
		}
		Ans=l;
	}else{
		fo(i,1,n) if (ru[i]<3) rt=i;
		int l=1,r=1e9;
		while (l<r){
			int mid=l+r+1>>1;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		Ans=l;
	}
}
void Print(){
	printf("%d\n",Ans);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	Init();
	Solve();
	Print();
	return 0;
}
