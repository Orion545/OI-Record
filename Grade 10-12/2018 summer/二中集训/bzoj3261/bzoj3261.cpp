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
int n,m,son[20000010][2],siz[20000010],rt[600010],cnt,tmpxor=0;
void insert(int num,int exe){
	int cur=rt[exe]=++cnt,pre=rt[exe-1],i;bool tmp;
//	cout<<"insert "<<num<<' '<<exe<<' '<<cur<<' '<<pre<<'\n';
	for(i=30;i>=0;i--){
		tmp=(num&(1<<i));son[cur][tmp]=++cnt;
		son[cur][tmp^1]=son[pre][tmp^1];
		cur=son[cur][tmp];pre=son[pre][tmp];
		siz[cur]=siz[pre]+1;
	}
}
int query(int pre,int cur,int num){
	int i,re=0;bool tmp;
//	cout<<"query "<<pre<<' '<<cur<<' '<<num<<'\n';
	for(i=30;i>=0;i--){
		tmp=(num&(1<<i));tmp^=1;
//		cout<<"	do "<<i<<' '<<tmp<<' '<<re<<' '<<siz[cur]<<' '<<siz[son[cur][tmp]]<<' '<<siz[son[pre][tmp]]<<'\n';
		if(siz[son[cur][tmp]]-siz[son[pre][tmp]]) re|=(1<<i),cur=son[cur][tmp],pre=son[pre][tmp];
		else cur=son[cur][tmp^1],pre=son[pre][tmp^1];
	}
	return re;
}
int main(){
	n=read();m=read();int i,t1,t2,t3;char tt[10];
	insert(0,1);
	for(i=1;i<=n;i++) t1=read(),tmpxor^=t1,insert(tmpxor,i+1);
	n++;
	for(i=1;i<=m;i++){
		scanf("%s",tt);
		if(tt[0]=='A') t1=read(),tmpxor^=t1,insert(tmpxor,++n);
		else{
			t1=read();t2=read();t3=read();
			printf("%d\n",query(rt[t1-1],rt[t2],t3^tmpxor));
		}
	}
}
