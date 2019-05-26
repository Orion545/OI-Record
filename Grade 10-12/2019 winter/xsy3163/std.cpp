#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int n,m,K;
#define Maxn 205
#define E 10010
struct Edge{
	int s,e,w,col;
	bool operator <(const Edge &z)const{return w!=z.w?w<z.w:col<z.col;}
}edge[E];
int fa[Maxn],anc[Maxn];
inline int FP(int a,int b){
	if(a<0)a+=Mod;
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int getroot(int x){
	if(fa[x]!=x)fa[x]=getroot(fa[x]);
	return fa[x];
}
int getanc(int x){
	if(anc[x]!=x)anc[x]=getanc(anc[x]);
	return anc[x];
}
inline int Kruskal(int mid){
	for(int i=1;i<=m;++i)
	if(!edge[i].col)edge[i].w+=mid;
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;++i)fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;++i){
		int fx=getroot(edge[i].s);
		int fy=getroot(edge[i].e);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=!edge[i].col;
	}
	for(int i=1;i<=m;++i)
	if(!edge[i].col)edge[i].w-=mid;
	return ans;
}
int black[Maxn][Maxn],white[Maxn][Maxn];
int matrix[Maxn][Maxn],id[Maxn],seq[Maxn],cnt;
int ans[Maxn];
inline void Build(int x){
	for(int i=1;i<=cnt;++i)
	for(int j=1;j<=cnt;++j)matrix[i][j]=0;
	for(int i=1;i<=cnt;++i)
	for(int j=1;j<=cnt;++j)
	matrix[i][j]=(black[i][j]+x*white[i][j]+Mod)%Mod;
}
inline int Matrix_Tree(){
	int ans=1;
	for(int i=1;i<cnt;++i){
		if(!matrix[i][i]){
			int t=i+1;
			while(!matrix[t][i]&&t<cnt)t++;
			if(t==cnt)continue;
			for(int j=i;j<cnt;++j)swap(matrix[i][j],matrix[t][j]);
			ans=-ans;
		}
		int inv=FP(matrix[i][i],Mod-2);
		for(int j=i+1;j<cnt;++j){
			int t=1ll*matrix[j][i]*inv%Mod;
			for(int k=i;k<cnt;++k)matrix[j][k]=(matrix[j][k]-1ll*matrix[i][k]*t%Mod+Mod)%Mod;
		}
	}
	if(ans<0)ans+=Mod;
	for(int i=1;i<cnt;++i)ans=1ll*ans*matrix[i][i]%Mod;
	return ans;
}
int X[Maxn];
int Ans[Maxn];
inline void Lagrange(int x){
	for(int i=0;i<cnt;++i)X[i]=!i;
	int lenx=0;
	for(int i=0;i<cnt;++i)
	if(i!=x){
		int inv=FP(i-x,Mod-2);
		for(int j=lenx+1;j>=1;--j)X[j]=(1ll*X[j]*i%Mod*inv+1ll*X[j-1]*(Mod-inv))%Mod;
		X[0]=1ll*X[0]*i%Mod*inv%Mod;
		lenx++;
	}
	for(int i=0;i<=lenx;++i)Ans[i]=(Ans[i]+1ll*ans[x]*X[i])%Mod;
}
int zjr[Maxn],ZJR[Maxn];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;++i)scanf("%d%d%d%d",&edge[i].s,&edge[i].e,&edge[i].w,&edge[i].col);
	int l=-1e9,r=1e9;
	while(l<r){
		if(r-l==1){
			if(Kruskal(r)<K)r=l;
			break;
		}
		int mid=(l+r)>>1;
		int ans=Kruskal(mid);
		if(ans>=K)l=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;++i)fa[i]=anc[i]=i;
	for(int i=1;i<=m;++i)
	if(!edge[i].col)edge[i].w+=r;
	sort(edge+1,edge+m+1);
	int N=0;
	zjr[0]=1;
	for(l=1;l<=m;l=r+1){
		r=l;
		while(r<m&&edge[r+1].w==edge[l].w)r++;
		for(int i=l;i<=r;++i){
			int fx=getanc(edge[i].s);
			int fy=getanc(edge[i].e);
			if(fx==fy)continue;
			anc[fx]=fy;
		}
		memset(id,0,sizeof(id));cnt=0;
		for(int i=l;i<=r;++i){
			int fx=getroot(edge[i].s);
			int fy=getroot(edge[i].e);
			if(fx!=fy){
				if(!id[fx])id[fx]=++cnt,seq[cnt]=fx;
				if(!id[fy])id[fy]=++cnt,seq[cnt]=fy;
			}
		}
		if(!cnt)continue;
		for(int i=1;i<=cnt;++i)
		for(int j=1;j<=cnt;++j)black[i][j]=white[i][j]=0;
		for(int i=l;i<=r;++i){
			int fx=getroot(edge[i].s);
			int fy=getroot(edge[i].e);
			if(fx!=fy){
				if(edge[i].col){
				   black[id[fx]][id[fy]]--;
				   black[id[fy]][id[fx]]--;
				   black[id[fx]][id[fx]]++;
				   black[id[fy]][id[fy]]++;
				}
				else{
				   white[id[fx]][id[fy]]--;
				   white[id[fy]][id[fx]]--;
				   white[id[fx]][id[fx]]++;
				   white[id[fy]][id[fy]]++;
				}
			}
		}
		int fir=0;
		for(int i=1;i<=cnt;++i){
			int x=seq[i];
			if(getanc(x)==x){
				if(fir){
					black[fir][i]--;
					black[i][fir]--;
					black[fir][fir]++;
					black[i][i]++;
				}else fir=i;
			}
		}
		for(int i=0;i<cnt;++i){
			Build(i);
			ans[i]=Matrix_Tree();
		}
		for(int i=0;i<cnt;++i)Ans[i]=0;
		for(int i=0;i<cnt;++i)Lagrange(i);
		for(int i=0;i<N+cnt;++i)ZJR[i]=0;
		for(int i=0;i<cnt;++i)
		for(int j=0;j<=N;++j)ZJR[i+j]=(ZJR[i+j]+1ll*Ans[i]*zjr[j])%Mod;
		N=N+cnt-1;
		memcpy(zjr,ZJR,sizeof(ZJR));
		memcpy(fa,anc,sizeof(anc));
	}
	printf("%d\n",zjr[K]);
	return 0;
}
