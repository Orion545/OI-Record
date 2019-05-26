#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define ri register int
#define N 100005
#define M 200005
#define inf 9000000000000
using namespace std;

int n,m,i,j,k,l,x,y,arr,tot,hd[N],fa[N],dp[N],w[N];
typedef long long ll;
ll fyou[N],fmei[N],f1[N],f0[N];
string tp;
struct nd{
	int t,nxt;
}e[M];

int gi()
{
	int res,w=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1;
	res=ch-48;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48;
	return res*w;
}
void ad(int x,int y){
	e[++tot].t=y;
	e[tot].nxt=hd[x];
	hd[x]=tot;
}
inline void ini(){
	for(ri j=1;j<=n;j++)f1[j]=fyou[j],f0[j]=fmei[j];
}
void chan1(int x,int c){
	if(c==1){
		f0[x]=inf;
		if(x==1)return;
		f1[x-1]=f1[x]+(ll)w[x-1];
		for(ri i=x-2;i>=1;i--){
			f1[i]=min(f1[i+1],f0[i+1])+(ll)w[i];
		    f0[i]=f1[i+1];
		}
	}
	else{
		f1[x]=inf;	
		if(x!=n){
			f0[x+1]=inf;
			f0[x]=f1[x+1];
		}
		if(x==1)return;
		f0[x-1]=inf;
		f1[x-1]=f0[x]+(ll)w[x-1];
		for(ri i=x-2;i>=1;i--){
			f1[i]=min(f1[i+1],f0[i+1])+(ll)w[i];
		    f0[i]=f1[i+1];
		}
	} 
	
	
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=gi(),m=gi();
	for(ri i=1;i<=n;i++)fyou[i]=fmei[i]=inf;
	getline(cin,tp);
	
	for(ri i=1;i<=n;i++)w[i]=gi();
	for(ri i=1;i<n;i++){
		j=gi(),k=gi();
		ad(j,k);
		ad(k,j);
	}
	dp[0]=0;
	fa[1]=0;
	fyou[n]=(ll)w[n];
	fmei[n]=0;
	for(ri i=n-1;i>=1;i--){
		fyou[i]=min(fyou[i+1],fmei[i+1])+(ll)w[i];
		fmei[i]=fyou[i+1];
	}
	for(ri i=1;i<=m;i++){
		ini();
		j=gi(),x=gi(),k=gi(),y=gi();
		if(j<k){
			swap(j,k);
			swap(x,y);
		}
		chan1(j,x);
		chan1(k,y);
		if(min(f1[1],f0[1])==inf){
			puts("-1");
		}
		else printf("%lld\n",min(f1[1],f0[1]));
	}
	return 0;
}
