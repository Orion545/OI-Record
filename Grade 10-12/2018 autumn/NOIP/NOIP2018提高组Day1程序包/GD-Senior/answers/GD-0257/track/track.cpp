#include<stdio.h>
#include<algorithm>
using namespace std;
int h[50010],nex[100010],to[100010],v[100010],M,n,m;
void add(int a,int b,int c){
	M++;
	to[M]=b;
	v[M]=c;
	nex[M]=h[a];
	h[a]=M;
}
namespace m1{
	int d[50010];
	void dfs(int fa,int x){
		for(int i=h[x];i;i=nex[i]){
			if(to[i]!=fa){
				d[to[i]]=d[x]+v[i];
				dfs(x,to[i]);
			}
		}
	}
	void work(){
		int i,p;
		dfs(0,1);
		p=0;
		for(i=1;i<=n;i++){
			if(d[i]>d[p])p=i;
		}
		d[p]=0;
		dfs(0,p);
		p=0;
		for(i=1;i<=n;i++)p=max(p,d[i]);
		printf("%d",p);
	}
}
namespace star{
	int a[50010],M,n;
	bool check(int k){
		int i,j,s=0;
		for(i=M;i>0&&a[i]>=k;i--)s++;
		n=i;
		j=1;
		for(i=n;i>0;i--){
			while(j<i&&a[i]+a[j]<k)j++;
			if(j>=i)break;
			s++;
			j++;
		}
		return s>=m;
	}
	void work(){
		int i,l,r,mid,ans;
		for(i=h[1];i;i=nex[i])a[++M]=v[i];
		sort(a+1,a+M+1);
		l=1;
		r=5e8;
		ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else
				r=mid-1;
		}
		printf("%d",ans);
	}
}
namespace line{
	int a[50010],s[50010],f[50010],n;
	bool check(int k){
		int i,j,mx;
		j=mx=0;
		for(i=1;i<=n;i++){
			while(s[i]-s[j+1]>=k)mx=max(mx,f[++j]);
			f[i]=s[i]-s[j]>=k?mx+1:0;
		}
		mx=0;
		for(i=1;i<=n;i++)mx=max(mx,f[i]);
		return mx>=m;
	}
	void work(){
		int i,l,r,mid,ans;
		for(i=1;i<M;i+=2)a[++n]=v[i];
		for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		l=1;
		r=5e8;
		ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}else
				r=mid-1;
		}
		printf("%d",ans);
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,x,y,z;
	bool st,li;
	scanf("%d%d",&n,&m);
	st=li=1;
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x!=1)st=0;
		if(x+1!=y)li=0;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==1){
		m1::work();
		return 0;
	}
	if(st){
		star::work();
		return 0;
	}
	if(li){
		line::work();
		return 0;
	}
}
