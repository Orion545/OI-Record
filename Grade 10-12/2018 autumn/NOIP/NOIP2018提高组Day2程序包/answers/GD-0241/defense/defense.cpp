#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#include<vector>
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
ll n,m,w[100010],first[100010],cnte=1;
struct edge{
	ll to,next;
}a[200010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
ll f0[100010],f1[100010],fa[100010],dep[100010];
void dfs(ll u,ll f){
	ll i,v;
	fa[u]=f;dep[u]=dep[f]+1;
	f0[u]=0;f1[u]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		f0[u]+=f1[v];
		f1[u]+=min(f1[v],f0[v]);
	}
}
ll g0[100010],g1[100010];
namespace brute{
	ll solve(ll l,ll x,ll r,ll y){
		if(x==0&&y==0&&((fa[l]==r)||(fa[r]==l))) return -1;
		if(dep[l]>dep[r]) swap(l,r),swap(x,y);
//		cout<<"solve "<<l<<' '<<x<<' '<<r<<' '<<y<<'\n';
		if(y==0){
			g1[r]=1e15;
			g0[r]=f0[r];
			if(r!=1){
				g0[fa[r]]=1e15;
				g1[fa[r]]=f1[fa[r]]-min(f1[r],f0[r])+min(g1[r],g0[r]);
				r=fa[r];
			}
		}
		else g0[r]=1e15,g1[r]=f1[r];
		while(dep[r]>dep[l]){
			g0[fa[r]]=f0[fa[r]]-f1[r]+g1[r];
			g1[fa[r]]=f1[fa[r]]-min(f1[r],f0[r])+min(g1[r],g0[r]);
			r=fa[r];
		}
		
//		cout<<"solve "<<l<<' '<<x<<' '<<r<<' '<<y<<' '<<g0[r]<<' '<<g1[r]<<'\n';
		if(x==0){
			g1[l]=1e15;
			if(l!=r) g0[l]=f0[l];
			if(l!=1){
				g0[fa[l]]=1e15;
				g1[fa[l]]=f1[fa[l]]-min(f1[l],f0[l])+min(g1[l],g0[l]);
				l=fa[l];
			}
		}
		else g0[l]=1e15,g1[l]=f1[l]; 
		
		while(dep[r]<dep[l]){
			g0[fa[l]]=f0[fa[l]]-f1[l]+g1[l];
			g1[fa[l]]=f1[fa[l]]-min(f1[l],f0[l])+min(g1[l],g0[l]);
			l=fa[l];
		}
		while(dep[r]>dep[l]){
			g0[fa[r]]=f0[fa[r]]-f1[r]+g1[r];
			g1[fa[r]]=f1[fa[r]]-min(f1[r],f0[r])+min(g1[r],g0[r]);
			r=fa[r];
		}
		
//		cout<<"solve "<<l<<' '<<x<<' '<<r<<' '<<y<<' '<<g0[r]<<' '<<g1[r]<<'\n';
		
		while(fa[l]!=fa[r]){
//			cout<<"jumping "<<l<<' '<<dep[l]<<' '<<r<<' '<<dep[r]<<'\n';
			g0[fa[l]]=f0[fa[l]]-f1[l]+g1[l];
			g1[fa[l]]=f1[fa[l]]-min(f1[l],f0[l])+min(g1[l],g0[l]);
			g0[fa[r]]=f0[fa[r]]-f1[r]+g1[r];
			g1[fa[r]]=f1[fa[r]]-min(f1[r],f0[r])+min(g1[r],g0[r]);
			l=fa[l];r=fa[r];
		}
		
		if(l!=r){
			g0[fa[l]]=f0[fa[l]]-f1[l]+g1[l]-f1[r]+g1[r];
			g1[fa[l]]=f1[fa[l]]-min(f1[l],f0[l])+min(g1[l],g0[l])-min(f1[r],f0[r])+min(g1[r],g0[r]);
			l=fa[l];r=fa[r];
		}
//		cout<<"solve "<<l<<' '<<x<<' '<<r<<' '<<y<<' '<<g0[r]<<' '<<g1[r]<<'\n';
		while(l!=1){
			g0[fa[l]]=f0[fa[l]]-f1[l]+g1[l];
			g1[fa[l]]=f1[fa[l]]-min(f1[l],f0[l])+min(g1[l],g0[l]);
			l=fa[l];
		}
//		cout<<"solve "<<l<<' '<<x<<' '<<r<<' '<<y<<' '<<g0[r]<<' '<<g1[r]<<'\n';
		return min(g0[1],g1[1]);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();ll i,t1,t2,t3,t4;char ss[10];
	scanf("%s",ss);
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
//	cout<<"finish dfs \n";
	while(m--){
		t1=read();t3=read();t2=read();t4=read();
		printf("%lld\n",brute::solve(t1,t3,t2,t4));
	}
}
