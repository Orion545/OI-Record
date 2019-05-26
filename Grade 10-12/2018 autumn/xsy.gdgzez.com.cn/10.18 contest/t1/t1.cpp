#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,h,in[1010],f[1010],v[1010],vis[1010];
int find(int x){return ((f[x]==x)?x:(f[x]=find(f[x])));}
int main(){
	n=read();h=read();int i,a,b,c,d,l,r;
	for(i=1;i<=1000;i++) f[i]=i;
	for(i=1;i<=n;i++){
		a=read();b=read();c=read();d=read();
		if(c) l=-c;
		else l=a;
		if(d) r=d;
		else r=-b;
		l+=500;r+=500;
		f[find(l)]=find(r);
		in[l]++;in[r]--;vis[l]=vis[r]=1;
//		cout<<"addedge "<<l<<' '<<r<<' '<<in[l]<<' '<<in[r]<<' '<<find(l)<<' '<<find(r)<<'\n';
	}
	for(i=1;i<500;i++) if(in[i]>0){puts("NO");return 0;}
	for(i=501;i<=1000;i++) if(in[i]<0){puts("NO");return 0;}
	for(i=1;i<=1000;i++) v[i]=(in[i]!=0);
	for(i=1;i<=1000;i++) v[find(i)]|=v[i];
	for(i=1;i<=1000;i++) if(i==find(i)&&vis[i]&&(!v[i])){puts("NO");return 0;}
	puts("YES");
}

