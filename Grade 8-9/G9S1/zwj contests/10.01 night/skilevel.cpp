#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const ll dx[3]={0,1,0},dy[5]={0,0,1};
ll n,m,cnt,t,a[510][510],b[300010],first[300010];
ll f[300010],s[300010];
ll ans=0;
ll id(ll xx,ll yy){
	return (xx-1)*m+yy;
}
ll abss(ll kk){
	return ((kk>0)?kk:-kk);
}
struct erickin{
	ll from,to,next,w;
}edge[1500100];
void add(ll u,ll v,ll w){
	cnt++;
	edge[cnt].from=u;edge[cnt].to=v;edge[cnt].next=first[u];edge[cnt].w=w;first[u]=cnt;
	return;
}
bool cmp(erickin l,erickin r){
	return l.w<r.w;
}
ll find(ll x){
	return ((f[x]<0)?x:f[x]=find(f[x]));
}
int main(){
	freopen("skilevel.in","r",stdin);
	freopen("skilevel.out","w",stdout);
	ll i,j,k,t1,t2,ti,tj,x,y,fx,fy;
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			f[id(i,j)]=-1;
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&t1);
			b[id(i,j)]=t1;
			if(t1) s[id(i,j)]=1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			t1=id(i,j);
			for(k=1;k<=2;k++){
				ti=i+dx[k];tj=j+dy[k];t2=id(ti,tj);
				if(ti==0||ti>n||tj==0||tj>m) continue;
				add(t1,t2,abss(a[i][j]-a[ti][tj]));
			}
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		x=edge[i].from;y=edge[i].to;
		fx=find(x);fy=find(y);
		if(fx==fy) continue;
//		cout<<i<<ends<<x<<ends<<y<<ends<<edge[i].w<<endl;
		f[fy]+=f[fx];f[fx]=fy;
		s[fy]+=s[fx];s[fx]=0;
//		cout<<"	join "<<fy<<ends<<f[fy]<<ends<<s[fy]<<endl;
		if(f[fy]<=(-t)){
//			cout<<"	suc"<<endl;//system("pause");
			ans+=edge[i].w*s[fy];s[fy]=0;
		}
	}
	printf("%lld",ans);
	return 0;
} 
