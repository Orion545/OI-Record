#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll d,len,ans=0,mi[20],me[20],cur[20];
void dfs(ll n,ll val,ll tmp){
//	cout<<"dfs "<<n<<' '<<val<<' '<<tmp<<' '<<d<<' '<<mi[len-n-1]<<' '<<mi[n-1]<<'\n';
	if(n>(len/2-1)){
		
		if(len%2) tmp*=10;
		if(val==d) ans+=tmp;
		return;
	}
	ll i=-9;
	while(i<=9&&i*(mi[len-n-1]-mi[n])+val<=d) i++;
	i--;cur[n]=i;
	dfs(n+1,val+i*(mi[len-n-1]-mi[n]),tmp*(me[i+10]-(n==0&&i>=0)));
	if(i==9) return;
	i++;cur[n]=i;
	dfs(n+1,val+i*(mi[len-n-1]-mi[n]),tmp*(me[i+10]-(n==0&&i>=0)));
} 
int main(){
	d=read();ll i,j;
	mi[0]=1;
	for(i=1;i<=18;i++) mi[i]=mi[i-1]*10;
	for(i=0;i<=9;i++) for(j=0;j<=9;j++) me[i-j+10]++; 
	for(len=0;len<=19;len++) dfs(0,0,1);
	printf("%lld\n",ans);
//	system("pause");
}
