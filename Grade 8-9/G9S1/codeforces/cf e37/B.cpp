#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,l[1010],r[1010],q[10010],head,tail,maxn;
int main(){
	int i,T=read(),t;
	while(T--){
		n=read();t=10000;head=0;tail=0;maxn=0;
		memset(q,0,sizeof(q));memset(l,0,sizeof(l));memset(r,0,sizeof(r));
		for(i=1;i<=n;i++) l[i]=read(),r[i]=read(),t=min(t,l[i]),maxn=max(maxn,r[i]);
		i=1;maxn+=n;//cout<<"max:"<<maxn<<endl;
		for(;(t<=maxn)&&((head<tail)||(i<=n));t++){
			while((l[i]==t)&&(i<=n)) q[tail++]=i++;
//			cout<<"time "<<t<<ends<<head<<ends<<tail<<ends<<i<<endl;
			if(head==tail) continue; 
			if(r[q[head]]>=t) printf("%d ",t);
			else t--,printf("0 ");
			head++;
		}
		printf("\n");
	}
} 
