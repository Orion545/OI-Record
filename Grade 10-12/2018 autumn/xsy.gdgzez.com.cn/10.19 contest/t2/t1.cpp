#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
int n,a[200010],b[200010],na[200010],nb[200010],f[200010];
int find(int x){return ((f[x]<0)?x:f[x]=find(f[x]));}
int main(){
	n=read();int i,xa=0,xb=0,ans=0,cnt,t1,t2;
	for(i=1;i<=n;i++) xa^=(na[i]=a[i]=read());
	for(i=1;i<=n;i++) xb^=(nb[i]=b[i]=read());
	n++;
	na[n]=a[n]=xa;nb[n]=b[n]=xb;
	sort(na+1,na+n+1);sort(nb+1,nb+n+1);
	for(i=1;i<=n;i++) if(na[i]!=nb[i]){puts("-1");return 0;}
	for(i=1;i<n;i++) ans+=(a[i]!=b[i]);
	if(!ans){puts("0");return 0;}
	cnt=unique(na+1,na+1+n)-na-1;
	memset(f,-1,sizeof(f));
//	cout<<"final cnt "<<cnt<<'\n';
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<a[i]<<'\n';
	for(i=1;i<=n;i++){
		a[i]=lower_bound(na+1,na+cnt+1,a[i])-na;
		b[i]=lower_bound(na+1,na+cnt+1,b[i])-na;
//		cout<<"get "<<a[i]<<' '<<b[i]<<'\n';
		t1=find(a[i]);t2=find(b[i]);
		if(t1!=t2) f[t1]+=f[t2],f[t2]=t1;
	}
	if(a[n]==b[n]&&f[find(a[n])]==-1) ans++;
	for(i=1;i<=n;i++) ans+=(f[i]<-1);
	printf("%d\n",ans-1);
}


















