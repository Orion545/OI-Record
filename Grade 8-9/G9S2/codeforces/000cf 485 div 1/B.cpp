#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
int n,a[1000010],pos[1000010];
int main(){
	n=read();int i,p1,p2,cnt=0;
	for(i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
	for(i=1;i<=n;i++){
		p1=pos[i];p2=i;
		if(p1==p2) continue;
		swap(pos[a[p1]],pos[a[p2]]);swap(a[p1],a[p2]);
		cnt++;
	}
	if((3*n-cnt)%2==0) puts("Petr");
	else puts("Um_nik");
}
