#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 1e9
inline int read(){
	int re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='0') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int tot=1,pri[1000010],cnt,vis[1000010];
void init(){
	int i,j,k;
	for(i=2;i<=1000000;i++){
		if(!vis[i]) pri[++cnt]=i;
		for(j=1;j<=cnt;j++){
			k=i*pri[j];if(k>1000000) break;
			vis[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int main(){
	init();
	int a,b,c,cc,ans=inf;c=read();
	int t1,t2,t3;
	int i=1,j;
	for(i=1;i<=cnt;i++){
		if(c%pri[i]==0) tot=max(tot,pri[i]);
		if(pri[i]>c) break;
	}
	ans=cc=c-tot+1;
//	cout<<"finish part 1 "<<c<<ends<<tot<<endl;
	for(i=1;i<=cnt;i++){
		t1=(cc/pri[i])*pri[i]+pri[i]*((cc%pri[i])!=0);
//		cout<<i<<ends<<pri[i]<<ends<<t1<<ends<<ans<<endl;
		if(pri[i]>cc) break;
		if(t1>c||t1==pri[i]) continue;
		ans=min(ans,t1-pri[i]+1);
	}
	cout<<ans<<"\n";
}
