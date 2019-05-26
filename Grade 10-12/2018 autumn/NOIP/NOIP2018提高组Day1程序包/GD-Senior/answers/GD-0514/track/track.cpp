#include<bits/stdc++.h>
#define add(u,v,vv) to[++top]=head[u],head[u]=top,w[top]=v,val[top]=vv
#define For(x) for(int h=head[x],o=w[h],v=val[h];h;o=w[h=to[h]],v=val[h])
#define mid ((l+r+1)>>1)
#define pb push_back
#define N 50050
using namespace std;
typedef long long ll;
ll tot=0ll,l=10000,r,f[N],ret;
int top=0,head[N<<1],to[N<<1],w[N<<1],val[N<<1];
int n,m,u,v,vv;
inline void dfs(int x,int fa,ll lim){
	int t,L,R,les,RL,RR,LL;
	vector <ll> a;
	For(x) if (o!=fa) dfs(o,x,lim),a.pb(f[o]+v);
	
	if (a.size()==0) return;
	sort(a.begin(),a.end());
	t=-1;
	while (t+1<a.size()&&a[t+1]<lim) t++;
	ret+=a.size()-t-1;
	L=0,R=t;
	if (R<0) return;
	if (L==R) {f[x]=a[R];return;}
	
	if (R==1){
		if (a[L]+a[R]>=lim) ret++;
		else f[x]=a[R];
		return;
	}
	while (a[L]+a[R]<lim&&L+1<R) L++;
	LL=L-1;
	if (a[L]+a[R]<lim) {f[x]=a[R];return;}
	while (L<R-1&&a[L]+a[R-1]>=lim) R--;
	RL=R,RR=R+1;
	
	while (L<=RL){
		if (L==RL){
			if (RR<=t) L++,RR++,ret++;
			break;
		}
		if (a[L]+a[RL]>=lim) ret++,L++,RL--;
		else{
			if (RR<=t) L++,RR++,ret++;
			else break;
		}
	}
	les=t-RR+1;
	ret+=les/2,les-=((les/2)*2);
	if (les) {f[x]=a[t];return;}
	if (L==RL) {f[x]=a[RL];return;}
	if (LL>=0) {f[x]=a[LL];return;}
}
inline bool check(ll lim){
	ret=0;
	memset(f,0,sizeof(f));
	dfs(1,0,lim);
	if (ret>=m) return 1;
	return 0;
}
inline void read(int &x){
	x=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
}
int main(){
	freopen("track.in","r",stdin),freopen("track.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<n;i++) read(u),read(v),read(vv),add(u,v,vv),add(v,u,vv),tot+=vv,l=min(l,(ll)vv);
	r=tot/m;
	while (l!=r){
		if (check(mid)) l=mid;else r=mid-1;
	}
	printf("%lld\n",l);
}
