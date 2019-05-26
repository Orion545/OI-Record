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
int n,m,ans=0,num[100010],l[100010],r[100010],siz[100010];
int main(){
	n=read();m=read();int i,t1,lasta=0,cnt=0;
	for(i=1;i<=n;i++) num[i]=read();
	for(i=1;i<=m;i++) l[i]=read(),r[i]=read(),siz[i]=r[i]-l[i]+1;
	int Q=read();
	while(Q--){
		t1=read();//t1=(t1+lasta-1)%n+1;
//		cout<<"do query "<<(++cnt)<<'\n';
		num[t1]--;
		if(!num[t1]){
			for(i=1;i<=m;i++){
				if(!siz[i]) continue;
				if(l[i]<=t1&&r[i]>=t1) siz[i]--;
				if(!siz[i]) ans++;
			}
		}
		lasta=ans;
		printf("%d\n",ans);
	}
}
