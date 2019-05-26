#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
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
int cnt;
int siz[10000010],ch[10000010][2];
void build(int x){
	int cur=0,tmp;
	for(int i=29;i>=0;i--){
		tmp=(x&(1<<i))!=0;siz[cur]++;
		if(!ch[cur][tmp]) cur=ch[cur][tmp]=++cnt;
		else cur=ch[cur][tmp];
	}
	siz[cur]++;
}
int n,xx[300010];
int search(int x){
	int cur=0,tmp,re=0;
	for(int i=29;i>=0;i--){
		tmp=(x&(1<<i))!=0;siz[cur]--;
		if((!ch[cur][tmp])||(!siz[ch[cur][tmp]])){
//			cout<<"turned\n";
			re+=(1<<i);cur=ch[cur][tmp^1];
		}
		else cur=ch[cur][tmp];
//		cout<<x<<ends<<i<<ends<<tmp<<ends<<re<<ends<<cur<<ends<<siz[cur]<<endl;
	}
	siz[cur]--;return re;
}
int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	int i,t1;
	n=read();
	for(i=1;i<=n;i++) xx[i]=read();
	for(i=1;i<=n;i++) t1=read(),build(t1);
	for(i=1;i<=n;i++){
//		cout<<"search "<<i<<endl;
		printf("%d ",search(xx[i]));
	}
}
