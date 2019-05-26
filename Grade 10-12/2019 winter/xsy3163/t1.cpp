#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
ll qpow(ll a,ll b){
	if(a<0) a+=MOD;
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll n,tm,lim,cnte;
struct edge{
	ll to,w,from,c,ch;
}e[20010];
inline bool cmp(edge l,edge r){
	if(l.w!=r.w) return l.w<r.w;
	return l.c<r.c;
}
inline void add(ll u,ll v,ll w,ll c){
	e[++cnte]=(edge){v,w,u,c,0};
}
ll f[210];
inline ll find(ll x){return ((f[x]==x)?x:f[x]=find(f[x]));}
inline void join(ll x,ll y){
	x=find(x);y=find(y);
	if(x==y) return;
	f[y]=x;
}
bool check(ll len){
	ll i,m=0,u,v;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=cnte;i++){
		e[i].ch=0;
		if(e[i].c==0) e[i].w+=len;
	}
	sort(e+1,e+cnte+1,cmp);
//	for(i=1;i<=cnte;i++) cout<<"check edge "<<e[i].from<<' '<<e[i].to<<' '<<e[i].w<<' '<<e[i].c<<'\n';
	for(i=1;i<=cnte;i++){
		u=find(e[i].from);
		v=find(e[i].to);
//		cout<<"get edge "<<u<<' '<<e[i].from<<' '<<v<<' '<<e[i].to<<'\n';
		if(u==v) continue;
//		cout<<"selected\n";
		e[i].ch=1;
		f[v]=u;
		m+=(e[i].c^1);
	}
//	cout<<"check "<<len<<' '<<m<<'\n';
	for(i=1;i<=cnte;i++) if(e[i].c==0) e[i].w-=len;
	return m>=lim;
}
ll black[210][210],white[210][210],a[210][210],belong[210],cnt;
void getmat(ll p){
	memset(belong,0,sizeof(belong));
	memset(black,0,sizeof(black));
	memset(white,0,sizeof(white));
	ll i,j,u,v;cnt=0;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=cnte;i++){
		if(e[i].w==p||!e[i].ch) continue;
		join(e[i].from,e[i].to);
	}
	for(i=1;i<=n;i++) if(find(i)==i) belong[i]=++cnt;
	for(i=1;i<=n;i++) belong[i]=belong[find(i)];
	for(i=1;i<=cnte;i++){
		if(e[i].w!=p) continue;
		u=belong[e[i].from];
		v=belong[e[i].to];
		if(e[i].c){
			black[u][u]++;black[v][v]++;
			black[u][v]--;black[v][u]--;
		}
		else{
			white[u][u]++;white[v][v]++;
			white[u][v]--;white[v][u]--;
		}
	}
//	cout<<"getmat "<<p<<' '<<cnt<<'\n';
}
void build(ll val){
	ll i,j;
//	cout<<"		build!!!!!!!!!\n";
	for(i=1;i<=cnt;i++){
//		cout<<"		";
		for(j=1;j<=cnt;j++){
			a[i][j]=(black[i][j]+val*white[i][j])%MOD;
//			cout<<a[i][j]<<' ';
		}
//		cout<<'\n';
	}
}
ll gauss(){
	ll i,j,tmp,num,k,ch=0,ans=1;
	for(i=1;i<cnt;i++){
		num=i;
		for(j=i+1;j<cnt;j++) if(abs(a[j][i])>abs(a[num][i])) num=j;
		if(num!=i) ch^=1,swap(a[i],a[num]);
		for(j=i+1;j<cnt;j++){
			while(a[j][i]){
				tmp=a[j][i]/a[i][i];
				for(k=1;k<cnt;k++) a[j][k]=(a[j][k]-a[i][k]*tmp%MOD+MOD)%MOD;
				if(a[j][i]==0) break;
				ch^=1;swap(a[j],a[i]);
			}
		}
	}
	for(i=1;i<cnt;i++) ans=ans*a[i][i]%MOD;
	if(ch) ans=MOD-ans;
	ans=(ans+MOD)%MOD;
//	cout<<"		gauss "<<ans<<'\n';
	return ans;
}
ll matans[210],lag[210],lhx[210],LHX[210],lagre[210];
void lagrange(ll p){
	ll i,j,len=0,inv;
	for(i=0;i<cnt;i++) lagre[i]=(!i);
//	cout<<"begin lag "<<lagre[0]<<'\n';
	for(i=0;i<cnt;i++){
		if(i==p) continue;
		inv=qpow(i-p,MOD-2);
		for(j=len+1;j>=1;j--) lagre[j]=(lagre[j]*i%MOD*inv+lagre[j-1]*(MOD-inv))%MOD;
//		cout<<"lag do "<<i<<' '<<lagre[0]<<' '<<inv<<'\n';
		lagre[0]=lagre[0]*i%MOD*inv%MOD;
//		cout<<"lag do "<<i<<' '<<lagre[0]<<'\n';
		len++;
	}
	for(i=0;i<=len;i++) lag[i]=(lag[i]+matans[p]*lagre[i])%MOD;
//	cout<<"	lagrange~~~~~~~~~~\n";
//	for(i=0;i<=len;i++) cout<<'	'<<i<<' '<<lag[i]<<'\n';
}
int main(){
	n=read();tm=read();lim=read();ll i,j,k,t1,t2,t3,t4,u,v,l,r,mid,curlen=0;
	for(i=1;i<=tm;i++){
		t1=read();t2=read();t3=read();t4=read();
		add(t1,t2,t3,t4);
	}

	l=-1e9;r=1e9;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	check(l);

//	for(i=1;i<=cnte;i++) cout<<"check edge "<<e[i].from<<' '<<e[i].to<<' '<<e[i].w<<' '<<e[i].c<<' '<<e[i].ch<<'\n';

	curlen=0;
	lhx[0]=1;

	for(i=1;i<=cnte;i=r+1){
		l=r=i;
		while(r<cnte&&e[r+1].w==e[r].w) r++;
		getmat(e[i].w);

		for(j=0;j<cnt;j++){
			build(j);
			matans[j]=gauss();
		}

		for(j=0;j<n;j++) lag[j]=LHX[j]=0;
		for(j=0;j<cnt;j++) lagrange(j);
		for(j=0;j<cnt;j++)
			for(k=0;k<=curlen;k++) LHX[j+k]=(LHX[j+k]+lag[j]*lhx[k])%MOD;
		curlen=curlen+cnt-1;
		memcpy(lhx,LHX,sizeof(LHX));
//		cout<<"get mul "<<cnt<<'\n';
//		for(j=0;j<=curlen;j++) cout<<lhx[j]<<' ';
//		cout<<'\n';
	}
	cout<<lhx[lim]<<'\n';
}
