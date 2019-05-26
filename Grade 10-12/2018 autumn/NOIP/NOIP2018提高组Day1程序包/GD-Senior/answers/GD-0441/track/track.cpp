#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int nxt[200010],h[100010],v[200010],w[200010],ec,n,m,mn,mp,p1,d[100010],p2,du[100010],p3,ans,f[100010],va[100010],ct,num[100010],t[100010],vis[100010],ss[100010];
void add(int x,int y,int z){v[++ec]=y;w[ec]=z;nxt[ec]=h[x];h[x]=ec;}
void dfs1(int x,int fa,int d){
	if(d>mn)mn=d,mp=x;
	for(int i=h[x];i;i=nxt[i])
		if(v[i]!=fa){
			dfs1(v[i],x,d+w[i]);
			if(f[x]<f[v[i]]+w[i]){
				f[x]=f[v[i]]+w[i];
				t[x]=v[i];
			}
		}
	vis[t[x]]=1;
}
int pd1(int md){
	int s=0,ans=0;
	for(int i=1;i<n;i++){
		s+=d[i];
		if(s>=md){
			s=0;
			ans++;
		}
	}
	return ans;
}
int pd2(int md){
	int s=0,ans=0;
	int l=1,r=n-1;
	while(d[r]>=md&&r>=1){
		r--;
		ans++;
	}
	if(r<1)return ans;
	while(l<r){
		if(d[l]+d[r]>=md){
			ans++;
			l++;
			r--;
		}
		else l++;
	}
	return ans;
}
void dg(int x,int fa){
	num[x]--;
	dg(t[x],x);
	int tp=f[x];
	f[x]=0;
	for(int i=h[x];i;i=nxt[i])
		if(v[i]!=fa&&v[i]!=t[x]&&f[t[x]]+w[i]>f[x]&&!vis[v[i]]){
			f[x]=f[t[x]]+w[i];
			t[x]=v[i];
		}
	vis[t[x]]=1;
}
void dfs2(int x,int fa,int md){
	if(d[x]==1)return;
	ct=0;
	for(int i=h[x];i;i=nxt[i])
		if(v[i]!=fa){
			dfs2(v[i],x,md);
			num[x]++;
		}
	for(int i=h[x];i;i=nxt[i])
		if(v[i]!=fa){
			va[++ct]=f[v[i]]+w[i];
			ss[ct]=v[i];
		}
	for(int i=1;i<=ct;i++)
		for(int j=i+1;j<=ct;j++)
			if(va[i]>va[j]){
				swap(va[i],va[j]);
				swap(ss[i],ss[j]);
			}
	int l=1,r=num[x];
	while(va[r]>=md&&r>=1){
		ans++;
		dg(ss[r],x);
	}
	if(r<1)return;
	while(l<r){
		if(va[l]+va[r]>=md){
			dg(ss[l],x);
			dg(ss[r],x);
			ans++;
			l++;
			r--;
		}
		else l++;
	}
}
int pd3(int md){
	ans=0;
	dfs2(1,0,md);
	return ans;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
		d[i]=c;
		if(a+1!=b)p1=1;
		if(a!=1)p2=1;
		du[b]++;du[c]++;
	}
	for(int i=1;i<=n;i++)
		if(du[i]>3)p3=1;
	if(m==1){
		dfs1(1,0,0);
		mn=0;
		dfs1(mp,0,0);
		printf("%d\n",mn);
		return 0;
	}
	if(!p1){
		int l=0,r=500000010,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pd1(mid)>=m)l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(!p2){
		int l=0,r=500000010,ans;
		sort(d+1,d+n);
		while(l<=r){
			int mid=(l+r)>>1;
			if(pd2(mid)>=m)l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
	int l=0,r=500000010,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(pd3(mid)>=m)l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
