#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,x) for(i=la[x];i;i=ne[i])
#define Max(a,b) (a>b)?a:b
#define Min(a,b) (a<b)?a:b
const int N=50005,INF=0x7fffffff;
struct arr{int x,de;}a[N];
int da[N*2],ne[N*2],la[N],le[N*2],fa[N],de[N],f[N];
int n,m,i,sum,ans,x,y,z,root,deep;
int l,r,mid;
bool Lian,thr,P[N];
int read(){
	char c=getchar(); int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+(c-'0');
	return x;
}
bool cmp(arr x,arr y){return x.de<y.de;}
void ins(int x,int y,int z){
	da[++sum]=y;ne[sum]=la[x];la[x]=sum;le[sum]=z;
	da[++sum]=x;ne[sum]=la[y];la[y]=sum;le[sum]=z;
}
void dfs(int x){
	int i;
	rep(i,x)if(da[i]!=fa[x]){
		fa[da[i]]=x;de[da[i]]=de[x]+1;
		dfs(da[i]);
	}
}
void bao(int x){
	int i,m1=0,m2=0;
	rep(i,x)if(da[i]!=fa[x]){
		bao(da[i]);
		f[x]=Max(f[x],f[da[i]]+le[i]);
		if(m1<=f[da[i]]+le[i]) m2=m1,m1=f[da[i]]+le[i];
		else if(m2<f[da[i]]+le[i]) m2=f[da[i]]+le[i];
	}ans=Max(ans,m1+m2);
}
void walk(int x){
	int i;
	rep(i,x)if(da[i]!=fa[x]){
		f[x]=le[i];
		walk(da[i]);
	}
}
bool lian(int lim){
	int i,s=0,x=0;
	fo(i,1,n){
		s+=f[i];
		if(s>=lim) x++,s=0;
	}
	if(x<m) return 0;return 1;
}
bool tree(int lim){
	int i,j,x,y,s=0;
	memset(P,0,sizeof(P));
	memset(f,0,sizeof(f));
	fo(i,1,n){
		x=a[i].x;y=fa[x];
		rep(j,x)if(y==da[j]){
			if(f[x]+le[j]>=lim){s++;break;}
			if(!P[y]){
				f[y]=f[x]+le[j];
				if(f[y]>=lim) f[y]=0,s++;else P[y]=1;
			}else{
				if(f[y]+f[x]+le[j]>=lim) f[y]=0,s++,P[y]=0;
				else f[y]=Max(f[y],f[x]+le[j]);
			}
			break;
		}
	}
	if(s<m) return 0;return 1;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	n=read(),m=read();ans=0;thr=Lian=1;
	fo(i,2,n){
		x=read(),y=read(),z=read();
		ins(x,y,z);r+=z;
		if(y!=(x+1)) Lian=0;
		f[x]++,f[y]++;
	}
	fo(i,1,n){
		if(f[i]>3){thr=0;break;}
		if(f[i]<3)root=i;
	}
	memset(f,0,sizeof(f));
	if(m==1){
		dfs(1);
		bao(1);
		printf("%d\n",ans);
		
		return 0;
	}
	if(Lian){
		dfs(1);
		walk(1);
		l=0;r=r/m;
		while(l<r){
			mid=(l+r+1)/2;
			if(lian(mid)) l=mid;else r=mid-1;
		}
		printf("%d\n",l);
		
		return 0;
	}
	if(thr){
		dfs(root);
		fo(i,1,n) deep=Max(deep,de[i]);
		fo(i,1,n){
			de[i]=deep-de[i];
			a[i]=(arr){i,de[i]};
		}
		sort(a+1,a+n+1,cmp);
		l=0;r=r/m;
		while(l<r){
			mid=(l+r+1)/2;
			if(tree(mid)) l=mid;else r=mid-1;
		}
		printf("%d\n",l);
		
		return 0;
	}
	printf("%d\n",r/m);
}
