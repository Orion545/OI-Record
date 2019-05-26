/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,f[200010],siz[200010],self[200010];
int find(int x){return ((f[x]<0)?x:(f[x]=find(f[x])));}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(x==y){
		self[fx]=1;
	}
	if(fx==fy){
		siz[fx]++;return;
	}
	siz[fx]+=siz[fy]+1;self[fx]|=self[fy];
	f[fx]+=f[fy];f[fy]=fx;
//	cout<<"join "<<x<<' '<<y<<' '<<fx<<' '<<fy<<' '<<f[fx]<<' '<<f[fy]<<'\n';
}
int main(){
	n=read();int i,t1,t2;
	for(i=1;i<=n*2;i++) f[i]=-1;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		join(t1,t2);
	}
	long long ans=1;
	for(i=1;i<=n*2;i++){
		if(find(i)==i){
			if(siz[i]==0) continue;
//			cout<<"available "<<i<<' '<<siz[i]<<' '<<f[i]<<'\n';
			if(siz[i]==-f[i]&&siz[i]>1&&!self[i]) (ans*=2)%=MOD;
			if(siz[i]==-f[i]-1) (ans*=(-f[i]))%=MOD;
		}
	}
	cout<<ans<<'\n';
}
