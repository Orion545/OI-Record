#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 2147483648
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct query{
	int n,m,val,ans,num;
}q[20010];
bool cmp(query l,query r){
	return l.val<r.val;
} 
bool cmp1(query l,query r){
	return l.num<r.num;
}
int mu[100010],sigma[100010],mi[100010],sum[100010],vis[100010],pri[100010],cntp,rk[100010],lim;
bool cmp2(int l,int r){
	return sigma[l]<sigma[r];
}
void init(){
	int i,j,k;mu[1]=sigma[1]=mi[1]=1;
	for(i=2;i<=lim;i++){
		if(!vis[i]){
			pri[++cntp]=i;
			mu[i]=-1;
			sigma[i]=i+1;
			mi[i]=i;sum[i]=i+1;
		}
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>lim) break;
			vis[k]=1;
			if(i%pri[j]==0){
				mu[k]=0;
				mi[k]=mi[i]*pri[j];sum[k]=sum[i]+mi[k];
				sigma[k]=sigma[i]/sum[i]*sum[k];break;
			}
			mu[k]=-mu[i];
			mi[k]=pri[j];sum[k]=pri[j]+1;
			sigma[k]=sigma[i]*sigma[pri[j]];
		}
	}
	for(i=1;i<=lim;i++) rk[i]=i;
	sort(rk+1,rk+lim+1,cmp2);
//	cout<<"finish init\n";
}
struct BIT{
	int a[100010];
	int lowbit(int x){
		return x&(-x);
	}
	void change(int x,int val){
//		cout<<"	change "<<x<<' '<<val<<'\n';
		for(;x<=lim;x+=lowbit(x)) a[x]+=val;
	}
	int ask(int x){
		int re=0;
//		cout<<"		ask "<<x<<' ';
		for(;x;x-=lowbit(x)) re+=a[x];
//		cout<<re<<'\n';
		return re;
	}
}T;
int main(){
	int Q=read();int i,j,k,ans,now;
	for(i=1;i<=Q;i++){
		q[i].n=read();q[i].m=read();q[i].val=read();q[i].num=i;
		if(q[i].n>q[i].m) swap(q[i].n,q[i].m);
		lim=max(lim,q[i].m);
	}
	sort(q+1,q+Q+1,cmp);init();
	now=0;
	for(i=1;i<=Q;i++){
		ans=0;
//		cout<<"solve "<<q[i].num<<' '<<q[i].n<<' '<<q[i].m<<' '<<now<<' '<<rk[now+1]<<'\n';
		while(sigma[rk[now+1]]<=q[i].val&&now<lim){
			now++;
			for(k=1;k*rk[now]<=lim;k++) T.change(k*rk[now],sigma[rk[now]]*mu[k]);
		}
//		cout<<"finish add "<<now<<' '<<rk[now+1]<<' '<<sigma[rk[now+1]]<<'\n';
		for(j=1;j<=q[i].n;j=k+1){
			k=min(q[i].m/(q[i].m/j),q[i].n/(q[i].n/j));
//			cout<<"	fenkuai "<<j<<' '<<k<<'\n'; 
			ans+=(q[i].n/j)*(q[i].m/j)*(T.ask(k)-T.ask(j-1));
//			cout<<"	tans "<<ans<<'\n';
		}
		if(ans<0) ans+=MOD;
//		cout<<"solved "<<ans<<'\n';
		q[i].ans=ans;
	}
	sort(q+1,q+Q+1,cmp1);
	for(i=1;i<=Q;i++) printf("%d\n",q[i].ans);
}

