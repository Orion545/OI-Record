#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int w[N*2],ne[N*2],la[N],len[N*2],lg1[N];
int f[N],n,m,t,ans,p[N],fa[N],d[N],d1,sum;
void link(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
int match(){
	int p=1,ret=0;
	for (int i=d1;i>=1;i--){
		if (d[i]>=ans){
			ret++;
			continue;
		}
		while (d[i]+d[p]<ans&&p<i)p++;
		if (p<i&&d[i]+d[p]>=ans)ret++;
		if (++p>=i)break;
	}
	return ret;
}
int calc(){
	sort(p+1,p+t+1);p[0]=0;
	d1=t;for (int i=1;i<=t;i++)d[i]=p[i];
	int g1=match(),m=0,ret=0;sum+=g1;
	for (int u=1<<lg1[t];u;u>>=1){
		if (m+u>t)continue;
		d1=0;
		for (int i=1;i<=t;i++)
			if (i!=m+u)d[++d1]=p[i];
		if (match()==g1)m+=u;
	}
	return p[m];
}
void dp(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		fa[z]=x;
		dp(z);
	}
	t=0;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		p[++t]=f[z]+len[y];
	}
	f[x]=calc();
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)lg1[i]=lg1[i>>1]+1;
	for (int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
		link(y,x,z);
	}t=0;
	ans=0;
	for (int i=1<<30;i;i>>=1){
		sum=0;ans+=i;
		dp(1);
		if (sum<m)ans-=i;
	}
	cout<<ans<<endl;
	return 0;
}
