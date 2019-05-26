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

int n,m,son[15000010][2],siz[15000010],rt[400010],cnt,tmpxor=0;
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
int pre[400010],suf[400010],a[400010],sump,sums;
int main(){
	freopen("9.in","r",stdin);
	n=read();int i,ans=0;
	insert(0,1);
	for(i=1;i<=n;i++) a[i]=read(),tmpxor^=a[i],insert(tmpxor,i+1);
	insert(0,n+2);
	for(i=1;i<=n;i++){
		sump^=a[i];
		pre[i]=max(pre[i-1],query(rt[0],rt[i+1],sump));
	}
	for(i=n;i>=1;i--){
		sums^=a[i];
		suf[i]=max(suf[i+1],query(rt[i],rt[n+2],sums));
	}
	for(i=1;i<n;i++) ans=max(ans,pre[i]+suf[i+1]);
	if(ans==16777213) ans++;
	cout<<ans;
}
