#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 31011
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,mm,m=1,first[110],cnte,num[1010],tote;
struct edge{
	ll to,next,w,from,id,ch;
}a[2010];
inline bool cmp(edge l,edge r){return l.w<r.w;}
inline void add(ll u,ll v,ll w){
	a[++cnte]=(edge){v,first[u],w,u,0,0};
}
ll f[110];
inline ll find(ll x){return ((f[x]==x)?x:f[x]=find(f[x]));}
inline void join(ll x,ll y){
	x=find(x);y=find(y);
	if(x==y) return;
	f[y]=x;
}
void kruskal(){
	ll i,fx,fy;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=cnte;i++){
		fx=find(a[i].from);
		fy=find(a[i].to);
		if(fx==fy) continue;
		num[a[i].id]++;a[i].ch=1;
		f[fy]=fx;tote++;
//		cout<<"join "<<a[i].from<<' '<<a[i].to<<' '<<a[i].id<<' '<<num[a[i].id]<<'\n';
	}
//	cout<<"finish kruskal\n";
}
ll x[110][110],cnt,belong[110],tcnt;
void getmat(ll p){
	memset(belong,0,sizeof(belong));
	cnt=num[p]+1;
	memset(x,0,sizeof(x));
	tcnt=0;
	ll i,u,v;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=cnte;i++){
		if(a[i].id==p||!a[i].ch) continue;
		join(a[i].from,a[i].to);
	}
	for(i=1;i<=n;i++) if(find(i)==i) belong[i]=++tcnt;
	for(i=1;i<=n;i++) belong[i]=belong[find(i)];
//	for(i=1;i<=n;i++) cout<<"belong "<<i<<' '<<belong[i]<<'\n';
	for(i=1;i<=cnte;i++){
		if(a[i].id!=p) continue;
		u=belong[a[i].from];
		v=belong[a[i].to];
//		cout<<"add mat "<<u<<' '<<v<<'\n';
		x[u][v]--;x[v][u]--;
		x[u][u]++;x[v][v]++;
	}
}
ll gauss(){
	ll i,j,k,tmp,val,pos,ch=0,ans=1;
//	for(i=1;i<=cnt;i++){
//		for(j=1;j<=cnt;j++) cout<<x[i][j]<<' ';
//		cout<<'\n';
//	}
	for(i=1;i<cnt;i++){
		pos=i;
		for(j=i+1;j<cnt;j++) if(abs(x[j][i])>abs(x[pos][i])) pos=j;
		if(pos!=i) ch^=1,swap(x[i],x[pos]);
		for(j=i+1;j<cnt;j++){
			while(x[j][i]){
				tmp=x[j][i]/x[i][i];
				for(k=1;k<cnt;k++) x[j][k]=(x[j][k]-x[i][k]*tmp%MOD+MOD)%MOD;
				if(x[j][i]==0) break;
				ch^=1;swap(x[i],x[j]);
			}
		}
	}
	for(i=1;i<cnt;i++) ans=ans*x[i][i]%MOD;
	if(ch) ans=MOD-ans;
//	for(i=1;i<=cnt;i++){
//		for(j=1;j<=cnt;j++) cout<<x[i][j]<<' ';
//		cout<<'\n';
//	}
	return (ans+MOD)%MOD;
}
int main(){
	n=read();mm=read();ll i,j,t1,t2,t3;
	for(i=1;i<=mm;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	sort(a+1,a+cnte+1,cmp);
	for(i=1,m=1;i<=cnte;m++,i=j){
		j=i;
		while(j<=cnte&&a[i].w==a[j].w) a[j].id=m,j++;
	}
	kruskal();
	if(tote<n-1){puts("0");return 0;}
//	for(i=1;i<=m;i++) cout<<i<<' '<<num[i]<<'\n';
	ll ans=1;
	for(i=1;i<=m;i++){
		if(!num[i]) continue;
		getmat(i);
		ans=(ans*gauss())%MOD;
	}
	cout<<ans<<'\n';
}
